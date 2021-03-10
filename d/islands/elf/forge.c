#include <std.h>
#include "elf.h"

inherit ROOM;

void create()
{
   ::create();
   set_indoors(1);
   set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("smithy",1); 
   set_name("Sky Forge");
   set_short("%^BOLD%^Sky Forge%^RESET%^");
   set_long(query_short()+"%^GREEN%^\nThis is a stone lean-to built against"+
   " the rock of the cliff.  Against the rock there are several "+
   "tables with anvils mounted on them.  Tools are hung from the"+
   " rock walls.   In the floor an ever-burning fire seems to "+
   "dance with a life of it's own.");
   set_smell("default", "It smells of a mix of thin air and fire.");
   set_listen("default", "The everburning flame roars like a living creature.");
   set_exits(([
      "northeast" : ROOMS"stable",
 
   ]));
   set_items(([
      ({"anvil", "anvils"}): "They are large blocks of metal or stone "+
         "in various shapes to form the metal over.",
      ({"tools", "stones"}): "Small and large hammers, piercing tools, "+
         "vises to clamp the metal in for bending, sharpening stones, "+
         "and other things you probably don't know the names of or what "+
         "they do.",
      "fire" : "%^BOLD%^%^RED%^There seems to be an ever-burning fire in a trench.",
   ]));
}
void reset(){
    ::reset();
    if(!present("illy"))
     new("/d/islands/elf/mon/metal")->move(TO);
}