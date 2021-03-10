#include <std.h>
#include "../inherits/area_stuff.h"
#include "../inherits/door_stuff.h"
inherit SFH;

void adjust_room(int state)
{
    string mycol;
    set_door("door", SFROOMS+"r3", "west");
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
    set_long(TO->query_original_long()+mycol+" The hallway continues to the north and south.%^RESET%^");
}

void create() 
{
    ::create();
	set_exits((["north" : SFROOMS+"h11", "south" : SFROOMS+"h9", "west" : SFROOMS+"r3"]));		

}
