#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       //"north" : MROOMS"center",
       //"east" : MROOMS"tomb1_3",
       "south" : MROOMS"tomb1_6",
       "west" : MROOMS"tomb1_2",
    ] ));    
    set_crack_destination("hidden1");
    set_cracked_wall("east");
}
