#include "script_component.hpp"
params ["_slider", "_value"];

private _minDiameter = ((getTerrainInfo)#2) * 2;
private _maxDiameter = 300;

private _idc = ctrlIDC _slider;
private _dialog = ctrlParentControlsGroup _slider;
private _valueCtrl = _dialog controlsGroupCtrl (_idc + 1);
private _textCtrl = _dialog controlsGroupCtrl IDC_SIZE_SLIDERTEXT;
private _sliderWidth = _dialog controlsGroupCtrl IDC_SIZE_SLIDERWIDTH;
private _sliderLength = _dialog controlsGroupCtrl IDC_SIZE_SLIDERLENGTH;
([sliderPosition _sliderWidth, sliderPosition _sliderLength] call FUNC(getBrushSizeActual)) params ["_width", "_length"];
_textCtrl ctrlSetText (format ["Size: (%1 / %2)m", _width toFixed 2, _length toFixed 2]);
