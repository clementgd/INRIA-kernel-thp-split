#!/bin/bash

function pause(){
    read -s -n 1 -p "Kernel will be updated via kexec, press any key to continue..."
    echo ""
}

source build.sh
pause
source deploy.sh
