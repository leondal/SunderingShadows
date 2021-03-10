//altered 5/30/08 by ~Circe~ for the new temple of Anhur
#include <std.h>

inherit ROOM;

int is_virtual(){ return 1; }

void create(){
   ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(FOOT_PATH);
   set_indoors(0);
   set_light(3);
   set_name("Oasis");
   set_short("Oasis");
   set_long(
@MELNMARN
%^BOLD%^You are in a vast desert.%^RESET%^
You are standing in a small stand of trees. The %^GREEN%^trees%^RESET%^
surround a small well. The sand seems cooler here from 
the shade of the trees.

%^BOLD%^%^RED%^A giant crevice resides here along with a shattered, broken down well. A small etching on the broken well reads in common: Here resided Anhur's temple.%^RESET%^
MELNMARN
   );

   set_exits(([
	"east":"/d/shadow/virtual/desert/38,16.desert",
	"north":"/d/shadow/virtual/desert/37,15.desert",
	"south":"/d/shadow/virtual/desert/39,15.desert",
    //"temple" : "/d/magic/temples/anhur"
   ]));
   set_smell("default","You smell the scent of palm trees.");
   set_listen("default","You hear the leaves rustling in the breeze.");
   set_items(([
      ({"tree","trees","palm"}): "There are half a dozen of them, "+
         "surrounding the well.  They are in excellent shape.  "+
         "They seem to be getting plenty of water from somewhere.  "+
         "They provide good shade from the sun.",
    //  ({"building","temple","stone building"}) : "The structure "+
    //     "of the building combined with the altar visible through "+
    //     "the glass windows suggest that it may be a temple."
   ]));
   new("/d/shadow/virtual/desert/obj/well")->move(TO);

}
