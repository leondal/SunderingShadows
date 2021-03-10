//herb_shop.c - herb and potion store for new Seneca
//sells single-use potions and herbs which have minor 
//effects (mostly RP) - may eventually be incorporated 
//into herbalism/alchemy  ~Circe~ 12/31/07
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_light(2);
   set_name("Mistmoss Herb Shop, Seneca");
   set_short("Mistmoss Herb Shop, Seneca");
   set_long("%^BOLD%^Mistmoss Herb Shop, Seneca%^RESET%^\n"+
      "%^ORANGE%^This humble adobe shop gets it name from the "+
      "soft, %^GREEN%^light green %^ORANGE%^moss that forms in "+
      "the nooks and crannies of the cliffside down near the "+
      "%^CYAN%^seashore%^ORANGE%^.  No shelves or counters "+
      "fill this store - rather the ceiling is alight with "+
      "strings of %^YELLOW%^hemp %^RESET%^%^ORANGE%^that dangle "+
      "and dance overhead, cradling small bundles of %^GREEN%^"+
      "herbs%^ORANGE%^ in various stages of drying.  A small, "+
      "round %^YELLOW%^wooden table %^RESET%^%^ORANGE%^is placed "+
      "in the southwestern portion of the room, just by the door, with "+
      "a rustic three-legged %^YELLOW%^stool %^RESET%^%^ORANGE%^"+
      "beside it.  The tabletop is scattered with several "+
      "%^RESET%^supplies%^ORANGE%^ needed for gathering and "+
      "preserving herbs.  Just to the east of the table along "+
      "the southern wall are %^YELLOW%^wooden crates %^RESET%^"+
      "%^ORANGE%^that hold many small %^CYAN%^vials %^ORANGE%^"+
      "filled with liquids of different colors.  All is in a "+
      "state of readiness so the shopkeeper may put the finishing "+
      "touches on any product when a customer requests it.%^RESET%^\n");
   set_smell("default","The clean scent of the ocean rises on the "+
      "breeze, mingling with the fragrances of many herbs.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"wall","walls","floor","adobe"}) : "%^ORANGE%^The building "+
         "is made from a adobe, the simple mud structure colored a "+
         "light brownish-red as it dried.  The walls are mostly "+
         "smooth, though here and there a depression is revealed.  "+
         "Likewise, the floor is moderately smooth and kept swept "+
         "clean.%^RESET%^",
      ({"ceiling","hemp","strings","strings of hemp","herbs","bundles of herbs"}) : 
         "The adobe ceiling overhead is given a natural decoration "+
         "with the %^ORANGE%^hemp strings %^RESET%^that dangle "+
         "from %^ORANGE%^wooden beams %^RESET%^overhead.  Each "+
         "string is tied around a small bundle of %^GREEN%^herbs"+
         "%^RESET%^, each of which seems to be in a different stage "+
         "of drying.  Many have been left whole, with stems intact, "+
         "while others have already been cut to discard unneeded parts.",
      ({"table","wooden table","round table","stool","rustic stool"}) : 
         "The small table is a rough circle that has been worn "+
         "mostly smooth from work.  The stool was clearly carved "+
         "from the same wood, and both look to have been in use "+
         "for some time.",
      "supplies" : "The supplies scattered across the tabletop "+
         "include knives, scissors, bundles of hemp twine, and "+
         "various other small items.",
      ({"crates","wooden crates","crate","vials"}) : "The wooden "+
         "crates in the southern portion of the room are left "+
         "open, revealing the %^CYAN%^glass vials %^RESET%^they "+
         "hold.  Padding of straw and hay has been packed between "+
         "the vials, likely to protect them."
   ]));
   set_exits(([
      "west" : ROOMS"skyline47"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/skyline47","west",0,0);
   set_door_description("door","This rustic door is made of roughly "+
      "hewn wooden planks.  It has a simple latch that lifts to "+
      "provide entry.");
}

void reset(){
   ::reset();
   if(!present("sayen")) {
      find_object_or_load(MON"sayen")->move(TO);
   }
}