/*
 * ErrorHandling.c
 *
 *  Created on: Nov 9, 2023
 *      Author: aaronvan
 */

#include "ErrorHandling.h"
void APPLICATION_ASSERT(bool x){
	if(x == false){
		while(1){
		}
	}
}
