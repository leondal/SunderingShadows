//Octothorpe (1/12/12)
//Shadow, Melistel Avenue B

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
   set_name("Intersection of Melistel Avenue and Dolanco Street");
   set_short("%^BOLD%^Intersection of %^RESET%^%^CYAN%^Melistel "+
      "Avenue %^BOLD%^%^WHITE%^and %^RESET%^%^GREEN%^Dolanco Street"+
      "%^BOLD%^%^WHITE%^, Shadow%^RESET%^");
   set_long("%^BOLD%^Intersection of %^RESET%^%^CYAN%^Melistel "+
      "Avenue %^BOLD%^%^WHITE%^and %^RESET%^%^GREEN%^Dolanco Street"+
      "%^BOLD%^%^WHITE%^, Shadow%^RESET%^\n "+
      "This bustling avenue travels along the north-south axis through "+
      "the center of the %^BOLD%^%^BLACK%^City of Shadow%^RESET%^. "+
      "The avenue is wider than those found in most large cities in "+
      "the North, and seems to have been designed to more than "+
      "adequately handle the throngs of Shadow's citizenry, or an "+
      "army on parade. Dark octogonal %^BOLD%^%^BLACK%^st%^RESET%^"+
      "o%^BOLD%^%^BLACK%^ne %^RESET%^pavers form the surface of the "+
      "roadway. A multitude of %^ORANGE%^wooden %^RESET%^and "+
      "st%^BOLD%^o%^RESET%^ne buildings line both sides of the "+
      "avenue, consisting mostly of storefronts on the ground floor "+
      "and apartments reaching up a story or two above that. The "+
      "avenue gently slopes up a hill toward %^BOLD%^Magistrates' "+
      "Plaza %^RESET%^in the center of the city.\n\n"+
      "The ancient %^BOLD%^Puente Zincharo %^RESET%^crosses over "+
      "the %^BOLD%^%^BLUE%^Sarcosta River %^RESET%^to the south.\n");
   set_smell("default","Your nose catches the miasma of thousands "+
      "of humanoids in close proximity.");
   set_listen("default","You hear the dull roar of conversations and "+
      "pedestrians and wagons rumbling down the street.");
   set_items(([
      ({"street","avenue","road","roadway","pavers"}) : "The wide "+
         "street allows for four horse-drawn wagons to travel abreast "+
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
   ]));
   set_exits(([
      "north" : ROOMS"melistela",
      "south" : ROOMS"melistelc",
      "east" : ROOMS"dolanco1",
   ]));  
}      
    
void reset(){
   ::reset();
   if(!present("street_light",TO)) new("/d/common/obj/misc/street_light")->move(TO);
}