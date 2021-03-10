#include "../../undead.h"

inherit ROOM;

void create() 
{
    ::create();

    set_name("On a bridge in the mountains");
    set_terrain(BOATS);
    set_travel(DIRT_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_climate("mountain");

    set_short("You are on a bridge.");

    set_long("%^BOLD%^%^BLUE%^You are on a bridge connecting the Thoradin Range.%^RESET%^\n"
        "The range rises up all around you as you cross this bridge. Beneath "
        "you, hundreds of feet below, is the %^BLUE%^River of Sorrows%^RESET%^.  "
        "You hold the railing on the bridge tighter as you think what a horrible "
        "death it would be should you fall.");

    set_exits(([
        "east"      :MTS+"room100",
        "west"      :MTS+"bridge"
             ]));

    set_smell("default","The fresh scent of nature is about you.");
    set_listen("default","You can hear a few birds chirping around you.");

}
