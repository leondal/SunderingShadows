// updated int bonus from the new system. Nienne, 09/07.
#include <std.h>
#include <daemons.h>
#include "../inherit/ruins.h"
inherit ARMOUR;

void create(){
   ::create();
   set_name("silvery circlet");
   set_id(({ "circlet","Circlet","coronet","Coronet","silver circlet","silvery circlet","coronet of illumination","Coronet of Illumination" }));
   set_short("%^WHITE%^%^BOLD%^C%^RESET%^%^WHITE%^o%^BLACK%^%^BOLD%^r%^RESET%^%^WHITE%^o%^WHITE%^%^BOLD%^n%^RESET%^%^WHITE%^e%^BLACK%^%^BOLD%^t %^RESET%^%^WHITE%^o%^WHITE%^%^BOLD%^f %^CYAN%^I%^WHITE%^l%^CYAN%^lu%^WHITE%^m%^CYAN%^in%^WHITE%^a%^CYAN%^ti%^WHITE%^o%^CYAN%^n%^RESET%^");
   set_obvious_short("%^WHITE%^%^BOLD%^s%^RESET%^%^WHITE%^i%^BLACK%^%^BOLD%^l%^RESET%^%^WHITE%^v%^WHITE%^%^BOLD%^e%^RESET%^%^WHITE%^r%^BLACK%^%^BOLD%^y %^RESET%^%^WHITE%^c%^WHITE%^%^BOLD%^i%^RESET%^%^WHITE%^r%^BLACK%^%^BOLD%^c%^RESET%^%^WHITE%^l%^WHITE%^%^BOLD%^e%^RESET%^%^WHITE%^t%^RESET%^");
   set_long("%^MAGENTA%^This circlet is nothing more than a delicate band of %^WHITE%^%^BOLD%^s%^RESET%^"
"%^WHITE%^il%^BOLD%^ve%^RESET%^%^WHITE%^r%^MAGENTA%^, which would rest comfortably atop one's head. The only "
"decoration to the item is near the front, where the band dips forward over the wearer's brow, clasping a "
"single perfect %^WHITE%^%^BOLD%^o%^CYAN%^p%^MAGENTA%^a%^WHITE%^l%^RESET%^%^MAGENTA%^. Despite its plain "
"appearance, it is obviously of very high quality crafting.%^RESET%^\n");
   set_weight(3);
   set_value(4055);
   set_lore("%^WHITE%^%^BOLD%^This circlet matches with tales you have heard of a particular magus "
"of note, Lachlan Crenulon.  While his strengths were in abjuration, he was also a noted enchanter.  "
"This particular circlet was one such enchanted creation, made to assist him in both his spellcraft and "
"his research.%^RESET%^");
   set_property("lore difficulty",17);
   set_type("clothing");
   set_limbs(({ "head" }));
   set_size(2);
   set_ac(0);
   set_property("enchantment",1);
   set_item_bonus("intelligence",1);
   set_item_bonus("sight bonus",2);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_property("repairtype",({ "jewel" }));
}

void init() {
   ::init();
   if(!interactive(ETO)) return;
   if(interactive(TP) && TP == environment(TO)) set_size(TP->query_size());
}

int wear_fun(){
   int modifier;
   if((int)ETO->query_level() < 15) {
     tell_object(ETO,"%^WHITE%^%^BOLD%^You can't make sense of how to use the circlet!%^RESET%^");
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" can't seem to make sense of how to wear the circlet!%^RESET%^",ETO);
     return 0;
   }
   if(member_array(ETO->query_race(),PLAYER_D->night_races()) != -1) modifier = (-2);
   else modifier = 2;
   tell_room(EETO,"%^WHITE%^%^BOLD%^An almost tangible aura flickers into being around "+ETOQCN+" as "
+ETO->QS+" slips the circlet over "+ETO->QP+" brow.%^RESET%^",ETO);
   tell_object(ETO,"%^WHITE%^%^BOLD%^An almost tangible aura flickers into being around you, as your "
"vision becomes startlingly clear.%^RESET%^");
   return 1;
}

int remove_fun(){
   int modifier;
   if(member_array(ETO->query_race(),PLAYER_D->night_races()) != -1) modifier = 2;
   else modifier = (-2);
   tell_room(EETO,"%^WHITE%^%^BOLD%^The near tangible aura fades from around "+ETOQCN+".%^RESET%^",ETO);
   tell_object(ETO,"%^WHITE%^%^BOLD%^The near tangible aura seems to fade from around you, as your "
"vision returns abruptly to normal.%^RESET%^");
   return 1;
}
