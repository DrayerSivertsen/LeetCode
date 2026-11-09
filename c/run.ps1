
$ErrorActionPreference = "Stop"

# Compile
gcc -Wall -Wextra -g -o linked_list.exe linked_list.c

# Stop if compilation fails
if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

# Run the executable
.\linked_list.exe
