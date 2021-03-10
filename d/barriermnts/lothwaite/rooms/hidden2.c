#include <std.h>
#include <move.h>
#include "../lothwaite.h"

inherit ROOM;

void create(){
   ::create();
   set_name("A Hidden Alcove");
   set_short("%^BOLD%^%^BLACK%^A Hidden Alcove%^RESET%^");
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_property("light",1);
   set_property("no teleport",1);
   set_property("no sticks",1);
   set_long("%^RESET%^%^BLUE%^This hidden alcove is at the end of a "+
      "crude, narrow %^ORANGE%^tunnel %^BLUE%^that leads back west.  "+
      "A %^RESET%^nest %^BLUE%^of sorts is in the center of the "+
      "room though, strangely, it seems made of %^RESET%^shredded "+
      "metal%^BLUE%^.  The walls have been carved, apparently by "+
      "the claws of some creature or other, to rise in a rough "+
      "arch overhead.  There is not much room in this place, "+
      "leaving it to feel rather claustrophobic.%^RESET%^\n");
   set_items(([
      ({"walls","stone walls","wall","stone"}) : "%^BLUE%^The walls of this "+
         "cavern are rough.  Like the other tunnels, they are "+
         "shot through with %^BOLD%^%^BLACK%^v"+
         "%^YELLOW%^e%^BLACK%^i%^YELLOW%^n%^BLACK%^s %^RESET%^"+
         "%^BLUE%^of %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^and "+
         "%^YELLOW%^gold%^RESET%^%^BLUE%^.  These walls curve "+
         "and are rugged, suggesting that something other than "+
         "the firbolgs dug them.",
      ({"veins","black","gold","veins of black and gold"}) : "%^BLUE%^"+
         "The %^BOLD%^%^BLACK%^dark gray stone %^RESET%^%^BLUE%^ of the "+
         "walls is shot through with web-like %^BOLD%^%^BLACK%^v"+
         "%^YELLOW%^e%^BLACK%^i%^YELLOW%^n%^BLACK%^s %^RESET%^"+
         "%^BLUE%^of %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^and "+
         "%^YELLOW%^gold%^RESET%^%^BLUE%^.  The %^YELLOW%^gold %^RESET%^"+
         "%^BLUE%^looks as though it were melted and poured along the "+
         "walls, while the %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^"+
         "almost looks to be a hidden force trying to break through the "+
         "stone.",
      ({"nest","metal","metal nest"}) : "The center of the room is "+
         "dominated by a small nest woven of shredded metal.  "+
         "Parts of it look to have been melted at one time or "+
         "another, though it appears most of the edges would still "+
         "cut."
   ]));
   set_listen("default","Your footsteps echo loudly down the deserted corridor.");
   set_smell("default","The foul odor of brimstone permeates the air.");
   set_exits(([
      "west" : PATHEXIT"hidden1"
   ]));
}

void reset(){
   ::reset();
   if(!present("devious imp")){
      new(MON"imp")->move(TO);
   }
}