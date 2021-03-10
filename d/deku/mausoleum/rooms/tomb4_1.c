#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       //"north" : MROOMS"center",
       "east" : MROOMS"tomb4_2",
       "south" : MROOMS"tomb4_4",
       //"west" : MROOMS"center",
    ] ));    
}
