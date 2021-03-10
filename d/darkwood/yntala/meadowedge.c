#include <std.h>
#include "yntala.h"
inherit ROOM;
int picked;

void create()
{
::create();
   set_property("light",2);
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
   set_name("Edge of the Meadow");
   set_short("%^BOLD%^%^GREEN%^The edge of a meadow%^RESET%^%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^BOLD%^%^GREEN%^The fresh scent of wildflowers floats on the breeze.%^RESET%^");
   set_listen("default","You hear children playing in the background.");
   set_items(([
      ({"tree","trees"}):"%^BOLD%^%^GREEN%^The trees here stop at the edge of the meadow and seem to be very well taken care of.%^RESET%^",
      ({"flowers","wildflowers"}):"%^BOLD%^%^GREEN%^Various types of %^YELLOW%^w%^MAGENTA%^i%^RED%^l%^BLUE%^d%^GREEN%^f%^WHITE%^l%^YELLOW%^o%^MAGENTA%^w%^BLUE%^e%^RED%^r%^YELLOW%^s %^GREEN%^grow wildly on the grasslands of the meadow.%^RESET%^",
      ({"bushes","bush","berry bushes","berries"}):"%^RED%^The berries look like they are well taken care of, and there are several ripe ones on the vines, perhaps you can pick them?%^RESET%^",
      "forest":"%^RESET%^%^GREEN%^The forest comes to an edge here and looks as though the trees lining the edge might even actually be pruned.%^RESET%^",
      "smoke":"%^BOLD%^%^BLACK%^Smoke rises up from somewhere in the center of the meadow.%^RESET%^",
      "thornbushes":"%^RESET%^%^GREEN%^Large %^ORANGE%^thornbushes %^GREEN%^have been planted in the forest surrounding the %^BOLD%^%^GREEN%^meadow.  %^RESET%^%^GREEN%^It looks like they would be very effective at keeping people or things out%^RESET%^", 
      "meadow":"%^BOLD%^%^GREEN%^The meadow is lush and green with several different types of %^YELLOW%^w%^MAGENTA%^i%^RED%^l%^BLUE%^d%^GREEN%^f%^WHITE%^l%^YELLOW%^o%^MAGENTA%^w%^BLUE%^e%^RED%^r%^YELLOW%^s %^GREEN%^adding color to the already magnificent scenery.%^RESET%^",
      "grass":"%^BOLD%^%^GREEN%^The lush green grass her grows to be about one foot tall, and sways gently in the breeze.%^RESET%^",
]));
   set_search("default", "%^RESET%^%^GREEN%^You notice large %^ORANGE%^thornbushes %^GREEN%^in the forest.%^RESET%^");
}
void reset() {
   ::reset();
   if(!present("centaur")){
      switch(random(10)){
         case 0..4:
         break;
         case 5..7:
            new(TMONDIR+"centaur.c")->move(TO);
         break;
         case 8..9:
            new(TMONDIR+"centaur.c")->move(TO);
            new(TMONDIR+"centaur.c")->move(TO);
         break;
      } 
   }

   picked = random(2);
}

void init(){
   ::init();
   add_action("pick", "pick");
}
int pick(string str)
{
   if(!str) {
      tell_object(TP,"Pick what?");
      return 1;
   }
   if(str != "berries" && str != "wildberries") {
      write("You do not see that here.");
   return 1;
   }
   if(picked <= 0) {               
	tell_object(TP,"%^GREEN%^There are no more berries on the vines.%^RESET%^");
   return 1;
   }
   {
   tell_object(TP,"%^GREEN%^You pick a wonderful a juicy handful of %^RESET%^%^RED%^berries.%^RESET%^");
   tell_room(ETP,""+TPQCN+" picks a large handful of %^RED%^berries%^RESET%^.",TP);
   new(OBJD+"wildberries.c")->move(TP);
   picked --;
   return 1;
   }
}
string ldesc(string str){
   return("%^BOLD%^%^GREEN%^The %^RESET%^%^GREEN%^forest %^BOLD%^%^GREEN%^comes to the edge of a peaceful meadow here.  %^BOLD%^%^RED%^B%^RESET%^%^RED%^e%^MAGENTA%^r%^RED%^r%^BOLD%^%^RED%^y %^GREEN%^bushes spill out of the %^RESET%^%^GREEN%^forest %^BOLD%^%^GREEN%^onto the soft grass of the meadow and look like they actually might be cultivated.  %^BOLD%^%^BLACK%^Smoke %^GREEN%^rises from the center of the meadow, away from any trees and you can hear the soft sound of a moving %^BLUE%^brook %^GREEN%^somewhere in the distance.\n");
} 
