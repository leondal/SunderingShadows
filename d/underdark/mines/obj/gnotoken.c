//Octothorpe (2/25/09)
//Underdark Mining Caverns, Gnome Quest Identifier

#include <std.h>
#include "../defs.h"
inherit ARMOUR;

void create(){
   ::create();
   set_name("gold signet ring");
   set_id(({"gldstr ring","goldstar","gold","gold star","star","ring","star ring","gold ring","signet","signet ring","gldstr"}));
   set_short("%^YELLOW%^A g%^ORANGE%^o%^YELLOW%^lden signet ring%^RESET%^");
   set_long("%^YELLOW%^This is a g%^ORANGE%^o%^YELLOW%^lden signet ring "+
      "bearing a simple star pattern on it.  Although it is crafted "+
      "from g%^ORANGE%^o%^YELLOW%^ld, the design is fairly simplistic, "+
      "and it is doubtful that this ring would fetch that high of a "+
      "price.%^RESET%^");
   set_type("ring");
   set_limbs(({"right hand","left hand"}));
   set_ac(0);
   set_weight(1);
   set_value(100);
   set_property("no animate",1);
   set_property("no remove",1);
   set_property("no offer",1);
   set_remove((:TO,"remove_fun":));
}

void init(){
   ::init();
   if(query_worn()){
      return;
   }
   TP->force_me("wear gldstr ring");
}

int drop(){ 
   return 1;
}

int remove_fun(){
   return 0;
}