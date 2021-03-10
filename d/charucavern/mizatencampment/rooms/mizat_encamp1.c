#include <std.h>
#include "../inherits/area_stuff.h"
inherit MIZCAMP;

void create() 
{
    ::create();    
    set_exits((["north" : MROOMS +"mizat_encamp5", "south" : MROOMS + "mizat_encamp2", "west" : MROOMS +"mizatcave3" ]));	
    
}
