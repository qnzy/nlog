/*
 * nlog: nano logging library
 * public domain / CC0
 *
 * this is a header only library. to use it you need
 * to define NLOG_IMPLEMENTATION in exactly one
 * compilation unit before including this file.
 */

#pragma once

#include <stddef.h>

#define LOG_ALWAYS      0
#define LOG_ERROR       1
#define LOG_WARNING     2
#define LOG_INFO        3
#define LOG_DEBUG       4

void nlog_init (void (*printstr)(const char*));
void nlog_set_level (unsigned int level);
void nlog (unsigned int level, const char* str);


#ifdef NLOG_IMPLEMENTATION

static unsigned int nlog_level = 0;
static void (*nlog_printstr)(const char * str) = NULL;

void nlog_init (void (*printstr)(const char*)) {
        // use nlog_init(NULL) to disable logging
        nlog_printstr = printstr;
}

void nlog_set_level (unsigned int level) {
    nlog_level = level;
}

void nlog (unsigned int level, const char* str) {
    if ((nlog_printstr != NULL) && (str != NULL) && (level <= nlog_level)) {
        nlog_printstr(str);
    }
}

#endif

