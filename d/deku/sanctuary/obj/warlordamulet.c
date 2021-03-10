#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("amulet");
	set_id(({ "warlord", "amulet", "amulet of the warlord" }));
	set_short("%^RESET%^%^RED%^Amulet of the %^BOLD%^%^GREEN%^W"+
		"%^BLACK%^a%^GREEN%^r%^BLACK%^l%^RED%^o%^BLACK%^r"+
		"%^GREEN%^d%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^A bloodstone amulet%^RESET%^");
	set_long("%^RED%^A cord of braided cracked %^ORANGE%^leather%^RED%^"+
		" supports a %^GREEN%^bloodstone%^RED%^ amulet.  The bloodstone"+
		" has been fashioned into a rounded triangle shape with the image"+
		" of an axe crossed over a great sword etched into the stone.  "+
		"The bloodstone is often prized by warriors for they claim it "+
		"aids them in battle.");
	set_weight(5);
	set_value(1000);
	set_lore(
@AVATAR
The Amulet of the Warlord was first worn by the barbrian king of Hel'darkual of the northern reaches, north of what is present day Daggerdale.  The then new port of Torm feared the savage attacks of the barbarian warlord and his tribes.  It was not uncommon for a horde of barbarians to tear through Torm's fragile defenses in the winter to steal food, furs, and women.  Hel'darkual met his end they say, by the hand of a half-elven priest of Tyr named Malthan.
AVATAR
	);
	set_property("lore",11);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",2);
      set_item_bonus("charisma",-2);
      set_item_bonus("attack bonus",2);
      set_item_bonus("damage bonus",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RED%^"+ETO->QCN+" %^RED%^takes in a sharp breath of air as "+ETO->query_possessive()+" neck veins become more pronounced.",ETO);
	tell_object(ETO,"%^RED%^A wild surge coarses through your body as you feel your blood heed the call of the amulet.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RED%^"+ETO->query_cap_name()+" %^RED%^sighs deeply as if a great weight had been lifted off of "+ETO->query_possessive()+" shoulders.",ETO);
	tell_object(ETO,"%^RED%^You feel the wild surge leave your body as the blood in your body quells down.");
	return 1;
}
