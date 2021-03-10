#include <std.h>
#include "../inherits/area_stuff.h"
inherit LOWER;

void create() 
{
    ::create();    
    set_exits((["east" : CRROOMS+"lower14", "south" : CRROOMS+"lower12"]));		    
}
