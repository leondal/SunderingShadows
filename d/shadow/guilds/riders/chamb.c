//coded by grendel
#include <std.h>
inherit ROOM;

create() {
::create();
set_light(2);
set_property("indoors",1);
set_short("Councilor's Chambers");
set_property("no teleport", 1);
set_long(
"When you enter the room you are heated by the warm glow of the fire in the large fireplace in the room.  There are many couches and chairs spread around the room for people to sit on while talking.  This is where the cavaliers meet to discuss the issues of the guild.  There is an oak door leading south to the Great Hall."
);
set_exits(([
    "south":"/d/shadow/room/city/cguild/cavalier/greathall.c"
]));
set_items(([
"fire" : "the fire is small, but gives off a lot of light and heat",
"couches" : "the couches look comfortable",
"chairs" : "the chairs look comfortable",
"door" : "the oak door looks very strong",
"wall" : "it looks like a wall"
]));
set_smell("default", "You smell the smoke from the fire as a small amount enters the room.");
set_listen("default", "You can hear the crackle of the fire over the muted conversations in the room.");
}
