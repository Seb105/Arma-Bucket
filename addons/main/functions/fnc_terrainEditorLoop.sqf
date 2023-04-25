#include "script_component.hpp"
brush_nextEdit = diag_tickTime;
[{
    params ["_args", "_idPFH"];
    _args params ["_ctrl"];
    if (isNull _ctrl) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        systemChat "Brush closed";
    };
    if (isGamePaused || !isGameFocused) exitWith {};
    private _settings = [_ctrl] call brush_fnc_getUIparams;
    _settings params ["_width", "_length", "_speed", "_angle", "_smoothness", "_modifyObjects", "_rectangle", "_flattenMode"];
    private _cursorPos = screenToWorld (getMousePosition);
    _cursorPos set [2, 0];
    private _canEdit = diag_tickTime > brush_nextEdit;
    [_cursorPos, _rectangle, _width, _length, _angle, _canEdit] call brush_fnc_drawBrush;
    if (!_canEdit) exitWith {};
    private _raiseStatus = inputAction "curatorGroupMod";
    private _lowerStatus = inputAction "curatorMoveY";
    private _editDelay = 0.25;
    // systemChat str _flattenMode;
    if (!_flattenMode) then {
        if (_raiseStatus == 1) exitWith {
            brush_nextEdit = diag_tickTime + _editDelay;
            private _area = [_cursorPos, _width, _length, _angle, _rectangle];
            [_area, _speed, _modifyObjects, _smoothness, 3, 2] remoteExecCall ["TerrainLib_fnc_addTerrainHeight", 2];
        };
        if (_lowerStatus == 1) exitWith {
            brush_nextEdit = diag_tickTime + _editDelay;
            private _area = [_cursorPos, _width, _length, _angle, _rectangle];
            [_area, -_speed, _modifyObjects, _smoothness, 3, 2] remoteExecCall ["TerrainLib_fnc_addTerrainHeight", 2];
        };
    } else {
        if (_raiseStatus == 1) exitWith {
            brush_nextEdit = diag_tickTime + _editDelay;
            private _terrainHeight = getTerrainHeightASL _cursorPos;
            private _area = [_cursorPos, _width, _length, _angle, _rectangle];
            [_area, _terrainHeight, _modifyObjects, _smoothness, 3, 2] remoteExecCall ["TerrainLib_fnc_flattenTerrainArea", 2];
        };
        if (_lowerStatus == 1) exitWith {
            brush_nextEdit = diag_tickTime + _editDelay;
            private _area = [_cursorPos, _width, _length, _angle, _rectangle];
            [_area, _modifyObjects, _smoothness, 3, 2] remoteExecCall ["TerrainLib_fnc_restoreTerrainHeight", 2];
        };
    }
}, 0, _this] call CBA_fnc_addPerFrameHandler
