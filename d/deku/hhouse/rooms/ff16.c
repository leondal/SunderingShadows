#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFHH;

void adjust_room(int state)
{
    string mycol;
    switch(state)
    {		
        case 0:	
            mycol = "%^BOLD%^%^WHITE%^";
            break;
        case 1:			
            mycol = "%^BOLD%^%^MAGENTA%^";
            break;
    }
    set_long(TO->query_original_long()+mycol+" The hallway continues east and west.%^RESET%^");

}

void create() 
{
    ::create();
    sexit = "south";
    dest = FFROOMS+"iw10";

    set_exits((["east" : FFROOMS+"15", "west" : FFROOMS+"17" ]));		
}
