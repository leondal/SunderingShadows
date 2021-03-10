//petals.c - flower petals you can gather and then toss
//for new Seneca by ~Circe~ 1/12/08
#include <std.h>
#include "../seneca.h"

inherit OBJECT;

void create(){
   ::create();
   set_name("bougainvillea petals");
   set_id(({"petals","bougainvillea petals","flower petals","handful of petals"}));
   set_short("%^RESET%^%^GREEN%^a handful of %^ORANGE%^c%^BOLD%^o"+
      "%^RED%^l%^MAGENTA%^o%^YELLOW%^r%^RESET%^%^MAGENTA%^f"+
      "%^BOLD%^u%^RESET%^%^ORANGE%^l %^GREEN%^petals%^RESET%^");
   set_long("%^GREEN%^This small handful of flower petals is "+
      "made up of %^BOLD%^%^MAGENTA%^pi%^WHITE%^n%^MAGENTA%^k"+
      "%^RESET%^%^ORANGE%^, %^BOLD%^%^RED%^scarlet%^RESET%^"+
      "%^GREEN%^, and %^ORANGE%^ora%^YELLOW%^n%^RESET%^%^ORANGE%^ge "+
      "%^GREEN%^bougainvillea blossoms.  They are quite "+
      "pretty and delicate, and you could %^BOLD%^<%^WHITE%^"+
      "toss%^GREEN%^> %^RESET%^%^GREEN%^them in the air "+
      "if you'd like.%^RESET%^");
   set_weight(1);
   set_value(0);
}

void init(){
   ::init();
   add_action("toss_em","toss");
}

int toss_em(string str){
   if(!str) return 0;
   if(!id(str)) return 0;
   if(ETO != TP){
      tell_object(TP,"You need to pick up the petals first.");
      return 1;
   }
   tell_object(TP,"%^BOLD%^You toss a handful of %^RESET%^%^ORANGE%^c%^BOLD%^o"+
      "%^RED%^l%^MAGENTA%^o%^YELLOW%^r%^RESET%^%^MAGENTA%^f"+
      "%^BOLD%^u%^RESET%^%^ORANGE%^l %^BOLD%^%^WHITE%^petals into the air.%^RESET%^");
   tell_room(ETP,"%^BOLD%^"+ETOQCN+" %^BOLD%^%^WHITE%^toss a "+
      "handful of %^RESET%^%^ORANGE%^c%^BOLD%^o"+
      "%^RED%^l%^MAGENTA%^o%^YELLOW%^r%^RESET%^%^MAGENTA%^f"+
      "%^BOLD%^u%^RESET%^%^ORANGE%^l %^BOLD%^%^WHITE%^petals into the air.%^RESET%^",TP);
   tell_room(ETP,"%^BOLD%^%^WHITE%^The petals gracefully cascade "+
      "toward the ground.%^RESET%^");
   new(OBJ"petals_spread")->move(EETO);
   remove();
   return 1;
}