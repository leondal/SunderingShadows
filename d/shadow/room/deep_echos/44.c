//44.c  inherits from 01 like many others
// locked chamber to the east
#include <std.h>
#include "deep_echo.h"

inherit DEEP;

void create(){
    ::create();
    set_exits(([
        
        "northeast"  : ROOMS"43",
        "west"  : ROOMS"46",
        "east"  : ROOMS"47",
        "southeast"  : ROOMS"45"
       
        ]));
	  set_door("gate",ROOMS"47","east","key");
	  set_locked("gate",1);
	  set_door_description("gate","The gate is made of"+
	  " rusted iron bars.  It is lodged into the "+
	  "cavern and is locked with a simple lock.");
}
