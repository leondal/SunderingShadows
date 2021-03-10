#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb2_1",
       "east" : MROOMS"tomb2_5",
       "south" : MROOMS"tomb2_7",
       //"west" : MROOMS"tomb1_2",
    ] ));    
}
