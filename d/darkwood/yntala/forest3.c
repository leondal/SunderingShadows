#include <std.h>
#include "yntala.h"
inherit ROOM;
int picked;

void create()
{
        ::create();
        set_property("light",2);
        set_terrain(LIGHT_FOREST);
        set_travel(FOOT_PATH);
        set_name("Forest regrowth");
        set_short("%^BOLD%^%^GREEN%^A newgrowth forest%^RESET%^%^");
      set_long((:TO,"ldesc":));
        set_smell("default","%^BOLD%^%^GREEN%^It smells of fresh growth.%^RESET%^");
        set_listen("default","You hear the chatter of various wildlife.");
        set_items(([
        ({"floor","forest floor"}):"%^BOLD%^%^GREEN%^The forest floor here is full of fresh green grass and %^YELLOW%^bright %^MAGENTA%^w%^BLUE%^i%^RED%^l%^YELLOW%^d%^GREEN%^f%^WHITE%^l%^YELLOW%^o%^MAGENTA%^w%^BLUE%^e%^RED%^r%^YELLOW%^s.%^RESET%^",
        ({"tree","trees"}):"%^BOLD%^%^GREEN%^The trees here are nothing more than young saplings, perhaps twenty feet in height each.%^RESET%^",
        ({"flowers","wildflowers"}):"%^BOLD%^%^GREEN%^Various types of %^YELLOW%^w%^MAGENTA%^i%^RED%^l%^BLUE%^d%^GREEN%^f%^WHITE%^l%^YELLOW%^o%^MAGENTA%^w%^BLUE%^e%^RED%^r%^YELLOW%^s %^GREEN%^dapple the forest floor.%^RESET%^", 
]));
}
void reset() {
   object ob;
   ::reset();
    picked = random(2);
}
void init(){
   ::init();
   add_action("pick", "pick");
}
int pick(string str){
   if(!str) {
   tell_object(TP,"Pick what?");
   return 1;
   }
   if(str != "flowers" && str != "wildflowers") {
   write("You do not see that here.");
   return 1;
   }
   if(picked <= 0) {               
   tell_object(TP,"There are no more flowers to pick.");
   return 1;
   }
   {
   tell_object(TP,"%^BOLD%^%^MAGENTA%^You pick a wonderful %^GREEN%^bouquet %^MAGENTA%^of %^YELLOW%^w%^MAGENTA%^i%^RED%^l%^BLUE%^d%^GREEN%^f%^WHITE%^l%^YELLOW%^o%^MAGENTA%^w%^BLUE%^e%^RED%^r%^YELLOW%^s.%^RESET%^");
   tell_room(ETP,""+TPQCN+" picks a lovely %^BOLD%^%^GREEN%^bouquet of %^YELLOW%^w%^MAGENTA%^i%^RED%^l%^BLUE%^d%^GREEN%^f%^WHITE%^l%^YELLOW%^o%^MAGENTA%^w%^BLUE%^e%^RED%^r%^YELLOW%^s.",TP);
      new(OBJD+"wildflowers.c")->move(this_object());
      picked --;
   return 1;
   }
}
string ldesc(string str){
   return("%^RESET%^%^GREEN%^The forest here looks as"
" though it was once %^BOLD%^%^BLACK%^destroyed %^RESET%^"
"%^GREEN%^by some terrible and unknown force.  But through"
" the destruction, new %^BOLD%^%^GREEN%^growth %^RESET%^"
"%^GREEN%^seems to be springing %^RESET%^%^GREEN%^forth.  %^BOLD%^"
"%^GREEN%^Young saplings %^RESET%^%^GREEN%^seem to be everywhere,"
" and the %^BOLD%^%^GREEN%^bright forest floor"
" %^RESET%^%^GREEN%^is %^BOLD%^%^MAGENTA%^d%^YELLOW%^a%^BLUE%^"
"p%^RED%^p%^GREEN%^l%^MAGENTA%^e%^YELLOW%^d %^RESET%^%^GREEN%^"
"with an %^YELLOW%^a%^RESET%^r%^YELLOW%^r%^RESET%^a%^YELLOW%^y"
" %^RESET%^%^GREEN%^of even more %^YELLOW%^brightly "
"%^RESET%^%^GREEN%^colored %^YELLOW%^w%^MAGENTA%^i%^RED%^l"
"%^BLUE%^d%^GREEN%^f%^WHITE%^l%^YELLOW%^o%^MAGENTA%^w%^BLUE%^e"
"%^RED%^r%^YELLOW%^s.%^RESET%^\n");
} 
