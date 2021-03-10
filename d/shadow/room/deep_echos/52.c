//52.c  inherits from 01 like many others
// collapsed exit
#include <std.h>
#include "deep_echo.h"

inherit DEEP;

void create(){
    ::create();
    set_exits(([
     "northwest" : ROOMS"51",
	 "southwest" : ROOMS"trap"
        ]));
   TO->collapse_exit("southwest",600);  
}
void reset(){
  ::reset();
  TO->collapse_exit("southwest");
}
