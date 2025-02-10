#!/bin/bash

# --------------------------------------------
# Ethical HTTP Client Runner (Localhost Only)
# --------------------------------------------

# Safeguard: Only allow localhost testing
TARGET_HOST="127.0.0.1"
TARGET_PORT="8080"  # Test against a local server

# Compile the C++ client
echo "Compiling client.cpp..."
g++ client.cpp -o client || {
  echo "Compilation failed. Ensure g++ is installed."
  exit 1
}

# Warn the user about usage
echo "---------------------------------------------"
echo "           ETHICAL USAGE NOTICE              "
echo "---------------------------------------------"
echo "This script will send 1 HTTP request to:"
echo "Host: $TARGET_HOST | Port: $TARGET_PORT"
echo "Ensure you have a local test server running!"
echo "Example: python3 -m http.server 8080"
echo "---------------------------------------------"

read -p "Do you want to proceed? (y/n): " choice
case "$choice" in
  y|Y)
    echo "Sending request to $TARGET_HOST:$TARGET_PORT..."
    ./client  # Run the compiled client
    ;;
  *)
    echo "Cancelled. No requests sent."
    exit 0
    ;;
esac

# Cleanup
rm -f client
echo "Done."
