#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       //"north" : MROOMS"center",
       "east" : MROOMS"tomb1_2",
       "south" : MROOMS"tomb1_4",
       //"west" : MROOMS"center",
    ] ));    
}
