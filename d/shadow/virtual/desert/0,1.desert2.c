//altered 5/30/08 by ~Circe~ for the new temple of Anhur
#include <std.h>

inherit ROOM;

int is_virtual(){ return 1; }

void create(){
   ::create();
   set_terrain(DESERT);
   set_travel(FOOT_PATH);
   set_indoors(0);
   set_light(3);
   set_name("A vast desert");
   set_short("%^RESET%^%^ORANGE%^You are nearing the Barrier Mountains%^RESET%^");
   set_long(
@MELNMARN
%^RESET%^%^ORANGE%^You are nearing the Barrier Mountains%^RESET%^
The Barrier Mountains loom to the north.
The desert stretches to the south.
The sandy ground here is much rougher.
Some boulders rise up and you think you see a crack leading between them.
MELNMARN
);
   set_exits(([
	"east":"/d/shadow/virtual/desert/0,0.desert",
      "west":"/d/shadow/virtual/desert/0,2.desert",
      "south":"/d/shadow/virtual/desert/1,1.desert"
   ]));
   set_smell("default","You can smell the fresh scent of pine to the west.");
   set_listen("default","You can hear the rustling of trees to the west.");
   set_items(([
      "stones" : "The stones are rather large and irregularly "+
         "shaped, and they seem to be laid out in a line rather "+
         "than simply blown here by the wind."
   ]));
}