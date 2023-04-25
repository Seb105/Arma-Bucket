#include "script_component.hpp"
params ["_slider", "_value"];
private _idc = ctrlIDC _slider;
private _dialog = ctrlParentControlsGroup _slider;
private _textCtrl = _dialog controlsGroupCtrl IDC_ANGLE_SLIDERTEXT;
private _angle = sliderPosition _slider;
_textCtrl ctrlSetText (format ["Angle: %1°", _angle toFixed 1]);
