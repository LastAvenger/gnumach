/*
 * INET		An implementation of the TCP/IP protocol suite for the LINUX
 *		operating system.  INET is implemented using the  BSD Socket
 *		interface as the means of communication with the user level.
 *
 *		Definitions for the UDP module.
 *
 * Version:	@(#)udp.h	1.0.2	05/07/93
 *
 * Authors:	Ross Biro, <bir7@leland.Stanford.Edu>
 *		Fred N. van Kempen, <waltje@uWalt.NL.Mugnet.ORG>
 *
 * Fixes:
 *		Alan Cox	: Turned on udp checksums. I don't want to
 *				  chase 'memory corruption' bugs that aren't!
 *
 *		This program is free software; you can redistribute it and/or
 *		modify it under the terms of the GNU General Public License
 *		as published by the Free Software Foundation; either version
 *		2 of the License, or (at your option) any later version.
 */
#ifndef _UDP_H
#define _UDP_H

#include <linux/udp.h>

#define UDP_HTABLE_SIZE		128

/* udp.c: This needs to be shared by v4 and v6 because the lookup
 *        and hashing code needs to work with different AF's yet
 *        the port space is shared.
 */
extern struct sock *udp_hash[UDP_HTABLE_SIZE];

extern unsigned short udp_good_socknum(void);

#define UDP_NO_CHECK	0


extern struct proto udp_prot;


extern void	udp_err(int type, int code, unsigned char *header, __u32 daddr,
			__u32 saddr, struct inet_protocol *protocol, int len);
extern void	udp_send_check(struct udphdr *uh, __u32 saddr, 
			__u32 daddr, int len, struct sock *sk);
extern int	udp_recvfrom(struct sock *sk, unsigned char *to,
			     int len, int noblock, unsigned flags,
			     struct sockaddr_in *sin, int *addr_len);
extern int	udp_read(struct sock *sk, unsigned char *buff,
			 int len, int noblock, unsigned flags);
extern int	udp_connect(struct sock *sk,
			    struct sockaddr_in *usin, int addr_len);
extern int	udp_rcv(struct sk_buff *skb, struct device *dev,
			struct options *opt, __u32 daddr,
			unsigned short len, __u32 saddr, int redo,
			struct inet_protocol *protocol);
extern int	udp_ioctl(struct sock *sk, int cmd, unsigned long arg);

/* CONFIG_IP_TRANSPARENT_PROXY */
extern int	udp_chkaddr(struct sk_buff *skb);

#endif	/* _UDP_H */
