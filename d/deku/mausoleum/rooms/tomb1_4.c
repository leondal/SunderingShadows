#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb1_1",
       "east" : MROOMS"tomb1_5",
       "south" : MROOMS"tomb1_7",
       //"west" : MROOMS"tomb1_2",
    ] ));    
    set_crack_destination("hidden31");
    set_cracked_wall("west");
}
