#!/bin/bash

# Create temp directory
TEMP_DIR=$(mktemp -d)

# Clone the vial-qmk repository
echo "Cloning vial-qmk repository..."
git clone https://github.com/Cyboard-DigitalTailor/vial-qmk.git "$TEMP_DIR/vial-qmk"

# Copy cyboard directory from vial-qmk to this repo
echo "Copying cyboard directory from vial-qmk..."
cp -r "$TEMP_DIR/vial-qmk/keyboards/cyboard" keyboards/

echo "Done! Cyboard directory copied from vial-qmk to local qmk_firmware"
echo "Source: $TEMP_DIR/vial-qmk/keyboards/cyboard"
echo "Destination: keyboards/cyboard"