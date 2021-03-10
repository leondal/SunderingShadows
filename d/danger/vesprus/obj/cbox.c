// cherrybox.c

#include <std.h>
#include "../vesprus.h"

inherit "/std/bag_logic";

void create(){
   ::create();
   set_id(({"box","cherry box","box of cherries","brown box","cardboard box","empty box"}));
   set_name("box of cherries");
   set_short("%^RESET%^%^ORANGE%^A small little box%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This is a small little cardboard box whose edges have been stained a light shade of"
" %^RED%^red.  %^ORANGE%^The faint sweet smell of %^BOLD%^%^RED%^cherries %^RESET%^%^ORANGE%^wafts up from within"
" the box. Though it may not be the most sturdy of containers, it seems as though it would be excellent place"
" for you to put all of your fruit.%^RESET%^\n");
   set_weight(2);
   set_max_internal_encumbrance(5);
   switch(random(3)){
      case 0:
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      case 1:
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      case 2:
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      new(VESPRUSOBJS+"cherry")->move(TO);
      break;
   return 1;
   }
}
