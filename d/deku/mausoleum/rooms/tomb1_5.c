#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb1_2",
       "east" : MROOMS"tomb1_6",
       "south" : MROOMS"tomb1_8",
       "west" : MROOMS"tomb1_4",
    ] ));    
}
