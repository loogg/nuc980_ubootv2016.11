#include <common.h>
#include <asm-generic/gpio.h>
#include "../../../drivers/gpio/nuc980_gpio.h"

#define RESET_PIN			GPIO_PE12
#define RESET_ACTIVE_LOGIC	1

void phy_hw_reset(void)
{
    /* init phy reset gpio */
	gpio_request(RESET_PIN, 0);
	gpio_direction_output(RESET_PIN, !RESET_ACTIVE_LOGIC);
	mdelay(10);

	/* reset phy */
	gpio_set_value(RESET_PIN, RESET_ACTIVE_LOGIC);
	mdelay(50);
	gpio_set_value(RESET_PIN, !RESET_ACTIVE_LOGIC);
	mdelay(1000);
}
