#include <std.h>
#include "../valley.h"
inherit DRYAD;

void create(){
	::create();
	set_short("An ash dryad");
	set_long(
	"This dryad is the lovely resident of an ash tree. She has"+
	" appointed herself as guardian of the tree and shall die if"+
	" anything ever happened to it. Her eyes are a very deep shade"+
	" of %^BLUE%^sapphire blue%^CYAN%^ and her skin is pale. Her"+
	" hair falls down her"+
	" back in long tumbling waves of %^GREEN%^green%^CYAN%^ with"+
	" %^BOLD%^%^BLUE%^blue%^RESET%^%^CYAN%^ highlights. Her"+
	" features are elven with her chiseled face and pointed ears."+
	" She blends in almost perfectly with the ash tree, her dress"+
	" is a mixture of white and green hues. She stares at you"+
	" watchfully with her %^BLUE%^sapphire%^CYAN%^ eyes, waiting"+
	" to see what you will do here in her home."
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
	}));
	set_spell_chance(50);
	set_funcs(({"storm","ice_breath"}));
	set_func_chance(30);
}

void storm(object targ)
{
	int i,j;
	object *inven;

	inven = all_living(ETO);
	inven -= ({TO});
	j = sizeof(inven);

	tell_room(ETO,"%^BOLD%^The dryad begins to sway back"+
	" and forth, chanting.");
	for(i=0;i<j;i++) {
		if(!objectp(inven[i])) continue;
		if(inven[i] == TO) continue;
		if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-11)){
			tell_object(inven[i],"%^BOLD%^%^CYAN%^Wind whips around"+
			" everything, tearing at viciously at your body and"+
			" clothes and forcing you to drop all your things"+
			" and hold onto some branches.");
			inven[i]->do_damage("torso",random(10)+15);
			inven[i]->force_me("drop all");
			return 1;
		}
		else {
			tell_object(inven[i],"%^CYAN%^Wind whips around you,"+
			" tearing viciously at your body and clothes and you're"+
			" barely able to hold on to everything.");
			inven[i]->do_damage("torso",(random(10)+15)/2);
			return 1;
		}
	}
}

void ice_breath(object targ)
{
	if(!"/daemon/saving_throw_d.c"->fort_save(targ,-14)){
		tell_object(targ,"%^BOLD%^%^CYAN%^The dryad blows an"+
		" icy wind at you and frost forms on your armor.");
		tell_room(ETO,"%^BOLD%^%^CYAN%^The dryad blows an icy wind"+
		" at "+targ->query_cap_name()+", frost even forms on"+
		" "+targ->query_possessive()+" armor.",targ);
		targ->do_damage("torso",random(10)+10);
		return 1;
	}
	else {
		tell_object(targ,"%^BOLD%^The dryad blows an icy wind at"+
		" you and you shiver from the extreme cold.");
		tell_room(ETO,"%^BOLD%^The dryad blows an icy wind at"+
		" "+targ->query_cap_name()+", causing "+targ->query_objective()+""+
		" to shiver from the extreme cold.",targ);
		targ->do_damage("torso",(random(10)+10)/2);
		return 1;
	}
}
