/*
 * Copyright (c) 2011, Google Inc.
 */
#ifndef BULK_CHECKIN_H
#define BULK_CHECKIN_H

#include "cache.h"

int index_bulk_checkin(struct object_id *oid,
		       int fd, size_t size, enum object_type type,
		       const char *path, unsigned flags);

/*
 * Tell the object database to optimize for adding
 * multiple objects. end_odb_transaction must be called
 * to make new objects visible. Transactions can be nested,
 * and objects are only visible after the outermost transaction
 * is complete or the transaction is flushed.
 */
void begin_odb_transaction(void);

/*
 * Make any objects that are currently part of a pending object
 * database transaction visible. It is valid to call this function
 * even if no transaction is active.
 */
void flush_odb_transaction(void);

/*
 * Tell the object database to make any objects from the
 * current transaction visible if this is the final nested
 * transaction.
 */
void end_odb_transaction(void);

#endif
