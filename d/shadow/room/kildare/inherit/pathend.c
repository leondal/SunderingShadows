#include <std.h>
#include "../kildare.h"

inherit VAULT;
void create(){
   ::create();
   set_indoors(0);
   set_property("light",1);
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_name("A rocky path");
   set_short("A Rocky Path");
   set_smell("default","You smell the clean air of the mountains.");
   set_listen("default","A strong breeze muffles the sounds around you.");
   set_items(([
      "mountain" : "The gray stone of the mountain gives way to fitfull "+
      "patches of prickly grass in places.  The moutains rise higher above "+
      "this valley all around.  You can see the snowcapped peaks to the north.",
      ({"building","buildings","stone buildings"}) : "Scattered around the "+
      "valley are simple small stone buildings.  They seem to be made of rock "+
      "quarried from the mountain and almost blend in with the gray surroundings.",
      ({"bush","bushes"}) : "No trees grow in this area, but gnarled bushes "+
      "grow close to the ground, clinging to the rock.  The wind seems to have "+
      "misshapen them.",
      ({"trees","tree"}) : "The only trees you see are far in the distance.  "+
      "Evergreens are growing on various peaks around you.",
      ({"path","foot path","footpath"}) : "Despite the rocky surroundings, a "+
      "few faint foot paths have been worn into the mountainside.  Most of them "+
      "seem to lead between buildings and around the village."
   ]));

}
