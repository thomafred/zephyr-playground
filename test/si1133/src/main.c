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
	struct device *si1133;

	printk("ZEPHYR Running on board %s\n", CONFIG_BOARD);

	si1133 = device_get_binding(CONFIG_SI1133_DEV_NAME);
	if(!si1133)
	{
		printk("Failed to get device %s\n", CONFIG_SI1133_DEV_NAME);

		return;
	}

	while(1)
	{
		sensor_sample_fetch(si1133);

		k_sleep(1000);
	}
}
