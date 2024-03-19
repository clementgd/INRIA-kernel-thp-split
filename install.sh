#!/bin/bash

function pause(){
    read -s -n 1 -p "Kernel will be updated via kexec, press any key to continue..."
    echo ""
}

if ! [ -f .config ]; then
    copied_config_file_path=$(find /boot -maxdepth 1 -name "config*" | head -1)
    echo Copied config file : $copied_config_file_path
    cp $copied_config_file_path .config
fi

linux_make_start="$(date -u +%s)"
make olddefconfig
echo "Compiling the kernel"
make -j $(nproc)
INSTALL_MOD_STRIP=1 make modules_install -j $(nproc) && make install
linux_make_end="$(date -u +%s)"
linux_make_time_seconds="$(($linux_make_end-$linux_make_start))"

vmlinuz_file=/boot/$(ls -t /boot | grep vmlinuz | head -1)
initrd_file=/boot/$(ls -t /boot | grep initrd.img | head -1)

echo "Compiled linux in $linux_make_time_seconds seconds\n"
echo "vmlinuz : $vmlinuz_file, initrd : $initrd_file"

pause

echo "Loading kexec with vmlinuz : $vmlinuz_file and initrd : $initrd_file"
kexec -d -l $vmlinuz_file --initrd=$initrd_file --append=$(cat /proc/cmdline)

echo "Running kexec in 3 seconds ..."
sleep 3
echo "Running kexec"
kexec -e