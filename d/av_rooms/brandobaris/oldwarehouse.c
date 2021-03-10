// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("oldwarehouse");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^within an o%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^d w%^WHITE%^a%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^eh%^BOLD%^%^BLACK%^o%^RESET%^u%^ORANGE%^se%^WHITE%^");

    set_long("%^ORANGE%^This old, %^BOLD%^%^BLACK%^d%^RESET%^u%^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^warehouse seems to have gone some time without seeing much use. Little more than a lar"
	"ge room with a plain wooden floor, it is lined with many rows of %^BOLD%^shelves%^RESET%^%^ORANGE%^, upon which numerous wooden %^BOLD%^%^BLACK%^crates %^RESET%^%^ORANGE%^have been stacked. %^WHITE%^"
	);

    set_smell("default","
The dust in the air here is heavy.");
    set_listen("default","It is eerily quiet.");


    set_exits(([ 
		"out" : "/d/antioch/wild/mount/pass_5",
	]));

}