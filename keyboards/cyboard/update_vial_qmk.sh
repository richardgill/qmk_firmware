#!/bin/bash

# Create temp directory
TEMP_DIR=$(mktemp -d)

# Clone the vial-qmk repository
echo "Cloning vial-qmk repository..."
git clone https://github.com/Cyboard-DigitalTailor/vial-qmk.git "$TEMP_DIR/vial-qmk"

# Copy root-level cyboard files (excluding directories)
echo "Copying root cyboard files from vial-qmk..."
cp "$TEMP_DIR/vial-qmk/keyboards/cyboard"/*.* keyboards/cyboard/ 2>/dev/null || true

# Copy only imprint_number_row_full_bottom_row from vial-qmk to this repo
echo "Copying imprint_number_row_full_bottom_row from vial-qmk..."
cp -r "$TEMP_DIR/vial-qmk/keyboards/cyboard/imprint/imprint_number_row_full_bottom_row" keyboards/cyboard/imprint/

echo "Done! Files copied from vial-qmk to local qmk_firmware"
echo "- Root cyboard files (*.h, *.c, *.mk, etc.)"
echo "- imprint_number_row_full_bottom_row keyboard variant"
