#include <std.h>
#include "keep.h"
inherit ROOM;
void create() 
{
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no snakes",1);
    set_name("Keep Blacktongue");
    set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_long("This is the inside of a tower in the walls that surround Keep Blacktongue.  "+
    "The walls are bare and there is a strong musty smell in the air.  Within the far "+
    "wall there are stairs that lead to the top of the guard tower and the tower walls.");
    set_smell("default","Dust and ale permeate the walls of this Keep");
    set_listen("default","You hear voices and shouts from guards now and then.");
    set_items(([
    ] ));

}

void reset() 
{
    int x;
    ::reset();
    if(!present("keep guard") && random(10) > 7 && base_name(TO) != TOWERI1) 
    {
        for(x = 0;x < random(3) + 1;x++) 
        {
            new(KEEPM+"keep_guard")->move(TO);
        }
    }
}
	
