#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       //"north" : MROOMS"center",
       //"east" : MROOMS"tomb1_3",
       "south" : MROOMS"tomb2_6",
       "west" : MROOMS"tomb2_2",
    ] ));    
}
