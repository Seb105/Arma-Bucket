
private _menu = findDisplay 313;
private _mode = _this#0;

if (_mode == "control") then {

    GF_lastAction set [1, diag_tickTime];
    ctrlSetFocus (_menu displayCtrl 103042);
    _ctrl = (_this#1#0);
    _ctrlidc = ctrlIDC (_this#1#0);    
    
    switch (_ctrlidc) do 
    {
        case 103022: {
            _value = _this#1#1;
            private _old = GF_brushSize;
            if (_value < 28) then {
                GF_brushSize = round _value max 1;
            } else {
                GF_brushSize = round (29+((_value-29)*2));
            };
            (_menu displayCtrl 103023) ctrlSetText format ["SIZE %1 m",round(GF_brushSize*GF_gridSize*2)];
                        
            if (GF_brushSize>=10) then {
                ["preBrush","updateHardness"] call GF_fnc_deformFunc;                
            };
            if ((_old > 7 && GF_brushSize < 8) || (_old < 8 && GF_brushSize > 7)) then {
                ["createBrushDecals"] call GF_fnc_deformFunc;
            };
        };

        case 103026: {
            GF_brushRate = _this#1#1;
        };
        
        case 103024: {
            GF_brushHardness = _this#1#1;
            if (GF_brushSize>=10) then {
                ["preBrush","updateHardness"] call GF_fnc_deformFunc;
            };
        };    
        
        case 113001: {
            ["switchTool",[_ctrlidc]] call GF_fnc_deformFunc;
        };
        case 113002: {
            ["switchTool",[_ctrlidc]] call GF_fnc_deformFunc;
        };
        
        case 103021: {
            _value = _this#1#1;
            GF_adaptive = [false,true] select _value;
            _ctrl ctrlsettooltip ("Adaptive raise/lower"+ (["(OFF)","(ON)"] select GF_adaptive));
        };
        
        case 103020: {
            _value = _this#1#1;
            if (GF_brushLimit > -100) then {
                GF_brushLimit = -100;
                _ctrl ctrlsettooltip ("Limit height");                
                GF_terrainIcons set [0, [[diag_tickTime +5,screenToWorld [0.5,0.8],format ["LIMIT REMOVED"],[1,1,1,1],0.8,"\GF_Deformer\data\GF_unlocked_ca.paa"]]];
            } else {
                [_ctrl] spawn {
                    ["notification",["Click ground to select height",0,false]] call GF_fnc_deformFunc;
                    GF_mouseclicked = false;
                    uiSleep 0.2;
                    _pos = [0,0,0];
                    waitUntil {
                        uisleep 0.03;
                        _pos = screenToWorld getMousePosition vectoradd [0,0,0.1];
                        GF_terrainIcons set [0,[[diag_tickTime+0.5,_pos,format ["Limit to %1m",(getTerrainHeightASL _pos) toFixed 1],[1,1,1,1],1,"\GF_Deformer\data\GF_unlocked_ca.paa"]]];
                        GF_mouseclicked
                    };
                    ["notification",["",1,false]] call GF_fnc_deformFunc;
                    GF_brushLimit = getTerrainHeightASL _pos; 
                    GF_mouseclicked = false;
                    GF_terrainIcons set [0,[[diag_tickTime+5,_pos,format ["LIMIT %1m",GF_brushLimit toFixed 1],[1,1,1,1],0.8,"\GF_Deformer\data\GF_locked_ca.paa"]]];
                    (_this#0) ctrlsettooltip (format ["Height limited to %1 m",GF_brushLimit tofixed 1]);
                };
            };
        };        
        
        case 103019: {
            _value = _this#1#1;
            GF_levelObjects = [false,true] select _value;
            _ctrl ctrlsettooltip ("Autolevel objects"+ (["(OFF)","(ON)"] select GF_levelObjects));
        };            
        
        case 103038: {
            ["doUndo",true] call GF_fnc_deformFunc;
            _ctrl ctrlEnable (count GF_history >0);
            ["showArea",cbChecked (_menu displayCtrl 103039)] call GF_fnc_deformFunc;
        };
        
        
        case 103040: {
            setterraingrid ([-1,49] select cbChecked _ctrl);
        };
        
        case 103039: {
            ["showArea",[cbChecked _ctrl,true]] call GF_fnc_deformFunc;
        };        
        
        case 103051: {
            if (cbChecked _ctrl) then {
                if (GF_waitingsave) then {
                    ["saveDeformations",[true]] call GF_fnc_deformFunc;
                    GF_waitingsave= false;
                };
            };
        };
        
        case 104049: {
            ['Are you sure you want to remove all terrain modifications?','Reset?',['Yes',{['resetEdits',[]] call GF_fnc_deformFunc;}],['No',{}],''] call BIS_fnc_3DENShowMessage;
        };
        
        case 103041: {// tools
            private _toolbar = _menu displayCtrl 873011;
            private _height = getNumber (configFile >> "Display3DEN" >> "Controls" >> "GF_deformerToolbar" >> "h");
            private _text = getText (configFile >> "Display3DEN" >> "Controls" >> "GF_deformerToolbar" >> "Controls" >> "tools" >> "text");;
            if (ctrlposition _toolbar#3 < _height*1.02) then {
                    _height = (32) * (pixelH * pixelGrid *  0.50);
                    _ctrl ctrlSetText "\GF_Deformer\data\GF_toolsON_ca.paa"
                } else {
                    _ctrl ctrlSetText _text;
                };
            _toolbar ctrlSetPositionh _height;
            _toolbar ctrlCommit 0.1;
        };
        
        case 104050: {
            ["Export Deformer script?<br/><br/>This may lock the game for a moment.",
            "Export?",
            ["Yes",{["exportSQF",[]] call GF_fnc_deformFunc}],
            ["No",{}],""] call BIS_fnc_3DENShowMessage;        
        };        
        case 104051: {
            ["Export ASC heightmap to clipboard? It may lock the game for minutes. You should save the mission beforehand just in case.",
            "Export?",
            ["Yes",{["exportASC"] call GF_fnc_deformFunc}],
            ["No",{}],""] call BIS_fnc_3DENShowMessage;            
        };        
        case 104041: {
            ["createBrushDecals"] call GF_fnc_deformFunc;                
        };        
        case 104043: {
            GF_noisemaps set [0,GF_noiseMaps#((_this#1#1)+1)];
        };        
        default {};
    };

};
if (_mode == "update") then {
    
    (_menu displayCtrl 103022) sliderSetSpeed [1,1];
    (_menu displayCtrl 103022) sliderSetRange [1,38]; 
    _spos = GF_brushSize;
    if (GF_brushSize > 28) then { 
        _spos = 29+((GF_brushSize-29)/2) 
    };
    (_menu displayCtrl 103022) sliderSetPosition _spos;
    
    (_menu displayCtrl 103023) ctrlSetText format ["SIZE: %1 m",round (GF_brushSize*GF_gridSize*2)];
    
    (_menu displayCtrl 103024) sliderSetRange [-0.8,6];
    (_menu displayCtrl 103024) sliderSetSpeed [0.5,0.5];
    (_menu displayCtrl 103024) sliderSetPosition GF_brushHardness;
    
    (_menu displayCtrl 103026) sliderSetSpeed [0.30,0.25];
    (_menu displayCtrl 103026) sliderSetRange [0.25,8];
    (_menu displayCtrl 103026) sliderSetPosition GF_brushRate;
    
    (_menu displayCtrl 113001) cbSetChecked false;
    (_menu displayCtrl 113002) cbSetChecked false;
    
    (_menu displayCtrl 103021) cbSetChecked GF_adaptive;
    (_menu displayCtrl 103021) ctrlsettooltip ("Adaptive raise/lower"+ (["(OFF)","(ON)"] select GF_adaptive));
    
    _tip = if (GF_brushLimit == -100) then {"Limit height"} else {format ["Height limited to %1 m",GF_brushLimit tofixed 1]};
    (_menu displayCtrl 103020) cbSetChecked (GF_brushLimit >-100);
    (_menu displayCtrl 103020) ctrlsettooltip _tip;
    
    (_menu displayCtrl 103019) cbSetChecked GF_levelObjects;
    (_menu displayCtrl 103019) ctrlsettooltip ("Autolevel objects"+ (["(OFF)","(ON)"] select GF_levelObjects));
    
    (_menu displayCtrl 103038) ctrlEnable (count GF_history >0);
    
    setterraingrid ([-1,49] select (cbChecked (_menu displayCtrl 103040)));

    (_menu displayCtrl 103039) cbSetChecked false; //area
    
    GF_noisemaps set [0,GF_noisemaps#(lbCurSel (_menu displayCtrl 104043) +1)];

};
