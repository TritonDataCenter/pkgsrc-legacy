/*
 * Python installs ABI-specific headers, this is a small wrapper to pick up
 * the correct one for the current build.
 */

#ifdef __amd64__
#include "amd64/pyconfig.h"
#else
#include "i86/pyconfig.h"
#endif
