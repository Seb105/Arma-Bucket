#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = QUOTE(COMPONENT);
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"zen_context_menu", "zen_dialog", "TerrainLib_main"};
        author = "Seb";
        VERSION_CONFIG;
    };
};


#include "CfgFunctions.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgRsc.hpp"
