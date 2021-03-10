//cleric_malar.c - Designed by Shar, coded by Circe.  For Riddle Quest
#include <std.h>
#include "../../nereid.h"
inherit CLERICWEAPON;

void create(){
	::create();
	set_name("spiked club");
	set_id(({ "club", "spiked club", "club of talon and fangs" }));
	set_short("%^RESET%^%^ORANGE%^Club of %^RED%^Talons%^ORANGE%^ and %^RED%^Fangs%^RESET%^");
	set_obvious_short("A spiked oak club");
	set_long(
@AVATAR
%^ORANGE%^Made of weathered oak, this club is studded with numerous spikes.  The body of the club, the oak wood, takes on a pale faded ash-like hue to it.  The hand grip of the club is carved to look like some shaggy feline beast with a fierce snarl on it's face.  How the wood is carved you realize there are grooves from ones fingers hidden among the body of the creature.  The top of the oak club is solid and blunt, not rounded like a typical club.  Protruding from the wood are a series of %^RED%^fangs%^ORANGE%^ and %^RED%^talons%^ORANGE%^ extracted from numerous beasts.  From owlbears to tigers to displacer beasts and blood hawks, all sorts fetishes from predators are imbedded into the club.

AVATAR
	);
	set_weight(6);
	set_lore(
@AVATAR
The Spike club of Talons and Fangs is a weapon that each Malarite strives to make at least once in their life.  By following the charge of the Lord of the Hunt, the clerics of Malar hunt down the beasts used in creation of this club.  Some say that these clerics are allowed only their holy symbol and nothing else for these sacred hunt, to learn what it means and feels like to be a true predator.  When the club is finished, some whisper, the Malarite then soaks the club in the blood of a unicorn, to corrupt it's purity.  The oak others claim comes from the sacred trees to Silvanus, as an afront to the Oakfather and his endless battle with the Beastlord.

AVATAR
	);
   set_property("lore difficulty",12);
	set_type("bludgeoning");
	set_prof_type("club");
	set_size(2);
	set_wc(1,6);
	set_large_wc(1,4);
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int unwield_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" looks exhausted after they unwield a spiked club.",ETO);
	tell_object(ETO,"%^ORANGE%^You unwield the club and your beating heart begins to quite after the hunt.");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"%^ORANGE%^"+ETOQCN+" gets a wild look in their eyes as they tear into "+targ->QCN+" with their spiked club.",({ETO,targ}));
	tell_object(ETO,"%^ORANGE%^You tear into "+targ->QCN+" with a brutal savage blow, shreading them with the %^RED%^fangs%^ORANGE%^ and %^RED%^talons%^ORANGE%^ rising out of your club.");
	tell_object(targ,"%^ORANGE%^"+ETOQCN+" gets a wild look in their eyes as they tear into you!");
		return roll_dice(2,4)+1;	}
}