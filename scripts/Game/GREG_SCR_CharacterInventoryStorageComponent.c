/*
	Author: gregfr_3d - Bearcore

	Description:
		Adds an event to SCR_CharacterInventoryStorageComponent to know when stuff are added or removed from the iventory.

	If you have any troubles with this mod or script please contact me on discord : Greg🔥#0431

*/

modded class SCR_CharacterInventoryStorageComponent : CharacterInventoryStorageComponent
{
    private ref ScriptInvoker _onAdded = new ScriptInvoker();
    private ref ScriptInvoker _onRemoved = new ScriptInvoker();
    
    ScriptInvoker GetOnAdded() { return _onAdded; }
    ScriptInvoker GetOnRemoved() { return _onRemoved; }
    
    protected override void OnAddedToSlot(IEntity item, int slotID)
    {
        super.OnAddedToSlot(item, slotID);
        _onAdded.Invoke(item);
    }
  
    protected override void OnRemovedFromSlot(IEntity item, int slotID)
    {
        super.OnAddedToSlot(item, slotID);
        _onRemoved.Invoke(item);
    }
}