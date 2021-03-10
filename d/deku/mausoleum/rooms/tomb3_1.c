#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       //"north" : MROOMS"center",
       "east" : MROOMS"tomb3_2",
       "south" : MROOMS"tomb3_4",
       //"west" : MROOMS"center",
    ] ));    
    set_crack_destination("hidden10");
    set_cracked_wall("north");
}
