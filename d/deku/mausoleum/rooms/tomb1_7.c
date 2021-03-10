#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb1_4",
       "east" : MROOMS"tomb1_8",
       //"south" : MROOMS"tomb1_9",
       //"west" : MROOMS"tomb1_5",
    ] ));    
}
