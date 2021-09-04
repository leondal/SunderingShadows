//underwater.c
#include <std.h>
#include "yntala.h"
inherit IHRMS+"inuw";
int taken;


void create(){
   if(base_name(TO)!= IHRMS+"uw"){
      switch(random(10)){
         case 0..5:
         break;
         case 6..8:
         set_monsters(({TMONDIR +"fish1.c",TMONDIR+"fish2.c",TMONDIR+"fish3.c"}),({1,1,1}));
         set_repop(25);
         break;
         case 9:
         set_monsters(({TMONDIR +"fish1.c",TMONDIR+"fish2.c",TMONDIR+"fish3.c",TMONDIR+"purplefish.c"}),({1,1,1,1}));
      }
   }
          
::create();
   set_property("indoors",1);
   set_property("light",2);
   set_property("no_sticks",1);
   set_property("no teleport",1);
   set_terrain(DEEP_WATER);
   set_travel(FRESH_BLAZE);
   set_name("%^RESET%^%^CYAN%^An underwater labyrinth%^RESET%^");
   set_short("%^RESET%^%^CYAN%^An underwater labyrinth%^RESET%^");
   set_long(ldesc());
   set_smell("default","%^BOLD%^%^CYAN%^You can't smell anything.%^RESET%^");
   set_listen("default","%^RESET%^%^BLUE%^All you can hear is the sound of moving water.%^RESET%^");
   set_items(([
      "bubbles":"%^RESET%^%^CYAN%^A few %^BOLD%^%^CYAN%^b%^RESET%^u%^CYAN%^b%^RESET%^b%^CYAN%^l%^RESET%^e%^BOLD%^%^CYAN%^s %^RESET%^%^CYAN%^come up from the cracks in the cave walls, perhaps you can pop them.%^RESET%^",
      ({"cave walls","walls"}):"%^RESET%^%^ORANGE%^The natural rock formations of the caves make very narrow passageways that are difficult to manuever.%^RESET%^",
      "cracks":"%^BOLD%^%^BLACK%^The cave walls are riddled with cracks.",
]));
}
string ldesc(string str){
   return("%^RESET%^%^CYAN%^It is very dark down here as you"
" swim around, and everything seems to close in around you. "
" %^BOLD%^%^BLACK%^Cave walls %^RESET%^%^CYAN%^form small passages"
" that you can swim through, but the narrow passage ways are"
" difficult to manuever.  %^BOLD%^%^CYAN%^B%^RESET%^u"
"%^CYAN%^b%^RESET%^b%^CYAN%^l%^RESET%^e%^BOLD%^%^CYAN%^s %^RESET%^"
"%^CYAN%^occassionally come up from small %^BOLD%^%^BLACK%^cracks"
" %^RESET%^%^CYAN%^in the floor of this system, and you cannot"
" help but to think perhaps you should make your way back to the"
" surface.%^RESET%^\n");
} 
void init(){
   ::init();
   add_action("pop","pop");
}
void reset() {
   ::reset();
   taken = 1;
}
int pop(string str){
  if(str == "bubble"){
     if(taken <= 0) {               
     tell_object(TP,"%^CYAN%^You reach out and pop a bubble.%^RESET%^");
     tell_room(TO,"%^CYAN%^"+TPQCN+" reaches out and starts"
" popping random %^BOLD%^%^CYAN%^b%^WHITE%^u%^RESET%^b%^BOLD%^"
"%^CYAN%^b%^RESET%^l%^BOLD%^%^WHITE%^e%^CYAN%^s %^RESET%^"
"%^CYAN%^with "+TP->query_possessive()+" fingers. As you watch"
" this, you begin to realize that "+TP->query_subjective()+" must"
" be going crazy as "+TP->query_subjective()+" is clearly seeing"
" things.%^RESET%^",TP);
     return 1;
   }
     if (taken == 1) { 
        switch(random(5)){
        case 0:
        tell_object(TP,"%^BOLD%^%^WHITE%^As you reach out to pop the %^CYAN%^bubble %^WHITE%^with your finger, something drops to the ground!%^RESET%^");
        tell_room(TO,"%^BOLD%^%^WHITE%^Something drops to the ground as "+TPQCN+" reaches out and pops the %^CYAN%^bubble!%^RESET%^",TP);
         new(OBJD+"bring.c")->move(TO);
         taken = 0;
         break;
         case 1..4:
         tell_object(TP,"%^CYAN%^You reach out and pop a bubble.%^RESET%^");
         tell_room(TO,"%^CYAN%^"+TPQCN+" reaches out and starts"
" popping random %^BOLD%^%^CYAN%^b%^WHITE%^u%^RESET%^b%^BOLD%^"
"%^CYAN%^b%^RESET%^l%^BOLD%^%^WHITE%^e%^CYAN%^s %^RESET%^"
"%^CYAN%^with "+TP->query_possessive()+" fingers. As you watch"
" this, you begin to realize that "+TP->query_subjective()+" must"
" be going crazy as "+TP->query_subjective()+" is clearly seeing"
" things.%^RESET%^",TP);
         taken = 0;
         return 1;
         }
      return 1;    
      }
   }
   tell_object(TP,"%^MAGENTA%^Are you really going to drown while you try to pop all of these bubbles, or are you going to just pop the one you want?");
   return 1;
}
