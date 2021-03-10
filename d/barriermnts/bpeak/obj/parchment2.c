#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("%^RESET%^%^ORANGE%^An old piece of parchment%^RESET%^");
   set_id(({"parchment","paper","piece of paper"}));
   set_short("%^RESET%^%^ORANGE%^An old and torn piece of parchment%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This is a very old piece of parchment that has been torn from age and looks to be hundreds of years old. You cannot tell exactly how long it has remained hidden from view, but it is written beautifully and surely must tell a story%^RESET%^.");
   set_weight(0);
   set_read("%^BOLD%^%^BLUE%^To whomever reads this paper you are in the debt of my"
" people.  \nA terrible travesty has befallen these peaceful lands within the"
" mountains.  \nLong ago the stories of the strange ones were brought to us by"
" travellers further north.  They talked of dark creatures crawling out of"
" mountainsides, infesting the lands with cruelty and images of their dark goddess."
"  They come now, looking for the riches of our beautiful city.  \nWe've thankfully"
" had time to hide most of our dearest items and hope that the city entrance will"
" remain hidden.  \nShould this scroll get found you can assume the worst... That"
" our city has been found and has fallen to these horrid beasts.  I implore of you,"
" if truly we are gone, avenge the City of Wolves.  \nFind the lairs and kill the"
" dark ones.  \nDo what we could not.%^RESET%^");
   switch(random(2)) { 
      case 0: 
      set_language("common"); 
      break; 
      case 1:
      set_language("elven");
   }   
}
