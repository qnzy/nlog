#include <stdio.h>
#define NLOG_IMPLEMENTATION
#include "nlog.h"

static int logcount = 0;
void printstr(const char*str) {
    printf("%s\n",str);
    logcount++;

}

void logAllLevels() {
    logcount = 0;
    nlog(LOG_ERROR,"error");
    nlog(LOG_WARNING,"warning");
    nlog(LOG_INFO,"info");
    nlog(LOG_DEBUG,"debug");
}

int main(void) {
    nlog_init(printstr);
    nlog_set_level(LOG_ERROR); 
    logAllLevels(); 
    if (logcount == 1) {printf("LOG_ERROR OK\n");} 
    else {printf("LOG_ERROR FAIL\n");}

    nlog_set_level(LOG_WARNING);
    logAllLevels();
    if (logcount == 2) {printf("LOG_WARNING OK\n");}
    else {printf("LOG_WARNING FAIL\n");}

    nlog_set_level(LOG_INFO);
    logAllLevels();
    if (logcount == 3) {printf("LOG_INFO OK\n");} 
    else {printf("LOG_INFO FAIL\n");}
    
    nlog_set_level(LOG_DEBUG);
    logAllLevels(); 
    if (logcount == 4) {printf("LOG_DEBUG OK\n");}
    else {printf("LOG_DEBUG FAIL\n");}

    return 0;
}
