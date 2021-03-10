//inherit for Kelemvor's graveyard.  Circe 11/14/04
#include <std.h>
#include "kelemvor.h"

inherit ROOM;

void create(){
   ::create();
   set_name("A well-tended cemetery");
   set_short("%^BOLD%^%^WHITE%^A well-tended cemetery%^RESET%^");
   set_terrain(CEMETERY);
   set_travel(FOOT_PATH);
   set_long((:TO,"long_desc":));
   set_smell("default","The strong earthy scent of the cemetery "+
      "pervades the air.");
   set_listen("default","A serene silence rises on the wind.");
   set_items(([
      ({"grasses","grass"}) : "%^BOLD%^%^GREEN%^The grass here "+
         "is kept cut low, neatly covering the final resting "+
         "place of so many people.  It is soft and a verdant "+
         "green, even in the midst of winter.",
      ({"graves","grave","mounds"}) : "The low, earthy mounds "+
         "seem peaceful rather than creepy as they do in many "+
         "cemeteries.",
      ({"wall","stone wall","ivy"}) : "The low stone wall is "+
         "clearly meant to mark the boundary of the hallowed "+
         "ground, rather than serve as a barrier.  The plentiful "+
         "ivy gives the wall a quaint appearance.",
      ({"headstones","headstones"}) : "The carved headstones are "+
         "made of many materials - the wealthy seem to favor "+
         "marble, while some are even carved on blocks of wood.",
      ({"building","stone building","temple"}) : "The building "+
         "to the north looks to be simple mausoleum.",
      ({"path","pathway","road"}) : "To the south, a narrow dirt "+
         "pathway lined with large river stones meanders toward "+
         "the busier road.  There, travelers to and from the cities "+
         "of Tharis, Azha, and Tabor can be seen."
   ]));
}

string long_desc(){
   return("This quiet %^BOLD%^%^BLACK%^cemetery %^RESET%^is a "+
      "place of serenity and peace.  Low, well-tended %^GREEN%^"+
      "grasses %^RESET%^cover the mounded graves of many who "+
      "have died.  Rows "+
      "and rows of %^BOLD%^headstones%^RESET%^ reveal names of "+
      "many people, both renowned and unknown.  A %^BOLD%^stone "+
      "fence %^RESET%^covered with running %^GREEN%^ivy %^RESET%^"+
      "borders the cemetery, and a small %^BOLD%^stone building "+
      "%^RESET%^resides on the northern end.  A %^ORANGE%^narrow "+
      "pathway %^RESET%^winds down the hillside to a wider road "+
      "to the south.\n");
}