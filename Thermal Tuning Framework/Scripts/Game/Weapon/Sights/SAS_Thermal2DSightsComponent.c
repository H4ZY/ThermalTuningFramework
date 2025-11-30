// File: SAS_Thermal2DSightsComponent.c
[EntityEditorProps(category: "GameScripted/Weapon/Sights", description: "2D sights with thermal post-process", color: "0 0 255 255")]
class SAS_Thermal2DSightsComponentClass : SCR_2DSightsComponentClass
{
}

//------------------------------------------------------------------------------------------------
class SAS_Thermal2DSightsComponent : SCR_2DSightsComponent
{
	[Attribute("{74E71247FB271851}UI/Materials/Editor/Exemple_Material.emat", UIWidgets.ResourceNamePicker, "Thermal effect resource\n", params: "emat", category: "2DSights")]
	protected ResourceName m_rScopeThermalMaterial;

	//------------------------------------------------------------------------------------------------
	override void OnSightADSActivated()
	{
		super.OnSightADSActivated();

		// World / câmera atual
		BaseWorld world = GetGame().GetWorld();
		if (!world)
			return;

		// Recurso válido?
		if (m_rScopeThermalMaterial == string.Empty)
			return;

		// Aplica Thermal na câmera atual (prioridade 11, como no PiP)
		int camId = world.GetCurrentCameraId();
		world.SetCameraPostProcessEffect(camId, 11, PostProcessEffectType.ThermalImaging, m_rScopeThermalMaterial);
	}

	//------------------------------------------------------------------------------------------------
	override void OnSightADSDeactivated()
	{
		// Limpa o efeito antes do super para garantir tear-down
		BaseWorld world = GetGame().GetWorld();
		if (world)
		{
			int camId = world.GetCurrentCameraId();
			world.SetCameraPostProcessEffect(camId, 11, PostProcessEffectType.ThermalImaging, string.Empty);
		}

		super.OnSightADSDeactivated();
	}
}
