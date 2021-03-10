//street8 - Circe 11/22/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit AZUL;

void create(){
   ::create();
   set_long(::query_long()+"The stucco wall of a small building stands to "+
      "the south.  A %^BOLD%^light brick chimney %^RESET%^runs along the "+
      "wall, rising over the %^BOLD%^tiled roof%^RESET%^.  Just west "+
      "of here, you see the junction of %^BOLD%^%^BLUE%^Azul Avenue %^RESET%^"+
      "and %^YELLOW%^Sol Boulevard %^RESET%^as well as the large %^ORANGE%^"+
      "oaken gate %^RESET%^reinforced with "+
      "%^BOLD%^%^BLACK%^iron%^RESET%^ that grants entry into the city.  "+
      "Directly north of here is a %^BOLD%^%^BLACK%^guard house %^RESET%^"+
      "built within the wall.\n");
   set_exits(([
      "west" : ROOMS"street7",
      "east" : ROOMS"street9",
//      "north" : ROOMS"guard_house"
   ]));
/*
   set_door("door","/d/attaya/newseneca/rooms/guard_house","north",0,0);
   set_door_description("door","The guard house door is quite thick and "+
      "made of %^ORANGE%^oaken planks%^RESET%^.  Thick %^BOLD%^%^BLACK%^"+
      "iron bands %^RESET%^reinforce the door, helping it repel attackers.");
*/
   add_item("wall","The building to the south is unremarkable, save for the "+
      "%^BOLD%^brick chimney %^RESET%^that rises over the %^BOLD%^tile "+
      "roof%^RESET%^.");
   add_item("building","The building to the south is unremarkable, save for the "+
      "%^BOLD%^brick chimney %^RESET%^that rises over the %^BOLD%^tile "+
      "roof%^RESET%^.");
   add_item("junction","To the west, %^BOLD%^%^BLUE%^Azul Avenue %^RESET%^"+
      "crosses over the wide thoroughfare of %^YELLOW%^Sol Boulevard"+
      "%^RESET%^.");
   add_item("gate","%^ORANGE%^To the north and west, you see a thick "+
      "%^BOLD%^%^BLACK%^iron-bound %^RESET%^%^ORANGE%^oaken gate that "+
      "grants entry to the city.  It has a very small window with "+
      "%^BOLD%^%^BLACK%^iron bars %^RESET%^%^ORANGE%^but is otherwise "+
      "solid.%^RESET%^");
   add_item("guard house","The guard house is known as the %^BOLD%^White "+
      "Dusk%^RESET%^, a quiet jab at the Intruder's Black Dawn.  The guard "+
      "has a saying that the Intruder may make the dawn black, but Seneca "+
      "will win out at dusk.  The building itself is made of %^BOLD%^co"+
      "%^MAGENTA%^q%^WHITE%^ui%^BLACK%^n%^WHITE%^a %^RESET%^like the walls, "+
      "and it has an %^BOLD%^%^BLACK%^iron-bound door%^RESET%^.");
}