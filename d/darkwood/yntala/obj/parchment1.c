#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("%^RESET%^%^ORANGE%^An old piece of paper%^RESET%^");
   set_id(({"parchment","paper","piece of paper"}));
   set_short("%^RESET%^%^ORANGE%^An old and torn piece of parchment%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This is a very old piece of parchment that has been torn from age and exposure. You think you might be able to still make out the writing if you try to read it%^RESET%^.");
   set_weight(0);
   set_read("%^BOLD%^BLUE%^%^Beyond the glade of the horse-men creatures\nAre many hidden secrets for the treasure-seekers. \nFind the place where no land lover would go, \nFor what thy seeks lies deep below.%^RESET%^");
   switch(random(2)) { 
      case 0: 
      set_language("common"); 
      break; 
      case 1:
      set_language("elven");
   }   
}
