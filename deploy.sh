#!/bin/bash

vmlinuz_file=/boot/$(ls -t /boot | grep vmlinuz | head -1)
initrd_file=/boot/$(ls -t /boot | grep initrd.img | head -1)
echo "Loading kexec with vmlinuz : $vmlinuz_file and initrd : $initrd_file"
kexec -d -l $vmlinuz_file --initrd=$initrd_file --append=$(cat /proc/cmdline)

echo "Running kexec in 3 seconds ..."
sleep 3
echo "Running kexec"
kexec -e