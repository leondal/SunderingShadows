#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }

void create() {
set_indoors(1);
 ::create();
 set_light(2);
 set_short("In a Dark forest.");
 set_long("You're walking somewhere in a dark forest. " +
 		"You feel cold and frightened and wish you had never come to " +
 		"this place in the first place. You jump at the sound of a twig " +
 		"snapping."
 );
 set_exits(([
    "east":"/d/antioch/wild/forest/forest_enter",
    "north":"/d/antioch/wild/forest/virtual/antiforest/19,11.antiforest.c",
]));
set_smell("default","You smell the odors of a bustling city.");
set_listen("default","You hear the sounds of people moving in the city.");
}
