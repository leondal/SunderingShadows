#include <std.h>
#include "../inherits/area_stuff.h"
#include "../inherits/door_stuff.h"
inherit FFH;

void adjust_room(int state)
{
    string mycol;
    set_door("door", FFROOMS+"r1", "north");
    switch(state)
    {		
        case 0:	
            mycol = "%^BOLD%^%^WHITE%^";
            set_door_description("door", HALLBD);
            break;
        case 1:			
            mycol = "%^BOLD%^%^MAGENTA%^";
            set_door_description("door", HALLGD);
            break;
    }
    set_long(TO->query_original_long()+mycol+" The hallway continues east and west. A "+
    "%^RESET%^%^GREEN%^door"+mycol+" is set into the northern wall.%^RESET%^");	
}

void create() 
{
    ::create();
	
    set_exits((["east" : FFROOMS+"5", "west" : FFROOMS+"3", "north" : FFROOMS+"r1" ]));			
}
