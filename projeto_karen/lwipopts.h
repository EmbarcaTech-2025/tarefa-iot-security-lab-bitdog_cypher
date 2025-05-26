#ifndef LWIPOPTS_H
#define LWIPOPTS_H

#define LWIP_TCP 1
#define LWIP_IPV4 1
#define LWIP_SOCKET 1
#define LWIP_NETCONN 1
#define LWIP_DNS 1

#define MEMP_NUM_SYS_TIMEOUT        (LWIP_NUM_SYS_TIMEOUT_INTERNAL + 1)
#define MQTT_REQ_MAX_IN_FLIGHT      (5)

#define LWIP_TIMEVAL_PRIVATE 0
#define NO_SYS 1

#endif /* LWIPOPTS_H */
