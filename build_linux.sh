#!/bin/bash

# Variables
BUILD_DIR="build"
GENERATOR="Unix Makefiles"

if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
else
fi

cd "$BUILD_DIR"
cmake .. -G "$GENERATOR"
echo "[3/3] Compilation du projet..."
cmake --build .
