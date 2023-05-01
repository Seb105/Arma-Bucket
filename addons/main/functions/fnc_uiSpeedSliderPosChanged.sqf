#include "script_component.hpp"
params ["_slider", "_value"];
private _idc = ctrlIDC _slider;
private _dialog = ctrlParentControlsGroup _slider;
private _textCtrl = _dialog controlsGroupCtrl IDC_SPEED_SLIDERTEXT;
private _speed = [sliderPosition _slider] call FUNC(getSpeedActual);
_textCtrl ctrlSetText (format ["Speed: %1m / step", _speed toFixed 2]);
