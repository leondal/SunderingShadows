#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/weapon/dagger.c";

void create()
{
	::create();
	set_name("sea dagger");
	set_id(({"dagger","sprite dagger","tiny dagger","nixie dagger","sea roar dagger","coral dagger"}));
	set_short("%^BOLD%^%^BLUE%^S%^RESET%^%^BLUE%^e%^CYAN%^a"+
		" %^BOLD%^R%^BLUE%^o%^RESET%^%^CYAN%^a%^BLUE%^r dagger%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A %^WHITE%^white coral%^BLUE%^"+
			" handle dagger%^RESET%^");
	set_long("%^CYAN%^This curved %^BOLD%^%^BLUE%^metal dagger%^RESET%^"+
		" %^CYAN%^is forged from a pale %^BOLD%^%^WHITE%^silver%^RESET%^"+
		"%^CYAN%^ metal. Swirling along the length of the blade is "+
		"ripples of %^BOLD%^%^BLUE%^b%^CYAN%^l%^RESET%^%^BLUE%^u%^CYAN%^e"+
		", giving the dagger a watery appearance.  Lengths of "+
		"%^BOLD%^%^WHITE%^white coral%^RESET%^%^CYAN%^ encircle the "+
		"lower part of the blade and create the pommel of this dagger."+
		"  Embedded into the pommel are tiny %^BOLD%^%^WHITE%^pearls%^RESET%^%^CYAN%^.");
	set_lore("The Sea Roar Dagger is crafted by the nixies to use in"+
		" defense against the threats of the forest around their "+
		"waterfall in the Moonstone Valley.  The creation of each "+
		"dagger is said to take three months, for the nixie "+
		"priestesses imbue the strength of the sea into each one.  "+
		"The daggers among the faith of Istishia are seens a lucky "+
		"relics to carry with them, for they feel its like having a "+
		"piece of the sea with you where ever you go.  Needless to say"+
		" the follower of Kossuth abhor the daggers and wish nothing "+
		"more to melt them all.");
	set_property("lore",11);
	//set_size(1);
	set_type("piercing");
	//set_weight3);
	//set_wc(1,4);
	//set_large_wc(1,3);
	set_value(400);
	set_property("enchantment",2+random(2));
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
	set_hit((:TO,"hitme":));

}
int wieldme(){
	if((string)ETO->query_diety() == "kossuth") {
      	tell_object(ETO,"%^CYAN%^Wield this dagger?!? Have you gone mad?");
      return 0;
   	}
   	if((string)ETO->query_diety() == "istishia") {
      	tell_object(ETO,"%^CYAN%^The shades of blue begin to crest and"+
			" fall across the dagger, as the sound of the sea fills your ears.");
		tell_room(environment(ETO),"%^CYAN%^Odd..is that the ocean I hear?",ETO);
	return 1;
	}
   else{
   	tell_object(ETO,"%^BOLD%^%^BLUE%^The sound of the sea fills your ears"+
		" as you grasp the dagger.");
   	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^Odd..is that the sea I hear?",ETO);
   	return 1;
	}
}
int removeme(){
	tell_object(ETO,"%^CYAN%^The shades of blue quell to a quiet ripple as"+
		" you unwield the dagger.");
	return 1;
}

int hitme(object targ)
{
	if(!objectp(targ)) return 1;

	if(!random(12)) {
		tell_object(ETO,"%^BOLD%^%^CYAN%^The dagger in your hand "+
			"begins to roar like the surf as you speed in towards"+
			" "+targ->QCN+", granting you the strength of the sea.");
		tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+" "+
		"speeds towards "+targ->QCN+" with "+ETO->QP+" dagger."+
		"  The roar of the sea follows the dagger's path before it "+
		"comes crashing into "+targ->QCN+".",({ETO,targ}));
		tell_object(targ,"%^BOLD%^%^CYAN%^"+ETO->QCN+""+
		" speeds towards you with "+ETO->QP+" dagger. The"+
		" roar of the sea follows the dagger's path until it comes "+
		"crashing into you with the strength of a mighty wave!");
				targ->do_damage("torso",random(5)+3);
		return 1;
	}
}