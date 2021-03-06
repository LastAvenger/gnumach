/*
 * Mach Operating System
 * Copyright (c) 1991,1990 Carnegie Mellon University
 * All Rights Reserved.
 *
 * Permission to use, copy, modify and distribute this software and its
 * documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 *
 * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"
 * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR
 * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.
 *
 * Carnegie Mellon requests users of this software to return to
 *
 *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU
 *  School of Computer Science
 *  Carnegie Mellon University
 *  Pittsburgh PA 15213-3890
 *
 * any improvements or extensions that they make and grant Carnegie Mellon
 * the rights to redistribute these changes.
 */
/*
 *	File:	mach_debug/ipc_info.h
 *	Author:	Rich Draves
 *	Date:	March, 1990
 *
 *	Definitions for the IPC debugging interface.
 */

#ifndef	_MACH_DEBUG_IPC_INFO_H_
#define _MACH_DEBUG_IPC_INFO_H_

#include <mach/boolean.h>
#include <mach/port.h>
#include <mach/machine/vm_types.h>

/*
 *	Remember to update the mig type definitions
 *	in mach_debug_types.defs when adding/removing fields.
 */

typedef struct ipc_info_name {
	mach_port_t iin_name;		/* port name, including gen number */
/*boolean_t*/integer_t iin_marequest;	/* extant msg-accepted request? */
	mach_port_type_t iin_type;	/* straight port type */
	mach_port_urefs_t iin_urefs;	/* user-references */
	vm_offset_t iin_object;		/* object pointer */
	natural_t iin_next;		/* marequest/next in free list */
} ipc_info_name_t;

typedef ipc_info_name_t *ipc_info_name_array_t;

/*
 *	Type definitions for mach_port_kernel_object.
 *	By remarkable coincidence, these closely resemble
 *	the IKOT_* definitions in ipc/ipc_kobject.h.
 */

#define	IPC_INFO_TYPE_NONE		0
#define IPC_INFO_TYPE_THREAD		1
#define	IPC_INFO_TYPE_TASK		2
#define	IPC_INFO_TYPE_HOST		3
#define	IPC_INFO_TYPE_HOST_PRIV		4
#define	IPC_INFO_TYPE_PROCESSOR		5
#define	IPC_INFO_TYPE_PSET		6
#define	IPC_INFO_TYPE_PSET_NAME		7
#define	IPC_INFO_TYPE_PAGER		8
#define	IPC_INFO_TYPE_PAGING_REQUEST	9
#define	IPC_INFO_TYPE_DEVICE		10
#define	IPC_INFO_TYPE_XMM_PAGER		11
#define IPC_INFO_TYPE_PAGING_NAME	12

#endif	/* _MACH_DEBUG_IPC_INFO_H_ */
