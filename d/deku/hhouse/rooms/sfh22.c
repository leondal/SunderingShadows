#include <std.h>
#include "../inherits/area_stuff.h"
#include "../inherits/door_stuff.h"
inherit SFH;

void adjust_room(int state)
{
    string mycol;
    set_door("door", SFROOMS+"r7", "east");	
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
    set_exits((["north" : SFROOMS+"h21", "south" : SFROOMS+"h23", "east" : SFROOMS+"r7"]));
}
