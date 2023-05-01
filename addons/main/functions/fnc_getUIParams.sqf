#include "script_component.hpp"
params ["_ctrl"];
private _widthP = sliderPosition (_ctrl controlsGroupCtrl IDC_SIZE_SLIDERWIDTH);
private _lengthP = sliderPosition (_ctrl controlsGroupCtrl IDC_SIZE_SLIDERLENGTH);
([_widthP, _lengthP] call FUNC(getBrushSizeActual)) params ["_width", "_length"];
private _speed = [sliderPosition (_ctrl controlsGroupCtrl IDC_SPEED_SLIDER)] call FUNC(getSpeedActual);
private _angle = sliderPosition (_ctrl controlsGroupCtrl IDC_ANGLE_SLIDER);
private _smooth = sliderPosition (_ctrl controlsGroupCtrl IDC_SMOOTH_SLIDER);
private _modifyObjects = cbChecked (_ctrl controlsGroupCtrl IDC_OBJECTS);
private _rectangle = cbChecked (_ctrl controlsGroupCtrl IDC_RECTANGLE);
private _flattenMode = cbChecked (_ctrl controlsGroupCtrl IDC_FLATTEN);
[_width, _length, _speed, _angle, _smooth, _modifyObjects, _rectangle, _flattenMode]
