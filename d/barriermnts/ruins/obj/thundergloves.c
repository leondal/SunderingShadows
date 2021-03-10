#include <std.h>
#include <daemons.h>
#include "../inherit/ruins.h"
inherit ARMOUR;

int timer;

void create() {
   ::create();
   set_name("cloudy-gray gloves");
   set_short("%^BLACK%^%^BOLD%^gloves of %^YELLOW%^thu%^WHITE%^n%^YELLOW%^derc%^WHITE%^l%^YELLOW%^ap%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^cloudy-gray gloves%^RESET%^");
   set_id(({"gloves","Gloves","gray gloves","cloudy gloves","cloudy gray gloves","cloudy-gray gloves","gloves of thunderclap","thunder gloves","thunderclap gloves"}));
   set_long("%^CYAN%^%^BOLD%^These gloves are very thin, and cover the hands very comfortably.  The "
"material is a %^BLACK%^dull gray%^CYAN%^ shade, but the colour is imperfect, fading from "
"%^RESET%^%^WHITE%^light%^CYAN%^%^BOLD%^ to %^BLACK%^dark%^CYAN%^ patches across the gloves.  Strangely "
"enough, these patches almost seem to move, and if you watch them long enough, you can see an occasional "
"streak of %^YELLOW%^yellow%^CYAN%^ that dashes across the surface of the garment and vanishes again.  "
"Upon the underside of the gloves are words embroidered in %^WHITE%^white%^CYAN%^ thread.%^RESET%^\n");
   set_weight(4);
   set_value(6340);
   set_ac(0);
   set_size(2);
   set_type("clothing");
   set_limbs(({"right arm","left arm"}));
   set_lore("%^WHITE%^%^BOLD%^The crafting of these gloves is attributed to a certain Lachlan Crenulon, "
"a mage of no small skill.  Despite his primary skills in magecraft being those of abjuration, he was "
"also quite knowledgeable of enchantments.  Captured within these gloves was rumoured to be the power of "
"the storm itself, able to be unleashed upon the wearer's command, although such powers needed a good "
"deal of time to recharge after use.%^RESET%^\n");
   set_property("lore difficulty",15);
   set_read("%^BLACK%^%^BOLD%^Simply think of a %^YELLOW%^<thunderclap>%^BLACK%^ to call forth the "
"gloves' power.%^RESET%^");
   set_language("common");
   set_property("enchantment",0);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

void init() {
   ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
    if(interactive(TP) && !avatarp(TP)) { set_size(TP->query_size()); }
   add_action("thunder_fun","thunderclap");
}

int wear_fun() {
   if((int)ETO->query_lowest_level() < 15) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You need more training to use this item!");
     tell_room(EETO,"%^BOLD%^%^WHITE%^The gloves don't seem to fit "+ETO->QCN+".",ETO);
     return 0;
   }
   tell_object(ETO,"%^BLACK%^%^BOLD%^The cloudy surface of the gloves almost seems to move as you slip them on.%^RESET%^");
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETO->QCN+" slips the cloudy gloves over each hand.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^BLACK%^%^BOLD%^The gloves' patterning becomes still again as you remove "
"them.%^RESET%^");
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETO->QCN+" gently removes the cloudy gloves.%^RESET%^",ETO);
   return 1;
}

int thunder_fun(string str) {
   object *pplz;
   int i;
   pplz = all_living(EETO);
   if(ETO->query_bound() || ETO->query_unconscious()) {
     ETO->send_paralyzed_message("info",ETO);
     return 1;
   }
   if(!query_worn()) {
     write("Wearing the gloves might help.\n");
     return 1;
   } 
   if (!str) {
     if(timer < time()) {
       timer = time() + 86400;
       tell_object(ETO,"%^BLACK%^%^BOLD%^You clap your hands together, and a great peal of thunder "
"shakes the area around you!%^RESET%^\n");
       tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETO->QCN+" claps "+ETO->QP+" hands together, and a great peal "
"of thunder shakes the area around you!%^RESET%^\n",ETO);
       for(i=0;i<sizeof(pplz);i++) {
         if(pplz[i] != ETO && !pplz[i]->query_true_invis() && objectp(pplz[i])) {
           tell_object(pplz[i],"%^BLACK%^%^BOLD%^The force of the thunderclap shakes you from your "
"feet!%^RESET%^\n");
           pplz[i]->set_paralyzed(18,"You are still trying to stand!\n");
         }
       }
       return 1;
     }
     write("The gloves fail to respond.\n");
     return 1;
   }
   write("Concentrate a little more clearly on the gloves - just think of a <thunderclap> to call forth the gloves' power.\n");
   return 1;
}

int isMagic(){
 int i;
 i = ::isMagic();
 i = i + 1;
 return i;
}
