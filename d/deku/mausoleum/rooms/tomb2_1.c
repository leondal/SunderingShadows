#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       //"north" : MROOMS"center",
       "east" : MROOMS"tomb2_2",
       "south" : MROOMS"tomb2_4",
       //"west" : MROOMS"center",
    ] ));    
}
