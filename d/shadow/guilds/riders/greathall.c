//coded by grendel while wishing seraph would leave his ass alone
#include <std.h>
inherit ROOM;

void create() {
::create();
set_light(2);
set_property("indoors", 1);
set_short("Great Hall");
set_property("no teleport", 1);
set_long(
"This is the great hall of the Rider's Guild.  The room has a high rectangular ceiling, and floors made of the purest white marble, which rise into a small stage for ceremonial purposes.  To the north you can see an oak door leading to the Councilor's Chambers, to the south is the courtyard, and to the southeast is the foyer.  Many colorful banners emblazoned with the crest of the riders hang from the ceiling."
);
set_exits(([
"north" : "/d/shadow/guilds/riders/chamb.c",
"south" : "/d/shadow/guilds/riders/cyard.c",
"southeast" : "/d/shadow/guilds/riders/guild2.c"
]));
set_items(([
"stage" : "this stage is made of the purest marble with several steps leading up to it.",
"door" : "it is an oaken door with the rider's crest on it.",
"banners" : "these banners depect several scenes of glory brought to the guild in defeating the evil of the world.",
"wall" : "it looks like a wall to me, how about you?"
]));
set_smell("default", "You can smell the wine and meat of several feasts past.");
set_listen("default", "You can hear the joyous cries of your comrades.");
}
