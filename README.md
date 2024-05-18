# FinUI

FinUI is a fork of [MinUI](https://github.com/shauninman/union-minui/). MinUI is
a focused custom launcher for the Anbernic RG35XX. FinUI adds additional features
on top of MinUI.

![FinUI](./github/minui-menu-gbc.png)

## Features

### MinUI features

- Simple launcher, simple SD card
- No settings or configuration
- No boxart, themes, or distractions
- Automatically hides extension
  and region/version cruft in
  display names
- Consistent in-emulator menu with
  quick access to save states, disc
  changing, and emulator options
- Automatically sleeps after 30 seconds
  or press POWER to sleep (and wake)
- Automatically powers off while asleep
  after two minutes or hold POWER for
  one second
- Automatically resumes right where
  you left off if powered off while
  in-game, manually or while asleep
- Resume from manually created, last
  used save state by pressing X in
  the launcher instead of A
- Streamlined emulator frontend
  (minarch + libretro cores)

### Additional FinUI features

- Add to Favorites
- Clear "Recently Played"
- Power saving improvements
- Performance improvements
- Multi-core CPU support
- Battery reading adjustments
- Additional emulators (MAME)
- Base and Extras are merged into one Full release
- Native macOS installation instructions
- Developer experience improvements

## Development

### Prerequisites

- [Docker Desktop](https://docker.com/products/docker-desktop/)

### Build project

Run `./start-toolchain.sh` and then run `make all` in the Docker container shell.

### Debug project

Create a file with the name `enableADB` on the `misc` disk to enable ADB.

### Install release

Update `DISK_PATH` and then run `./install-release.sh`.

## Disclaimer

This software is provided without warranty of any kind. In no event shall the authors
or contributors be liable for any claim, damages, or other liability, arising from,
out of, or in connection with this software, the use of this software, or other
dealings with this software.

Use at your own risk.
