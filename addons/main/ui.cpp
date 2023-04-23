class ctrlXListbox;
class RscXListBox;
class ctrlCheckbox;
class ctrlCheckboxToolbar;
class ctrlButton;
class ctrlXSliderH;
class ctrlMenuStrip;
class ctrlStatic;
class ctrlStaticTitle;
class ctrlControlsGroupNoScrollbars;
class ctrlButtonToolbar;
class ctrlStaticPictureKeepAspect;
class ctrlCombo;
class ctrlStaticBackground;
class ctrlStructuredText;
class RscText;
class GF_deformerToolbar : ctrlControlsGroupNoScrollbars
{
    idc = 873017;
    show = 0;
    x = "((safeZoneW - (210 * (pixelW * pixelGrid * 0.50))) / 2 + safeZoneX)";
    y = "(safezoneY + 21 * (pixelH * pixelGrid * 0.50))";
    w = "(    210 * (pixelW * pixelGrid * 0.50))";
    h = "(    9) * (pixelH * pixelGrid * 0.50)";
    class Controls
    {
        class ToolbarBackground : ctrlStatic
        {
            idc = -1;
            colorBackground[] = {0.2, 0.2, 0.20999999, 1};
            x = 0;
            y = 0;
            w = "safezoneW";
            h = "(40 * (pixelH * pixelGrid * 0.50))";
        };
        class ToolbarLogoBackground : ctrlStatic
        {
            idc = -1;
            colorBackground[] = {0.76999998, 0.50999999, 0.079999998, 1};
            x = 0;
            y = 0;
            w = "(10 * (pixelW * pixelGrid *     0.50))";
            h = "(40 * (pixelH * pixelGrid *     0.50))";
        };
        class logo : ctrlStaticPictureKeepAspect
        {
            idc = -1;
            text = "\GF_Deformer\data\GF_terrainsculptor_ca.paa";
            x = "(    1 * (pixelW * pixelGrid *     0.50))";
            y = "(    0.5 * (pixelH * pixelGrid *     0.50))";
            w = "8 * (pixelW * pixelGrid *     0.50)";
            h = "8 * (pixelH * pixelGrid *     0.50)";
        };
        class brushsizeSlider : ctrlXSliderH
        {
            idc = 103022;
            text = "";
            sliderStep = 1;
            onSliderPosChanged = "['control',_this] call FUNC(deformGUI)";
            tooltip = "";
            colorActive[] = {1, 1, 1, 0.40000001};
            color[] = {1, 1, 1, 0.40000001};
            x = "(    13 * (pixelW * pixelGrid *     0.50))";
            y = "(    2 * (pixelH * pixelGrid *     0.50))";
            w = "(    35 * (pixelW * pixelGrid *     0.50))";
            h = "(    5 * (pixelH * pixelGrid *     0.50))";
        };
        class brushsizetext : ctrlStatic
        {
            idc = 103023;
            text = "SIZE";
            sizeEx = "(3.8 * (1 / (getResolution select 3)) * pixelGrid * 0.5)";
            x = "(22 * (pixelW * pixelGrid *  0.50))";
            y = "(    2 * (pixelH * pixelGrid *     0.50))";
            w = "(22 * (pixelW * pixelGrid *  0.50))";
            h = "(    5 * (pixelH * pixelGrid *     0.50))";
        };
        class brushrateSlider : brushsizeSlider
        {
            idc = 103026;
            text = "";
            sliderStep = 0.25;
            sliderRange[] = {0.1, 4};
            onSliderPosChanged = "['control',_this] call FUNC(deformGUI)";
            tooltip = "";
            x = "(51 * (pixelW * pixelGrid *  0.50))";
        };
        class brushratetext : brushsizetext
        {
            idc = 103027;
            text = "STRENGTH";
            x = "(61 * (pixelW * pixelGrid *  0.50))";
        };
        class brushhardnessSlider : brushsizeSlider
        {
            idc = 103024;
            text = "";
            sliderStep = 0.25;
            onSliderPosChanged = "['control',_this] call FUNC(deformGUI)";
            tooltip = "";
            x = "(89 * (pixelW * pixelGrid *  0.50))";
        };
        class brushhardnesstext : brushsizetext
        {
            idc = 103025;
            text = "HARDNESS";
            x = "(100 * (pixelW * pixelGrid *  0.50))";
        };
        // class toolconvert : ctrlCheckboxToolbar
        // {
        //     idc = 113001;
        //     checked = 0;
        //     tooltip = "Terrain object tool";
        //     onCheckedChanged = "['control',_this] call FUNC(deformGUI)";
        //     colorBackgroundPressed[] =
        //         {
        //             "(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
        //             "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
        //             "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
        //             1};
        //     textureChecked = "\GF_Deformer\data\GF_toolConvertON_ca.paa";
        //     textureUnchecked = "\GF_Deformer\data\GF_toolConvertOFF_ca.paa";
        //     textureFocusedChecked = "\GF_Deformer\data\GF_toolConvertON_ca.paa";
        //     textureFocusedUnchecked = "\GF_Deformer\data\GF_toolConvertOFF_ca.paa";
        //     textureHoverChecked = "\GF_Deformer\data\GF_toolConvertON_ca.paa";
        //     textureHoverUnchecked = "\GF_Deformer\data\GF_toolConvertOFF_ca.paa";
        //     texturePressedChecked = "\GF_Deformer\data\GF_toolConvertON_ca.paa";
        //     texturePressedUnchecked = "\GF_Deformer\data\GF_toolConvertOFF_ca.paa";
        //     textureDisabledChecked = "\GF_Deformer\data\GF_toolConvertON_ca.paa";
        //     textureDisabledUnchecked = "\GF_Deformer\data\GF_toolConvertOFF_ca.paa";
        //     x = "( 128 * (pixelW * pixelGrid *  0.50))";
        //     y = "( 2.0 * (pixelH * pixelGrid *  0.50))";
        //     w = "( 5 * (pixelW * pixelGrid *  0.50))";
        //     h = "( 5 * (pixelH * pixelGrid *  0.50))";
        // };
        class toolreset : toolconvert
        {
            idc = 113002;
            tooltip = "Erase deformations tool";
            textureChecked = "\GF_Deformer\data\GF_toolResetON_ca.paa";
            textureUnchecked = "\GF_Deformer\data\GF_toolResetOFF_ca.paa";
            textureFocusedChecked = "\GF_Deformer\data\GF_toolResetON_ca.paa";
            textureFocusedUnchecked = "\GF_Deformer\data\GF_toolResetOFF_ca.paa";
            textureHoverChecked = "\GF_Deformer\data\GF_toolResetON_ca.paa";
            textureHoverUnchecked = "\GF_Deformer\data\GF_toolResetOFF_ca.paa";
            texturePressedChecked = "\GF_Deformer\data\GF_toolResetON_ca.paa";
            texturePressedUnchecked = "\GF_Deformer\data\GF_toolResetOFF_ca.paa";
            textureDisabledChecked = "\GF_Deformer\data\GF_toolResetON_ca.paa";
            textureDisabledUnchecked = "\GF_Deformer\data\GF_toolResetOFF_ca.paa";
            x = "( 134 * (pixelW * pixelGrid *  0.50))";
        };
        class separator00 : ctrlStatic
        {
            idc = 123454;
            colorBackground[] = {0, 0, 0, 0.5};
            x = "(140.5 * (pixelW * pixelGrid *     0.50))";
            y = "( 2.0 * (pixelH * pixelGrid *  0.50))";
            w = "pixelW";
            h = "( 5 * (pixelH * pixelGrid *  0.50))";
        };
        class adaptive : ctrlCheckboxToolbar
        {
            idc = 103021;
            checked = 0;
            onCheckedChanged = "['control',_this] call FUNC(deformGUI)";
            colorBackgroundPressed[] =
                {
                    "(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
                    "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
                    "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
                    1};
            tooltip = "";
            textureChecked = "\GF_Deformer\data\GF_adaptiveON_ca.paa";
            textureUnchecked = "\GF_Deformer\data\GF_adaptiveOFF_ca.paa";
            textureFocusedChecked = "\GF_Deformer\data\GF_adaptiveON_ca.paa";
            textureFocusedUnchecked = "\GF_Deformer\data\GF_adaptiveOFF_ca.paa";
            textureHoverChecked = "\GF_Deformer\data\GF_adaptiveON_ca.paa";
            textureHoverUnchecked = "\GF_Deformer\data\GF_adaptiveOFF_ca.paa";
            texturePressedChecked = "\GF_Deformer\data\GF_adaptiveON_ca.paa";
            texturePressedUnchecked = "\GF_Deformer\data\GF_adaptiveOFF_ca.paa";
            textureDisabledChecked = "\GF_Deformer\data\GF_adaptiveON_ca.paa";
            textureDisabledUnchecked = "\GF_Deformer\data\GF_adaptiveOFF_ca.paa";
            x = "( 143 * (pixelW * pixelGrid *  0.50))";
            y = "( 2.0 * (pixelH * pixelGrid *  0.50))";
            w = "( 5 * (pixelW * pixelGrid *  0.50))";
            h = "( 5 * (pixelH * pixelGrid *  0.50))";
        };
        class objectlevel : adaptive
        {
            idc = 103019;
            checked = 1;
            onCheckedChanged = "['control',_this] call FUNC(deformGUI)";
            tooltip = "";
            textureChecked = "\GF_Deformer\data\GF_autolevelON_ca.paa";
            textureUnchecked = "\GF_Deformer\data\GF_autolevelOFF_ca.paa";
            textureFocusedChecked = "\GF_Deformer\data\GF_autolevelON_ca.paa";
            textureFocusedUnchecked = "\GF_Deformer\data\GF_autolevelOFF_ca.paa";
            textureHoverChecked = "\GF_Deformer\data\GF_autolevelON_ca.paa";
            textureHoverUnchecked = "\GF_Deformer\data\GF_autolevelOFF_ca.paa";
            texturePressedChecked = "\GF_Deformer\data\GF_autolevelON_ca.paa";
            texturePressedUnchecked = "\GF_Deformer\data\GF_autolevelOFF_ca.paa";
            textureDisabledChecked = "\GF_Deformer\data\GF_autolevelON_ca.paa";
            textureDisabledUnchecked = "\GF_Deformer\data\GF_autolevelOFF_ca.paa";
            x = "(149 * (pixelW * pixelGrid *     0.50))";
        };
        class locked : adaptive
        {
            idc = 103020;
            checked = 0;
            onCheckedChanged = "['control',_this] call FUNC(deformGUI)";
            textureChecked = "\GF_Deformer\data\GF_lockedON_ca.paa";
            textureUnchecked = "\GF_Deformer\data\GF_lockedOFF_ca.paa";
            textureFocusedChecked = "\GF_Deformer\data\GF_lockedON_ca.paa";
            textureFocusedUnchecked = "\GF_Deformer\data\GF_lockedOFF_ca.paa";
            textureHoverChecked = "\GF_Deformer\data\GF_lockedON_ca.paa";
            textureHoverUnchecked = "\GF_Deformer\data\GF_lockedOFF_ca.paa";
            texturePressedChecked = "\GF_Deformer\data\GF_lockedON_ca.paa";
            texturePressedUnchecked = "\GF_Deformer\data\GF_lockedOFF_ca.paa";
            textureDisabledChecked = "\GF_Deformer\data\GF_lockedON_ca.paa";
            textureDisabledUnchecked = "\GF_Deformer\data\GF_lockedOFF_ca.paa";
            colorBackgroundPressed[] = {0, 0, 0, 0};
            x = "( 155 * (pixelW * pixelGrid *  0.50))";
        };
        class separator01 : separator00
        {
            idc = -1;
            colorBackground[] = {0, 0, 0, 0.5};
            x = "(162 * (pixelW * pixelGrid *     0.50))";
        };
        // class undo : ctrlButtonToolbar
        // {
        //     idc = 103038;
        //     text = "\a3\3den\Data\Displays\Display3DEN\ToolBar\undo_ca.paa";
        //     tooltip = "Undo";
        //     onButtonClick = "['control',_this] call FUNC(deformGUI)";
        //     x = "(    164.0 * (pixelW * pixelGrid *     0.50))";
        //     y = "(    2 * (pixelH * pixelGrid *     0.50))";
        //     w = "(    5 * (pixelW * pixelGrid *     0.50))";
        //     h = "(    5 * (pixelH * pixelGrid *     0.50))";
        // };
        class separator02 : separator00
        {
            idc = -1;
            x = "(170.5 * (pixelW * pixelGrid *     0.50))";
        };
        class separator03 : separator00
        {
            idc = -1;
            x = "(198.5 * (pixelW * pixelGrid *     0.50))";
        };
        class tools : ctrlButtonToolbar
        {
            idc = 103041;
            text = "\GF_Deformer\data\GF_toolsOFF_ca.paa";
            tooltip = "Toggle settings & tools menu";
            onButtonClick = "['control',_this] call FUNC(deformGUI)";
            x = "(    201 * (pixelW * pixelGrid * 0.50))";
            y = "(    2 * (pixelH * pixelGrid * 0.50))";
            w = "(    5 * (pixelW * pixelGrid * 0.50))";
            h = "(    5 * (pixelH * pixelGrid * 0.50))";
        };
        class separatorbottom : separator00
        {
            idc = -1;
            colorBackground[] = {0, 0, 0, 0.5};
            x = "(13 * (pixelW * pixelGrid *  0.50))";
            y = "( 9.5 * (pixelH * pixelGrid *  0.50))";
            w = "( 195 * (pixelW * pixelGrid *  0.50))";
            h = "pixelH";
        };
        class brushdarktext : brushsizetext
        {
            idc = -1;
            text = "Dark brush color";
            tooltip = "";
            sizeEx = "(4.5 * (1 / (getResolution select 3)) * pixelGrid * 0.5)";
            x = "( 12 * (pixelW * pixelGrid *  0.50))";
            y = "(    12 * (pixelH * pixelGrid *     0.50))";
            w = "(    31 * (pixelW * pixelGrid *     0.50))";
            h = "(    5 * (pixelH * pixelGrid *     0.50))";
        };
        class brushdarkcheckbox : ctrlCheckbox
        {
            idc = 104041;
            onCheckedChanged = "['control',_this] call FUNC(deformGUI)";
            x = "(    40 * (pixelW * pixelGrid *     0.50))";
            y = "(    12 * (pixelH * pixelGrid *     0.50))";
            w = "( 5 * (pixelW * pixelGrid *  0.50))";
            h = "(    5 * (pixelH * pixelGrid *     0.50))";
        };
        // class autosavetext : brushdarktext
        // {
        //     idc = -1;
        //     text = "Autosave";
        //     tooltip = "";
        //     x = "(    12 * (pixelW * pixelGrid *     0.50))";
        //     y = "(    18 * (pixelH * pixelGrid *     0.50))";
        // };
        // class autosavecheckbox : brushdarkcheckbox
        // {
        //     idc = 103051;
        //     onCheckedChanged = "['control',_this] call FUNC(deformGUI)";
        //     checked = 1;
        //     tooltip = "When disabled, edits are only saved when toolbar is closed.(SHIFT+Y)\This eliminates some stutter after each deformation.";
        //     x = "(    40 * (pixelW * pixelGrid *     0.50))";
        //     y = "(    18 * (pixelH * pixelGrid *     0.50))";
        // };
        // class noiseslisttext : brushdarktext
        // {
        //     idc = -1;
        //     text = "Noise size";
        //     tooltip = "Cell size of the noise tool (ALT+3)";
        //     sizeEx = "4 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
        //     x = "( 12 * (pixelW * pixelGrid *  0.50))";
        //     y = "(    24 * (pixelH * pixelGrid *     0.50))";
        //     w = "(    28 * (pixelW * pixelGrid *     0.50))";
        //     h = "(    5 * (pixelH * pixelGrid *     0.50))";
        // };
        // class noiselistbox : ctrlCombo
        // {
        //     idc = 104043;
        //     text = "";
        //     tooltip = "";
        //     colorActive[] = {1, 1, 1, 0.40000001};
        //     color[] = {1, 1, 1, 0.40000001};
        //     x = "(    33 * (pixelW * pixelGrid *     0.50))";
        //     y = "(    24 * (pixelH * pixelGrid *     0.50))";
        //     w = "( 18 * (pixelW * pixelGrid *  0.50))";
        //     h = "(    5 * (pixelH * pixelGrid *     0.50))";
        //     onLBSelChanged = "['control',_this] call FUNC(deformGUI)";
        //     class Items
        //     {
        //         class size1
        //         {
        //             text = "Small";
        //             value = 1;
        //         };
        //         class size2
        //         {
        //             text = "Medium";
        //             value = 2;
        //             default = 1;
        //         };
        //         class size3
        //         {
        //             text = "Large";
        //             value = 3;
        //         };
        //     };
        // };
        class highlightareatext : brushdarktext
        {
            idc = -1;
            text = "Show edited area";
            tooltip = "";
            x = "(    56 * (pixelW * pixelGrid *     0.50))";
        };
        class highlightareacheckbox : brushdarkcheckbox
        {
            idc = 103039;
            onCheckedChanged = "['control',_this] call FUNC(deformGUI)";
            checked = 0;
            tooltip = "";
            x = "(    84 * (pixelW * pixelGrid *     0.50))";
        };
        class hidegrasstext : brushdarktext
        {
            idc = -1;
            text = "Hide grass";
            tooltip = "";
            x = "(    56 * (pixelW * pixelGrid *     0.50))";
            y = "(    18 * (pixelH * pixelGrid *     0.50))";
        };
        class hidegrasscheckbox : brushdarkcheckbox
        {
            idc = 103040;
            onCheckedChanged = "['control',_this] call FUNC(deformGUI)";
            checked = 0;
            tooltip = "";
            x = "(    84 * (pixelW * pixelGrid *     0.50))";
            y = "(    18 * (pixelH * pixelGrid *     0.50))";
        };
        // class resetedits : ctrlButton
        // {
        //     idc = 104049;
        //     text = "Reset";
        //     sizeEx = "(4.5 * (1 / (getResolution select 3)) * pixelGrid * 0.5)";
        //     tooltip = "";
        //     onButtonClick = "['control',_this] call FUNC(deformGUI)";
        //     x = "(    172 * (pixelW * pixelGrid * 0.50))";
        //     y = "(    12 * (pixelH * pixelGrid *     0.50))";
        //     w = "(    26 * (pixelW * pixelGrid *     0.50))";
        //     h = "(    5 * (pixelH * pixelGrid *     0.50))";
        // };
        class deformerinfo : ctrlButtonToolbar
        {
            idc = 103042;
            text = "\GF_deformer\data\GF_help_ca.paa";
            tooltip = "";
            action = "(findDisplay 313) createDisplay 'GF_deformInfo'";
            x = "(    201.5 * (pixelW * pixelGrid * 0.50))";
            y = "(    11.5 * (pixelH * pixelGrid * 0.50))";
            w = "(    6 * (pixelW * pixelGrid * 0.50))";
            h = "(    6 * (pixelH * pixelGrid * 0.50))";
        };
    };
};
