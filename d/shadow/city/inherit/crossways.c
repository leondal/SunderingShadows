//Octothorpe (1/5/12)
//Shadow, Crossways Road Inherit

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_climate("temperate");
   set_name("Crossways Avenue");
   set_short("%^MAGENTA%^Crossways Road, Shadow%^RESET%^");
   set_long("%^MAGENTA%^Crossways Road, Shadow%^RESET%^\n "+
      "This diagonal side street travels between the busy main "+
      "thoroughfares through %^BOLD%^%^BLACK%^Shadow%^RESET%^. "+
      "This street is wide enough to accomodate two wagons "+
      "abreast, and has its fair share of citizens trying to "+
      "bypass the city's busy central plaza. Dark octogonal "+
      "%^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^ne "+
      "%^RESET%^pavers form the surface of the roadway. "+
      "A multitude of %^ORANGE%^wooden %^RESET%^and "+
      "st%^BOLD%^o%^RESET%^ne buildings line both sides of the "+
      "avenue, consisting mostly of storefronts on the ground floor "+
      "and apartments reaching up a story or two above that. The "+
      "nearby hill at the center of town provides a constant measure "+
      "of %^BOLD%^%^BLACK%^shade %^RESET%^during most of the day.\n\n");
   set_smell("default","Your nose catches the miasma of thousands "+
      "of humanoids in close proximity.");
   set_listen("default","You hear the dull roar of conversations and "+
      "pedestrians and wagons rumbling down the street.");
   set_items(([
      ({"street","avenue","road","roadway","pavers"}) : "The wide "+
         "street allows for two horse-drawn wagons to travel abreast "+
         "of each other. Thousands of octogonal pavers carved out of a "+
         "fairly mundane dark %^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^"+
         "%^BLACK%^ne %^RESET%^compose the surface of the road. The "+
         "center of the street is crested, with the edges slightly "+
         "graded to provide runoff during inclement weather.",
      ({"buildings","stone buildings","wooden buildings","storefronts"}) : 
         "A barricade of buildings line both sides of the street. Most "+
         "reach up to two or three stories and contain storefronts in "+
         "the ground floor, with apartments above. The buildings themselves "+
         "are fairly unremarkable and appear to be stereotypical of those "+
         "seen north of the Tsarven Empire.",
      "hill" : "The top of the hill at the center of the city is visible "+
         "over the tops of the buildings on the west side of the street."
   ]));   
}      
    
void reset(){
   ::reset();
   if (!present("street_light", TO)) {
       // new("/d/common/obj/misc/street_light")->move(TO);
       new(OBJ+"street_light")->move(TO);// blame jenna
    }
}    