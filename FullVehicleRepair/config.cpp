class CfgPatches
{
    class Custom_Blowtorch_Mod
    {
        units[] = {};  
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"}; 
    };
};

class CfgVehicles
{
    class Inventory_Base;

    class Blowtorch: Inventory_Base
    {
        scope = 2;
        displayName = "Blowtorch Repair Tool";
        descriptionShort = "A blowtorch that can repair vehicles.";
        model = "\dz\gear\tools\blowtorch.p3d"; 
        weight = 500;
        itemSize[] = {3, 3};
        rotationFlags = 1;
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"dz\gear\tools\data\blowtorch_co.paa"};

        class EnergyManager
        {
            energyUsagePerSecond = 0.01;
            plugType = 1;
            attachmentAction = 1;
            hasIcon = 1;
        };

        class AnimEvents
        {
            class SoundWeapon
            {
                class BlowtorchTurnOn
                {
                    soundSet = "BlowtorchTurnOn_SoundSet";
                    id = 201;
                };
                class BlowtorchTurnOff
                {
                    soundSet = "BlowtorchTurnOff_SoundSet";
                    id = 202;
                };
            };
        };
        
        class Actions
        {
            class Repair
            {
                actionName = "Repair Vehicle";
                inputs[] = {"UAInputCarRepair"};
                condition = "(_target isKindOf 'Car') and (player distance _target < 5)";
                statement = "[this] call Custom_Blowtorch_Mod_fnc_RepairCar";
            };
        };
    };
};

class CfgActions
{
    class ActionRepairCarWithBlowtorch
    {
        actionName = "Repair Vehicle";
        inputs[] = {"UAInputCarRepair"};
        condition = "(_target isKindOf 'Car') and (player distance _target < 5)";
        statement = "[this] call Custom_Blowtorch_Mod_fnc_RepairCar";
    };
};

// Add your custom input action
class CfgInputActions
{
    class UAInputCarRepair
    {
        action = "UAInputCarRepair";  
        displayName = "Repair Vehicle"; 
        type = "keyboard";
        binding = "U";  
    };
};
