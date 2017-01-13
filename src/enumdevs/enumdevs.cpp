/*
This file is part of hdtools project.
https://github.com/vurdalakov/hdtools

Copyright (c) 2016 Vurdalakov
email: vurdalakov@gmail.com

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#include <stdio.h>
#include <string.h>
#include <libudev.h>

int main (int argc, char *argv[])
{
    bool physicalOnly = ((2 == argc) && (0 == strcmp(argv[1], "-p")));
    if ((argc != 1) && !physicalOnly)
    {
        printf("Usage:\n");
        printf("./enumdevs [-p]\n");
        printf("Examples:\n");
        printf("./enumdevs\n");
        printf("./enumdevs -p\n");
        return 1;
    }

	struct udev* udev = udev_new();
	if (!udev)
    {
	    printf("udev_new() failed\n");
        return 1;
	}
	
	struct udev_enumerate* enumerate = udev_enumerate_new(udev);
	udev_enumerate_add_match_subsystem(enumerate, "block");
    udev_enumerate_scan_devices(enumerate);
    
	struct udev_list_entry* devices = udev_enumerate_get_list_entry(enumerate);

    struct udev_list_entry* dev_list_entry;
	udev_list_entry_foreach(dev_list_entry, devices)
    {
		const char* systemPath = udev_list_entry_get_name(dev_list_entry);
        
		struct udev_device* device = udev_device_new_from_syspath(udev, systemPath);
        
        if (physicalOnly)
        {
            struct udev_list_entry* udev_list_entry = udev_device_get_properties_list_entry(device);
            if (!udev_list_entry)
            {
                printf("udev_device_get_properties_list_entry() failed\n");
                continue;
            }
            else
            {
            	struct udev_list_entry* dev_list_entry = udev_list_entry_get_by_name(udev_list_entry, "DEVTYPE");

                if (!dev_list_entry)
                {
                    printf("udev_list_entry_get_by_name(DEVTYPE) failed\n");
                    continue;
                }

                if (strcmp(udev_list_entry_get_value(dev_list_entry), "disk") != 0)
                {
                    continue;
                } 

            	dev_list_entry = udev_list_entry_get_by_name(udev_list_entry, "DEVPATH");

                if (!dev_list_entry)
                {
                    printf("udev_list_entry_get_by_name(DEVPATH) failed\n");
                    continue;
                }

                if (strstr(udev_list_entry_get_value(dev_list_entry), "/virtual/") != 0)
                {
                    continue;
                } 
            }
        }

        const char* devicePath = udev_device_get_devnode(device);

		printf("%s=%s\n", devicePath, systemPath);

		udev_device_unref(device);
	}

	udev_enumerate_unref(enumerate);

	udev_unref(udev);

	return 0;       
}
