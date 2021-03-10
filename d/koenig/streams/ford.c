//ford.c - for Koenig.  Updated by Circe 11/28/03
#include <std.h>
#include <objects.h>
#include "../koenig.h"

inherit ROOM;

void create() {
    ::create();
    set_terrain(SHORE);
    set_travel(RUTTED_TRACK);
    set_property("light",2);
    set_property("indoors",0);
    set_short("A tiny ford");
    set_long(
	"%^BOLD%^%^BLUE%^This is a small ford that joins the opposing banks.  "+
      "It is made of %^BOLD%^%^BLACK%^rocks%^BLUE%^ and %^RESET%^gravel "+
      "%^BOLD%^%^BLUE%^that have formed it over time. The water from the stream"+
	" still runs over your feet. To the northwest and southeast the ford"+
	" drops a bit lower, you'll have to wade to shore from there.\n"
    );
     set_smell("default","You smell the fresh water.");
     set_listen("default","The stream rushes around your feet.");
    set_exits(([
       "northwest" : VILSTREAM"stream10",
       "southeast" : VILSTREAM"stream14",
    ] ));
    set_items(([
	"ford" : "You are standing on a tiny ford in the river that runs"+
	" southeast to northwest, joining the two banks.",
	({"rocks","gravel"}) : "Rocks and gravel and formed together over time"+
	" to create this tiny ford in the center of the river.",
    ] ));
}
