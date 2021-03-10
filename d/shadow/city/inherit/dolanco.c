//Octothorpe (1/22/12)
//Shadow, Dolanco Street Inherit

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
   set_name("Dolanco Street");
   set_short("%^GREEN%^Dolanco Street, Shadow%^RESET%^");
   set_long("%^GREEN%^Dolanco Street, Shadow%^RESET%^\n "+
      "This street leads through the heart of %^BOLD%^%^BLACK%^Shadow's "+
      "%^RESET%^riverfront district, comprised mostly of tenements, "+
      "warehouses, and docks. The street is clogged with stevedores, "+
      "sailors, and the poor, whom seem to go to and fro no matter "+
      "the hour. Dark octogonal %^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^"+
      "%^BLACK%^ne %^RESET%^pavers form the surface of the roadway, "+
      "and are generally smeared with a patina of refuse and %^BOLD%^"+
      "seag%^BOLD%^%^BLACK%^u%^WHITE%^ll %^RESET%^droppings. A variety of "+
      "dilapidated %^ORANGE%^wooden %^RESET%^tenements and warehouses line "+
      "both sides of the street. The road ascends a shallow slope "+
      "to reach the bustling avenues in the center of the city.\n\n");
   set_smell("default","Your nose catches the miasma of thousands "+
      "of humanoids in close proximity.");
   set_listen("default","You hear the squawking of seagulls and "+
      "wagons rumbling down the street.");
   set_items(([
      ({"street","avenue","road","roadway","pavers"}) : "The wide "+
         "street allows for four horse-drawn wagons to travel abreast "+
         "of each other. Thousands of octogonal pavers carved out of a "+
         "fairly mundane dark %^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^"+
         "%^BLACK%^ne %^RESET%^compose the surface of the road. The "+
         "center of the street is crested, with the edges slightly "+
         "graded to provide runoff during inclement weather, however "+
         "the gutters on the sides of the street are thoroughly clogged "+
         "with refuse.",
      ({"buildings","wooden buildings","warehouses","tenements"}) : "A "+
         "barricade of dilapidated wooden buildings line both sides of "+
         "the street. Most reach up to two or three stories and contain "+
         "storefronts in the ground floor, with apartments above. "+
         "Interspersed with the tenements are warehouses where the "+
         "various cargo is stored for import and export.",
   ]));   
}   
    
void reset(){
   ::reset();
   if(!present("street_light",TO)) new("/d/common/obj/misc/street_light")->move(TO);
}