#include <std.h>
#include "../valley.h"
inherit DRYAD;

void create()
{
	::create();
	set_short("A walnut dryad");
	set_long(
	"The dryad watches you cautiously, prepared to defend herself"+
	" should you make any hostile move. You have invaded her home"+
	" which she has sworn to protect at all costs. Should the"+
   " walnut tree she lives in ever die, she would perish with"+
	" it. She blends in well with the tree, her skin is darkly"+
	" tanned to match the color of the branches, and her hair"+
	" is a very dark shade of %^GREEN%^green%^CYAN%^ that matches"+
	" the leaves, she keeps it cut short. Her eyes are a"+
	" startlingly bright shade of"+
	" %^BOLD%^%^GREEN%^emerald%^RESET%^%^CYAN%^ similar to"+
	" the color of the nuts on the tree. Her dress is a mixture"+
	" of shades, all blending in perfectly with the leaves. She's"+
	" very beautiful in an exotic way."
	);
	set_spells(({
		"lightning bolt",
		"hold person",
		"hideous laughter",
		"wall of thorns",
	}));
	set_spell_chance(50);
	set_funcs(({"earth_quake","pelt"}));
	set_func_chance(30);
}

void earth_quake(object targ)
{
	int i,j;
	object *inven;

	inven = all_living(ETO);
	inven -= ({TO});
	j = sizeof(inven);

	tell_room(ETO,"%^GREEN%^The dryad closes her eyes and"+
	" focuses for a moment and the ground beneath you begins"+
	" to shake!");
	for(i=0;i<j;i++) {
		if(!objectp(inven[i])) continue;
		if(inven[i] == TO) continue;
		if(!"daemon/saving_d"->saving_throw(inven[i],"spell",-4)) {
			tell_object(inven[i],"%^ORANGE%^The tree shakes and you"+
			" must cling to the branches or else fall to the ground!");
			inven[i]->set_paralyzed(random(25)+50,"You are clinging to the"+
			" branches!");
			return 1;
		}
		else {
			tell_object(inven[i],"%^ORANGE%^You manage to hold on to"+
			" to a branch while mostly keeping your balance.");
			return 1;
		}
	}
}

void pelt(object targ)
{
	tell_object(targ,"%^BOLD%^The dryad plucks a walnut from the"+
	" tree and throws it at you!");
	tell_room(ETO,"%^BOLD%^The dryad plucks a walnut from the"+
	" tree and throws it at "+targ->query_cap_name()+"!",targ);
	if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
 		tell_object(targ,"%^RED%^%^BOLD%^The walnut bursts into a"+
		" fireball and engulfs you in flames!");
		tell_room(ETO,"%^RED%^%^BOLD%^The walnut bursts into a"+
		" fireball and engulfs "+targ->query_cap_name()+" in"+
		" flames!",targ);
		targ->do_damage("torso",random(15)+10);
		return 1;
	}
	else {
		tell_object(targ,"%^RED%^%^BOLD%^The walnut bursts into"+
		" a fireball and singes you badly!");
		tell_room(ETO,"%^RED%^%^BOLD%^The walnut bursts into a"+
		" fireball and singes "+targ->query_cap_name()+" badly!",targ);
		targ->do_damage("torso",(random(15)+10)/2);
		return 1;
	}
}
