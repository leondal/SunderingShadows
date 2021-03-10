#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb4_2",
       "east" : MROOMS"tomb4_6",
       "south" : MROOMS"tomb4_8",
       "west" : MROOMS"tomb4_4",
    ] ));    
}
