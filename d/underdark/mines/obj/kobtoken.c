//Octothorpe (2/25/09)
//Underdark Mining Caverns, Kobold Quest Identifier

#include <std.h>
#include "../defs.h"
inherit ARMOUR;

void create(){
   ::create();
   set_name("iron signet ring");
   set_id(({"bldscl ring","bloodscale","iron","ring","iron ring","signet","signet ring","bldscl"}));
   set_short("%^RESET%^Ir%^BOLD%^o%^RESET%^n signet ring%^RESET%^");
   set_long("%^RESET%^This is an ir%^BOLD%^o%^RESET%^n signet ring "+
      "bearing a simple, painted %^RED%^red %^RESET%^drop pattern on "+
      "it. The design of the ring is fairly simplistic, it is doubtful "+
      "that this ring would fetch that high of a price.%^RESET%^");
   set_type("ring");
   set_limbs(({"right hand","left hand"}));
   set_ac(0);
   set_weight(1);
   set_value(100);
   set_property("no animate",1);
   set_property("no remove",1);
   set_remove((:TO,"remove_fun":));
}

void init(){
   ::init();
   if(query_worn()){
      return;
   }
   TP->force_me("wear bldscl ring");
}

int drop(){ 
   return 1;
}

int remove_fun(){
   return 0;
}