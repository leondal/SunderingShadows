#include <std.h>
#include "../yntala.h"
inherit ROOM;

void create()
{
::create();

   set_property("light",2);
   set_travel(FOOT_PATH);
   set_terrain(SHORE);
   set_property("no_teleport",1);
   set_name("%^BOLD%^%^GREEN%^The edge of a %^CYAN%^spring%^RESET%^");
   set_short("%^BOLD%^%^GREEN%^At the edge of a spring%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","You smell fresh pine.%^RESET%^");
   set_listen("default","%^RESET%^%^BLUE%^You can hear the sound of %^BOLD%^%^BLUE%^w%^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^r %^RESET%^%^BLUE%^gurgling.%^RESET%^");
   set_items(([
      "forest":"%^RESET%^%^GREEN%^The forest hovers over you.%^RESET%^",
      "bushes":"%^BOLD%^%^GREEN%^The bushes here look amazingly healthy and large.%^RESET%^",
      "ferns":"%^BOLD%^%^GREEN%^The ferns here are very large and could easily hide something beneath them.",
      "spring":"%^BOLD%^%^CYAN%^The spring looks like it is very deep, and you realize that this is the sound that you heard in the meadow rather than a brook... Maybe you might want to take a closer look?%^RESET%^",
      "hole":"%^RESET%^%^CYAN%^The hole here looks like it is very deep, maybe you want to look more closely.%^RESET%^",
      "thornbushes":"%^RESET%^%^ORANGE%^The thornbushes are pretty thick, but you can see the path through them.%^RESET%^",
      "trees":"%^RESET%^%^GREEN%^The trees grow high above you and are covered by many %^BOLD%^%^GREEN%^vi%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^es.%^RESET%^",
      "vines":"%^BOLD%^%^GREEN%^These vi%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^es seem to grow and hang off of everything here.%^RESET%^",
       "forest":"%^GREEN%^The forest here is especially %^BOLD%^%^GREEN%^lush.%^RESET%^",
]));
   set_search("ferns","%^GREEN%^You notice that beneath the %^BOLD%^%^GREEN%^ferns %^RESET%^%^GREEN%^and %^BOLD%^%^GREEN%^bushes, %^RESET%^%^GREEN%^a fairly large %^BOLD%^%^CYAN%^s%^RESET%^%^CYAN%^p%^BLUE%^r%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^g %^RESET%^%^GREEN%^is hidden.%^RESET%^");
   set_search("bushes","%^GREEN%^You notice that beneath the %^BOLD%^%^GREEN%^ferns %^RESET%^%^GREEN%^and %^BOLD%^%^GREEN%^bushes, %^RESET%^%^GREEN%^a fairly large %^BOLD%^%^CYAN%^s%^RESET%^%^CYAN%^p%^BLUE%^r%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^g %^RESET%^%^GREEN%^is hidden.%^RESET%^");
   set_search("spring","%^BOLD%^%^CYAN%^You can see a large %^RESET%^%^CYAN%^hole %^BOLD%^%^CYAN%^at the bottom of the spring.%^RESET%^");
   set_search("hole","%^RESET%^%^CYAN%^As you peer into the hole you realize that you might actually be able to dive into it.%^RESET%^");
   set_exits(([
       "southwest":INRMS+"meadowedge6"
       ]));
}

void init(){
  ::init();
  add_action("dive","dive");
}
int dive(string str){
   if(str == "hole"||str=="into hole"||str=="in"){
   tell_object(TP,"%^RESET%^%^CYAN%^You take a deep breath and dive deep into the spring.%^RESET%^");
   tell_room(TO,""+TPQCN+" takes a deep breath and dives into the spring.",TP);
   this_player()->move_player(INRMS+"uw1");
   return 1;
   }
   write("Dive what?  Dive into hole?");
}
string ldesc(string str){
   return("%^RESET%^%^GREEN%^As you make your way through"
" the %^ORANGE%^thornbushes %^GREEN%^and into this area of the"
" forest, you wonder why the centaurs even have a path leading"
" here.  There is nothing but bushes, trees and ferns all around"
" you, and no apparent way out other than the way you came in."
"%^RESET%^\n");
} 


 
