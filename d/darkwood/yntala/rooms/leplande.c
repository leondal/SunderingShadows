//leplande
#include <std.h>
#include "../yntala.h"
inherit CROOM;

void create(){
   switch(random(11)){
      case 0..5:
         set_monsters(({TMONDIR +"lep2.c"}),({1}));
      break;
      case 6..10:
         set_monsters(({TMONDIR +"lep2.c"}),({2}));
   }
   set_repop(30);
::create();
   set_property("outdoors",0);
   set_property("light",3);
   set_property("no_teleport",1);
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
   set_name("The other end of the rainbow");
   set_short("%^YELLOW%^A very bright room%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^BOLD%^%^GREEN%^You smell nothing but spring grass.%^RESET%^");
   set_listen("default","You don't hear anything.");
   set_items(([
      "rainbow":"%^YELLOW%^This is a very pretty and bright %^MAGENTA%^r%^RED%^a%^BLUE%^i%^YELLOW%^n%^GREEN%^b%^RED%^o%^CYAN%^w %^YELLOW%^west of here.  It is quite a bit larger than any other you've seen before, and its %^MAGENTA%^radiance %^YELLOW%^encompasses the entire area.%^RESET%^",
      "clovers":"%^BOLD%^%^GREEN%^That's strange, every single clover here is a four-leaf clover.",
      ({"bunnies","bunny","rabbit"}):"%^BOLD%^%^WHITE%^These cute and playful bunnies have floppy ears, fluffy tails and are pure white.  They playfully hop around the base of the rainbow and throughout the rolling green hills.%^RESET%^",
]));
   set_exits((["west":INRMS+"lepland","northwest":INRMS+"leplandn","southwest":INRMS+"leplands"]));
}
string ldesc(string str){
   return("%^BOLD%^%^GREEN%^This place is very large, bright and cheery, there is no sign of the portal that got"
" you here though...  Nevertheless, that is the least of your worries, for this is an endless area filled with rolling"
" green hills covered in fresh spring grass and clovers.  A large rainbow ends west of here and"
" the atmosphere is one of pure bliss.  Playful little bunnies happily bounce around the area without a care in"
" the world.%^RESET%^\n");
} 

