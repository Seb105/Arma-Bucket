#include "script_component.hpp"
params ["_slider", "_value"];
private _idc = ctrlIDC _slider;
private _dialog = ctrlParentControlsGroup _slider;
private _textCtrl = _dialog controlsGroupCtrl IDC_SMOOTH_SLIDERTEXT;
private _smooth = sliderPosition _slider;
_textCtrl ctrlSetText (format ["Smooth: %1", _smooth toFixed 2]);
