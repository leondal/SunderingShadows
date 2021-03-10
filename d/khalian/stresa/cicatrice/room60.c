//rooms by the house of svaha

#include <std.h>
inherit ROOM;

void create() {
::create();

set_property("light", 2);
set_property("indoors", 0);

set_short("%^ORANGE%^The Cicatrice Desert");
set_long("%^ORANGE%^You are in the Cicatrice Desert.  You are surrounded
by sand and dunes, heat and wind.  There are no landmarks for you to
follow.  Deep inside you pray you have a good sense of direction.");

set_smell("default", "%^CYAN%^Only the hot winds leave something of an
odour, but perhaps it is just you.");
set_listen("default", "%^CYAN%^Just the sound of the wind grinding grains
of sand, or mayhaps its only your teeth.");

set_exits
(([
"north" : "/d/khalian/stresa/cicatrice/room42",
"south" : "/d/khalian/stresa/cicatrice/room81",
"east" : "/d/khalian/stresa/cicatrice/room61",
"west" : "/d/khalian/stresa/cicatrice/room59",
"northeast" : "/d/khalian/stresa/cicatrice/room43",
"northwest" : "/d/khalian/stresa/cicatrice/room41",
"southeast" : "/d/khalian/stresa/cicatrice/room82",
"southwest" : "/d/khalian/stresa/cicatrice/room80"
]));

set_items
(([
"landmarks" : "An anatomical structure used as a point of orientation
in location",
]));

}
