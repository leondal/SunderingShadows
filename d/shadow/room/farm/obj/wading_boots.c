#include <std.h>
inherit ARMOUR;

int wading;

void create(){
	::create();
	set_name("wading boots");
	set_id(({"boots","black boots","shoes","leather boots","hip-high leather boots","wading boots","gnomish wading boots"}));
      set_obvious_short("hip-high leather boots");
	set_short("%^BLACK%^%^BOLD%^Gnomish Wading Boots%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This leather boots are made to "+
	   "reach hip-high on a person of approximately gnomish "+
	   "size.  The black leather has been weather-proofed and "+
	   "polished to a high shine.  The toes are perfectly smooth, "+
	   "while each of the tops has been fitted with a %^RESET%^"+
	   "silver buckle %^BOLD%^%^BLACK%^that would allow them to "+
         "be drawn tight.  Looking closely, you see that a message "+
         "has been inscribed just inside the top of the right "+
         "boot next to a small pull tab.%^RESET%^");
      set_read("For a water experience, be sure to <wade>!");
	set_lore("These Gnomish Wading Boots were crafted "+
	   "exclusively by Piaf Huffelmuffin for his own "+
	   "personal use.  The gnome enjoyed spending time "+
	   "sifting through the sand for hidden treasures, and "+
	   "he claimed there were no boots like these!  Many "+
	   "people feel their function is...unusual at best.  "+
	   "But Piaf loved the feel of wading in the stream so "+
	   "much, he decided to create these boots to take that "+
	   "feeling of wading with him anywhere he went.  An Observation"+
	   " of Piaf - Theadora Illonium");
	set_size(1);
      set_ac(0);
	set_weight(10);
	set_value(50);
	set_type("clothing");
	set_limbs(({"right foot","left foot"}));
	set_wear((:TO, "wearme":));
	set_remove((:TO, "removeme":));
	wading = 0;
}

int wearme(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^You slip into the hip-high boots "+
      "and cinch the %^RESET%^silver buckles%^BOLD%^%^BLACK%^.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" pulls on the hip-high "+
      "boots and cinches the buckles.",ETO);
   return 1;
}

int removeme(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^You undo the %^RESET%^silver "+
      "buckles %^BOLD%^%^BLACK%^and slide your feet out of the boots.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" undoes the buckles "+
      "and slips "+ETO->QP+" feet out of the boots.",ETO);
   if(wading){
      tell_room(EETO,"%^BOLD%^%^BLUE%^Water comes gushing out of "+
         "the boots!");
      wading = 0;
   }
   return 1;
}

void init(){
   ::init();
   add_action("wade","wade");
}

int wade(string str){
   if(!query_worn()){
      tell_object(ETO,"You must be wearing the boots to wade.");
      return 1;
   }
   if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed()
|| ETO->query_tripped()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(str){
      tell_object(ETO,"Simply <wade> to experience all the boots "+
         "have to offer.");
      return 1;
   }
   if(wading){
      tell_object(ETO,"Your feet are already soaking!");
      return 1;
   }
   tell_object(ETO,"%^BOLD%^%^BLUE%^You pull the tab on the boots "+
      "and wait for a moment.");
   tell_object(ETO,"%^BOLD%^%^CYAN%^Suddenly, the boots fill with "+
      "water, giving your feet the sensation of wading through a "+
      "stream!  Delightful! (if you like wet feet...)");
   tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+" pulls a tab on "+
      ""+ETO->QP+" boots and a squishing sound fills the air.",ETO);
   wading = 1;
   return 1;
}