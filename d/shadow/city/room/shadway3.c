//Octothorpe (1/17/12)
//Shadow, Shadow Way 3 (Bridge)

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
   set_name("Shadow Bridge");
   set_short("%^BOLD%^%^BLACK%^Shadow Bridge, Shadow%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Shadow Bridge, Shadow%^RESET%^\n "+
      "%^BLUE%^Shadow Way %^RESET%^crosses over an impressive "+
      "%^BOLD%^%^BLACK%^black stone %^RESET%^bridge to reach the "+
      "opposite shore of the %^BOLD%^%^BLUE%^Sarcosta River%^RESET%^. "+
      "The bridge is wide enough to accomodate the normal flow of "+
      "pedestrians and wagons that %^BLUE%^Shadow Way %^RESET%^sees "+
      "on a typical day. Unlike its sister bridge, the %^BOLD%^Puente "+
      "Zincharo%^RESET%^, this bridge is devoid of buildings and shops, "+
      "allowing a clear view of the surrounding area. South of the "+
      "bridge on the bank of the %^BOLD%^%^BLUE%^Sarcosta%^RESET%^, "+
      "the various estates and compounds of %^BOLD%^%^BLACK%^Shadow's "+
      "%^RESET%^elite stand haughtily over the river. East of the "+
      "bridge %^BLUE%^Shadow Way %^RESET%^gently ascends a hill and "+
      "eventually leads to the center of the city.%^RESET%^\n");
   set_smell("default","Your nose catches the miasma of thousands "+
      "of humanoids in close proximity.");
   set_listen("default","The sound of the flowing river beneath you "+
      "is drowned out by the dull roar of conversations and "+
      "pedestrians and wagons rumbling over the bridge.");
   set_items(([
      ({"bridge","stone arch bridge","stone bridge"}) : "This bridge "+
         "is fashioned out of the same %^BOLD%^%^BLACK%^black basalt tuff "+
         "%^RESET%^that the city's walls are made out of. The "+
         "bridge is roughly 400 feet in length, and is high enough "+
         "to accomodate the flat-bottomed boats that travel up river "+
         "to Tabor.",
      ({"estates","compounds"}) : "The southern bank of the river is "+
         "obviously where the upper crust of %^BOLD%^%^BLACK%^Shadow "+
         "%^RESET%^makes its home. Consisting mostly of walled "+
         "compounds that sit high enough on berms to keep out any "+
         "riffraff from the river, as well as any seasonal flooding.",
   ]));  
   set_exits(([
      "west" : ROOMS"shadway4",
      "east" : ROOMS"shadway2",
   ]));   
}

void reset(){
   ::reset();
   if(!present("street_light",TO)) new("/d/common/obj/misc/street_light")->move(TO);
} 