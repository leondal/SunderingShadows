#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       //"north" : MROOMS"center",
       //"east" : MROOMS"tomb1_3",
       "south" : MROOMS"tomb4_6",
       "west" : MROOMS"tomb4_2",
    ] ));    
}
