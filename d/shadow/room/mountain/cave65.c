//cave65.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"A large, cavernous mine is to the "+
       "southwest, but it looks like these living quarters continue "+
       "to the northeast.\n");
    set_exits(([
        "southwest" : ROOMS"cave61",
        "northeast" : ROOMS"cave66",
   	]));
}
