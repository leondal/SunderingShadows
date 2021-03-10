#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb4_4",
       "east" : MROOMS"tomb4_8",
       //"south" : MROOMS"tomb1_9",
       //"west" : MROOMS"tomb1_5",
    ] ));
    set_crack_destination("hidden16");
    set_cracked_wall("west");
}
