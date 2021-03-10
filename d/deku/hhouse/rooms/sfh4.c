#include <std.h>
#include "../inherits/area_stuff.h"
#include "../inherits/door_stuff.h"
inherit SFH;

void adjust_room(int state)
{
    string mycol;
    set_door("door", SFROOMS+"r1", "north");	
    switch(state)
    {		
        case 0:	
            mycol = "%^RESET%^%^ORANGE%^";
            set_door_description("door", HALLBD);
            break;
        case 1:			
            mycol = "%^RESET%^%^GREEN%^";
            set_door_description("door", HALLGD);
            break;
    }
    set_long(TO->query_original_long()+mycol+" The hallway continues to the east and west.%^RESET%^");
}

void create() 
{
    ::create();
	
    set_exits((["east" : SFROOMS+"h5", "west" : SFROOMS+"h3", "north" : SFROOMS+"r1"]));
}
