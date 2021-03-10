#include <std.h>
#include "../valley.h"
inherit DRYAD;

void create()
{
	::create();
	set_short("A willow dryad");
	set_long(
	"This lovely dryad has chosen a willow tree as her home. She"+
	" has sworn to protect it with her very last breath, and thus"+
	" does not kindly welcome intruders into it. She watches you"+
	" warily, prepared to defend herself. She is very beautiful"+
	" standing there, guarding her tree. Her %^BOLD%^%^GREEN%^moss"+
	" green%^RESET%^%^CYAN%^ hair falls down passed her waist and her"+
	" %^BOLD%^%^GREEN%^hazel%^RESET%^%^CYAN%^ eyes carefully"+
	" measure your every move. She is darkly tanned, perfectly"+
	" matching the shade of the branches. Her hair billows around"+
	" her in the gentle breeze, but she keeps her eyes fixed on"+
	" you, her %^BOLD%^%^RED%^red%^RESET%^%^CYAN%^ lips set in"+
	" a firm line."
	);
        set_class("mage");
	set_mlevel("mage",19);
	set_guild_level("mage",19);
	add_search_path("/cmds/wizard");
	set_funcs(({"spray","blind"}));
	set_func_chance(30);
	set_spells(({
		"lightning bolt",
		"hold person",
		"hideous laughter",
		"wall of thorns",
	}));
	set_spell_chance(50);
	set_funcs(({"spray","blind"}));
	set_func_chance(30);
}

void spray(object targ)
{
	if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-14)){
		tell_object(targ,"%^BLUE%^The dryad points her finger at"+
		" you and a stream of water shoots forth from it, but the"+
		" water burns like acid!");
		tell_room(ETO,"%^BLUE%^The dryad points her finger at"+
		" "+targ->query_cap_name()+" and a stream of water shoots"+
		" forth from it and "+targ->query_subjective()+" screams.",targ);
		targ->do_damage("torso",random(10)+10);
		return 1;
	}
	else {
		tell_object(targ,"%^BLUE%^The dryad points her finger at"+
		" you and a stream of water shoots forth from it, but you"+
		" dodge to the side.");
		tell_room(ETO,"%^BLUE%^The dryad points her finger at"+
		" "+targ->query_cap_name()+" and a stream of water shoots"+
		" forth from it, but "+targ->query_subjective()+" dodges"+
		" it.",targ);
		return 1;
	}
}

void blind(object targ)
{
	int i,j;
	object *inven;

	inven = all_living(ETO);
	inven -= ({TO});
	j = sizeof(inven);

	tell_room(ETO,"%^YELLOW%^The dryad shouts a word and the room lights"+
	" up with blindingly bright light!");
	for(i=0;i<j;i++) {
		if(!objectp(inven[i])) continue;
		if(inven[i] == TO) continue;
		if(!"/daemon/saving_throw_d.c"->fort_save(inven[i],-14)){
			tell_object(inven[i],"%^BOLD%^The light blinds you!");
			inven[i]->set_blind(1);
			return 1;
		}
		else {
			tell_object(inven[i],"You close your eyes in time to"+
			" avoid the worst of the blast and save your eyes.");
			return 1;
		}
	}
}
