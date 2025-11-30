# Thermal Tunning Framework

## Description
Arma Reforger 1.6 introduced a new thermal imaging filter, but it is not fully enabled by default and does not work correctly with many materials and particle systems.

This project activates the thermal system, adjusts its behavior, and provides a complete guide for modders who want to implement or customize thermal effects. It includes practical examples and a clear tutorial on how to configure materials, particles, filters and scripts related to the effect.

Inside the project you will find:
* More than 10 thermal color filters
* 2 example materials
* 1 example particle
* 1 vehicle with thermal enabled
* 1 short range weapon optic with thermal as a demonstration

## Materials and Particles
Some materials, including those used in particle systems, do not work correctly with certain material classes. This will probably be improved by Bohemia in the future, but currently only specific material types support thermal imaging.

Each material may require different setup steps. Use the included example materials to understand how they are configured.

## Thermal Script Overview

The thermal effect is a camera post process applied via:

`BaseWorld.SetCameraPostProcessEffect(cameraId, prioritySlot, PostProcessEffectType.ThermalImaging, resourcePath);`


### Usage

**ADS (2D view)**  
Use the player's current camera ID.

**PiP (Picture in Picture)**  
Use the PiP camera index, the same one used in RenderTargets.

### Important rules
* Use slot 11 for the thermal effect to keep a stable order with other post processing effects  
* To disable the effect, pass `string.Empty` in the same slot  
* The applied resource must be a thermal .emat material  
  Example: `Mod/UI/Materials/ThermalExemple.emat`

### Camera references
**Fullscreen or ADS**
`int camId = world.GetCurrentCameraId();`


**PiP**
Use your PiP camera index:
`m_iCameraIndex`


### Enabling and disabling
**Enable**
`SetCameraPostProcessEffect(..., 11, PostProcessEffectType.ThermalImaging, "<path to .emat>");`


**Disable**
`SetCameraPostProcessEffect(..., 11, PostProcessEffectType.ThermalImaging, string.Empty);`


## Credits
* Bohemia Interactive  
* [@TepacheLoco](https://x.com/TepacheLoco), for the original code that made it possible to study and understand the system
* 3D model of the "Red dot" sight made by me