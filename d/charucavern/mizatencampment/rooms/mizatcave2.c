#include <std.h>
#include "../inherits/area_stuff.h"
inherit MIZCAVE;

void create() 
{
    ::create();
    
    set_exits((["east" : MROOMS +"mizatcave3", "west" : MROOMS +"mizatcave1" ]));	
    
}
