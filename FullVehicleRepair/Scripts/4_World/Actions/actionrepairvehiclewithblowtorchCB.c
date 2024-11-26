class ActionRepairVehicleWithBlowtorchCB : ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
        m_ActionData.m_ActionComponent = new CAContinuousTime(10);
    }
};
