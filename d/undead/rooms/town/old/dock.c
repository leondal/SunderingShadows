#include <std.h>
#include "../../undead.h"

inherit "/d/shadow/virtual/sea/dock";

int is_water()  { return 1; }
int is_dock()   { return 1; }

void create() 
{ 
    ::create();

    set_name("Sangri Dock");
    set_terrain(BOATS);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);

    set_short("You stand on a giant sea dock.");
 
    set_long("%^BOLD%^You are on the main docks of Graez.%^RESET%^\n"
        "Graez is the last remnant of good on this isle of the damned. It "
        "manages to maintain itself only through heavy sea trade from this "
        "dock. Right now ships are leaving and entering the dock by the "
        "dozen, many of them conducting business with the merchants of Graez."
        "The money is desperately needed to fund the war against the evil "
        "Undead Lord, Kartakass. But that is a horrible story which we shall "
        "not trouble you with now.");

    set_exits(([
        "north"     :TOWN+"room"
             ]));

    set_smell("default","The salty smell of the sea invades your nostrils.");
    set_listen("default","You hear the bustling of a city in the distance.");
    
    find_object_or_load("d/shadow/virtual/sea/obj/ferryboat")->move(TO);
}
