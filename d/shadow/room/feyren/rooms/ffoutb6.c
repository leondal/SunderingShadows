#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFOBR;
int searched;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^RED%^A %^RESET%^%^MAGENTA%^thick wooden%^BOLD%^"+
    "%^RED%^ door leading to a cellar is set into the base of the "+
    "north wall.%^RESET%^");
    set_exits( ([ "exit" : FFOR"8", "down" : FFCR"1"]) );
    set_door("cellar door",FFCR"1","down");
    set_door_description("cellar door",C_DOOR);
    searched = 0;
}

void open_hidden_room()
{
    object hidroom;
    if(searched == 0) 
    {
        searched = 1;
        tell_room(TO, "%^BOLD%^%^RED%^A section of "+
        "the west wall slides to the side, revealing an opening "+
        "into a %^BOLD%^%^WHITE%^hidden chamber%^BOLD%^"+
        "%^RED%^!%^RESET%^");

        TO->add_exit(FFOR"b7", "west");
		
        hidroom = find_object_or_load(FFOR"b7");
        if(!objectp(hidroom)) return;
        hidroom->open_hidden_room();
        return;
    }
}

void close_hidden_room()
{
    object hidroom;
    if(searched == 1)
    {
        tell_room(TO, "%^BOLD%^%^RED%^A section of "+
        "the west wall slides back into place!%^RESET%^");

        searched = 0;
        TO->remove_exit("west");

        hidroom = find_object_or_load(FFOR"b7");
        if(!objectp(hidroom)) return;
        hidroom->close_hidden_room();
        return;
    }
}

void reset()
{
    ::reset();
    close_hidden_room();	
}