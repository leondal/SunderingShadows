//Octothorpe (1/8/12)
//Shadow, East Wall Street 3

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
   set_name("East Wall Road");
   set_short("%^BOLD%^%^WHITE%^Intersection of %^BOLD%^%^BLACK%^East "+
      "Wall Road %^BOLD%^%^WHITE%^and %^RESET%^%^RED%^Kathmared "+
      "Road%^BOLD%^%^WHITE%^, Shadow%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Intersection of %^BOLD%^%^BLACK%^East "+
      "Wall Road %^BOLD%^%^WHITE%^and %^RESET%^%^RED%^Kathmared "+
      "Road%^BOLD%^%^WHITE%^, Shadow%^RESET%^\n "+
      "This bustling road travels along the base of %^BOLD%^%^BLACK%^"+
      "Shadow's %^RESET%^defensive wall. The road is wider than those "+
      "found in most large cities in the North, and seems to have "+
      "been designed to more than adequately handle the throngs of "+
      "Shadow's citizenry, or an army on parade. Dark octogonal "+
      "%^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^ne %^RESET%^"+
      "pavers form the surface of the roadway. A multitude of "+
      "%^ORANGE%^wooden %^RESET%^and st%^BOLD%^o%^RESET%^ne buildings "+
      "line the western side of the road, consisting mostly of "+
      "storefronts on the ground floor and apartments reaching up "+
      "a story or two above that. The opposite side of the road is "+
      "dominated by the %^BOLD%^%^BLACK%^dark st%^RESET%^o%^BOLD%^"+
      "%^BLACK%^ne %^RESET%^wall that protects the city.\n");
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
         "A barricade of buildings line the western side of the street. Most "+
         "reach up to two or three stories and contain storefronts in "+
         "the ground floor, with apartments above. The buildings themselves "+
         "are fairly unremarkable and appear to be stereotypical of those "+
         "seen north of the Tsarven Empire.",
      ({"walls","wall","stone wall","dark stone wall"}) : "The sturdy "+
         "defensive wall that surrounds %^BOLD%^%^BLACK%^Shadow %^RESET%^"+
         "is constructed out of %^BOLD%^%^BLACK%^black basalt tuff"+
         "%^RESET%^, which is an unusual building material in the "+
         "region. The wall measures roughly twelve feet thick at its "+
         "base and reaches up to nearly forty feet in height.",
   ]));
   set_exits(([
      "northwest" : ROOMS"eastwall2",
      "southwest" : ROOMS"kathmared3",
      "southeast" : ROOMS"eastwall4",
   ])); 
}
    
void reset(){
   ::reset();
   if(!present("street_light",TO)) new("/d/common/obj/misc/street_light")->move(TO);
   if(!present("guard"))
       new("/d/shadow/city/mon/city_guard")->move(TO);
   if(!present("guard 2"))
       new("/d/shadow/city/mon/city_guard")->move(TO);
   if(!present("guard 3"))
       new("/d/shadow/city/mon/city_guard")->move(TO);
}

