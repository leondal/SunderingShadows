#include <std.h>
#include "../inherits/area_stuff.h"
inherit MIZCAMP;

void create() 
{
    ::create();    
    set_exits((["north" : MROOMS +"mizat_encamp1", "south" : MROOMS + "mizat_encamp3"]));	
    
}
