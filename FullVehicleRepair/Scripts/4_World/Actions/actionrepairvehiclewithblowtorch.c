class ActionRepairVehicleWithBlowtorchCB : ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
        m_ActionComponent = new CAContinuousTime(5.0); // Adjust time as needed
    }
}

class ActionRepairVehicleWithBlowtorch : ActionContinuousBase
{
    void ActionRepairVehicleWithBlowtorch()
    {
        m_CallbackClass = ActionRepairVehicleWithBlowtorchCB;
        m_MessageStart = "You start repairing the vehicle.";
        m_MessageSuccess = "You have repaired the vehicle.";
        m_MessageFail = "You failed to repair the vehicle.";
        m_MessageCancel = "You stopped repairing the vehicle.";
    }

    override void CreateConditionComponents()
    {
        m_ConditionTarget = new CCTNonRuined(2); // Adjust conditions
        m_ConditionItem = new CCINonRuined();
    }

    override string GetText()
    {
        return "Repair Vehicle";
    }

    override void OnStartServer(ActionData action_data)
    {
        Blowtorch blowtorch = Blowtorch.Cast(action_data.m_MainItem);
        EntityAI vehicle = EntityAI.Cast(action_data.m_Target.GetObject());

        if (blowtorch && vehicle)
        {
            blowtorch.RepairVehicle(vehicle);
        }
    }
}
