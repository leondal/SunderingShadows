//belt that adds att bonus to wimpy ppl
#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("headband of accuracy");
   set_id(({"headband","Headband","headband of accuracy"}));
   set_short("%^RESET%^headband of accuracy");
   set_obvious_short("%^RESET%^a gray headband");
   set_lore("This headband was created for aging monks.  "+
   "They found that as they got older their combat ability"+
   " diminished.  Not wanting the young and strong to "+
   "rely on it's power, it only accepts the weak.");
   set_property("lore difficulty",15);
   set_long(

"This is a simple gray headband.  It is made from tightly "+
"woven %^ORANGE%^cotton%^RESET%^.  There are several "+
"%^ORANGE%^magical looking marks%^RESET%^ "+
"woven into the fabric.  It looks like something a "+
"samurai or martial artist would use.  There is a single "+
"%^ORANGE%^glowing rune%^RESET%^ on the front of the headband."

   );
   set_limbs(({"head"}));
   set_type("clothing");
   set_size(-1);
   set_weight(5); 
   set_value(500);
   set_property("enchantment",1);
   set_item_bonus("attack bonus",1);
   set_wear((:TO,"wear_me":));
   set_remove((:TO,"remove_me":));
 
}

int wear_me(){
  tell_object(ETO,"You feel more accurate.  "+
   "Like you could strike through your enemies defenses better.");
  return 1;
}
