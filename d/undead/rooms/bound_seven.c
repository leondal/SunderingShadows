#include "../undead.h"

inherit ROOM;

void create() 
{
    ::create();

    set_name("In a dark swamp");
    set_terrain(SWAMP);
    set_travel(FRESH_BLAZE);
    set_climate("tropical");
    set_property("light", 2);

    set_short("%^BOLD%^%^BLACK%^A nasty swamp%^RESET%^");
    
    set_long("%^BOLD%^%^BLACK%^You have entered into a nasty riverside swamp.\n%^RESET%^"
        "%^BLUE%^Now you are almost to the bank of the %^RESET%^River of Sorrows%^BLUE%^ "
        "for you can hear it roaring in the distance. The river must have "
        "over flowed into this area causing it to become saturated in water "
        "and grime. To your west you can see trees from the Peth Forest rise "
        "up, almost blocking what little sunlight there is in this wicked land.");
 
    set_exits(([
        "north"     :BO+"sroom2",
        "south"     :BO+"sroom23"
             ]));
    set_smell("default","The smell of decay and mildew radiate from this area.");
    set_listen("default","You can hear the rushing river not far away.");

}
