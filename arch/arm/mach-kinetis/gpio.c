/*
 * (C) Copyright 2011, 2012
 * Linh Nguyen <nvl1109@gmail.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <linux/types.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/io.h>

#include <asm/clkdev.h>

#include <mach/platform.h>
#include <mach/clock.h>
#include <mach/kinetis.h>
#include <mach/power.h>
#include <mach/gpio.h>


void __init kinetis_gpio_init(void)
{
	KINETIS_SIM->scgc[csgc5] |= 0x00 | CYGHWR_HAL_KINETIS_SIM_SCGC5_ALL_M;

#if CONFIG_KINETIS_LEDS_ENABLE
	// Config as output
	GPIOA_PDDR |= 0x00 | (1 << K70_LED0_IDX) | (1 << K70_LED1_IDX) | (1 << K70_LED2_IDX) | (1 << K70_LED3_IDX);
	// Clear all leds
	GPIOA_PCOR |= 0x00 | (1 << K70_LED0_IDX) | (1 << K70_LED1_IDX) | (1 << K70_LED2_IDX) | (1 << K70_LED3_IDX);
#endif /*CONFIG_KINETIS_LEDS_ENABLE*/
	
	return;
}

