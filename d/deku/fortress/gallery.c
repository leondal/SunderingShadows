#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Eastern Gallery");
    set_long(
@KAYLA
%^YELLOW%^Fortress Gallery%^RESET%^
This huge room is chilly, exposed to the drafts coming from a number
of slit windows along the curving walls.  To the right, it follows 
the angle of the wall of the fortress.  The entire outer wall of the 
room is covered with paintings.  The different styles and varying
degrees of aging suggest that they were created over a long span
of history.
KAYLA
    );
    set_smell("default","There is a faintly nauseating smell of death and decay here.");
    set_exits(([
       "west" : "/d/deku/fortress/hallE1"
    ] ));
    set_items(([
	"paintings" : "Three paintings look interesting: the right, left and center ones.",
       "left painting" : "It shows a high mountain pass glittering in the light of the sun.",
	"center painting" : "This is a painting showing mighty dragons raging about the tower of Shadow.",
       "right painting" : "Here is a portrait of the mighty master mage."
    ] ));
}

void reset() {
  ::reset();
  if(!present("banshee")) {
    new("/d/deku/fortress/monster/banshee")->move(TO);
  }
}
