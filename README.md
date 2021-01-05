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
2. Install [vitaGL](https://github.com/Rinnegatamante/vitaGL) using `make HAVE_SBRK=1 HAVE_SHARK=1 install`.
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
<a href="https://discord.gg/aKYAwCx92H"><img src="https://img.shields.io/badge/discord-join-7289DA.svg?logo=discord&longCache=true&style=flat" /></a>

## Intro

The aim of this project is to reverse GTA III for PC by replacing
parts of the game [one by one](https://en.wikipedia.org/wiki/Ship_of_Theseus)
such that we have a working game at all times.

## How can I try it?

- re3 requires game assets to work, so you **must** own [a copy of GTA III](https://store.steampowered.com/app/12100/Grand_Theft_Auto_III/).
- Build re3 or download it from one of the above links (Debug or Release).
- (Optional) If you want to use optional features like Russian language or menu map, copy the files in /gamefiles folder to your game root folder.
- Move re3.exe to GTA 3 directory and run it.

## Preparing the environment for building

You may want to point GTA_III_RE_DIR environment variable to GTA3 root folder if you want executable to be moved there via post-build script.

- For Linux, proceed: [Building on Linux](https://github.com/GTAmodding/re3/wiki/Building-on-Linux)
- For FreeBSD, proceed: [Building on FreeBSD](https://github.com/GTAmodding/re3/wiki/Building-on-FreeBSD) 
- For Windows, assuming you have Visual Studio:
    - Clone the repo using the argument `--recursive`.
    - Run one of the `premake-vsXXXX.cmd` variants on root folder.
    - Open the project via Visual Studio  
    
**If you use 64-bit D3D9**: We don't ship 64-bit Dx9 SDK. You need to download it from Microsoft if you don't have it(although it should come pre-installed after some Windows version)  

There are various settings at the very bottom of [config.h](https://github.com/GTAmodding/re3/tree/master/src/core/config.h), you may want to take a look there. i.e. FIX_BUGS define fixes the bugs we've come across.

> :information_source: **If you choose OpenAL on Windows** You must read [Running OpenAL build on Windows](https://github.com/GTAmodding/re3/wiki/Running-OpenAL-build-on-Windows).

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

