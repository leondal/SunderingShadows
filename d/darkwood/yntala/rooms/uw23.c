//uw23
#include <std.h>;
#include "/d/darkwood/yntala/yntala.h"
inherit IHRMS+"underwater.c";
int taken;

void create(){
::create();
   set_long("%^RESET%^%^CYAN%^It is very dark down here as you"
" swim around, and everything seems to close in around you."
" %^BOLD%^%^BLACK%^Cave walls %^RESET%^%^CYAN%^form small passages"
" that you can swim through, but the narrow passageways are"
" difficult to manuever. Large %^BOLD%^%^CYAN%^b%^RESET%^u"
"%^CYAN%^b%^RESET%^b%^CYAN%^l%^RESET%^e%^BOLD%^%^CYAN%^s %^RESET%^"
"%^CYAN%^occassionally come up from small %^BOLD%^%^BLACK%^cracks"
" %^RESET%^%^CYAN%^in the floor and walls of this system, and you"
" cannot help but to think perhaps you should make your way back"
" to the surface.%^RESET%^\n");
   set_items(([
({"crack","cracks"}):"%^ORANGE%^These cracks look a little different than the rest of them, maybe you should take a closer look.%^RESET%^",
"bubbles":"%^BOLD%^%^CYAN%^The bubbles here are much larger than in any of the other rooms. Different images are reflected on the surface of the bubbles, but one in particular catches your eye.",
"bubble":"%^BOLD%^CYAN%^The image of a %^WHITE%^breastplate %^CYAN%^can be seen on it, and you cannot help but wonder if the plate is actually trapped inside.%^RESET%^",
]));
   set_search("crack 1","%^ORANGE%^You notice that this crack is quite large and to the northern end of the room, maybe you can enter it?%^RESET%^");
   set_search("crack","%^ORANGE%^Which crack?  You notice two that are quite large and different than the rest.%^RESET%^");
   set_search("crack 2","%^ORANGE%^This crack is on the southern side of the area, and quite well hidden, maybe you can enter it?%^RESET%^");

}
void init()
{
   ::init();
   add_action("enter","enter");
   add_action("pop","pop");
}
int enter(string str){
   if(str == "crack 1"||str == "the crack"||str == "crack"){
   tell_object(TP,"%^BOLD%^%^BLACK%^You squeeze through the crack.%^RESET%^");
   tell_room(ETP,""+TPQCN+" disappears in a poof of %^BOLD%^%^WHITE%^bubbles!%^RESET%^",TP);
   this_player()->move_player(INRMS+"uw20");
   return 1;
   }
   if(str == "crack 2"){
   tell_object(TP,"%^BOLD%^%^BLACK%^You squeeze through the crack.%^RESET%^");
   tell_room(ETP,""+TPQCN+" disappears in a poof of %^BOLD%^%^WHITE%^bubbles!%^RESET%^",TP);
   this_player()->move_player(INRMS+"hid1");
   return 1;
   }
   if(str == "cracks"){
   tell_object(TP,"%^CYAN%^Now that's an interesting concept, but instead of trying to become numerous little pieces of fish food in order to enter all the cracks, why don't you just try to get through one?");
  return 0;
  }
  tell_object(TP,"%^BOLD%^%^CYAN%^Don't you just want to enter the crack?%^RESET%^");
  return 1;
}
void reset() {
   ::reset();
   if(!present("shark")){
       new(TMONDIR+"shark1.c")->move(TO);
       new(TMONDIR+"shark1.c")->move(TO);
   }
   taken = 1;
}
int pop(string str)
{
   if(present("shark")) {
       write("%^BOLD%^%^CYAN%^The Sharks protect the bubbles!%^RESET%^");
       return 0;
   }
   if(str == "bubble"){
      if(taken <= 0) {               
      tell_object(TP,"%^CYAN%^Hmm... It must have just been a mirage.%^RESET%^");
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
         tell_object(TP,"%^BOLD%^%^WHITE%^As you reach out to pop the %^CYAN%^bubble %^WHITE%^with your finger, a breastplate drops out!%^RESET%^");
         tell_room(TO,"%^BOLD%^%^WHITE%^A breastplate drops out as "+TPQCN+" reaches out and pops the %^CYAN%^bubble!%^RESET%^",TP);
         new(OBJD+"pbreastplate.c")->move(TO);
         taken = 0;
         break;
         case 1..4:
         tell_object(TP,"%^CYAN%^Hmm... It must have just been a mirage.%^RESET%^");
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
