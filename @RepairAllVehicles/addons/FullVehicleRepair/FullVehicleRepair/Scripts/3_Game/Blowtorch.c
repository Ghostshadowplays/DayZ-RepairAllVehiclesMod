modded class Blowtorch extends ItemBase
{
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        if (target.GetObject() && target.GetObject().IsInherited(Transport))
        {
            return true; 
        }

        return super.ActionCondition(player, target, item);
    }

    override void OnAction(PlayerBase player, ActionTarget target, ItemBase item)
    {
        super.OnAction(player, target, item);

        Object targetObject = target.GetObject();

        if (targetObject && targetObject.IsInherited(Transport))
        {
            RepairVehicle(EntityAI.Cast(targetObject));
            player.MessageStatus("The vehicle has been fully repaired!");
        }
    }

    void RepairVehicle(EntityAI vehicle)
    {
        Transport transport = Transport.Cast(vehicle);

        if (transport)
        {
            float fuel = this.GetHealth("", ""); 
            if (fuel > 0)
            {
                this.AddHealth("", "", -10); 
            }
            else
            {
                Print("[Blowtorch] Out of fuel!");
                return; 
            }

            array<string> zones = new array<string>();
            transport.GetDamageZones(zones);

            foreach (string zone : zones)
            {
                vehicle.SetHealth(zone, "", vehicle.GetMaxHealth(zone, ""));
            }

            Print("[Blowtorch] Repaired vehicle: " + transport.GetType());
        }
    }
}
