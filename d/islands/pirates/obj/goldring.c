#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("ring");
   set_id(({"ring of protection","ring","rop","gold ring","gold ring of protection"}));
   set_short("%^RESET%^%^ORANGE%^Gold Ring of Protection%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^gold ring%^RESET%^");
   set_long("This ring is made from %^ORANGE%^pure gold%^RESET%^, and is quite thick and heavy.  It forms a "
"solid band, perfectly shaped, and unmarked by any damages or engravings.  It seems free of the weaknesses "
"commonly found in golden jewelry, however, and shows a distinctly high quality of crafting.");
   set_lore("%^WHITE%^%^BOLD%^Rings such as these were once quite common, and were regularly crafted and "
"imbued with protective magics by the dwarves of Mt Celestia, purchased by varied races and cities around "
"the realms.  After a particularly devastating attack upon the city there by a hoarde of giants, the dwarves "
"retreated, along with their craft, into the depths of the mountain itself, and the rings became items of "
"the past, only rarely to be found since.%^RESET%^\n");
   set_property("lore difficulty",18);
   set_type("ring");
   set_ac(0);
   set_weight(2);
   set_value(25);
   set_limbs(({"right hand","left hand"}));
   set_property("enchantment",2);
   set_wear((:TO,"do_wear":));
}

int do_wear() {
   object *stuff;
   int i,j, flag;

   stuff = TP->all_armour();
   j = sizeof(stuff);
   for(i=0;i<j;i++) {
     if(!objectp(stuff[i])) continue;
     if((string)stuff[i]->query_type() == "ring") {
       if(member_array("ring of protection",stuff[i]->query_id()) != -1) {
         flag = 1;
         break;
       }
     }
   }
   if(flag) {
     tell_object(TP,"%^WHITE%^%^BOLD%^The magic of the ring already worn prevents you from wearing this one!"
"%^RESET%^");
     return 0;
   }
   return 1;
}
