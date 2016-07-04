/*-
 * Copyright (c) 2015 The NetBSD Foundation, Inc.
 * Copyright (c) 2016 The FreeBSD Foundation, Inc.
 * All rights reserved.
 *
 * Portions of this software were developed by Kurt Lidl
 * under sponsorship from the FreeBSD Foundation.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Christos Zoulas.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"
#include "login-common.h"
#include "client-common.h"

#ifdef HAVE_LIBBLACKLIST
#include <blacklist.h>
#endif

#include "blacklist-client.h"

struct blacklist *
blacklist_init(void)
{
	struct blacklist *ptr = NULL;

#ifdef HAVE_LIBBLACKLIST
	ptr = blacklist_open();
#endif

	return ptr;
}

void
blacklist_notify(struct client *client, int action)
{
#ifdef HAVE_LIBBLACKLIST
	if (client->blstate == NULL)
		return;

	(void)blacklist_r(client->blstate, action, client->fd, "imap-login");
#endif

	return;
}
