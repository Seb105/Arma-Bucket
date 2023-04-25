#define FONT_H ((((safezoneW / safezoneH) min 1.2) / 1.5) / 25)
#define FONT_W (FONT_H / pixelH * pixelW)
#define GAP_W (pixelW * 2)
#define GAP_H (pixelH * 2)
#define ELEMENT_HEIGHT FONT_H*3 + FONT_W
#define TOTAL_H FONT_H * 3 + GAP_H
#define SCROLLBAR_WIDTH FONT_W*10
#define SCROLLBAR_HEIGHT FONT_H * 0.8
#define CENTRE_X (safeZoneX + (safeZoneW / 2))
#define CENTRE_Y (safeZoneY + (safeZoneH / 2))
#define SCROLLGROUP_W (SCROLLBAR_WIDTH + FONT_W)
#define TOTAL_W SCROLLGROUP_W*4

class ctrlCheckbox;
class ctrlButton;
class ctrlXSliderH;
class ctrlStatic;
class ctrlStaticTitle;
class RscControlsGroupNoScrollbars;

class GVAR(RscTerrainEditor) : RscControlsGroupNoScrollbars {
    idc = IDD_TERRAIN_EDITOR;
    w = 2;
    x = QUOTE(-safezoneW/3.5);
    y = QUOTE(-safezoneH/2.5);
    class Controls {
        class Title: ctrlStaticTitle {
            x = QUOTE(CENTRE_X);
            y = QUOTE(CENTRE_Y - (FONT_H * 1.2) - GAP_H);
            w = QUOTE(TOTAL_W);
            h = QUOTE(FONT_H * 1.1);
            sizeEx = QUOTE(FONT_H * 1.2);
            text = "Terrain Editor";
        };
        class Background: ctrlStatic {
            colorBackground[] = {0, 0, 0, 0.35};
            x = QUOTE(CENTRE_X);
            y = QUOTE(CENTRE_Y);
            w = QUOTE(TOTAL_W);
            h = QUOTE(ELEMENT_HEIGHT);
        };
        class SizeSliderText: ctrlStatic {
            idc = IDC_SIZE_SLIDERTEXT;
            x = QUOTE(CENTRE_X + FONT_W);
            y = QUOTE(CENTRE_Y - FONT_H);
            w = QUOTE(SCROLLBAR_WIDTH);
            h = QUOTE(ELEMENT_HEIGHT - FONT_W);
            sizeEx = QUOTE(FONT_H);
            text = "Size: (null / null)m";
        };
        class SizeSliderWidth: ctrlXSliderH {
            idc = IDC_SIZE_SLIDERWIDTH;
            x = QUOTE(CENTRE_X + FONT_W/2);
            y = QUOTE(CENTRE_Y + FONT_W/2 + FONT_H);
            w = QUOTE(SCROLLBAR_WIDTH);
            h = QUOTE(SCROLLBAR_HEIGHT);
            tooltip = "Width (m)";
            onSliderPosChanged = QUOTE(_this call FUNC(uiSizeSliderPosChanged));
        };
        class SizeSliderLength: ctrlXSliderH {
            idc = IDC_SIZE_SLIDERLENGTH;
            x = QUOTE(CENTRE_X + FONT_W/2);
            y = QUOTE(CENTRE_Y + FONT_W/2 + FONT_H + SCROLLBAR_HEIGHT + 2*GAP_H);
            w = QUOTE(SCROLLBAR_WIDTH);
            h = QUOTE(SCROLLBAR_HEIGHT);
            tooltip = "Length (m)";
            onSliderPosChanged = QUOTE(_this call FUNC(uiSizeSliderPosChanged));
        };
        class SpeedText: ctrlStatic {
            idc = IDC_SPEED_SLIDERTEXT;
            x = QUOTE(CENTRE_X + FONT_W + SCROLLGROUP_W);
            y = QUOTE(CENTRE_Y - FONT_H);
            w = QUOTE(SCROLLBAR_WIDTH);
            h = QUOTE(ELEMENT_HEIGHT - FONT_W);
            sizeEx = QUOTE(FONT_H);
            text = "Speed: null m / step";
        };
        class SpeedSlider: ctrlXSliderH {
            idc = IDC_SPEED_SLIDER;
            x = QUOTE(CENTRE_X + FONT_W/2 + SCROLLGROUP_W);
            y = QUOTE(CENTRE_Y + FONT_W/2 + FONT_H);
            w = QUOTE(SCROLLBAR_WIDTH);
            h = QUOTE(SCROLLBAR_HEIGHT);
            onSliderPosChanged = QUOTE(_this call FUNC(uiSpeedSliderPosChanged));
        };
        class AngleSlider: ctrlXSliderH {
            idc = IDC_ANGLE_SLIDER;
            x = QUOTE(CENTRE_X + FONT_W/2 + SCROLLGROUP_W*2);
            y = QUOTE(CENTRE_Y + FONT_W/2 + FONT_H);
            w = QUOTE(SCROLLBAR_WIDTH);
            h = QUOTE(SCROLLBAR_HEIGHT);
            onSliderPosChanged = QUOTE(_this call FUNC(uiAngleSliderPosChanged));
        };
        class AngleText: ctrlStatic {
            idc = IDC_ANGLE_SLIDERTEXT;
            x = QUOTE(CENTRE_X + FONT_W + SCROLLGROUP_W*2);
            y = QUOTE(CENTRE_Y - FONT_H);
            w = QUOTE(SCROLLBAR_WIDTH);
            h = QUOTE(ELEMENT_HEIGHT - FONT_W);
            sizeEx = QUOTE(FONT_H);
            text = "Angle: null°";
        };

