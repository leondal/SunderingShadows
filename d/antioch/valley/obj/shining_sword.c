//Added Lore and inherit broad.c - Cythera 4/05\\
#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/weapon/broad.c";

int FLAG, OWNED;
string owner;

void create()
{
	::create();
	set_name("%^BOLD%^%^WHITE%^Shining Broad Sword%^RESET%^");
	set_id(({"broad sword","sword","broadsword","shining broad sword","Shining Broad Sword","Shining Broadsword","shining sword","shining broadsword"}));
	set_short("%^BOLD%^%^WHITE%^Shining Broad Sword of the"+
		" %^RED%^S%^YELLOW%^t%^RED%^arb%^YELLOW%^u%^RED%^rst%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^An adamantium broad sword%^RESET%^");
	set_long(
	"%^WHITE%^%^BOLD%^The blade of this sword is made from pure"+
	" adamantium that shines brightly in the light. The blade"+
	" is razor sharp and is joined seamlessly to the ivory hilt."+
	" On the pommel is the insignia of a blazing starburst."
	);
	set_lore("The Shinning Broadsword of the Starburst is a "+
		"blade with a curious and strange history.  The sword "+
		"was originally forged for a power-hungry (well aren't "+
		"they all) warlord of Kossuth who wanted to try to bind"+
		" the world together under his rule.  The warlord's name"+
		" has fallen out of history.  Some claim it was Irvaran "+
		"the Bold while others believe it to have been Wasselex "+
		"the Fierce.  The warlord it would seem was unsuccessful."+
		"  The blade then fell out of history for nearly 75 years"+
		" when it then found it's way into the hands of Piranex of"+
		" Torm, a holy knight of Torm who proved himself in combat"+
		" and on the field.  Piranex devoted deeply to his god, as"+
		" nearly all holy knights are, and took Torm's crusade to "+
		"the lands.  Piranex created many a foes with his unwavering"+
		" beliefs, his lance and his favored sword.  Piranex though "+
		"met with a horrible fate when he assisted Antioch with its "+
		"undead issues.  The sword is rumored to show it's true power"+
		" to those that are kind of heart and unselfish in nature.");
	set_property("lore",12);
	//set_weight(6);
	//set_size(2);
	set_property("enchantment",3+random(2));
	//set_type("slash");
	set_value(120);
	//set_wc(2,4);
	//set_large_wc(1,6);
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
	set_hit((:TO,"hitme":));
}

void init()
{
	::init();
	if(!interactive(ETO)) return;
	if(interactive(TP) && TP == environment(TO) && !OWNED) {
		owner = TPQN;
		OWNED = 1;
	}
}

int wieldme(object targ)
{
        if(!userp(ETO)) return 1;
        if((string)TPQN != owner && (string)TPQN != "knight of the order of ximes") {
		tell_object(ETO,"This is not your sword!");
		return 0;
	}
	if(ETO->query_level() < 15 && ALIGN->is_good(ETO)) {
		FLAG = 0;
		tell_object(ETO,"The sword seems a little heavy as you"+
		" wield it.");
		return 1;
	}
        else if(ETO->query_level() < 20 && ALIGN->is_good(ETO)) {
		FLAG = 1;
		tell_object(ETO,"You grip the sword with a comfortable"+
		" ease.");
		return 1;
	}
        else if(ALIGN->is_good(ETO)) {
		FLAG = 2;
		tell_object(ETO,"%^BOLD%^As you wield the sword you think"+
		" you see the starburst flare to life for a moment.");
		tell_room(environment(ETO),"%^BOLD%^There is a flash of"+
		" light as "+ETO->query_cap_name()+" wields the shining"+
		" broad sword.",ETO);
		set_item_bonus("attack bonus",2);
		return 1;
	}
        else if(ALIGN->is_evil(ETO)) {
		FLAG = 4;
		tell_object(ETO,"%^BOLD%^%^RED%^The starburst flares as"+
		" you wield the blade, burning your hand.");
		tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+""+
		" is burned as "+ETO->query_subjective()+" wields the"+
		" shining broad sword.",ETO);
		ETO->do_damage("torso",random(8)+1);
		set_item_bonus("attack bonus",0);
		return 1;
	}
	else {
		FLAG = 3;
		tell_object(ETO,"This sword seems like any other in your"+
		" hand.");
		set_item_bonus("attack bonus",0);
		return 1;
	}
}

