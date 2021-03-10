#include <std.h>
#include "../valley.h"
inherit DRYAD;

void create()
{
	::create();
	set_short("A chestnut dryad");
	set_long(
	"The dryad is stunningly beautiful. Although she almost"+
	" seems to disappear into the branches of the tree, once"+
	" you've sighted her, your heart skips a beat. Her hair is"+
	" like %^YELLOW%^spun gold%^RESET%^%^CYAN%^ and rests on"+
	" her shoulders in tight curls. A pale yellow flower from the"+
	" chestnut tree is tucked behind her right ear and she is"+
	" peering at you watchfully with her %^YELLOW%^golden%^RESET%^%^CYAN%^"+
	" eyes. Her skin is tanned dark, perfectly matching the"+
	" color of the branches. Her dress is a mixture of brown"+
	" and green hues, helping her blend in with the branches."+
	" Having dedicated her life to this chestnut tree, she isn't"+
	" about to let anything happen to it, and will stop you if"+
	" you try to harm it."
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
	set_funcs(({"pelt","rains"}));
	set_func_chance(30);
}

void pelt(object targ)
{
	tell_object(targ,"The dryad throws a glowing chestnut at you!");
	tell_room(ETO,"The dryad throws a glowing chestnut at"+
	" "+targ->query_cap_name()+"!",targ);
	if(!"/daemon/saving_throw_d.c"->fort_save(targ,-14)){
		tell_object(targ,"%^BOLD%^The chestnut hits you hard and"+
		" you can feel your limbs stiffen.");
		tell_room(ETO,"%^BOLD%^The chestnut hits "+targ->query_cap_name()+""+
		" and "+targ->query_subjective()+" stiffens.",targ);
		targ->do_damage("torso",random(8)+4);
		targ->set_paralyzed(random(100)+25,"You are paralyzed!");
		return 1;
	}
	else {
		tell_object(targ,"The chestnut hits you rather hard.");
		tell_room(ETO,"The chestnut hits "+targ->query_cap_name()+""+
		" with a loud crack.",targ);
		targ->do_damage("torso",random(8)+4);
		return 1;
	}
}

void rains(object targ)
{
	int i,j;
	object *inven;

	inven = all_living(ETO);
	inven -= ({TO});
	j = sizeof(inven);

	tell_room(ETO,"%^BLUE%^The dryad raises her hands in the air"+
	" and calls forth a violent rain storm.");
	for(i=0;i<j;i++) {
		if(!objectp(inven[i])) continue;
		if(inven[i] == TO) continue;
		if(!"/daemon/saving_throw_d.c"->fort_save(inven[i],-14)){
			tell_object(inven[i],"%^BOLD%^%^BLUE%^The rains pelt"+
			" you mercilessly, the cold water freezing your skin"+
			" and making your footing slippery.");
			inven[i]->do_damage("torso",random(20)+10);
			inven[i]->set_paralyzed(25,"It's too slippery to risk"+
			" doing that!");
			return 1;
		}
		else {
			tell_object(inven[i],"%^BOLD%^%^BLUE%^The rain drops"+
			" sting as they pelt you mercilessly, freezing you"+
			" with their coldness.");
			inven[i]->do_damage("torso",(random(20)+10)/2);
			return 1;
		}
	}
}
