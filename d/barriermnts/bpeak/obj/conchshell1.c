#include <std.h>
#include "../bpeak.h"
inherit OBJECT;

void create()
{
   ::create();
      set_name("%^RESET%^%^ORANGE%^C%^RESET%^o%^BOLD%^%^WHITE%^n%^RESET%^%^ORANGE%^c%^RESET%^h s%^BOLD%^%^WHITE%^h%^BLACK%^e%^RESET%^l%^BOLD%^%^WHITE%^l%^RESET%^");
      set_id(({"shell","conch shell","conchshell","Shell","Conch Shell","Conch shell","Conchshell","seashell"}));    
      set_short("%^RESET%^%^ORANGE%^C%^RESET%^o%^BOLD%^%^WHITE%^n%^RESET%^%^ORANGE%^c%^RESET%^h s%^BOLD%^%^WHITE%^h%^BLACK%^e%^RESET%^l%^BOLD%^%^WHITE%^l%^RESET%^");
      set_long("%^BOLD%^%^WHITE%^This attractive shell is fairly large at nearly five"
" inches in length and is rolled like the typical %^RESET%^%^ORANGE%^c%^BOLD%^"
"%^WHITE%^o%^RESET%^n%^ORANGE%^c%^RESET%^h %^BOLD%^%^WHITE%^with one end pointed"
" and spiked.  The roll fans out into even more small spikes that help keep it"
" setting flat when put down.  The outer part of the shell is a %^RESET%^"
"%^ORANGE%^darker o%^YELLOW%^r%^RESET%^%^ORANGE%^a%^YELLOW%^n%^RESET%^%^ORANGE%^ge"
" %^BOLD%^%^WHITE%^in color with the spikes ending in a %^RESET%^%^ORANGE%^deep"
" brown, %^BOLD%^%^WHITE%^while the inside of the shell is smooth in texture and"
" a lighter shade of %^MAGENTA%^c%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^r"
"%^RESET%^%^ORANGE%^a%^BOLD%^%^MAGENTA%^l.\n"
"%^WHITE%^It is said that if you listen to these shells, one can hear the sounds"
" of the ocean.%^RESET%^\n");
      set_weight(2);
      set_value(25);
}
void init(){
  ::init();
  add_action("listen","listen");
}
int listen(string str){
   if(str == "shell" || str == "conch" || str == "conchshell" || str == "to shell" || str == "to conch" || str == "to conchshell"){
   tell_object(TP,"%^RESET%^%^CYAN%^As you hold the %^RESET%^s%^BOLD%^%^WHITE%^h"
"%^BLACK%^e%^RESET%^l%^BOLD%^%^WHITE%^l %^RESET%^%^CYAN%^up to your ear, you can"
" hear the sounds of the ocean echoing from within its depths.  Even more faintly"
" you can hear a strange but beautiful voice singing a haunting tune that seems to"
" be calling out to you.%^RESET%^");
   tell_room(ETP,"%^RESET%^%^CYAN%^A strange look crosses "+TPQCN+"'s face as "+TP->query_subjective()+" holds the shell up to "+TP->query_possessive()+" ear.%^RESET%^",TP);
   return 1;
   }
}