int removeme(object targ)
{
	if(FLAG < 2) {
		return 1;
	}
	if(FLAG == 2) {
		//ETO->add_attack_bonus(-3);
		return 1;
	}
	if(FLAG > 2) {
		return 1;
	}
}

int hitme(object targ)
{
	if(!objectp(targ)) return 1;

	if(FLAG == 0) {
		return 1;
	}
	if(FLAG == 1 || FLAG == 2) {
		if(!random(10)) {
			tell_object(ETO,"%^YELLOW%^You slice your sword deeply"+
			" into "+targ->query_cap_name()+".");
			tell_object(targ,""+ETO->query_cap_name()+" slices"+
			" "+ETO->query_possessive()+" sword deeply into you.");
			tell_room(environment(ETO),""+ETO->query_cap_name()+""+
                     " slices "+ETO->query_possessive()+" sword deeply into"+
			" "+targ->query_cap_name()+".",({ETO,targ}));
			targ->do_damage("torso",random(5)+2);
			return 1;
		}
		if(!random(25)) {
			tell_object(ETO,"%^BOLD%^%^MAGENTA%^Your sword cuts"+
			" through "+targ->query_cap_name()+"'s armor like it"+
			" was butter.");
			tell_object(targ,"%^BOLD%^%^MAGENTA%^"+ETO->query_cap_name()+"'s"+
			" sword cuts through your armor as thought it were butter.");
			tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^"+ETO->query_cap_name()+"'s"+
			" sword cuts through "+targ->query_cap_name()+"'s"+
			" armor as though it were butter.",({ETO,targ}));
			targ->do_damage("torso",random(8)+3);
			return 1;
		}
	}
	if(FLAG == 2) {
		if(!random(30)) {
			tell_object(ETO,"%^BOLD%^Your sword sings through the"+
			" air as you bring it down in a deadly slice on"+
			" "+targ->query_cap_name()+".");
			tell_object(targ,"%^BOLD%^"+ETO->query_cap_name()+""+
			" sword sings through the air as "+ETO->query_subjective()+""+
			" brings whips it down in a deadly slice against you.");
			tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+""+
			" sword sings through the air as "+ETO->query_subjective()+""+
			" brings whips it down in a deadly slice against"+
			" "+targ->query_cap_name()+".",({ETO,targ}));
			targ->do_damage("torso",random(8)+6);
			return 1;
		}
		if(!random(50)) {
			tell_object(ETO,"%^BOLD%^%^RED%^Starbursts flare off"+
			" in sparks from your sword as you score an especially"+
			" brutal blow against "+targ->query_cap_name()+".");
			tell_object(targ,"%^BOLD%^%^RED%^Starbursts flare from"+
			" "+ETO->query_cap_name()+"'s sword as "+ETO->query_subjective()+""+
			" slices deeply into you.");
			tell_room(environment(ETO),"%^BOLD%^%^RED%^Starbursts"+
			" flare from "+ETO->query_cap_name()+"'s sword as "+ETO->query_subjective()+""+
			" slices deeply into "+targ->query_cap_name()+".",({ETO,targ}));
			targ->do_damage("torso",random(5)+10);
			return 1;
		}
	}
	if(FLAG == 3) {
		if(!random(20)) {
			tell_object(ETO,"%^BOLD%^Your sword plunges deeply into"+
			" "+targ->query_cap_name()+".");
			tell_object(targ,"%^BOLD%^"+ETO->query_cap_name()+"'s"+
			" sword plunges deeply into you.");
			tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+"'s"+
			" sword plunges deeply into "+targ->query_cap_name()+".",({ETO,targ}));
			targ->do_damage("torso",random(5)+2);
			return 1;
		}
		if(!random(35)) {
			tell_object(ETO,"%^RED%^Sparks fly off of your sword"+
			" as you tear into "+targ->query_cap_name()+"'s armor.");
			tell_object(targ,"%^RED%^Sparks fly off of "+ETO->query_cap_name()+"'s"+
			" sword as "+ETO->query_subjective()+" tears into"+
			" your armor.");
			tell_room(environment(ETO),"%^RED%^Sparks fly off of"+
			" "+ETO->query_cap_name()+"'s sword as "+ETO->query_subjective()+""+
			" tears into "+targ->query_cap_name()+"'s armor.",({ETO,targ}));
			targ->do_damage("torso",random(6)+3);
			return 1;
		}
	}
	else {
		return 0;
	}
}



