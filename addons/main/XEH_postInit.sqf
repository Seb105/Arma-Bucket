#include "script_component.hpp"

private _action = [
    "Modify Terrain",
    "Modify Terrain",
    "\a3\ui_f\data\igui\rsctitles\mpprogress\timer_ca.paa",
    {
        0 spawn FUNC(initDisplay)
    }
] call zen_context_menu_fnc_createAction;
[_action, [], 0] call zen_context_menu_fnc_addAction;
