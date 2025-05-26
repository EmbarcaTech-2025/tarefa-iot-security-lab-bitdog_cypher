# Projetos de Sistemas Embarcados - EmbarcaTech 2025

**Autora:** Karen Beatrice Souza Gonçalves  
**Curso:** Residência Tecnológica em Sistemas Embarcados  
**Instituição:** EmbarcaTech - HBr  
**Brasília, abril de 2025**

---

## Sobre este repositório

Este repositório reúne os projetos desenvolvidos ao longo do curso de Sistemas Embarcados, durante a etapa de residência.  
Cada projeto tem sua própria pasta, contendo o código-fonte, documentação e recursos visuais.

---

## Projeto: Segurança em IoT com BitDogLab (C/C++)

Este projeto implementa uma aplicação de comunicação segura usando o microcontrolador **Raspberry Pi Pico W**, com:

- Conexão Wi-Fi
- Protocolo **MQTT**
- Autenticação de usuário
- Criptografia leve (**XOR**)

### Funcionalidades

- 🔌 Conexão automática à rede Wi-Fi configurada  
- 📡 Comunicação com broker MQTT com autenticação (usuário e senha)  
- 📨 Publicação de mensagens no tópico MQTT `debug/karen`  
- 🔧 Teste de envio sem depender de comunicação serial (via COM)  
- 📁 Organização modular (`wifi_conn`, `mqtt_comm`, `crypto`)  
- 🛡️ Preparado para futura adição de criptografia e proteção contra replay  

---

## Estrutura do Projeto

firmware/
├── app/ # Código principal (main.c)
├── hal/ # Abstrações de hardware (Wi-Fi, MQTT, Criptografia)
├── include/ # Headers correspondentes
├── lwipopts.h # Configurações da stack lwIP
├── mosquitto.conf # Configuração do broker local com autenticação
├── passwd.txt # Arquivo com senha gerada via mosquitto_passwd
├── CMakeLists.txt # Arquivo de build do projeto


---

## Como Executar

### 1. Compile o projeto com Ninja

```bash
cd build
ninja

2. Grave o main.uf2 na BitDogLab
Coloque a placa em modo BOOTSEL

Arraste o arquivo main.uf2 para o disco RPI-RP2

3. Inicie o broker Mosquitto com autenticação
cd "C:\Program Files\mosquitto"
mosquitto.exe -c caminho\para\mosquitto.conf -v

4. Execute o subscriber para o tópico
mosquitto_sub.exe -h 172.19.8.126 -t debug/karen -u aluno -P senha123

Segurança Implementada
✅ Autenticação MQTT com aluno / senha123

✅ Mensagens publicadas em tópico exclusivo debug/karen

🔐 (Opcional) Criptografia leve XOR do payload

🕒 (Opcional) Proteção contra replay com timestamp

Testado com
📌 Raspberry Pi Pico W (BitDogLab)

🧠 Broker Mosquitto 2.0+

🌐 Rede Wi-Fi: AP-ACCESS BLH

💻 Windows 10 + PowerShell + VS Code



