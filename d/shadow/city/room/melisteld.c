//Octothorpe (6/2/16)
//Shadow, Melistel Avenue D (Center Bridge)

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
   set_name("Puente Zincharo");
   set_short("%^BOLD%^Center Span of the Puente Zincharo, Shadow%^RESET%^");
   set_long("%^BOLD%^Center Span of the Puente Zincharo, Shadow%^RESET%^\n "+
      "%^CYAN%^Melistel Avenue %^BOLD%^%^WHITE%^crosses over the center "+
      "span of an impressive stone arch bridge over the %^BOLD%^%^BLUE%^"+
      "Sarcosta River%^WHITE%^. The bridge is wide enough to accomodate "+
      "the normal flow of pedestrians and wagons that %^RESET%^%^CYAN%^"+
      "Melistel Avenue %^BOLD%^%^WHITE%^sees on a typical day, as "+
      "well as the series of four-story buildings that line both "+
      "sides of the bridge on its north and south spans. Both sides "+
      "of this span of the bridge are open allowing a view of the "+
      "river and surrounding area. The sprawling riverfront docks "+
      "and warehouses are visible to the northeast through the forest "+
      "of %^RESET%^%^ORANGE%^ship masts %^BOLD%^%^WHITE%^and rigging. "+
      "Beyond the docks and the harbor %^BOLD%^%^BLACK%^fortifications"+
      "%^WHITE%^, the %^BOLD%^%^BLUE%^Sarcosta %^BOLD%^%^WHITE%^empties "+
      "into %^BLUE%^Shadow Bay%^BOLD%^%^WHITE%^. The bridge continues "+
      "to the north and south. To the north %^RESET%^%^CYAN%^Melistel "+
      "Avenue %^BOLD%^%^WHITE%^gently ascends a hill and eventually "+
      "leads to the center of the city. To the south %^RESET%^%^CYAN%^"+
      "Melistel Avenue %^BOLD%^%^WHITE%^leads toward the city's southern "+
      "gate.%^RESET%^\n");
   set_smell("default","Your nose catches a whiff of unusual scents "+
      "from the shops.");
   set_listen("default","The sound of the flowing river beneath you "+
      "is drowned out by the dull roar of conversations and "+
      "pedestrians and wagons rumbling over the bridge.");
   set_items(([
      ({"bridge","stone arch bridge","stone bridge"}) : "This ancient "+
         "stone bridge dates to the time of the Zin'Charu Empire. It "+
         "is constructed out of a stout light gr%^WHITE%^a%^RESET%^y "+
         "stone, however multiple parts of the bridge bear the same "+
         "type of stone, yet of differing weathering and color. The "+
         "bridge is roughly 400 feet in length, across three arched "+
         "spans. The arches are high enough to accomodate the flat-"+
         "bottomed boats that travel up river to Tabor. A row of "+
         "four-story buildings line both sides of the bridge, "+
         "containing a multitude of shops.",
      ({"riverfront","docks","warehouses", "ships"}) : "Northeast of "+
         "the bridge the riverbank is cluttered with a multitude of "+
         "docks and piers, and accompanying boats and ships of all "+
         "sizes. Close to the piers are many warehouses and "+
         "low-slung %^ORANGE%^wooden %^RESET%^buildings.",
      ({"harbor", "bay", "shadow bay", "Shadow Bay"}) : "A small "+
         "inlet along the northern riverbank of the %^BOLD%^"+
         "%^BLUE%^Sarcosta %^RESET%^serves as a natural "+
         "harbor for %^BOLD%^%^BLACK%^Shadow%^RESET%^. Due to its "+
         "close proximity to %^BLUE%^Shadow Bay %^RESET%^the harbor "+
         "is deep enough to accomodate oceangoing vessels.",
   ]));  
   set_exits(([
      "north" : ROOMS"melistelc",
      "south" : ROOMS"melistele",
   ]));   
}

void reset(){
   ::reset();
   if(!present("street_light",TO)) new("/d/common/obj/misc/street_light")->move(TO);
} 