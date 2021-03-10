#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb1_3",
       //"east" : MROOMS"tomb1_6",
       "south" : MROOMS"tomb1_9",
       "west" : MROOMS"tomb1_5",
    ] ));    
}
