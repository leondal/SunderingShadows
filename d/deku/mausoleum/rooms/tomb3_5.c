#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb3_2",
       "east" : MROOMS"tomb3_6",
       "south" : MROOMS"tomb3_8",
       "west" : MROOMS"tomb3_4",
    ] ));    
}
