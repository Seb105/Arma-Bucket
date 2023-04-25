#include "script_component.hpp"
params ["_args", "_mode"];
missionNameSpace setVariable [QGVAR(canEdit), false, true];
private _fnc = switch _mode do {
    case 0: {
        Terrainlib_fnc_addTerrainHeight
    };
    case 1: {
        Terrainlib_fnc_flattenTerrainArea
    };
    case 2: {
        Terrainlib_fnc_restoreTerrainHeight
    };
};

[{
    params ["_args", "_fnc"];
    [{
        missionNameSpace setVariable [QGVAR(canEdit), true, true];
    }] call CBA_fnc_execNextFrame;
    _args call _fnc;
}, [_args, _fnc]] call CBA_fnc_execNextFrame;
