//forest2.c - changed to use CROOM for mob clean-up along with the rooms

#include <std.h>
#include "./forest.h"

inherit CROOM;

void create(){
	::create();
	set_name("Forest Path");
	set_short("A small twisting path through the forest");
	set_property("indoors",0);
	set_property("light",1);
     set_terrain(HEAVY_FOREST);
     set_travel(FOOT_PATH);
	set_long(
@OLI
	%^BOLD%^%^GREEN%^A small twisting path through the forest%^RESET%^
As you enter the forest you notice a quiet all around you. Tall trees
loom over you almost basking in their grandeur.  All around you
sense a horrible feeling of pain.  Nature's work is here but that
work is being hurt.  Small plants grow around the floor of the forest,
fighting for sunshine as it creeps sparsely through the thick canopy.
OLI
	);
   set_items(([
	"floor":"The ground is cluttered with twigs and leaves.",
	"trees":"These grand creatures range from oak and hickory to Pine and spruce."
   ]));
   set_exits(([
   ]));
	set_smell("default","The lush fragrances of the forest quell your worries.");
	set_listen("default","The silence of the forest is unnatural, as if all the insects and birds are hiding.");
   if(base_name(TO) == "/d/tharis/forest/forest_base"){
      set_property("no teleport",1);
   }
//added by Circe to stop people teleporting in.  12/20/04
}

