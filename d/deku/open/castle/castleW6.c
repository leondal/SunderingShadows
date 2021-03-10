//	/realms/pator/castle/castleW6.c
//	Written by pator@ShadowGate
//	Tue May 9  1995

#include <std.h>
#include <objects.h>
#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_light(1);
    set_indoors(1);
    set_short("Near the Armoury");
    set_long(
@HALL
  You are outside the castle armoury.  You can see the gallery to your east and the armoury to the west.  It is not a very nice place here.
Some blood droplets can be seen on the floor. You think they dripped off some of the practice swords.
HALL
    );
set_smell("default","You smell the castle.");
set_listen("default","You hear sounds comming from the yard");
    set_exits(([
       "west" : CASTLE+"castleA1.c",
       "east" : CASTLE+"castleW7.c",
       "south" : CASTLE+"castleW4.c",
       "north" : CASTLE+"castleW8.c"
    ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "droplets" : "You see that they are surely made of blood !!"
    ] ));
}
