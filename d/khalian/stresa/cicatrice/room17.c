
//rooms by the house of Svaha

#include <std.h>
inherit ROOM;

void create() {
::create();

set_property("light", 2);
set_property("indoors", 0);

set_short("%^ORANGE%^The Cicatrice Desert");
set_long("%^ORANGE%^The sound of the ocean recedes.  All about you is
sand, sand and more sand.  You have no landmarks from which you can get
a bearing, only shifting hills of (what else) sand.  Here and there you 
notice that the sand seems to fall into small holes, as if following some
unknown trail.  Heat waves undulate around you giving the desert an errie 
moving texture.  You begin to wonder why in all the God's names did you 
decide to come here, and how you are going to get out, if that is at all
possible.");


set_smell("default", "%^CYAN%^You can only smell the hot air trying to 
sear your lungs");
set_listen("default", "%^CYAN%^The sound of vultures cackling, as if 
they are laughing at you can be heard in the distance.");

set_exits
(([
"north" : "/d/khalian/stresa/cicatrice/room10",
		"south" : "/d/khalian/stresa/cicatrice/room28",
		"west" : "/d/khalian/stresa/cicatrice/room16",
		"east" : "/d/khalian/stresa/cicatrice/room18",
		"northeast" : "/d/khalian/stresa/cicatrice/room11",
		"northwest" : "/d/khalian/stresa/cicatrice/room9",
		"southeast" : "/d/khalian/stresa/cicatrice/room29",
		"southwest" : "/d/khalian/stresa/cicatrice/room27"
]));

set_items
(([
"desert" : "A dry, arid area comprised of(what else?) SAND!",
"holes" : "Small than a cup, sand appears to be tricking down, but to
where or why?"
]));

}
