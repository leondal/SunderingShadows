#include <std.h>
inherit ROOM;

void create() {
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("Daggerdale Courthouse");
    set_long(
"%^BOLD%^%^WHITE%^This is the Daggerdale courthouse%^RESET%^\n"
"%^RESET%^%^ORANGE%^With the warm golden wood used used on the floor and "
"walls this courtroom has a rustic feel to it.  A simple wooden table is "
"set up close to the eastern wall.  This table is where the judge sits to "
"officiate the trials brought before the court.  Two smaller wooden tables "
"face opposite of the judges' table.  Mismatched wooden chairs carry a "
"rustic feeling further inside the room.  On the eastern wall a worn older "
"looking banner in %^GREEN%^green %^ORANGE%^hangs.  The banner shows an "
"image of a %^YELLOW%^Roc %^RESET%^%^ORANGE%^in flight clutching two pairs "
"of crisscross daggers in either talon, the symbol for Daggerdale. Tin "
"punched lanterns cast a warm glow on the courthouse.%^RESET%^\n"
    );
    set_smell("default","You smell new paint.");
    set_listen("default","You hear the sounds of hammers.");

    set_items( ([
      ]) );
    set_exits( ([
	"west" : "/d/dagger/Daggerdale/streets/street32",
      ]) );
}

