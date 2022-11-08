/*
 * nlog: nano logging library
 * public domain / CC0
 *
 * this is a header only library. to use it you need
 * to define NLOG_IMPLEMENTATION in exactly one
 * compilation unit before including this file.
 * */
#pragma once

#define LOG_ERROR 0
#define LOG_WARN 1
#define LOG_INFO 2
#define LOG_DEBUG 3

static unsigned int nlog_level = 0;
static void (*nlog_printstr)(const char * str) = NULL;

void nlog_init (void (*printstr)(const char*));
void nlog_set_level (unsigned int level);
void nlog(unsigned int level, const char* str);

#ifdef NLOG_IMPLEMENTATION

void nlog_init (void (*printstr)(const char*)) {
    if (printstr != NULL) {
        nlog_printstr = printstr;
    }
}
    
    
void nlog_set_level (unsigned int level) {
    nlog_level = level;
}

void nlog(unsigned int level, const char* str) {
    if ((nlog_printstr != NULL) && (level <= nlog_level)) {
        nlog_printstr(str);
    }
}

#endif
