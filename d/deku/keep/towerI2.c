#include <std.h>
#include "keep.h"
inherit VAULT;
void create() 
{
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no snakes",1);
    set_property("no teleport",1);
    set_name("Keep Blacktongue");
    set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
    set_long("You are standing on the top of one of the guard towers that protect Keep "+
    "Blacktongue.  A %^RED%^rusty door%^RESET%^ is inset into the floor near the "+
    "northern wall of this room.  All around you, Shadowlord Forest stretches to the "+
    "horizon, its darkness so thick that its almost tangible.  A chill wind sends shivers "+
    "surging down your spine.");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_smell("default","Dust and ale permeate the walls of this Keep");
    set_listen("default","You hear voices and shouts from guards now and then.");
    set_items(([
        ({"Forest","forest","Darkwood","darkwood","Darkwood Forest","darkwood forest"}) : "%^BOLD%^%^WHITE%^This "+
        "massive forest stretches as far as the eye can see in any direction.  From here you notice "+
        "the almost tangible darkness that seems to linger over it.%^RESET%^",
    ] ));
}

void reset() 
{
    int x;
    ::reset();
    if(!present("archer") && random(10) > 5 && base_name(TO) != TOWERI2) 
    {
        for(x = 0;x < random(3) + 2;x++) 
        {
            new(KEEPM + "archer")->move(TO);
        }
    }
}

