#include "script_component.hpp"

if (isServer) then {
    missionNameSpace setVariable [QGVAR(canEdit),true,true];
};
private _action = [
    "Modify Terrain",
    "Modify Terrain",
    "\a3\ui_f\data\Map\MapControl\rock_ca.paa",
    {
        0 spawn FUNC(initDisplay)
    }
] call zen_context_menu_fnc_createAction;
[_action, [], 0] call zen_context_menu_fnc_addAction;
