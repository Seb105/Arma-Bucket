#include "script_component.hpp"
[{
    params ["_args", "_idPFH"];
    _args params ["_ctrl"];
    if (isNull _ctrl || !(ctrlShown _ctrl)) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        // systemChat "Brush closed";
    };
    if (isGamePaused || !isGameFocused) exitWith {};
    private _canEdit = GVAR(canEdit);
    private _settings = [_ctrl] call FUNC(getUIparams);
    _settings params ["_width", "_length", "_speed", "_angle", "_smoothness", "_modifyObjects", "_rectangle", "_flattenMode"];
    private _cursorPos = screenToWorld (getMousePosition);
    _cursorPos set [2, 0];
    [_cursorPos, _rectangle, _width, _length, _angle, _canEdit] call FUNC(drawBrush);
    if (!_canEdit) exitWith {};
    private _raiseStatus = inputAction "curatorGroupMod";
    private _lowerStatus = inputAction "curatorMoveY";
    private _editDelay = 0.25;
    private _area = [_cursorPos, _width, _length, _angle, _rectangle];
    if (!_flattenMode) then {
        // Raise terrain
        if (_raiseStatus == 1) exitWith {
            private _args = [_area, _speed, _modifyObjects, _smoothness, 3, 2];
            private _mode = 0;
            missionNameSpace setVariable [QGVAR(canEdit), false, true];
            [_args, _mode] remoteExecCall [QFUNC(modifyTerrain), 2];
        };
        // Lower terrain
        if (_lowerStatus == 1) exitWith {
            private _args = [_area, -_speed, _modifyObjects, _smoothness, 3, 2];
            private _mode = 0;
            missionNameSpace setVariable [QGVAR(canEdit), false, true];
            [_args, _mode] remoteExecCall [QFUNC(modifyTerrain), 2];
        };
    } else {
        // Flatten terrain
        if (_raiseStatus == 1) exitWith {
            private _terrainHeight = getTerrainHeightASL _cursorPos;
            private _args = [_area, _terrainHeight, _modifyObjects, _smoothness, 3, 2];
            private _mode = 1;
            missionNameSpace setVariable [QGVAR(canEdit), false, true];
            [_args, _mode] remoteExecCall [QFUNC(modifyTerrain), 2];
        };
        // Restore terrain
        if (_lowerStatus == 1) exitWith {
            private _args = [_area, _modifyObjects, _smoothness, 3, 2];
            private _mode = 2;
            missionNameSpace setVariable [QGVAR(canEdit), false, true];
            [_args, _mode] remoteExecCall [QFUNC(modifyTerrain), 2];
        };
    }
}, 0, _this] call CBA_fnc_addPerFrameHandler
