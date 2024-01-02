#!/bin/bash

# make all rgbmatrix first
make fingerpunch/ffkb/rgbmatrix_evq:vial
make fingerpunch/ffkb/rgbmatrix_pimoroni_evq:vial
make fingerpunch/ffkb/rgbmatrix_pimoroni_ec11:vial
make fingerpunch/ffkb/rgbmatrix_oled:vial
make fingerpunch/ffkb/rgbmatrix:vial
make fingerpunch/ffkb/rgbmatrix_ec11:vial
make fingerpunch/ffkb/rgbmatrix_oled_ec11:vial
make fingerpunch/ffkb/rgbmatrix_pimoroni:vial
make fingerpunch/ffkb/rgbmatrix_oled_evq:vial

# sub out the rgbmatrix config so that vial gui works, see IMPORTANT in readme.md for details
cp keyboards/fingerpunch/ffkb/keymaps/vial/vial.json keyboards/fingerpunch/ffkb/keymaps/vial/vial.json.bak
cp keyboards/fingerpunch/ffkb/keymaps/vial/vial.nonrgbmatrix.json keyboards/fingerpunch/ffkb/keymaps/vial/vial.json

make fingerpunch/ffkb/rgblight_evq:vial
make fingerpunch/ffkb/ec11:vial
make fingerpunch/ffkb/pimoroni_evq:vial
make fingerpunch/ffkb/oled:vial
make fingerpunch/ffkb/rgblight_pimoroni_evq:vial
make fingerpunch/ffkb/rgblight_oled_evq:vial
make fingerpunch/ffkb/pimoroni:vial
make fingerpunch/ffkb/evq:vial
make fingerpunch/ffkb/rgblight_ec11:vial
make fingerpunch/ffkb/rgblight_pimoroni_ec11:vial
make fingerpunch/ffkb/rgblight_oled:vial
make fingerpunch/ffkb/oled_ec11:vial
make fingerpunch/ffkb/rgbmatrix_ec11_evq:vial
make fingerpunch/ffkb/rgblight:vial
make fingerpunch/ffkb/no_features:vial
make fingerpunch/ffkb/pimoroni_ec11:vial
make fingerpunch/ffkb/rgblight_pimoroni:vial
make fingerpunch/ffkb/rgblight_ec11_evq:vial
make fingerpunch/ffkb/oled_evq:vial
make fingerpunch/ffkb/ec11_evq:vial
make fingerpunch/ffkb/rgblight_oled_ec11:vial

# put the original file back
cp keyboards/fingerpunch/ffkb/keymaps/vial/vial.json.bak keyboards/fingerpunch/ffkb/keymaps/vial/vial.json
rm keyboards/fingerpunch/ffkb/keymaps/vial/vial.json.bak

cp fingerpunch_ffkb_*_vial.hex /mnt/g/My\ Drive/qmk-keyboards/ffkb/vial/
rm -rf /mnt/g/My\ Drive/qmk-keyboards/ffkb/vial/fingerpunch_ffkb_byomcu_*_vial.hex
