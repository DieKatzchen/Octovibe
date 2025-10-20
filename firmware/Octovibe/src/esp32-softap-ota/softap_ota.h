#ifndef SOFTAP_OTA_H
#define SOFTAP_OTA_H

#include <string.h>

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>

#ifndef WIFI_SSID
#define WIFI_SSID "ESP32 OTA Update"
#endif

/*
 * Serve OTA update portal (index.html)
 */
extern const uint8_t index_html_start[] asm("_binary_index_html_start");
extern const uint8_t index_html_end[] asm("_binary_index_html_end");

/*
 * HTTP Server
 */
httpd_uri_t index_get = {
	.uri	  = "/",
	.method   = HTTP_GET,
	.handler  = index_get_handler,
	.user_ctx = NULL
};

httpd_uri_t update_post = {
	.uri	  = "/update",
	.method   = HTTP_POST,
	.handler  = update_post_handler,
	.user_ctx = NULL
};


class softap_ota {
  public:
	  void activate_ota();
		void validate_ota();
	private:
	  esp_err_t index_get_handler(httpd_req_t *req);
		esp_err_t update_post_handler(httpd_req_t *req);
		static esp_err_t http_server_init();
	  static esp_err_t softap_init();
}

#endif