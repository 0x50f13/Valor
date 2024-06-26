#include "message.h"

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

uint8_t log_level = 0b1111111;

void debug(const char *format, ...) {
    if (LVL_DEBUG & log_level) {
        PRINT_FORMATTED(INFO);
    }
}

void info(const char *format, ...) {
    if (LVL_INFO & log_level) {
        PRINT_FORMATTED(INFO);
    }
}

void warn(const char *format, ...) {
    if (LVL_WARN & log_level) {
        PRINT_FORMATTED(WARN);
    }
}

void error(const char *format, ...) {
    if (LVL_ERROR & log_level) {
        PRINT_FORMATTED(ERROR);
    }
}

void success(const char *format, ...) {
    if (LVL_SUCCESS & log_level) {
        PRINT_FORMATTED(SUCCESS);
    }
}

void die(const char *format, ...) {
    if (LVL_FATAL & log_level) {
        PRINT_FORMATTED(ERROR);
        error("Fatal error.");
    }
    exit(-1);
}

void status(const char *format, ...) {
    if (LVL_STATUS & log_level) {
        PRINT_FORMATTED_NO_NEWLINE(SUCCESS);
    }
}

void debug_warn(const char *format, ...) {
    if (LVL_DEBUG & log_level) {
        PRINT_FORMATTED(WARN);
    }
}

void set_loglevel(uint8_t _log_level) {
    log_level = _log_level;
}

void add_loglevel(uint8_t _log_level) {
    log_level = log_level | _log_level;
}

void remove_loglevel(uint8_t _log_level) {
    _log_level = ~_log_level;
    log_level = log_level & _log_level;
}
