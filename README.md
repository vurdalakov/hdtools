# hdtools

Simple command line Linux tools to work with HDDs and SSDs.

* [enumdevs](https://github.com/vurdalakov/hdtools#enumdevs) - enumerates block devices
* [devprops](https://github.com/vurdalakov/hdtools#devprops) - enumerates device properties

### enumdevs

Enumerates block devices. Uses `udev` library.

To build:

```
g++ enumdevs.cpp -l udev -o enumdevs
```

Usage:

```
./enumdevs [-p]
```

To enumerate all devices:

```
./enumdevs
```

```
vurdalakov@laptop:/$ ./enumdevs
/dev/sdc=/sys/devices/pci0000:00/0000:00:14.0/usb3/3-1/3-1:1.0/host7/target7:0:0/7:0:0:0/block/sdc
/dev/sdc1=/sys/devices/pci0000:00/0000:00:14.0/usb3/3-1/3-1:1.0/host7/target7:0:0/7:0:0:0/block/sdc/sdc1
/dev/sdb=/sys/devices/pci0000:00/0000:00:1a.0/usb1/1-1/1-1.1/1-1.1:1.0/host6/target6:0:0/6:0:0:0/block/sdb
/dev/sdb1=/sys/devices/pci0000:00/0000:00:1a.0/usb1/1-1/1-1.1/1-1.1:1.0/host6/target6:0:0/6:0:0:0/block/sdb/sdb1
/dev/sdb2=/sys/devices/pci0000:00/0000:00:1a.0/usb1/1-1/1-1.1/1-1.1:1.0/host6/target6:0:0/6:0:0:0/block/sdb/sdb2
/dev/sdb3=/sys/devices/pci0000:00/0000:00:1a.0/usb1/1-1/1-1.1/1-1.1:1.0/host6/target6:0:0/6:0:0:0/block/sdb/sdb3
/dev/sdb4=/sys/devices/pci0000:00/0000:00:1a.0/usb1/1-1/1-1.1/1-1.1:1.0/host6/target6:0:0/6:0:0:0/block/sdb/sdb4
/dev/sdb5=/sys/devices/pci0000:00/0000:00:1a.0/usb1/1-1/1-1.1/1-1.1:1.0/host6/target6:0:0/6:0:0:0/block/sdb/sdb5
/dev/sda=/sys/devices/pci0000:00/0000:00:1f.2/ata1/host0/target0:0:0/0:0:0:0/block/sda
/dev/sda1=/sys/devices/pci0000:00/0000:00:1f.2/ata1/host0/target0:0:0/0:0:0:0/block/sda/sda1
/dev/sda2=/sys/devices/pci0000:00/0000:00:1f.2/ata1/host0/target0:0:0/0:0:0:0/block/sda/sda2
/dev/sda3=/sys/devices/pci0000:00/0000:00:1f.2/ata1/host0/target0:0:0/0:0:0:0/block/sda/sda3
/dev/sda4=/sys/devices/pci0000:00/0000:00:1f.2/ata1/host0/target0:0:0/0:0:0:0/block/sda/sda4
/dev/sda5=/sys/devices/pci0000:00/0000:00:1f.2/ata1/host0/target0:0:0/0:0:0:0/block/sda/sda5
/dev/sda6=/sys/devices/pci0000:00/0000:00:1f.2/ata1/host0/target0:0:0/0:0:0:0/block/sda/sda6
/dev/sda7=/sys/devices/pci0000:00/0000:00:1f.2/ata1/host0/target0:0:0/0:0:0:0/block/sda/sda7
/dev/sr0=/sys/devices/pci0000:00/0000:00:1f.2/ata3/host2/target2:0:0/2:0:0:0/block/sr0
/dev/loop0=/sys/devices/virtual/block/loop0
/dev/loop1=/sys/devices/virtual/block/loop1
/dev/loop2=/sys/devices/virtual/block/loop2
/dev/loop3=/sys/devices/virtual/block/loop3
/dev/loop4=/sys/devices/virtual/block/loop4
/dev/loop5=/sys/devices/virtual/block/loop5
/dev/loop6=/sys/devices/virtual/block/loop6
/dev/loop7=/sys/devices/virtual/block/loop7
/dev/ram0=/sys/devices/virtual/block/ram0
/dev/ram1=/sys/devices/virtual/block/ram1
/dev/ram10=/sys/devices/virtual/block/ram10
/dev/ram11=/sys/devices/virtual/block/ram11
/dev/ram12=/sys/devices/virtual/block/ram12
/dev/ram13=/sys/devices/virtual/block/ram13
/dev/ram14=/sys/devices/virtual/block/ram14
/dev/ram15=/sys/devices/virtual/block/ram15
/dev/ram2=/sys/devices/virtual/block/ram2
/dev/ram3=/sys/devices/virtual/block/ram3
/dev/ram4=/sys/devices/virtual/block/ram4
/dev/ram5=/sys/devices/virtual/block/ram5
/dev/ram6=/sys/devices/virtual/block/ram6
/dev/ram7=/sys/devices/virtual/block/ram7
/dev/ram8=/sys/devices/virtual/block/ram8
/dev/ram9=/sys/devices/virtual/block/ram9
```

To enumerate physical devices:

```
./enumdevs -p
```

```
vurdalakov@laptop:/$ ./enumdevs -p
/dev/sdc=/sys/devices/pci0000:00/0000:00:14.0/usb3/3-1/3-1:1.0/host7/target7:0:0/7:0:0:0/block/sdc
/dev/sdb=/sys/devices/pci0000:00/0000:00:1a.0/usb1/1-1/1-1.1/1-1.1:1.0/host6/target6:0:0/6:0:0:0/block/sdb
/dev/sda=/sys/devices/pci0000:00/0000:00:1f.2/ata1/host0/target0:0:0/0:0:0:0/block/sda
/dev/sr0=/sys/devices/pci0000:00/0000:00:1f.2/ata3/host2/target2:0:0/2:0:0:0/block/sr0
```

### devprops

Enumerates device properties. Uses `udev` library.

To build:

```
g++ devprops.cpp -l udev -o devprops
```

Usage:

```
./devprops <device name or path>
```

```
./devprops sda
./devprops /dev/sda
./devprops /devices/pci0000:00/0000:00:1f.2/ata1/host0/target0:0:0/0:0:0:0/block/sda
./devprops /sys/devices/pci0000:00/0000:00:1f.2/ata1/host0/target0:0:0/0:0:0:0/block/sda
```

##### Example 1: Get all device properties

```
./devprops /dev/sda
```

```
vurdalakov@laptop:/$ ./devprops /dev/sda
DEVLINKS=/dev/disk/by-id/ata-ST1000LM024_HN-M101MBB_S2U4J9AD213740 /dev/disk/by-id/wwn-0x50006cf2095885c7 /dev/disk/by-path/pci-0000:00:1f.2-ata-1
DEVNAME=/dev/sda
DEVPATH=/devices/pci0000:00/0000:00:1f.2/ata1/host0/target0:0:0/0:0:0:0/block/sda
DEVTYPE=disk
ID_ATA=1
ID_ATA_DOWNLOAD_MICROCODE=1
ID_ATA_FEATURE_SET_APM=1
ID_ATA_FEATURE_SET_APM_CURRENT_VALUE=128
ID_ATA_FEATURE_SET_APM_ENABLED=1
ID_ATA_FEATURE_SET_HPA=1
ID_ATA_FEATURE_SET_HPA_ENABLED=1
ID_ATA_FEATURE_SET_PM=1
ID_ATA_FEATURE_SET_PM_ENABLED=1
ID_ATA_FEATURE_SET_SECURITY=1
ID_ATA_FEATURE_SET_SECURITY_ENABLED=0
ID_ATA_FEATURE_SET_SECURITY_ENHANCED_ERASE_UNIT_MIN=206
ID_ATA_FEATURE_SET_SECURITY_ERASE_UNIT_MIN=206
ID_ATA_FEATURE_SET_SECURITY_FROZEN=1
ID_ATA_FEATURE_SET_SMART=1
ID_ATA_FEATURE_SET_SMART_ENABLED=1
ID_ATA_ROTATION_RATE_RPM=5400
ID_ATA_SATA=1
ID_ATA_SATA_SIGNAL_RATE_GEN1=1
ID_ATA_SATA_SIGNAL_RATE_GEN2=1
ID_ATA_WRITE_CACHE=1
ID_ATA_WRITE_CACHE_ENABLED=1
ID_BUS=ata
ID_MODEL=ST1000LM024_HN-M101MBB
ID_MODEL_ENC=ST1000LM024\x20HN-M101MBB\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20
ID_PART_TABLE_TYPE=gpt
ID_PART_TABLE_UUID=595fab90-b7d3-4c08-a018-6d6f2d43fc96
ID_PATH=pci-0000:00:1f.2-ata-1
ID_PATH_TAG=pci-0000_00_1f_2-ata-1
ID_REVISION=2AR10001
ID_SERIAL=ST1000LM024_HN-M101MBB_S2U4J9AD213740
ID_SERIAL_SHORT=S2U4J9AD213740
ID_TYPE=disk
ID_WWN=0x50006cf2095885c7
ID_WWN_WITH_EXTENSION=0x50006cf2095885c7
MAJOR=8
MINOR=0
SUBSYSTEM=block
TAGS=:systemd:
USEC_INITIALIZED=2309270
```

##### Example 2: Get specific device property

For example, serial number (`ID_SERIAL_SHORT`):

```
./devprops /dev/sda | grep ID_SERIAL_SHORT= | awk -F "=" '{print $2}'
```

```
vurdalakov@laptop:/$ ./devprops /dev/sda | grep ID_SERIAL_SHORT= | awk -F "=" '{print $2}'
S2U5J9ED212740
```

### License

Distributed under the terms of the [MIT license](https://opensource.org/licenses/MIT).

### Disclaimer

```
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```
