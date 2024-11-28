// fnc_RepairCar.sqf
params ["_blowtorch"];

if (isNull _blowtorch) exitWith {};  // Make sure the blowtorch is valid

_target = _blowtorch;  // Target vehicle (should be the Blowtorch that the player is using)

if (!(_target isKindOf "Car")) exitWith {};  // Check if the target is a car

// List of vehicle components that need repair
_vehicleParts = [
    "engine",
    "fuelTank",
    "radiator",
    "wheels",
    "doors",
    "body",
    "hood",
    "trunk"
];

// Loop through each part and repair it
{
    _part = _vehicleParts select _forEachIndex;

    // Repair the part
    if (_target getVariable [_part, -1] == 0) then
    {
        _target setVariable [_part, 100];  // Set the part health to pristine (100%)
    };
} forEach _vehicleParts;

// Send a message or play sound upon successful repair
player playActionNow "Craft";
["Vehicle repaired!", "You have successfully repaired the vehicle with the blowtorch."] call BIS_fnc_infoText;
