class CfgPatches
{
    class FullVehicleRepair
    {
        units[] = {}; // No units added
        weapons[] = {}; // No weapons added
        requiredVersion = 1.0; // Minimum game version (set this according to your game version)
        requiredAddons[] = {
            "DZ_Data", // Required data files
            "DZ_Scripts", // Base scripts
            "DZ_Gear_Tools", // For tools (like Blowtorch)
            "DZ_Vehicles_Parts" // Required for vehicle-related classes
        }; 
    };
};

class CfgMods
{
    class FullVehicleRepair
    {
        dir = "FullVehicleRepair"; // Mod folder name
        picture = ""; // No picture (can be added later if needed)
        action = ""; // No action URL
        hideName = 0; // Mod name visible
        hidePicture = 1; // No picture to display
        name = "Full Vehicle Repair"; // Mod name
        credits = "Ghosty"; // Mod credits
        author = "Ghosty"; // Author name
        authorID = "0"; // Optional (ID can be filled)
        version = "0.1"; // Mod version
        extra = 0; // No extra info
        type = "mod"; // Mod type
        dependencies[] = {
            "Game", // Game dependency
            "World", // World dependency for entities and world scripts
            "Mission" // Mission scripts dependency
        };

        class defs
        {
            class gameScriptModule
            {
                files[] = {
                    "FullVehicleRepair/Scripts/3_Game" // Path to Game scripts
                };
            };
            class worldScriptModule
            {
                files[] = {
                    "FullVehicleRepair/Scripts/4_World" // Path to World scripts (if applicable)
                };
            };
            class missionScriptModule
            {
                files[] = {
                    "FullVehicleRepair/Scripts/5_Mission" // Path to Mission scripts (if applicable)
                };
            };
        };
    };
};
