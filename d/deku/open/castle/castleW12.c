//	/realms/pator/castle/castleW12.c
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
    set_short("In a cross-road of halls");
    set_long(
@HALL
You are standing at a crossroad of halls and you can see various ways : 
To the west there is the blacksmith, to the east is the dininghall and
to the southwest there is the gallery.
HALL
    );
   set_smell("default","You smell the foods from the dining room here.");
set_listen("default","You hear the sound of steel on steel from far .");
    set_exits(([
       "east" : CASTLE+"castleE10.c",
       "west" : CASTLE+"castleW11.c",
       "southwest" : CASTLE+"castleW9.c"
    ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "torch" : "This torch lights up the hall here"
    ] ));
}
