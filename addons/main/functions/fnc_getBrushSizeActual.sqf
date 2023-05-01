#include "script_component.hpp"
params ["_width", "_length"];
private _minDiameter = ((getTerrainInfo)#2);
private _maxDiameter = 300;
_width = _width^3*(_maxDiameter - _minDiameter) + _minDiameter;
_length = _length^3*(_maxDiameter - _minDiameter) + _minDiameter;
[_width, _length]
