<img src="https://github.com/GTAmodding/re3/blob/master/logo.png?raw=true" alt="re3 logo" width="200">

re3-vita is a port of [re3](https://github.com/GTAmodding/re3), a full reverse engineered reimplementation of Grand Theft Auto III using librw, a full and open source reimplementation of RenderWare graphics engine.  
re3-vita allows to play Grand Theft Auto III on PS Vita/PSTV after providing game files from your own copy of the game (if you don't have a physical copy of GTA III for PC, you can buy the game on Steam (https://store.steampowered.com/app/12100/Grand_Theft_Auto_III/).

## Downloads

Check [releases](https://github.com/TheOfficialFloW/re3/releases).

## Installation

A comprehensive tutorial, wrote by Samilop Cimmerian Iter, on how to install re3-vita can be found here:
https://samilops2.gitbook.io/vita-troubleshooting-guide/grand-theft-auto/gta-iii.

## Build instructions

1. Install [vitasdk](https://vitasdk.org/).
2. Install [vitaGL](https://github.com/Rinnegatamante/vitaGL) using `make NO_DEBUG=1 PHYCONT_ON_DEMAND=1 install`.
3. Install [librw-vita](https://github.com/Rinnegatamante/librw) using `make install`.
4. Compile re3-vita using `make`.

## Credits

- The re3 team for the incredible work done with the reverse engineering of the game.
- aap, author of re3 that gave us a huge hand improving, fixing and optimizing this port.
- AGraber for the Switch port of re3 used as original base for the port and for his Batch script used to convert audio files into uncompressed wavs easily.
- Freakler for the awesome Livearea assets
- Samilop Cimmerian Iter for the installation tutorial and extensively testing the port.

## Original README

[![Build Status](https://img.shields.io/endpoint.svg?url=https%3A%2F%2Factions-badge.atrox.dev%2FGTAmodding%2Fre3%2Fbadge%3Fref%3Dmaster&style=flat)](https://actions-badge.atrox.dev/GTAmodding/re3/goto?ref=master)
<a href="https://discord.gg/RFNbjsUMGg"><img src="https://img.shields.io/badge/discord-join-7289DA.svg?logo=discord&longCache=true&style=flat" /></a>

## Intro

The aim of this project is to reverse GTA III for PC by replacing
parts of the game [one by one](https://en.wikipedia.org/wiki/Ship_of_Theseus)
such that we have a working game at all times.

## How can I try it?
It has been tested and works on Windows, Linux, MacOS and FreeBSD, on x86, amd64, arm and arm64.\
Rendering is handled either by original RenderWare (D3D8)
or the reimplementation [librw](https://github.com/aap/librw) (D3D9, OpenGL 2.1 or above, OpenGL ES 2.0 or above).\
Audio is done with MSS (using dlls from original GTA) or OpenAL.

- re3 requires game assets to work, so you **must** own [a copy of GTA III](https://store.steampowered.com/app/12100/Grand_Theft_Auto_III/).
- Build re3 or download [the latest nightly build](https://github.com/GTAmodding/re3/actions) (You must be logged in.)
- (Optional) If you want to use optional features like Russian language or menu map, copy the files in /gamefiles folder to your game root folder.
- Move re3.exe to GTA 3 directory and run it.

## Latest standalone executables to download 

(Put content of selected archive into gamedir)

- re3 requires PC game assets to work, so you **must** own [a copy of GTA III](https://store.steampowered.com/app/12100/Grand_Theft_Auto_III/).
- Build re3 or download the latest build:
  - [Windows D3D9 MSS 32bit](https://nightly.link/GTAmodding/re3/workflows/re3_msvc_x86/master/re3_Release_win-x86-librw_d3d9-mss.zip)
  - [Windows D3D9 64bit](https://nightly.link/GTAmodding/re3/workflows/re3_msvc_amd64/master/re3_Release_win-amd64-librw_d3d9-oal.zip)
  - [Windows OpenGL 64bit](https://nightly.link/GTAmodding/re3/workflows/re3_msvc_amd64/master/re3_Release_win-amd64-librw_gl3_glfw-oal.zip)
  - [Linux 64bit](https://nightly.link/GTAmodding/re3/workflows/build-cmake-conan/master/ubuntu-18.04-gl3.zip)
  - [MacOS 64bit x86-64](https://nightly.link/GTAmodding/re3/workflows/build-cmake-conan/master/macos-latest-gl3.zip)
- Extract the downloaded zip over your GTA 3 directory and run re3. The zip includes the binary, updated and additional gamefiles and in case of OpenAL the required dlls.

## Screenshots

![re3 2021-02-11 22-57-03-23](https://user-images.githubusercontent.com/1521437/107704085-fbdabd00-6cbc-11eb-8406-8951a80ccb16.png)
![re3 2021-02-11 22-43-44-98](https://user-images.githubusercontent.com/1521437/107703339-cbdeea00-6cbb-11eb-8f0b-07daa105d470.png)
![re3 2021-02-11 22-46-33-76](https://user-images.githubusercontent.com/1521437/107703343-cd101700-6cbb-11eb-9ccd-012cb90524b7.png)
![re3 2021-02-11 22-50-29-54](https://user-images.githubusercontent.com/1521437/107703348-d00b0780-6cbb-11eb-8afd-054249c2b95e.png)

## Improvements

We have implemented a number of changes and improvements to the original game.
They can be configured in `core/config.h`.
Some of them can be toggled at runtime, some cannot.

* Fixed a lot of smaller and bigger bugs
* User files (saves and settings) stored in GTA root directory
* Settings stored in re3.ini file instead of gta3.set
* Debug menu to do and change various things (Ctrl-M to open)
* Debug camera (Ctrl-B to toggle)
* Rotatable camera
* XInput controller support (Windows)
* No loading screens between islands ("map memory usage" in menu)
* Skinned ped support (models from Xbox or Mobile)
* Rendering
  * Widescreen support (properly scaled HUD, Menu and FOV)
  * PS2 MatFX (vehicle reflections)
  * PS2 alpha test (better rendering of transparency)
  * PS2 particles
  * Xbox vehicle rendering
  * Xbox world lightmap rendering (needs Xbox map)
  * Xbox ped rim light
  * Xbox screen rain droplets
  * More customizable colourfilter
* Menu
  * Map
  * More options
  * Controller configuration menu
  * ...
* Can load DFFs and TXDs from other platforms, possibly with a performance penalty
* ...

## To-Do

The following things would be nice to have/do:

* Fix physics for high FPS
* Improve performance on lower end devices, especially the OpenGL layer on the Raspberry Pi (if you have experience with this, please get in touch)
* Compare code with PS2 code (tedious, no good decompiler)
* [PS2 port](https://github.com/GTAmodding/re3/wiki/PS2-port)
* Xbox port (not quite as important)
* reverse remaining unused/debug functions
* compare CodeWarrior build with original binary for more accurate code (very tedious)

## Modding

Asset modifications (models, texture, handling, script, ...) should work the same way as with original GTA for the most part.

Mods that make changes to the code (dll/asi, CLEO, limit adjusters) will *not* work.
Some things these mods do are already implemented in re3 (much of SkyGFX, GInput, SilentPatch, Widescreen fix),
others can easily be achieved (increasing limis, see `config.h`),
others will simply have to be rewritten and integrated into the code directly.
Sorry for the inconvenience.

## Building from Source  

If you gonna use premake, then before starting you may want to point GTA_III_RE_DIR environment variable to GTA3 root folder, if you want executable to be moved there via post-build script.

<details><summary>Linux Premake</summary>

For Linux using premake, proceed: [Building on Linux](https://github.com/GTAmodding/re3/wiki/Building-on-Linux)

</details>

<details><summary>Linux Conan</summary>

Obtain source code.
```
git clone https://github.com/GTAmodding/re3.git
cd re3
git submodule init
git submodule update --recursive
```
Install python and conan, and then run build.
```
conan export vendor/librw librw/master@
mkdir build
cd build
conan install .. re3/master@ -if build -o re3:audio=openal -o librw:platform=gl3 -o librw:gl3_gfxlib=glfw --build missing -s re3:build_type=RelWithDebInfo -s librw:build_type=RelWithDebInfo
conan build .. -if build -bf build -pf package
```
</details>

<details><summary>MacOS Premake</summary>

For MacOS using premake, proceed: [Building on MacOS](https://github.com/GTAmodding/re3/wiki/Building-on-MacOS)

</details>

<details><summary>FreeBSD</summary>

For FreeBSD using premake, proceed: [Building on FreeBSD](https://github.com/GTAmodding/re3/wiki/Building-on-FreeBSD)

</details>

<details><summary>Windows</summary>

Assuming you have Visual Studio:
- Clone the repo using the argument `--recursive`.
- Run one of the `premake-vsXXXX.cmd` variants on root folder.
- Open the project via Visual Studio  
    
**If you use 64-bit D3D9**: We don't ship 64-bit Dx9 SDK. You need to download it from Microsoft if you don't have it(although it should come pre-installed after some Windows version)  

**If you choose OpenAL on Windows** You must read [Running OpenAL build on Windows](https://github.com/GTAmodding/re3/wiki/Running-OpenAL-build-on-Windows).
</details>

> :information_source: There are various settings at the very bottom of [config.h](https://github.com/GTAmodding/re3/tree/master/src/core/config.h), you may want to take a look there. i.e. FIX_BUGS define fixes the bugs we've come across.

> :information_source: **Did you notice librw?** re3 uses completely homebrew RenderWare-replacement rendering engine; [librw](https://github.com/aap/librw/). librw comes as submodule of re3, but you also can use LIBRW enviorenment variable to specify path to your own librw.

## Contributing
Please read the [Coding Style](https://github.com/GTAmodding/re3/blob/master/CODING_STYLE.md) Document

### Unreversed / incomplete classes (at least the ones we know)
The following classes have only unused or practically unused code left:
```
NameGrid.cpp - only on mobile (a player name grid, either a very early player name code ala GTA1 or a multiplayer leftover)
PedDebug.cpp - only on mobile (debug code)
HandlingMgr.cpp - debug functions from mobile
CFormationInfo - unused PedAI class that could be found on mobile
CVehicle::ProcessBikeWheel - early bike code (only on mobile)
CAutomobile::DebugCode - debug function from mobile
CBoat::DebugCode - debug function from mobile
CBoat::ModifyHandlingValue - debug function from mobile
CBoat::DisplayHandlingData - debug function from mobile
CStreaming::PrintRequestList - debug function from mobile
d3d8raster.c - only on PC (slight RW modification that we don't actually need)
```