        class SmoothText: ctrlStatic {
            idc = IDC_SMOOTH_SLIDERTEXT;
            x = QUOTE(CENTRE_X + FONT_W + SCROLLGROUP_W*3);
            y = QUOTE(CENTRE_Y - FONT_H);
            w = QUOTE(SCROLLBAR_WIDTH);
            h = QUOTE(ELEMENT_HEIGHT - FONT_W);
            sizeEx = QUOTE(FONT_H);
            text = "Smoothing: null";
        };
        class SmoothSlider: ctrlXSliderH {
            idc = IDC_SMOOTH_SLIDER;
            x = QUOTE(CENTRE_X + FONT_W/2 + SCROLLGROUP_W*3);
            y = QUOTE(CENTRE_Y + FONT_W/2 + FONT_H);
            w = QUOTE(SCROLLBAR_WIDTH);
            h = QUOTE(SCROLLBAR_HEIGHT);
            onSliderPosChanged = QUOTE(_this call FUNC(uiSmoothSliderPosChanged));
        };
        class RectangleText: ctrlStatic {
            idc = -1;
            x = QUOTE(CENTRE_X + FONT_W + SCROLLGROUP_W);
            y = QUOTE(CENTRE_Y + FONT_W/2 + FONT_H + SCROLLBAR_HEIGHT + 2*GAP_H);
            w = QUOTE(FONT_H*5);
            h = QUOTE(FONT_H);
            sizeEx = QUOTE(FONT_H);
            text = "Rectangle: ";
        };
        class RectangleCheckbox: ctrlCheckbox {
            idc = IDC_RECTANGLE;
            x = QUOTE(CENTRE_X + FONT_W/2 + SCROLLGROUP_W + FONT_H*6);
            y = QUOTE(CENTRE_Y + FONT_W/2 + FONT_H + SCROLLBAR_HEIGHT + 2*GAP_H);
            w = QUOTE(FONT_W);
            h = QUOTE(FONT_H);
        };
        class EditObjectsText: ctrlStatic {
            idc = -1;
            x = QUOTE(CENTRE_X + FONT_W + SCROLLGROUP_W*2);
            y = QUOTE(CENTRE_Y + FONT_W/2 + FONT_H + SCROLLBAR_HEIGHT + 2*GAP_H);
            w = QUOTE(FONT_H*5);
            h = QUOTE(FONT_H);
            sizeEx = QUOTE(FONT_H);
            text = "Move Objects: ";
        };
        class EditObjectsCheckbox: ctrlCheckbox {
            idc = IDC_OBJECTS;
            x = QUOTE(CENTRE_X + FONT_W/2 + SCROLLGROUP_W*2 + FONT_H*6);
            y = QUOTE(CENTRE_Y + FONT_W/2 + FONT_H + SCROLLBAR_HEIGHT + 2*GAP_H);
            w = QUOTE(FONT_W);
            h = QUOTE(FONT_H);
        };
        class FlattenModeText: ctrlStatic {
            idc = -1;
            x = QUOTE(CENTRE_X + FONT_W + SCROLLGROUP_W*3);
            y = QUOTE(CENTRE_Y + FONT_W/2 + FONT_H + SCROLLBAR_HEIGHT + 2*GAP_H);
            w = QUOTE(FONT_H*5);
            h = QUOTE(FONT_H);
            sizeEx = QUOTE(FONT_H);
            text = "Flatten/Restore Mode:";
        };
        class FlattenModeCheckbox: ctrlCheckbox {
            idc = IDC_FLATTEN;
            x = QUOTE(CENTRE_X + FONT_W/2 + SCROLLGROUP_W*3 + FONT_H*6);
            y = QUOTE(CENTRE_Y + FONT_W/2 + FONT_H + SCROLLBAR_HEIGHT + 2*GAP_H);
            w = QUOTE(FONT_W);
            h = QUOTE(FONT_H);
        };
        class CancelButton: ctrlButton {
            idc = -1;
            x = QUOTE(CENTRE_X);
            y = QUOTE(CENTRE_Y + ELEMENT_HEIGHT + GAP_H);
            w = QUOTE(FONT_W * 6);
            h = QUOTE(FONT_H*1.5);
            sizeEx = QUOTE(FONT_H);
            text = "Exit";
            onButtonClick = QUOTE(_this spawn {params ['_ctrl']; private _main = ctrlParentControlsGroup _ctrl; ctrlDelete _main;});
        };
        class ControlsHintText: ctrlStatic {
            idc = -1;
            x = QUOTE(CENTRE_X + FONT_W + SCROLLGROUP_W*2);
            y = QUOTE(CENTRE_Y - (FONT_H * 1.2) - GAP_H);
            w = QUOTE(FONT_H*30);
            h = QUOTE(FONT_H);
            sizeEx = QUOTE(FONT_H*1.1);
            text = "Controls: LCTRL: Raise/Flatten |  LALT: Lower/Restore";
        };
    };
};
