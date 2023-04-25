#include "script_component.hpp"
params ["_cursorPos", "_rectangle", "_width", "_length", "_angle", "_canEdit"];
private _gridSize = (_width max _length) * 3;
getTerrainInfo params ["", "", "_cellsize", "_resolution"];
private _gridSideLength = ceil (_gridSize / _cellsize);
private _sinAngle = sin _angle;
private _cosAngle = cos _angle;

// Drawing edges of brush area
private _edges = if (_rectangle) then {
    private _sinWidth = _sinAngle * _width;
    private _cosWidth = _cosAngle * _width;
    private _sinLength = _sinAngle * _length;
    private _cosLength = _cosAngle * _length;
    private _edges = [];
    private _p1 = [ -_sinLength - _cosWidth, -_cosLength + _sinWidth, 1];
    private _p2 = [ -_sinLength + _cosWidth, -_cosLength - _sinWidth, 1];
    private _p3 = [ _sinLength + _cosWidth, _cosLength - _sinWidth, 1];
    private _p4 = [ _sinLength - _cosWidth, _cosLength + _sinWidth, 1];
    private _p1Dir = _p1 vectorFromTo _p2;
    private _p2Dir = _p2 vectorFromTo _p3;
    private _p3Dir = _p3 vectorFromTo _p4;
    private _p4Dir = _p4 vectorFromTo _p1;
    for "_i" from 1 to 10 do {
        private _startWidth = ((_i-1) / 10) * 2 * _width;
        private _endWidth = (_i / 10) * 2 * _width;
        private _startLength = ((_i-1) / 10) * 2 * _length;
        private _endLength = (_i / 10) * 2 * _length;
        private _p1Start = _p1 vectorAdd (_p1Dir vectorMultiply _startWidth);
        private _p1End = _p1 vectorAdd (_p1Dir vectorMultiply _endWidth);
        private _p2Start = _p2 vectorAdd (_p2Dir vectorMultiply _startLength);
        private _p2End = _p2 vectorAdd (_p2Dir vectorMultiply _endLength);
        private _p3Start = _p3 vectorAdd (_p3Dir vectorMultiply _startWidth);
        private _p3End = _p3 vectorAdd (_p3Dir vectorMultiply _endWidth);
        private _p4Start = _p4 vectorAdd (_p4Dir vectorMultiply _startLength);
        private _p4End = _p4 vectorAdd (_p4Dir vectorMultiply _endLength);
        _edges pushBack [_p1Start, _p1End];
        _edges pushBack [_p2Start, _p2End];
        _edges pushBack [_p3Start, _p3End];
        _edges pushBack [_p4Start, _p4End];
    };
    _edges
} else {
    private _edges = [];
    private _step = 10;
    private _mod = (time*4) % 360;
    for "_i" from 0 to 360 step _step do {
        _i1 = _i + _mod;
        private _i2 = _i1 + _step;
        private _sini1 = sin _i1;
        private _cosi1 = cos _i1;
        private _sini2 = sin _i2;
        private _cosi2 = cos _i2;
        private _p1 = [
            _cosi1 * _length * _sinAngle - _sini1 * _width * _cosAngle,
            _cosi1 * _length * _cosAngle + _sini1 * _width * _sinAngle,
            1
        ];
        private _p2 = [
            _cosi2 * _length * _sinAngle - _sini2 * _width * _cosAngle,
            _cosi2 * _length * _cosAngle + _sini2 * _width * _sinAngle,
            1
        ];
        _edges pushBack [_p1, _p2];
    };
    _edges
};
_edges = _edges apply {
    [
        _x#0 vectorAdd _cursorPos,
        _x#1 vectorAdd _cursorPos
    ]
};
private _edgeColour = if (_canEdit) then {
    [0, 0, 1, 1]
} else {
    [1, 0, 0, 1]
};
{
    _x params ["_start", "_end"];
    drawLine3D [_start, _end, _edgeColour];
    drawIcon3D ["\A3\ui_f\data\igui\cfg\simpleTasks\types\default_ca", _edgeColour, _start, 0.25, 0.25, 0];
} forEach _edges;





/* Drawing grid of terrain cells */
_cursorPosNearestCell = _cursorPos apply {
    (floor (_x/_cellsize)) * _cellsize
};
_cursorPosNearestCell set [2, 1];
private _grid = [];
// Simplify grid drawing by only drawing every nth line when count is too large
private _maxDrawsPerSide = 500;
private _numSegments = (ceil (_maxDrawsPerSide / _gridSideLength)) min _gridSideLength;
private _segmentLength = (ceil (_gridSideLength / _numSegments));
private _gridSideLengthNew = _numSegments * _segmentLength;
private _halfSideLength= _gridSideLengthNew / 2;
for "_i" from -_halfSideLength to _halfSideLength do {
    for "_j" from -_halfSideLength to _halfSideLength step _segmentLength do {
        private _start = [_i, _j, 0] vectorMultiply _cellsize;
        private _end = [_i, _j+_segmentLength, 0] vectorMultiply _cellsize;
        _grid pushBack [
            _start vectorAdd _cursorPosNearestCell,
            _end vectorAdd _cursorPosNearestCell
        ];
        private _start = [_j, _i, 0] vectorMultiply _cellsize;
        private _end = [_j+_segmentLength, _i, 0] vectorMultiply _cellsize;
        _grid pushBack [
            _start vectorAdd _cursorPosNearestCell,
            _end vectorAdd _cursorPosNearestCell
        ];
    };
};
{
    drawLine3D [_x#0, _x#1, [1, 0, 1, 1]]
} forEach _grid;
