#include <std.h>
#include "../gantioch.h"
inherit OBJECT;

create(){
   ::create();
   set_id(({"tee-pee"}));
   set_name("tee-pee");
   set_obvious_short("%^RESET%^%^ORANGE%^A n%^RESET%^%^RED%^a%^RESET%^%^ORANGE%^tive tee-pee");
   set_short("%^RESET%^%^ORANGE%^A n%^RESET%^%^RED%^a%^RESET%^%^ORANGE%^tive tee-pee");
   set_long(
      "%^RESET%^%^ORANGE%^This well-crafted tee-pee has been decorated heavily. All along its sides"+
      "are %^BOLD%^%^YELLOW%^paw prints %^RESET%^%^ORANGE%^and streaks of %^RESET%^%^RED%^blood%^RESET%^%^ORANGE%^."+
      " The entrance has a leather pelt made from %^BOLD%^%^WHITE%^wolf skin %^RESET%^%^ORANGE%^over it to give"+
      "some amount of privacy. Outside of the tee-pee are a pile of bones, obviously recent victims.%^RESET%^"
   );
   set_weight(1000000);
   set_value(1300);
}
   
void init(){
   ::init();
   add_action("enter","enter");
    }
	int enter (string str){
	if(!str) {return 0;}
/*
	if (ETO->query_bound() || EETO->query_unconscious() ||
EETO->query_paralyzed()) {
      ETO->send_paralyzed_message("info",ETO);
	  }
*/
	if(str == "tee-pee"){
   this_player()->move_player("/realms/klieth/greaterantioch/rooms/grassland/teepee1.c");
   return 1;}
}
