#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       //"north" : MROOMS"center",
       //"east" : MROOMS"tomb1_3",
       "south" : MROOMS"tomb3_6",
       "west" : MROOMS"tomb3_2",
    ] ));    
}
