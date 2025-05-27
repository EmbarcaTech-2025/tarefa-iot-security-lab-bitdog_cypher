#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "include/mqtt_comm.h"
#include "include/wifi_conn.h"
#include "include/xor_cipher.h" 

int main() {
    stdio_init_all();
    sleep_ms(3000); // Aguarda USB serial iniciar

    const char *ssid = "FABIO_WSNET";
    const char *pass = "fabiobarbosa.2016";
    connect_to_wifi(ssid, pass);

    const char *client_id = "bitdog1";
    const char *client_user = "Fabio";
    const char *client_pass = "123";
    const char *broker_ip = "192.168.1.12"; // IP do seu broker local
    mqtt_setup(client_id, broker_ip, client_user, client_pass); 

    const char *mensagem = "26.5";

    uint8_t criptografada[16];
    
    xor_encrypt((uint8_t *)mensagem, criptografada, strlen(mensagem), 42);

    while (1) {

        
        mqtt_comm_publish("escola/sala1/temperatura", (uint8_t *)mensagem, strlen(mensagem));
       // mqtt_comm_publish("escola/sala1/temperatura", criptografada, strlen(mensagem));

        sleep_ms(10000);
    }

    return 0;
}
