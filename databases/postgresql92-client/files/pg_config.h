/*
 * PostgreSQL installs ABI-specific headers, this is a small wrapper to pick
 * up the correct one for the current build.
 */

#ifdef __amd64__
#include "amd64/pg_config.h"
#else
#include "i86/pg_config.h"
#endif
