#include "ets_sys.h"
#include "osapi.h"
#include "gpio.h"
#include "os_type.h"

#define PIN 5u

static os_timer_t timer;

static void toggle_pin(void)
{
    if (GPIO_REG_READ(GPIO_OUT_ADDRESS) & (1 << PIN))
        gpio_output_set(0, (1 << PIN), 0, 0);
    else
        gpio_output_set((1 << PIN), 0, 0, 0);
}

void user_init(void)
{
    gpio_init();
    /* PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDO_U, FUNC_GPIO5); */
    gpio_output_set(0, 0, (1 << PIN), 0);
    gpio_output_set(0, (1 << 2), (1 << 2), 0);
    os_timer_setfn(&timer, toggle_pin, 0);
    os_timer_arm(&timer, 200, 1);
}
