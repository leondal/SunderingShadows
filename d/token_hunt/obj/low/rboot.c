// boots of stone coded by hades 6/27/10
#include <std.h>
inherit ARMOUR;
int timer;

void create() {
   ::create();
   set_id(({"boots","leather boots","boots of stone","boot"}));
   set_name("%^RESET%^Boots of %^ORANGE%^Stone");
   set_short("%^RESET%^%^ORANGE%^Rock%^ORANGE%^ covered boots");
   set_obvious_short("%^RESET%^A pair of %^ORANGE%^stone%^RESET%^ boots");
   set_long(
    "%^RESET%^The heavy boots are made with thick %^ORANGE%^leather%^RESET%^ "+
	"that was hardened and boiled to protect the "+
	"wearers feat.  Not only that, but they have "+
	"many %^ORANGE%^brown rocks%^RESET%^ encrusted into the outside.  "+
	"The upper portion is open with several lips that"+
	" also have the strange %^ORANGE%^crafted rock%^RESET%^ melded with "+
	"the leather.  Several holes have been drilled "+
	"into the rock-leather allowing the boots to "+
	"be laced up firmly to the wearer's feet."
   );
   set_lore("The boots of stone were from a batch"+
   " created by a firbolg priest named Gromish.  He"+
   " followed the earth god Grumbar and made these"+
   " boots to better connect his followers to the "+
   "earth.  Not many used them as they were extremely"+
   " heavy and wearing stone encrusted boots tended"+
   " to make one look silly to their peers.  "+
   "You could <stomp> to use them.");
   set_property("lore difficulty",20);
   set_value(0);
   set_type("clothing");
   set_size(-1);
   while ((int)TO->query_property("enchantment") != 1) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",1);
   }
   set_item_bonus("charisma",-1);
   set_ac(0);
   set_weight(10);
   set_limbs(({"right foot","left foot"}));
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
   set_struck((:TO,"strikeme":));
   set_overallStatus(220);
}

int wearme(){
   if((int)ETO->query_level() < 10){
      tell_object(ETO,"The boots are too robust "+
         "for your feet!");
      return 0;
   }
   tell_object(ETO,"%^ORANGE%^You squeeze into the rock covered boots.");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" looks like a fool"+
    " wearing the rock covered boots.",ETO);
   return 1;
}

int unwearme(){
   tell_object(ETO,"%^ORANGE%^The boots come off with a -clunk-");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" removes the boots with a -clunk-",ETO);
   return 1;
}

int strikeme(int damage, object what, object who){
	
    if(!random(10))
    {
        tell_room(environment(query_worn()),"%^ORANGE%^"+
           ""+ETOQCN+"'s boots are struck with a clank.",ETO);
        tell_object(ETO,"%^ORANGE%^When the boots are struck,"+
		" the rocks deflect some of the damage.");
        return 0;
    }
    return damage;
}

void init() {
   ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
   add_action("stomp_fun","stomp");
}

