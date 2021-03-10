#include <std.h>
#include "../yntala.h"
inherit ROOM;
int taken;

void create()
{
::create();
   set_property("light",2);
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
   set_name("Center of the meadow");
   set_short("%^BOLD%^%^GREEN%^The center of a meadow%^RESET%^%^");
   set_long("%^BOLD%^%^GREEN%^This is the center of a large, lush"
" meadow.  %^BLACK%^Smoke %^GREEN%^pours out of a %^RESET%^"
"%^RED%^firepit %^BOLD%^%^GREEN%^that sits here in the center of"
" the area, away from any %^RESET%^%^GREEN%^trees %^BOLD%^"
"%^GREEN%^or other things that may catch fire.  The grass is tall"
" and lush, and various pots sit next to the stacked"
" %^RESET%^%^ORANGE%^firewood %^BOLD%^%^GREEN%^off to the"
" side.%^RESET%^\n");
   set_smell("default","%^RESET%^%^ORANGE%^It smells of smoked fish.%^RESET%^");
   set_listen("default","You hear children playing in the background.");
   set_items(([
      ({"firepit","pit"}):"%^RESET%^A %^RED%^firepit %^RESET%^sits in the center of the area, encircled by large %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^WHITE%^on%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^to contain it. %^BOLD%^%^BLACK%^Smoke %^RESET%^billows out from it, effectively cooking the fish that are turning on the %^BOLD%^%^BLACK%^spit %^RESET%^over the %^RED%^fire.%^RESET%^",
     ({"fish","smoked fish"}):"%^RESET%^Fish are cooking over the %^RED%^fire%^RESET%^. They look like they would taste pretty good, maybe you could take one?",
     "pots":"%^RESET%^%^ORANGE%^Various types of pottery sit next to the stacked firewood. The pots are most likely used to store things.%^RESET%^",
     ({"firewood","wood"}):"%^RESET%^%^ORANGE%^Firewood is stacked neatly to the side and looks as though it is used to tend the %^RED%^fire.%^RESET%^",
     "smoke":"%^BOLD%^%^BLACK%^Smoke rises up from the fire.%^RESET%^",
     "fire":"%^RESET%^%^RED%^The %^BOLD%^%^RED%^flames %^RESET%^%^RED%^dance in the center of the firepit, occassionally jumping up to lick the cooking %^BOLD%^%^BLACK%^f%^RESET%^i%^BOLD%^%^WHITE%^s%^BLACK%^h%^RESET%^.",
]));
   set_exits(([
"north":INRMS+"meadow1",
"south":INRMS+"meadow3",
"east":INRMS+"meadow2",
"west":INRMS+"meadow4",
"northeast":INRMS+"meadowedge6",
"southeast":INRMS+"meadowedge4",
"northwest":INRMS+"meadowedge8",
"southwest":INRMS+"meadowedge2"
]));
}
void reset() {
  ::reset();
  if(!present("female centaur")){
     new(TMONDIR+"centaurcl.c")->move(TO);
  }

  taken = random(2);
}

void init(){
   ::init();
   add_action("take", "take");
}
int take(string str){
   if(!str) {
      tell_object(TP,"Take what?");
      return 1;
   }
   if(str != "fish" && str != "smoked fish") {
      write("You do not see that here.");
      return 1;
   }

   if(taken <= 0) {               
	tell_object(TP,"%^BOLD%^%^BLACK%^There are no more %^RESET%^fish %^BOLD%^%^BLACK%^on the spit.%^RESET%^");
      return 1;
   }
   {
   tell_object(TP,"%^RED%^You burn your hand as you take a %^RESET%^fish %^RED%^from the %^BOLD%^%^BLACK%^pit.%^RESET%^");
   tell_room(ETP,""+TPQCN+" takes a fish from the %^BOLD%^%^BLACK%^spit%^RESET%^.",TP);
   new(OBJD+"smokedfish.c")->move(this_object());
   taken --;
   TP->do_damage("torso",random(6)+3);
   return 1;
   }
}