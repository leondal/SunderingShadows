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
    set_long(TO->query_original_long()+mycol+" The hallway continues to the south and west.%^RESET%^");
}

void create() 
{
    ::create();
	
    set_exits((["south" : SFROOMS+"h13", "west" : SFROOMS+"h15"]));		
}
