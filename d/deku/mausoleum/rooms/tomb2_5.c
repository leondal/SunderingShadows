#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb2_2",
       "east" : MROOMS"tomb2_6",
       "south" : MROOMS"tomb2_8",
       "west" : MROOMS"tomb2_4",
    ] ));    
}
