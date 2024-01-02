#!/bin/bash

rsync -av --exclude '*vial*' ../qmk_firmware/keyboards/fingerpunch/ keyboards/fingerpunch/
rsync -av --exclude '*vial*' ../qmk_firmware/users/sadekbaroudi/ users/sadekbaroudi/
rsync -av --exclude '*vial*' ../qmk_firmware/bin/fp_build.sh bin/fp_build.sh

# keep this list updated as vial support is added for these boards
rm -rf keyboards/fingerpunch/arachnophobe/
rm -rf keyboards/fingerpunch/bgkeeb/
rm -rf keyboards/fingerpunch/bigbarobord/
rm -rf keyboards/fingerpunch/euclid36/
rm -rf keyboards/fingerpunch/euclid36proto/
rm -rf keyboards/fingerpunch/dweeeeep/
rm -rf keyboards/fingerpunch/ffkb/byomcu/v3/kle-via.json
rm -rf keyboards/fingerpunch/ffkb/rp/
rm -rf keyboards/fingerpunch/fpm101/
rm -rf keyboards/fingerpunch/kucheza/
rm -rf keyboards/fingerpunch/luakeeb/
rm -rf keyboards/fingerpunch/pinkiesout/v2_ext/
rm -rf keyboards/fingerpunch/stemcell_jumper_tester/
rm -rf keyboards/fingerpunch/personal/
rm -rf keyboards/fingerpunch/svlinky/
rm -rf keyboards/fingerpunch/vulpes_majora/
rm -rf keyboards/fingerpunch/vulpes_minora/
rm -rf keyboards/fingerpunch/xivik/

