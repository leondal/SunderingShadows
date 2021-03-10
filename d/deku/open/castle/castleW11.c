//	/realms/pator/castle/castleW11.c
//	Written by pator@ShadowGate
//	Thu May 11  1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_light(2);
    set_indoors(1);
    set_short("Outside the blacksmith");
    set_long(
@HALL
You are outside the blacksmith of the castle. Far to the east there is the dining hall and to the west there is the northwestern tower. You see a torch which lights the hall.
HALL
    );
set_smell("default","You smell the blacksmith very clearly here.");
set_listen("default","You hear the sound of steel on steel.");
    set_exits(([
       "east" : CASTLE+"castleW12.c",
       "west" : CASTLE+"castleW10.c",
       "north" : CASTLE+"castleB1.c"
    ] ));
//    set_pre_exit_functions(({"north"}),({"go_north"}));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "torch" : "This torch lights up the hall here"
    ] ));
}

int go_north() {
  write("This area is blocked off by fallen rock.");
  return 0;
}
