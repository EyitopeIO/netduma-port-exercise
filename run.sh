#!/bin/sh

# Today :   23rd July 2022


FILE_NAME=nnn
JSON_SKEY=nnn

while [[ "$#" -gt 0 ]]; do
    case $1 in

        --file)
        SETUP_EMMC=1
        FILE_NAME=$2
        shift 2
        ;;

        --key)
        UPDATE_ALL_PACKAGES=1
        JSON_SKEY=$2
        shift 2
        ;;

        *)
        echo "Unknown option"
        exit 1
    esac
done

if ! [ -e $FILE_NAME ]; then
    echo "File not found"
    exit 1

else
    cp $FILE_NAME $JSON_SKEY && exit 0 || exit 1

fi
