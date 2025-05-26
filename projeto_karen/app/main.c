#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "wifi_conn.h"
#include "mqtt_comm.h"

int main() {
    const char *ssid = "AP-ACCESS BLH";
    const char *password = "Fin@ApointBlH";
    const char *client_id = "bitdog1";
    const char *broker_ip = "172.19.8.126";  // ajuste conforme IP do seu PC
    const char *username = "aluno";
    const char *pass = "senha123";

    connect_to_wifi(ssid, password);
    sleep_ms(3000); // tempo para conectar

    mqtt_setup(client_id, broker_ip, username, pass);
    sleep_ms(3000); // tempo para conectar ao MQTT

    const char *msg = "teste";
    mqtt_comm_publish("debug/karen", (const uint8_t *)msg, strlen(msg));

    // Loop infinito para manter a placa ligada
    while (1) {
        sleep_ms(10000);
    }

    return 0;
}
