#include "../undead.h"

inherit ROOM;

void create() 
{
    ::create();

    set_name("A hilly meadow");
    set_terrain(GRASSLANDS);
    set_travel(FOOT_PATH);
    set_climate("temperate");
    set_property("light", 2);

    set_short("%^MAGENTA%^You are in a large meadow.%^RESET%^");
 
    set_long("%^YELLOW%^You are moving through a large hilly meadow.\n%^RESET%^"
        "To your west you see the hills level out to a plain, which is covered "
        "with the machines of war. You can almost hear the yelling and shouting "
        "of men's voices from where you stand, several leagues away. To your "
        "south lies the ocean, and to your east is the Peth Forest, home to "
        "many creatures of evil.%^RESET%^");
 
    set_exits(([
        "north"     :BO+"room48",
        "east"      :PATH+"room19",
        "south"     :PATH+"room29",
        "west"      :BO+"room3"
             ]));

    set_smell("default","The scent of clean open air enters your lungs.");
    set_listen("default","In the distance you can almost make out the sounds of war.");
}