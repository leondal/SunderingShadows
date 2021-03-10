#include <std.h>
#include "../inherit/ruins.h"
inherit ARMOUR;
int wpn_enchant;

void set_wpn_enchant(int x) 
{
	wpn_enchant = x;
}

void create() {
   ::create();
	wpn_enchant = 0;
   set_name("dragon fang hairpin");
   set_short("%^WHITE%^%^BOLD%^Dragon Fang%^RESET%^");
   set_obvious_short("%^WHITE%^%^BOLD%^ivory hairpin%^RESET%^");
   set_id(({"hairpin","pin","Hairpin","Pin","ivory hairpin","dragon fang","Dragon Fang","dragon fang hairpin"}));
   set_long("%^MAGENTA%^This elegant hairpin is crafted from a single piece of "
"%^WHITE%^%^BOLD%^flawless ivory%^RESET%^%^MAGENTA%^.  The handle is shaped to fit "
"comfortably within one's hand, and is carved in an ornate fashion, detailing an intricate "
"image of a coiled dragon, complete with glinting eyes as minute points of "
"%^BLUE%^%^BOLD%^s%^CYAN%^ap%^WHITE%^ph%^CYAN%^ir%^BLUE%^e%^RESET%^%^MAGENTA%^.  A smooth, "
"slender point extends from this handle, to be placed through the hair, though this hairpin "
"seems uncharacteristically sharp - it would be best to be careful when trying to wear "
"it.%^RESET%^\n");
   set_weight(4);
   set_value(1025);
   set_ac(0);
   set_type("clothing");
   set_limbs(({"head"}));
   set_lore("%^WHITE%^%^BOLD%^Originally this was a gift to the bardess Rhiannon Eiryanah, from one of "
"her countless suitors, a magus of considerable reputation.  It was rumoured to have more than just "
"ascetic value, containing hidden enchantments, and some recounts claim Rhiannon was able to use the "
"hairpiece itself as a weapon, when the bardess lacked more effective defenses.%^RESET%^\n");
   set_property("lore difficulty",19);
   set_property("repairtype",({ "jewel" }));
   set_property("enchantment",2);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

void init(){
    ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
    if(interactive(TP) && !avatarp(TP)) { set_size(TP->query_size()); }
    add_action("wield_fun","wield");
}

int wear_fun() {
   if((int)ETO->query_lowest_level() < 15) {
     tell_object(ETO,"%^MAGENTA%^You can't seem to get the hairpin to stay in your hair.%^RESET%^");
     tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" can't seem to keep the hairpin secured in "+ETO->QP+" hair"
".%^RESET%^",ETO);
     return 0;
   }
   tell_object(ETO,"%^MAGENTA%^You twist your hair into place and secure it with the hairpin, careful "
"not to harm yourself on its sharp tip.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" twists "+ETO->QP+" hair into place and secures it carefully "
"with the hairpin.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^MAGENTA%^You slide the hairpin free, letting your hair fall loose again.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" slides the hairpin free, letting "+ETO->QP+" hair fall "
"loose.%^RESET%^",ETO);
   return 1;
}

int wield_fun(string str) {
   object ob,*names;
   int i;
   if (!str) {
     notify_fail("Wield what?");
     return 0;
   }
   if (member_array(str,TO->query_id()) == -1) {
     notify_fail("You can't wield that.\n");
     return 0;
   }
   if (TP != ETO) {
     notify_fail("You should pick that up first.\n");
     return 0;
   }
   if(ETO->query_lowest_level() < 15) {
     notify_fail("You can't make sense of how to wield that.");
     return 0;
   }
   	ob = new(OBJ+"hairpin2.c");
   	ob->move(ETO);

   	if ((int)TO->query_property("enchantment") < 0 && !wpn_enchant) 
	{
    		ob->remove_property("enchantment");
		ob->set("no curse", 1);
     		ob->set_property("enchantment",(int)TO->query_property("enchantment"));
		ob->delete("no curse");
   	}	
   	else 	
	{
		//You can do this without using a loop 
		//just do set("no curse", 1) - Saide
		ob->set("no curse", 1);
		if(wpn_enchant) 
		{
			ob->remove_property("enchantment");
			ob->set_property("enchantment", wpn_enchant);
		}
		else
		{
    			if((int)ob->query_property("enchantment") != 3)
			{
       			ob->remove_property("enchantment");
			      ob->set_property("enchantment",3);
 			}
		}
		ob->delete("no curse");
   	}	
   if (TO->query_identified()) {
     names = TO->query_identified();
     for (i=0;i<sizeof(names);i++) {
       ob->add_identified(names[i]);
     }
   }
   if(TO->query_property("soulbound")) ob->set_property("soulbound",1);
   ETO->force_me("wield hairpin dagger");
   TO->remove();
   return 1;
}