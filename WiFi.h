#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_event.h"
#include "esp_err.h"
#include "esp_interface.h"
#include "esp_wifi.h"
#include "nvs_flash.h"

#define SSID "Smackiya HQ"
#define APSSID "Smackiya HQ"

#define PassWord "12345678"
#define APPassWord "12345678"
#define Max_AP 4
#define AP_Channel 0


void connect_STA() {
	wifi_config_t sta_config = {
			.sta = {
					.ssid = SSID,
					.password = PassWord,
			},
	};
	ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &sta_config));

}



void connect_AP() {

	wifi_config_t ap_config = {

		.ap = {

			.ssid = APSSID,
			.password = APPassWord,
			.max_connection = 4,
			.channel = 0,
			.ssid_hidden = 0,


	},

			 

};
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_AP, &ap_config));
}


void reconnect() {
  printf("Reconnectting ... ... ... ... .... .... ... ");

  ESP_ERROR_CHECK(esp_wifi_connect());
  
}


void scann(){
// configure and run the scan process in blocking mode

  wifi_scan_config_t scan_config = {
    .ssid = 0,
    .bssid = 0,
    .channel = 0,
        .show_hidden = true
    };
  printf("Start scanning...");
  ESP_ERROR_CHECK(esp_wifi_scan_start(&scan_config, true));
  printf(" completed!\n");

  // get the list of APs found in the last scan
  uint16_t ap_num;
  wifi_ap_record_t ap_records[20];
     ESP_ERROR_CHECK(esp_wifi_scan_get_ap_num(&ap_num));
  ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&ap_num, ap_records));

  // print the list
  printf("Found %d access points:\n", ap_num);

  printf("               SSID              | Channel | RSSI |   MAC \n\n");

  for(int i = 0; i < ap_num; i++)
    printf("%32s | %7d | %4d   %2x:%2x:%2x:%2x:%2x:%2x   \n", ap_records[i].ssid, ap_records[i].primary, ap_records[i].rssi , *ap_records[i].bssid, *(ap_records[i].bssid+1), *(ap_records[i].bssid+2), *(ap_records[i].bssid+3), *(ap_records[i].bssid+4), *(ap_records[i].bssid+5));


}
