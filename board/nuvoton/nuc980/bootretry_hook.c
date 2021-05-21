#include <common.h>
#include <asm-generic/gpio.h>
#include "../../../drivers/gpio/nuc980_gpio.h"

#define LD1_PIN             GPIO_PD15
#define LD1_ACTICE_LOGIC    1

static uchar init_ok = 0;
static unsigned long ts = 0;

static void LD1_Init(void)
{
    if(init_ok)
        return;
    
    gpio_request(LD1_PIN, 0);
	gpio_direction_output(LD1_PIN, !LD1_ACTICE_LOGIC);
    ts = get_timer(0);

    init_ok = 1;
}

void bootretry_hook(void)
{
    LD1_Init();

    if(get_timer(ts) > 50)
    {
        gpio_set_value(LD1_PIN, !gpio_get_value(LD1_PIN));
        ts = get_timer(0);
    }
}
