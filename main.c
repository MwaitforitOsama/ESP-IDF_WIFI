#include "WiFi.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_event_loop.h"
#include "esp_wifi.h"
#include "nvs_flash.h"
#include "tcpip_adapter.h"

#define portTick_RATE_MS 1


void app_main()
{
 tcpip_adapter_init();
  // initialize NVS
  ESP_ERROR_CHECK(nvs_flash_init());
  


  wifi_init_config_t wifi_config = WIFI_INIT_CONFIG_DEFAULT();
  ESP_ERROR_CHECK(esp_wifi_init(&wifi_config));
  ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_APSTA));// starts wifi usage
  

  
      while(1) {  vTaskDelay(3000 / portTICK_RATE_MS);
      	  scann();
      	  connect_AP();
      	  connect_STA();
          reconnect();

      }
  }
