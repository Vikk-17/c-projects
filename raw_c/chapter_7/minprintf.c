/*
 * minprintf: minimal printf with variable args list
*/

#include<stdarg.h>
#include<stdio.h>

// variadic function, args with ...
// at least one fix params before ...
// required <stdarg.h> for the macros to handle variable args
void minprintf(char* fmt, ...) {
    // va_list hold the information neede by va_start, va_end and va_copy
    va_list ap; // points to each unnamed arg in turn; typedef
    char *p, *sval;
    int ival;
    double dval;

    // enable access to variadic function args
    va_start(ap, fmt); // function macros
    for(p = fmt; *p; p++) {
        if(*p != '%') {
            putchar(*p);
            continue;
        }
        switch(*++p) {
            case 'd':
                ival = va_arg(ap, int); // access the next variadic function argument
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for(sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    // clean up when done
    // end traversal of vaiadic function args
    va_end(ap); // function macros
}
