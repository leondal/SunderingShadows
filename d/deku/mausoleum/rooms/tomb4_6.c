#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb4_3",
       //"east" : MROOMS"west3",
       "south" : MROOMS"tomb4_9",
       "west" : MROOMS"tomb4_5",
    ] ));    
    set_crack_destination("hidden15");
    set_cracked_wall("east");
}
