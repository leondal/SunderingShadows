#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       //"north" : MROOMS"center",
       "east" : MROOMS"tomb1_3",
       "south" : MROOMS"tomb1_5",
       "west" : MROOMS"tomb1_1",
    ] ));    
}
