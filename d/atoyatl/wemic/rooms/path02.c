#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit PATHBASE;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "path01" ,
           "northwest" : ROOMS + "path03"]) );
}
