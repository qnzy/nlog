# nlog
This is a small logging library for C (it's short for nano log).

There are three functions:

`void nlog_init (void (*printstr)(const char*));`

`void nlog_set_level (unsigned int level);`

`void nlog (unsigned int level, const char* str);`

Before using the library you must call **nlog_init** and pass it
an output function as a parameter. 

The logging level can be set using the **nlog_set_level** function. 

Finally, use **nlog** for logging a message. The message will be
logged, if the given level is smaller or equal to the level
set previously with nlog_set_level.

The following levels are predefined in the header: LOG_ERROR,
LOG_WARNING, LOG_INFO, LOG_DEBUG.

This library is public domain / CC0.
    
