#include <std.h>
#include "../valley.h"
inherit DRYAD;

void create()
{
	::create();
	set_short("A cherry dryad");
	set_long(
	"This lovely dryad is the occupant of a cherry tree. You can"+
	" tell from her fiery %^BOLD%^%^RED%^red%^RESET%^%^CYAN%^ hair"+
	" and pale skin. She almost disappears against the flowers"+
	" in the tree clad in a light pink dress mixed with streaks"+
	" of brown. Her %^GREEN%^emerald%^CYAN%^ eyes stare at you"+
	" watchfully, wondering what you will do in her home. If"+
	" anything should happen to this cherry tree, the dryad"+
	" would perish, and so she guards it very carefully. She is"+
	" almost quivering with tension at your very presence. She"+
	" wants you gone from here so she can feel safe again and"+
	" she nervously twirls a strand of her hair as she waits for"+
	" you to leave."
	);
        set_class("mage");
	set_mlevel("mage",19);
	set_guild_level("mage",19);
	add_search_path("/cmds/wizard");
	set_funcs(({"bees","shower"}));
	set_func_chance(30);
	set_spells(({
		"lightning bolt",
		"hold person",
		"hideous laughter",
		"wall of thorns",
	}));
	set_spell_chance(50);
}

void bees(object targ)
{
	int i,j;
	object *inven;

	inven = all_living(ETO);
	inven -= ({TO});
	j = sizeof(inven);

	tell_room(ETO,"%^BOLD%^The dryad summons bees from nearby and they"+
	" come swarming in to sting you!");
	for(i=0;i<j;i++) {
		if(!objectp(inven[i])) continue;
		if(inven[i] == TO) continue;
		inven[i]->do_damage("torso",random(10)+5);
	}	
}

void shower(object targ)
{
	int i,j;
	object *inven;

	inven = all_living(ETO);
	inven -= ({TO});
	j = sizeof(inven);

	tell_room(ETO,"%^BOLD%^%^MAGENTA%^The dryad sings a soft"+
	" lullaby and cherry flowers begin to fall around you.");
	for(i=0;i<j;i++) {
		if(!objectp(inven[i])) continue;
		if(inven[i] == TO) continue;
		if(!"/daemon/saving_throw_d.c"->fort_save(inven[i],-14)){
					tell_object(inven[i],"%^BOLD%^%^CYAN%^You decide to"+
			" take a nice nap.");
			inven[i]->set_paralyzed(100,"You are sleeping.");
			return 1;
		}
		else {
			tell_object(inven[i],"%^CYAN%^You resist the incredible"+
			" urge to close your eyes.");
			return 1;
		}
	}
}
