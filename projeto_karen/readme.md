Projetos de Sistemas Embarcados - EmbarcaTech 2025

Autora: Karen Beatrice Souza Goncalves

Curso: Residencia Tecnologica em Sistemas Embarcados

Instituicao: EmbarcaTech - HBr

Brasilia, abril de 2025

Sobre este repositorio
Este repositorio reune os projetos desenvolvidos ao longo do curso de Sistemas Embarcados, durante a etapa de Cada projeto tem sua propria pasta, contendo o codigo-fonte, documentacao e recursos visuais.
Projeto: Seguranca em IoT com BitDogLab (C/C++)
Este projeto implementa uma aplicacao de comunicacao segura usando o microcontrolador Raspberry Pi Pico W (conexao Wi-Fi, protocolo MQTT, autenticacao de usuario e criptografia leve (XOR).

Funcionalidades:
- Conexao automatica a rede Wi-Fi configurada
- Comunicacao com broker MQTT com autenticacao (usuario e senha)
- Publicacao de mensagens no topico MQTT debug/karen
- Teste de envio sem depender de comunicacao serial (via COM)
- Organizacao modular com wifi_conn, mqtt_comm e crypto
- Preparado para futura adicao de criptografia e protecao contra replay

Estrutura do Projeto:
firmware/
■■■ app/ # Codigo principal (main.c)
■■■ hal/ # Abstracoes de hardware (Wi-Fi, MQTT, Criptografia)
■■■ include/ # Headers correspondentes
■■■ lwipopts.h # Configuracoes da stack lwIP
■■■ mosquitto.conf # Configuracao do broker local com autenticacao
■■■ passwd.txt # Arquivo com senha gerada via mosquitto_passwd
■■■ CMakeLists.txt # Arquivo de build do projeto

Como Executar:
1. Compile o projeto com Ninja
 cd build
 ninja
2. Grave o main.uf2 na BitDogLab
 - Coloque a placa em modo BOOTSEL
 - Arraste o arquivo main.uf2 para o disco RPI-RP2
3. Inicie o broker Mosquitto com autenticacao
 cd "C:\Program Files\mosquitto"
 mosquitto.exe -c caminho\para\mosquitto.conf -v
4. Execute o subscriber para o topico
 mosquitto_sub.exe -h 172.19.8.126 -t debug/karen -u aluno -P senha123

Seguranca implementada:
 Autenticação MQTT com aluno / senha123

 Mensagens publicadas em tópico exclusivo debug/karen

(opcional) Criptografia leve XOR do payload

(opcional) Proteção contra replay com timestamp

Testado com
Raspberry Pi Pico W (BitDogLab)

Broker Mosquitto 2.0+

Rede Wi-Fi: AP-ACCESS BLH

Windows 10 + PowerShell + VS Code





