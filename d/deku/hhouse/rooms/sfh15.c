#include <std.h>
#include "../inherits/area_stuff.h"
inherit SFH;

void adjust_room(int state)
{
    string mycol;
    switch(state)
    {		
        case 0:	
            mycol = "%^RESET%^%^ORANGE%^";
            break;
        case 1:			
            mycol = "%^RESET%^%^GREEN%^";
            break;
    }
    set_long(TO->query_original_long()+mycol+" The hallway continues to the east and west.%^RESET%^");
}

void create() 
{
    sexit = "south";
    dest = SFROOMS+"iw5";
    ::create();
    set_exits((["east" : SFROOMS+"h14", "west" : SFROOMS+"h16"]));		
}
