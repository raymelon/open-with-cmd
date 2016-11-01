/**
 * convert_time.h
 *
 * Converts double-type time in seconds to hh:mm:ss format
 * (c) May 2015 Raymel Francisco
 */

#include <stdio.h>
#include "convert_time.h"
/*
 * @discussion	Converts a double-type seconds to hh:mm:ss format
 * @param 		seconds		The double-type seconds to be converted
 * @return		Converted seconds in hh:mm:ss format, including unit specifiers
 */
char *convert_time(double seconds) {

    static char converted[12];
    double hr = seconds / 3600;
    double min = decimal_part(hr) * 60;
    double sec = decimal_part(min) * 60 ;

    if (!(int) hr && !(int) min) {
        sprintf(converted, "%ds", round_up(sec));
    } else if (!(int) hr) {
        sprintf(converted, "%dm %ds", (int) min, round_up(sec));
    } else {
		sprintf(converted, "%dh %dm %ds", (int) hr, (int) min, round_up(sec));
	}
    return converted;
}
/*
 * @discussion	Extracts the decimal part of a double number
 * @param 		num		The double number in which the decimal part is to be extracted 
 * @return		The decimal part of the number
 */
double decimal_part(double num) {
    return (double) (num - (int) num);
}
/*
 * @discussion	Rounds up a double number
 * @param 		num 	The double number to round up
 * @return		Rounded up form, in integer
 */
int round_up(double num) {
    return (num - (int) num < 0.5) ? num : ++num;
}
