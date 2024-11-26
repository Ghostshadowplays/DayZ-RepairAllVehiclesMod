modded class Blowtorch
{
    void RepairVehicle(EntityAI vehicle)
    {
        if (vehicle)
        {
            vehicle.SetHealth("", "", vehicle.GetMaxHealth("", ""));
        }
    }


    override void OnInit()
    {
        super.OnInit();

        DayZGame game = GetDayZGame();
        if (game)
        {
            game.RegisterAction(ActionRepairVehicleWithBlowtorch)
        }
    }
}