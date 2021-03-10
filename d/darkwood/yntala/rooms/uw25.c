//uw25
#include <std.h>;
#include "/d/darkwood/yntala/yntala.h"
inherit IHRMS+"underwater.c";
int searched;

void create(){
::create();
   set_long("%^BOLD%^%^BLUE%^You have entered a large and"
" %^YELLOW%^bright %^BLUE%^room whose walls are lined"
" with %^RED%^g%^WHITE%^e%^GREEN%^m%^CYAN%^s. %^BLUE%^The"
" ceiling reaches up to unspeakable heights above you, and the"
" %^CYAN%^w%^RESET%^%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BOLD%^%^CYAN%^r"
" %^BLUE%^here acts much like a %^WHITE%^pr%^CYAN%^i%^WHITE%^sm"
", %^BOLD%^%^CYAN%^reflecting %^BLUE%^the many %^YELLOW%^c"
"%^WHITE%^o%^GREEN%^l%^CYAN%^o%^BLUE%^r%^RED%^s %^BLUE%^of the"
" walls and making the room look as though it were dancing around"
" you. Even the %^BOLD%^%^CYAN%^b%^RESET%^u%^CYAN%^b%^RESET%^"
"b%^CYAN%^l%^RESET%^e%^BOLD%^%^CYAN%^s %^BLUE%^seem to slowly"
" %^WHITE%^bounce %^BLUE%^around the room as if under some %^BOLD%^"
"%^CYAN%^m%^WHITE%^a%^CYAN%^gi%^WHITE%^c%^CYAN%^al %^BLUE%^trance."
"%^RESET%^\n");
   set_exits(([
"south":INRMS+"uw24"
]));
   set_items(([
      "bubbles":"%^BOLD%^%^CYAN%^The %^BOLD%^%^CYAN%^b%^RESET%^u%^CYAN%^b%^RESET%^b%^CYAN%^l%^RESET%^e%^BOLD%^%^CYAN%^s seem to constantly rise around you, reflecting the dazzling %^YELLOW%^c%^WHITE%^o%^GREEN%^l%^CYAN%^o%^BLUE%^r%^MAGENTA%^s %^BOLD%^%^CYAN%^of the room.%^RESET%^",
      "walls":"The walls are lined with %^BOLD%^%^RED%^g%^WHITE%^e%^GREEN%^m%^CYAN%^s.%^RESET%^",
      "gems":"%^YELLOW%^The walls are very bright, as they are lined with several different kinds of %^BOLD%^%^RED%^g%^WHITE%^e%^GREEN%^m%^CYAN%^s, %^YELLOW%^perhaps if you searched you would find some loose ones?",
]));
   set_search("gems", (: TO, "search_gems" :) );
   set_search("walls", (: TO, "search_gems" :) );
}
void reset() {
   if(!present("shalarin")){
      new(TMONDIR+"shalarin.c")->move(TO);
   }
  ::reset();
  if(!random(3))
  searched = 1 ;
}
void search_gems() {
   if(searched <= 0) {               
   tell_object(TP,"%^BOLD%^%^MAGENTA%^It looks like someone has taken all the loose gems already.%^RESET%^");
   return 1;
   }
   if (searched == 1) {  
   write("%^BOLD%^%^BLUE%^%^You found some loose gems!\n");
   tell_room(TO,"%^YELLOW%^"+TPQCN+" searches around and pulls out some loose gems.%^RESET%^",TP);
      switch(random(10)){
         case 0..3:
            new("/d/antioch/valley/obj/gem.c")->move(TO);
            new("/d/antioch/valley/obj/gem.c")->move(TO);
            new("/d/antioch/valley/obj/gem.c")->move(TO);
            new("/d/antioch/valley/obj/gem.c")->move(TO);
          case 4..6:
            new("/d/antioch/valley/obj/gem.c")->move(TO);
            new("/d/antioch/valley/obj/gem.c")->move(TO);
          case 7..9:
            new("/d/antioch/valley/obj/gem.c")->move(TO);
            new("/d/antioch/valley/obj/gem.c")->move(TO);
            break;     
      }
      searched = 0;
      return 1;
   }
}
