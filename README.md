# STM32_GNSS
GNSS library for STM32. Parses GNGGA message received via UART.

## Usage:
```
#include "GNSS.h"

...

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	GNSS_callback(&huart1);//pointer to UART
}

...

GNSS_Init(&huart1);

...

while (1){
 //no need to modify main loop
}

```

Access received data by
```
GNSS.GNGGA.x
```

 I hope this will be helpful to your project!
