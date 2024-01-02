#!/bin/bash

# make all rgbmatrix first
make fingerpunch/ffkb_byomcu/rgbmatrix_evq:vial
make fingerpunch/ffkb_byomcu/rgbmatrix_pimoroni_evq:vial
make fingerpunch/ffkb_byomcu/rgbmatrix_pimoroni_ec11:vial
make fingerpunch/ffkb_byomcu/rgbmatrix_oled:vial
make fingerpunch/ffkb_byomcu/rgbmatrix:vial
make fingerpunch/ffkb_byomcu/rgbmatrix_ec11:vial
make fingerpunch/ffkb_byomcu/rgbmatrix_oled_ec11:vial
make fingerpunch/ffkb_byomcu/rgbmatrix_pimoroni:vial
make fingerpunch/ffkb_byomcu/rgbmatrix_oled_evq:vial

# sub out the rgbmatrix config so that vial gui works, see IMPORTANT in readme.md for details
cp keyboards/fingerpunch/ffkb_byomcu/keymaps/vial/vial.json keyboards/fingerpunch/ffkb_byomcu/keymaps/vial/vial.json.bak
cp keyboards/fingerpunch/ffkb_byomcu/keymaps/vial/vial.nonrgbmatrix.json keyboards/fingerpunch/ffkb_byomcu/keymaps/vial/vial.json

make fingerpunch/ffkb_byomcu/rgblight_evq:vial
make fingerpunch/ffkb_byomcu/ec11:vial
make fingerpunch/ffkb_byomcu/pimoroni_evq:vial
make fingerpunch/ffkb_byomcu/oled:vial
make fingerpunch/ffkb_byomcu/rgblight_pimoroni_evq:vial
make fingerpunch/ffkb_byomcu/rgblight_oled_evq:vial
make fingerpunch/ffkb_byomcu/pimoroni:vial
make fingerpunch/ffkb_byomcu/evq:vial
make fingerpunch/ffkb_byomcu/rgblight_ec11:vial
make fingerpunch/ffkb_byomcu/rgblight_pimoroni_ec11:vial
make fingerpunch/ffkb_byomcu/rgblight_oled:vial
make fingerpunch/ffkb_byomcu/oled_ec11:vial
make fingerpunch/ffkb_byomcu/rgbmatrix_ec11_evq:vial
make fingerpunch/ffkb_byomcu/rgblight:vial
make fingerpunch/ffkb_byomcu/no_features:vial
make fingerpunch/ffkb_byomcu/pimoroni_ec11:vial
make fingerpunch/ffkb_byomcu/rgblight_pimoroni:vial
make fingerpunch/ffkb_byomcu/rgblight_ec11_evq:vial
make fingerpunch/ffkb_byomcu/oled_evq:vial
make fingerpunch/ffkb_byomcu/ec11_evq:vial
make fingerpunch/ffkb_byomcu/rgblight_oled_ec11:vial

# put the original file back
cp keyboards/fingerpunch/ffkb_byomcu/keymaps/vial/vial.json.bak keyboards/fingerpunch/ffkb_byomcu/keymaps/vial/vial.json
rm keyboards/fingerpunch/ffkb_byomcu/keymaps/vial/vial.json.bak

cp fingerpunch_ffkb_byomcu_*_vial.hex /mnt/g/My\ Drive/qmk-keyboards/ffkb_byomcu/vial/
