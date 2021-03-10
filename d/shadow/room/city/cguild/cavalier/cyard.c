#include <std.h>
inherit ROOM;

void create() {
::create();
set_light(2);
set_property("indoors",0);
    set_terrain(GARDEN);
    set_travel(FOOT_PATH);
set_short("Cavaliers' courtyard");
// set_property("no teleport", 1);
set_long(
"Here in the middle of the guild hall is a great open air courtyard.  There are many trees and bushes here that give this place a serene feeling.  There are several chairs and tables under umbrellas.  To the east is a pair of great glass doors that lead to the foyer and to the north a wide hallway leads to the Cavalier's Great Hall."
);
set_exits(([
    "east":"/d/shadow/room/city/cguild/cavalier/guild2",
    "north":"/d/shadow/room/city/cguild/cavalier/greathall",
]));
set_items(([
"tree" : "These large oak trees provide a good amount of shade.",
"bush" : "These bushes are teeming with life.",
"chairs" : "these wicker chairs look comfortable",
"tables" : "these tables have several empty glasses from drinks.",
"wall" : "it looks like a wall"
]));
set_smell("default", "You can smell the food and drink float over the walls to you.");
set_listen("default", "you can hear the birds chirp from the trees.");
}

