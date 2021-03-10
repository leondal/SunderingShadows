//sr1.c
#include <std.h>
#include "../koenig.h"
inherit ROOM;

void create(){

::create();
  set_property("indoors",1);
  set_property("light",1);
  set_travel(RUBBLE);
  set_terrain(ROCKY);
  set_name("A dank hole");
  set_short("%^RESET%^%^BLUE%^%^The bottom of a  %^BOLD%^%^BLACK%^dark %^RESET%^%^BLUE%^hole%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This is the bottom of the hole you"
" found. The walls are carved out of sharp and craggy rock,"
" climbing straight into the room above. %^RESET%^Shackles"
" %^BOLD%^%^BLACK%^are affixed to the walls, but they look"
" %^RESET%^%^ORANGE%^rusty %^BOLD%^%^BLACK%^and unused."
" %^RESET%^%^RED%^Blood %^BOLD%^%^BLACK%^is splattered all over"
" the floor, indicating that perhaps the victims down here just"
" get thrown down the hole without a care as to how they fair"
" once they hit bottom. A few %^RESET%^skeletons %^BOLD%^"
"%^BLACK%^are scattered in crumpled heaps.%^RESET%^\n");
  set_smell("default","It smells like something is rotting.%^RESET%^");
  set_listen("default","Moans of poor slaves echo through the room.");
  set_items(([
     ({"floor","cave floor"}):"%^BOLD%^%^BLACK%^The floor here is rocky and uneven, and littered with skeletons.%^RESET%^",
     ({"blood","dried blood"}):"%^RESET%^%^RED%^Dried blood can be seen splattered all over the floor.%^RESET%^",
      ({"walls","cave walls"}):"%^RESET%^%^BLUE%^The walls of this room are sharp and jagged, making it nearly impossible to climb out.",
      "skeletons":"%^RESET%^A few skeletons lay in crumpled heaps on the floor, apparently not everyone survives the fall...",
      "shackles":"%^RESET%^%^ORANGE%^These line the walls and look like they might have at one time been used to hold prisoners, but by the way they are rusted now, it appears that whoever use to use them no longer cares whether their prisoners are shackled or not.%^RESET%^",
]));
   set_climb_exits(([
"climb":({INRMS+"tr1",10,4,100})
]));
   switch(random(3)){
      case 0:
      new(TMONDIR+"kobold1.c")->move(TO);
      new(TMONDIR+"kobold1.c")->move(TO);
      case 1:
      new(TMONDIR+"kobold1.c")->move(TO);  
      case 2: 
      new(TMONDIR+"kobold1.c")->move(TO);          
      break;
   } 
}
