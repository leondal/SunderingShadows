#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit PATHBASE;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "path02" ,
	      "southeast" : ROOMS + "trail08"]) );
}
