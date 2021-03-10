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
    set_long(TO->query_original_long()+mycol+" The hallway continues to the north and south.%^RESET%^");
}

void create() 
{
    sexit = "east";
    dest = SFROOMS+"iw1";
    ::create();
	
    set_exits((["north" : SFROOMS+"h25", "south" : SFROOMS+"h27"]));
}
