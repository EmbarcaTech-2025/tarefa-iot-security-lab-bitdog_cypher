#include "include/mqtt_comm.h"
#include "lwip/apps/mqtt.h"
#include "lwip/ip_addr.h"
#include <stdio.h>
#include <stdbool.h>  // Adicionado para usar 'bool'

// Cliente MQTT
static mqtt_client_t *client;
// Flag para indicar se está conectado ao broker
static bool mqtt_connected = false;

// Callback da conexão
static void mqtt_connection_cb(mqtt_client_t *client, void *arg, mqtt_connection_status_t status) {
    if (status == MQTT_CONNECT_ACCEPTED) {
        mqtt_connected = true;
        printf("Conectado ao broker MQTT com sucesso!\n");
    } else {
        mqtt_connected = false;
        printf("Falha ao conectar ao broker, código: %d\n", status);
    }
}

// Callback da publicação
static void mqtt_pub_request_cb(void *arg, err_t result) {
    if (result == ERR_OK) {
        printf("Publicação MQTT enviada com sucesso!\n");
    } else {
        printf("Erro ao publicar via MQTT: %d\n", result);
    }
}

// Setup da conexão MQTT
void mqtt_setup(const char *client_id, const char *broker_ip, const char *user, const char *pass) {
    ip_addr_t broker_addr;

    // Converte IP do broker
    if (!ip4addr_aton(broker_ip, &broker_addr)) {
        printf("Erro no IP\n");
        return;
    }

    // Cria o cliente MQTT
    client = mqtt_client_new();
    if (client == NULL) {
        printf("Falha ao criar o cliente MQTT\n");
        return;
    }

    // Informações do cliente
    struct mqtt_connect_client_info_t ci = {
        .client_id = client_id,
        .client_user = user,
        .client_pass = pass
    };

    // Conecta ao broker
    mqtt_client_connect(client, &broker_addr, 1883, mqtt_connection_cb, NULL, &ci);
}

// Publicação de mensagens
void mqtt_comm_publish(const char *topic, const uint8_t *data, size_t len) {
    if (!mqtt_connected) {
        printf("Ainda não conectado ao broker, publicação abortada.\n");
        return;
    }

    err_t status = mqtt_publish(client, topic, data, len, 0, 0, mqtt_pub_request_cb, NULL);
    if (status != ERR_OK) {
        printf("mqtt_publish falhou: %d\n", status);
    }
}
