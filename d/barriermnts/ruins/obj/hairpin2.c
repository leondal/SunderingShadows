#include <std.h>
#include "../inherit/ruins.h"
inherit "/d/common/obj/weapon/dagger.c";

object ob,*names;
int i;

void create() {
   ::create();
   set_id(({"hairpin","pin","Hairpin","Pin","ivory hairpin","dagger","Dagger","ivory dagger","dragon fang","Dragon Fang","hairpin dagger","dragon fang dagger"}));
   set_name("dragon fang dagger");
   set_obvious_short("%^WHITE%^%^BOLD%^ivory hairpin%^RESET%^");
   set_short("%^WHITE%^%^BOLD%^Dragon Fang%^RESET%^");
   set_long("%^MAGENTA%^This elegant hairpin is crafted from a single piece of "
"%^WHITE%^%^BOLD%^flawless ivory%^RESET%^%^MAGENTA%^.  The handle is shaped to fit "
"comfortably within one's hand, and is carved in an ornate fashion, detailing an intricate "
"image of a coiled dragon, complete with glinting eyes as minute points of "
"%^BLUE%^%^BOLD%^s%^CYAN%^ap%^WHITE%^ph%^CYAN%^ir%^BLUE%^e%^RESET%^%^MAGENTA%^.  A smooth, "
"slender point extends from this handle, to be placed through the hair, though this hairpin "
"seems uncharacteristically sharp - you could probably use it as quite an effective "
"weapon.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Originally a gift to the bardess Rhiannon Eiryanah, from one of her countless suitors, a magus of considerable reputation.  It was rumoured to have more than just ascetic value, containing hidden enchantments, and some recounts claim Rhiannon was able to use the hairpiece itself as a weapon, when the bardess lacked more effective defenses.%^RESET%^\n");
   set_property("lore difficulty",19);
   set_weight(4);
   set_property("enchantment",3);
   set_value(1025);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
}

int wield_fun() {
   if(!ETO->query_invis()) {
     tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" grasps the smooth-handled hairpin in one hand... suddenly the "
"sharpened point of the hairpiece looks a good deal more dangerous!%^RESET%^",ETO);
   }
   tell_object(ETO,"%^MAGENTA%^You grasp the smooth-handled hairpin within your hand, realising the "
"sharpened point would be quite an effective weapon!%^RESET%^");
   return 1;
}

int unwield_fun() {
   tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" releases "+ETO->QP+" grip on the sharpened "
"hairpin.%^RESET%^",ETO);
   tell_object(ETO,"%^MAGENTA%^You release your grip on the sharpened hairpin.%^RESET%^");
   return 1;
}

void __ActuallyUnwield() {
   ::__ActuallyUnwield();
   	ob = new(OBJ+"hairpin.c");
   	ob->move(ETO);
	if((int)TO->query_property("enchantment") != 3) 
	{
		ob->set_wpn_enchant((int)TO->query_property("enchantment"));
	}
   	if((int)ob->query_property("enchantment") != 2) 
	{
		ob->set("no curse", 1);
    		ob->remove_property("enchantment");
     		ob->set_property("enchantment",2);
		ob->delete("no curse");
   	}
   if (TO->query_identified()) {
     names = TO->query_identified();
     for (i=0;i<sizeof(names);i++) {
       ob->add_identified(names[i]);
     }
   }
   if(TO->query_property("soulbound")) ob->set_property("soulbound",1);
   TO->remove();
}

int hit_fun(object target) {
   if(!random(5)) {
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" stabs at "+target->QCN+" with the sharpened point of "
"the hairpin!%^RESET%^",({ETO,target}));
     tell_object(ETO,"%^WHITE%^%^BOLD%^You quickly stab at "+target->QCN+" with the sharpened point of "
"the hairpin!%^RESET%^");
     tell_object(target,"%^WHITE%^%^BOLD%^"+ETOQCN+" stabs quickly at you with the sharpened point of "
"the hairpin!%^RESET%^");
     target->do_damage(target->return_target_limb(),roll_dice(1,6)+2);
   }
}
