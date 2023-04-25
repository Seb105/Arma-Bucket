#include "script_component.hpp"
params ["_ctrl"];
private _minDiameter = ((getTerrainInfo)#2) * 2;
private _maxDiameter = 300;

private _width = sliderPosition (_ctrl controlsGroupCtrl IDC_SIZE_SLIDERWIDTH);
private _length = sliderPosition (_ctrl controlsGroupCtrl IDC_SIZE_SLIDERLENGTH);
_width = _width^3*_maxDiameter + _minDiameter;
_length = _length^3*_maxDiameter + _minDiameter;
private _speed = sliderPosition (_ctrl controlsGroupCtrl IDC_SPEED_SLIDER);
private _angle = sliderPosition (_ctrl controlsGroupCtrl IDC_ANGLE_SLIDER);
private _smooth = sliderPosition (_ctrl controlsGroupCtrl IDC_SMOOTH_SLIDER);
private _modifyObjects = cbChecked (_ctrl controlsGroupCtrl IDC_OBJECTS);
private _rectangle = cbChecked (_ctrl controlsGroupCtrl IDC_RECTANGLE);
private _flattenMode = cbChecked (_ctrl controlsGroupCtrl IDC_FLATTEN);
[_width, _length, _speed, _angle, _smooth, _modifyObjects, _rectangle, _flattenMode]
