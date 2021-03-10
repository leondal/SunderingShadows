//tunnel.c - tunnels for Kildare Glen expansion ~Circe~ 6/6/07
#include <std.h>
#include "../kildare.h"

inherit CROOM;
object ob;

void create(){
   switch(random(20)) {
      case 0: break;
      case 1..3: set_monsters( ({MON"aberration"}),({2+random(2)}));
              break;
      case 4..6: set_monsters( ({MON"aberration"}),({random(3)+1}));
              break;
      case 7..8: set_monsters( ({MON"aberration",MON"aberrationthief"}),({random(2),1+random(2)}));
              break;
      case 9..11: set_monsters( ({MON"aberrationthief"}),({1}));
              break;
      case 12:  set_monsters( ({MON"cloaker"}),({1}));
              break;
      case 13..14:  set_monsters( ({MON"ooze"}),({1}));
              break;
      default:  break;
   }
   ::create();
   set_repop(35);
   set_indoors(1);
   set_property("light",-2);
   set_terrain(BUILT_TUNNEL);
   set_travel(RUTTED_TRACK);
      set_property("no teleport",1);
   set_name("A roughly carved tunnel");
   set_short("%^BOLD%^%^BLACK%^A roughly carved tunnel%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This roughly-hewn tunnel winds its "+
      "way through the mountainside.  The %^RESET%^walls %^BOLD%^"+
      "%^BLACK%^are uneven and covered with small %^RESET%^"+
      "%^BLUE%^depressions %^BOLD%^%^BLACK%^and %^RESET%^raised "+
      "places %^BOLD%^%^BLACK%^just sharp enough to cut anyone who "+
      "unwittingly brushes against them.  The twistings and turnings "+
      "of the cavern combine with the %^RESET%^%^BLUE%^darkness "+
      "%^BOLD%^%^BLACK%^to make it difficult for most to see far.  "+
      "Each step here is treacherous, thanks to the still-drying "+
      "%^WHITE%^bird droppings %^BLACK%^littering the floor.  "+
      "Walking through here disturbs countless %^GREEN%^f%^BLACK%^e"+
      "%^GREEN%^a%^BLACK%^t%^GREEN%^h%^BLACK%^e%^GREEN%^r%^BLACK%^s "+
      "and %^RESET%^%^RED%^small animal carcasses%^BOLD%^%^BLACK%^.\n");
   set_smell("default","The filthy stench of animal and bird droppings is almost overwhelming.");
   set_listen("default","Every noise reverberates through the tunnels.");
   set_items(([
      ({"feathers","green feathers","green-black feathers"}) : "%^GREEN%^Large, "+
         "soft feathers of a green so deep they are nearly black line the "+
         "floor several inches deep.  Several of the feathers "+
         "are soft and downy, probably belonging to the beastial bird's young.",
      ({"droppings","bird droppings"}) : "Disgusting white bird droppings "+
         "tinged with black are streaked down the walls.  Several small puddles "+
         "have formed on the floor as well.  Given the amount of droppings "+
         "and the size of the nest, either the bird that lives here is the "+
         "size of a dragon or several of the same type of creature live here.",
      ({"depressions","raised places","wall","walls"}) : "The depressions and corresponding "+
         "raised places form mock mountains and valleys all along the "+
         "walls.  The wall seems to lie in wait for some hapless person to "+
         "brush against it.",
      ({"carcass","carcasses","small animal carcasses"}) : "The floor "+
         "is littered with the half-decayed carcasses of small animals "+
         "hidden among the feathers.  Most seem to be rodents of some "+
         "sort and few are little more than bones."
   ]));
   set_property("no peer",1);
}
