#include <std.h>
#include "../inherits/area_stuff.h"
inherit TOMB;

void create() 
{
    ::create();
    set_exits(([
       "north" : MROOMS"tomb1_6",
       //"east" : MROOMS"tomb1_9",
       //"south" : MROOMS"north3",
       "west" : MROOMS"tomb1_8",
    ] ));        
}
