#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit ROOM;

void create()
{
    ::create();
    set_name("keep1");
    set_terrain(ROCKY);
    set_travel(DIRT_ROAD);
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",0);

    set_short("%^BOLD%^%^YELLOW%^Pathway to a Keep%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This path makes its way up the sloped terrain to a massive keep ahead. The hard"+
			" %^RESET%^%^ORANGE%^packed dirt%^BOLD%^%^WHITE%^ which you walk on gives nothing to your weight, being"+
			" well-suited to constant travel. The sides of the path are covered by heavy %^BOLD%^%^CYAN%^boulders %^BOLD%^%^WHITE%^which"+
			" stands tall on either side. The keep ahead looks fairly new, and dominates the countryside it stands on.");

    set_smell("default","\n%^BOLD%^%^GREEN%^The smell of the forest is still strong here.%^RESET%^");
    set_listen("default","%^RESET%^%^CYAN%^You hear the chirping of birds in the background.%^RESET%^");

    set_items(([
      "dirt"    : "%^RESET%^%^RED%^The dirt here is packed hard from constant use.",
      "boulders" : "%^RESET%^%^ORANGE%^The piles of boulders look like they are leftover building materials. This"+
      " keep was obviously just recently built.",
    ]) );

    set_exits(([
		"north" : ROAD"road5",
		"south"	: KEEP"keep2",
	]));

}



