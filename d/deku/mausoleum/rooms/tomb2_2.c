#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       //"north" : MROOMS"center",
       "east" : MROOMS"tomb2_3",
       "south" : MROOMS"tomb2_5",
       "west" : MROOMS"tomb2_1",
    ] ));    
    set_crack_destination("hidden22");
    set_cracked_wall("north");
}
