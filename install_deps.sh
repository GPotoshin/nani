#!/bin/bash

# Set the repository URL and directory name
REPO_URL="https://github.com/GPotoshin/slog.git"
DIR_NAME="deps/slog"

# Check if the directory exists
if [ -d "$DIR_NAME" ]; then
  # If the directory exists, change into it and fetch the latest changes
  cd "$DIR_NAME"
  git fetch
else
  # If the directory does not exist, clone the repository
  git clone "$REPO_URL" "$DIR_NAME"
fi
