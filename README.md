# Netduma Task

The following task involves the following (more details are provided
in the sections below):
 1. writing a minimal C program
 2. writing a package Makefile for it
 3. building the package in the qualcomm sdk ('qsdk')
 4. Write a bash script for the json parser
 5. Sending back an archive with the specified artifacts


1: Write a minimal C program
---------------------------

Write a C program that can parse the included `sample.json` json file 
and can generally be called with a `file` and `field` parameters. For the
specified field, the program would return the json value -- if the
field exists -- else an empty string.

So for example, given a key-value pair in json of
```
"foo": "bar" 
```
stored in `blah.json`, calling the c program like `./myparser
balh.json foo` should print out `bar`.

The program will need to be compiled and packaged to run on an openwrt
system. For json-parsing, the `libjson-c` library can be used (which
should be provided by openwrt by default).


2: Write a package Makefile for it
---------------------------------------------

The mini parser above will need to have a package Makefile such that
it can be built in the build sdk as normal e.g. `make
package/<myparser>/{clean,compile} V=sc -j1`.

The package should be such that it shows up in the `menuconfig`
interface in its own category named `netduma`, where it can be 
selected/unselected.


3: Build the package in the qualcomm sdk 
------------------------------------------

The qualcomm SDK ('qsdk') is an openwrt-based build sdk for Qualcomm
boards. The sdk can be downloaded as explained [here](https://wiki.codelinaro.org/en/clo/qsdk/overview).

 * download the `11.1` version of the `qsdk` and use the following
   configuration for the build:
```
Target System   : Qualcomm Atheros IPQ
Subtargets      : QCA IPQ807x(32bit) based boards, QCA IPQ807x(64bit) based boards
Target Profiles : Default Profile (minimum package set)
```

Notice the subtarget**s**: two builds will need to be done for
platforms with 32 and 64 bitness, respectively.

4. Write a bash script for the json parser
---------------------------------

A bash script is required to use the json parser. Json files 
and search strign could be passed as an arguments to the bash script.
Using bash functions is a requirement.

5: Send back build artifacts
---------------------------------

Once set up properly, build the package in the sdk for the
aforementioned targets and send us:
 - the `.ipk` archive for your package
 - the package Makefile
 - the source code for the C program
 - the bash script

