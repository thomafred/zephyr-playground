/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <misc/printk.h>

#include <sensor.h>

void main(void)
{
	struct sensor_value val;
	struct device *si7021;
	int err;

	printk("ZEPHYR Running on board %s\n", CONFIG_BOARD);

	si7021 = device_get_binding(CONFIG_SI7021_DEV_NAME);
	if(!si7021)
	{
		printk("Failed to get device %s\n", CONFIG_SI7021_DEV_NAME);

		return;
	}

	while(1)
	{
		k_sleep(500);

		err = sensor_sample_fetch(si7021);
		if(err)
		{
			printk("Failed to read sensor (err = %d)\n", err);
			continue;
		}

		err = sensor_channel_get(si7021, SENSOR_CHAN_HUMIDITY, &val);
		if(err == 0)
		{
			printk("Humidity: %d.%02d %%\n", val.val1, val.val2);
		}
		else
		{
			printk("Failed to get humidity (err = %d)\n", err);
		}

		err = sensor_channel_get(si7021, SENSOR_CHAN_AMBIENT_TEMP, &val);
		if(err == 0)
		{
			printk("Temperature: %d.%02d C\n", val.val1, val.val2);
		}
		else
		{
			printk("Failed to get temperature (err = %d)\n", err);
		}
	}
}
