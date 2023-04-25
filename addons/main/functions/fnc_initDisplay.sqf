#include "script_component.hpp"
private _zenDisplay = findDisplay 312;
private _ctrl = _zenDisplay ctrlCreate ["terrainEditor", -1];
{
    (_ctrl controlsGroupCtrl _x) sliderSetRange [0, 1];
    (_ctrl controlsGroupCtrl _x) sliderSetPosition 0.5;
} forEach [
    IDC_SIZE_SLIDERWIDTH,
    IDC_SIZE_SLIDERLENGTH
];
(_ctrl controlsGroupCtrl IDC_SIZE_SLIDERWIDTH) call brush_fnc_sizeSliderPosChanged;

(_ctrl controlsGroupCtrl IDC_SPEED_SLIDER) sliderSetRange [0.1, 25];
(_ctrl controlsGroupCtrl IDC_SPEED_SLIDER) sliderSetPosition 10;
(_ctrl controlsGroupCtrl IDC_SPEED_SLIDER) call brush_fnc_speedSliderPosChanged;

(_ctrl controlsGroupCtrl IDC_ANGLE_SLIDER) sliderSetRange [0, 360];
(_ctrl controlsGroupCtrl IDC_ANGLE_SLIDER) sliderSetPosition 0;
(_ctrl controlsGroupCtrl IDC_ANGLE_SLIDER) call brush_fnc_angleSliderPosChanged;

(_ctrl controlsGroupCtrl IDC_SMOOTH_SLIDER) sliderSetRange [0, 1];
(_ctrl controlsGroupCtrl IDC_SMOOTH_SLIDER) sliderSetPosition 1;
(_ctrl controlsGroupCtrl IDC_SMOOTH_SLIDER) call brush_fnc_smoothSliderPosChanged;

(_ctrl controlsGroupCtrl IDC_OBJECTS) cbSetChecked true;

[_ctrl] call brush_fnc_terrainEditorLoop;
