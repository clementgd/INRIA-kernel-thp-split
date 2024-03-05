#!/bin/bash

copied_config_file_path=$(find /boot -maxdepth 1 -name "config*" | head -1)
echo Copied config file : $copied_config_file_path
cp $copied_config_file_path .config