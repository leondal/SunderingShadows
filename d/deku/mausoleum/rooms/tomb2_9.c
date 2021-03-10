#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb2_6",
       //"east" : MROOMS"tomb1_9",
       //"south" : MROOMS"north3",
       "west" : MROOMS"tomb2_8",
    ] ));        
    set_crack_destination("hidden21");
    set_cracked_wall("south");
}
