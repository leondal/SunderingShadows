#include <std.h>
#include "../valley.h"
inherit DRYAD;

void create()
{
	::create();
	set_short("An oak dryad");
	set_long(
	"%^WHITE%^Silver%^CYAN%^ eyes peer out from beneath dark"+
	" lashes, staring at you warily. The dryad almost blends"+
	" in with the oak tree, her long %^GREEN%^green%^CYAN%^ hair"+
	" is the exact shade of the leaves, and even has a few streaks"+
	" of %^WHITE%^silver%^CYAN%^ in it. Her skin is pale, blending"+
	" in with the branches, and her dress matches her skin tone"+
	" and has green leaves painted onto it. She is a very"+
	" beautiful creature and she has chosen to dedicate her life"+
	" to watching over this oak tree. From the apparent age of"+
	" the tree, it looks like she's done a pretty good job so far."
	);
        set_class("mage");
	set_mlevel("mage",19);
	set_guild_level("mage",19);
	add_search_path("/cmds/wizard");
	set_spells(({
		"lightning bolt",
		"hold person",
		"hideous laughter",
		"wall of thorns",
		"summon air elemental"
	}));
	set_spell_chance(50);
	set_funcs(({"bolt"}));
	set_func_chance(30);
}

void bolt(object targ)
{
	if(!"/daemon/saving_throw_d.c"->fort_save(targ,-14)){
		tell_object(targ,"%^YELLOW%^The dryad throws a thunderbolt"+
		" at you and your body arches in pain.");
		tell_room(ETO,"The dryad throws a thunderbolt at "+targ->query_cap_name()+""+
		" and "+targ->query_possessive()+" body arches in pain.",targ);
		targ->do_damage("torso",random(15)+8);
		targ->set_paralyzed(25,"You're in too much pain to move.");
		return 1;
	}
	else {
		tell_object(targ,"%^YELLOW%^The dryad throws a thunderbolt"+
		" at you and you clench your teeth in pain.");
		tell_room(ETO,"%^YELLOW%^The dryad throws a thunderbolt"+
		" at "+targ->query_cap_name()+" and "+targ->query_subjective()+""+
		" clenches "+targ->query_possessive()+" teeth in pain.",targ);
		targ->do_damage("torso",(random(15)+8)/2);
		return 1;
	}
}
