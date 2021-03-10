#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb2_5",
       "east" : MROOMS"tomb2_9",
       //"south" : MROOMS"north3",
       "west" : MROOMS"tomb2_7",
    ] ));    
}
