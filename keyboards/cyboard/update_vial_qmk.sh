#!/bin/bash

# Create temp directory
TEMP_DIR=$(mktemp -d)

# Clone the vial-qmk repository
echo "Cloning vial-qmk repository..."
git clone https://github.com/Cyboard-DigitalTailor/vial-qmk.git "$TEMP_DIR/vial-qmk"

# Copy cyboard directory from this repo to vial-qmk
echo "Copying cyboard directory..."
cp -r keyboards/cyboard "$TEMP_DIR/vial-qmk/keyboards/"

echo "Done! Vial QMK cloned to: $TEMP_DIR/vial-qmk"
echo "Cyboard directory copied to: $TEMP_DIR/vial-qmk/keyboards/cyboard"