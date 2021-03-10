#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb3_5",
       "east" : MROOMS"tomb3_9",
       //"south" : MROOMS"north3",
       "west" : MROOMS"tomb3_7",
    ] ));    
    set_crack_destination("hidden11");
    set_cracked_wall("south");
}
