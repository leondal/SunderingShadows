#include <std.h>
#include "../tormdefs.h"
inherit MARKET;

void create() {
  ::create();
//   set_long(TO->query_long()+" There is a large fountain here.");
   set_long("%^RESET%^%^CYAN%^Torm's marketplace bustles with activity. It is set up along a %^YELLOW%^"
"cobbled square %^RESET%^%^CYAN%^in the center of town with vendors selling their wares from whereever "
"they can find enough room to setup shop. Many people and creatures walk through the %^BOLD%^%^BLUE%^"
"booths %^RESET%^%^CYAN%^and %^MAGENTA%^mats %^CYAN%^laid out with goods, not minding the mixed company "
"at all. Most of the vendors sell mundane items, there are only a few with things of interest for you "
"here. There is a %^BOLD%^%^CYAN%^large fountain %^RESET%^%^CYAN%^here bubbling with everflowing clear "
"water. The fountain is said to have been dedicated to those who fought off the invasion of Shadow and "
"Tonovi upon Torm.%^RESET%^");
  set_exits(([
  "north":TCITY+"c45",
  "east":TCITY+"c57",
  "west":TCITY+"c55",
  "south":TCITY+"c64",
  ]));
  new(OBJ+"fountain")->move(TO);
  set_property("fill waterskin",1);
}
void init(){
  ::init();
  add_action("drink","drink");
  }
int drink(string str){
  if(!str) return 0;
  if(str !="from fountain") return 0;
  if(!TP->add_quenched(50)){
  write("As tempting as the water looks you decide against any right now.");
   return 1;
  }
  write("You take a large drink from the fountain.");
  say(""+TPQCN+" takes a large drink from the fountain and seems to savor the flavor.");
  return 1;
}
void reset() {
  ::reset();
/*  moving the troll to outside the city, just doesn't fit for a troll to be friendly and tame *Styx*  3/23/03


  if(!(query_night())){
  if(!present("troll")) new(MON"troll")->move(TO);
  if(!present("child")) new(MON"child")->move(TO);
  if(!present("child 2")) new(MON"child")->move(TO);
  if(!present("citizen")) new(MON"citizen")->move(TO);
  }
*/
}
