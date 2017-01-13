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

int main(int argc, char *argv[])
{
    if ((argc != 2) || (0 == strcmp(argv[1], "--help")))
    {
        printf("Usage:\n");
        printf("./devprops <device name>\n");
        printf("Examples:\n");
        printf("./devprops /dev/sda\n");
        printf("./devprops sda\n");
        return 1;
    }
    
    const char* deviceName = argv[1];

	const char* slash = strrchr(deviceName, '/');
	const char* systemName = NULL == slash ? deviceName : (slash + 1);
    
    struct udev* udev = udev_new();
    if (!udev)
    {
        printf("udev_new() failed\n");
        return 2;
    }
    
    int result = 0;

	struct udev_device* device = udev_device_new_from_subsystem_sysname(udev, "block", systemName);
	if (!device)
	{
		printf("udev_device_new_from_syspath() failed on '%s'\n", systemName);
		result = 3;
	}
    else
    {
        struct udev_list_entry* propListEntry = udev_device_get_properties_list_entry(device);
        if (!propListEntry)
        {
            printf("udev_device_get_properties_list_entry() failed\n");
            result = 4;
        }
        else
        {
            struct udev_list_entry* it = propListEntry;
            while (it != NULL)
            {
                printf("%s=%s\n", udev_list_entry_get_name(it), udev_list_entry_get_value(it));
                it = udev_list_entry_get_next(it);
            }
        }

        udev_device_unref(device);
    }

	udev_unref(udev);

    return result;
}
