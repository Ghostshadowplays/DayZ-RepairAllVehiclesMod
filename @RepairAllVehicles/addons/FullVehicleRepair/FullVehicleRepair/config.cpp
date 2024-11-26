
class CfgPatches
{
	class FullVehicleRepair
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts","DZ_Gear_Tools","DZ_Vehicles_Parts"};
	};
};
class CfgMods
{
	class FullVehicleRepair
	{
		dir = "FullVehicleRepair";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 1;
		name = "Full Vehicle Repair";
		credits = "Ghosty";
		author = "Ghosty";
		authorID = "0";
		version = "0.1";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				files[] = {"FullVehicleRepair/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				files[] = {"FullVehicleRepair/Scripts/4_World"};
			};
			class missionScriptModule
			{
				files[] = {"FullVehicleRepair/Scripts/5_Mission"};
			};
		};
	};
};
