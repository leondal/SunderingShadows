#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("megalo-centipede");
	set_id(({"monster","centipede","megalo-centipede","huge centipede","mega centipede","megalo centipede","animal"}));
	set_short("Megalo-centipede");
	set_long(
	"The centipede is huge! It looks as though some mage has"+
	" cast an enlargement spell on the creature. This centipede"+
	" can not simply be crushed beneath a shoe and forgotten,"+
	" but looks as though it would put up quite a fight. Its"+
	" coloration is a reddish brown, allowing it to blend well"+
	" with the earth under the thick foliage. Its"+
	" thousands of legs dance in anticipation, antennas waving"+
	" and some green ichor drips from its mouth. The insect"+
        " looks rather hungry and, if you're not careful, you just"+
	" might be its next meal."
	);
	set_gender("male");
	set_race("centipede");
	set_body_type("insectoid");
	set_hd(20,4);
	set_max_level(25);
	set_size(2);
	set_alignment(5);
	set_max_hp(random(200)+100);
	set_hp(query_max_hp());
	set_overall_ac(5);
	set_level(20);
	set_class("thief");
	set_mlevel("thief",20);
	set_class("fighter");
	set_mlevel("fighter",15);
	set_stats("dexterity",20);
	add_limb("pincers","head",0,0,0);
	set_attack_limbs(({"pincers"}));
	set_attacks_num(4);
	set_base_damage_type("piercing");
	set_damage(2,4);
//	set_exp(16000);
	set_new_exp(18,"normal");
	set("aggressive",25);
	set_property("swarm",1);
   set_property("no bows",1);
	set_funcs(({"poison"}));
	set_func_chance(30);
	set_emotes(10,({
	"The centipede thrashes around restlessly.",
	"Drops of poison singe the ground as they fall from the"+
	" centipede's pincers.",
	"The centipede clicks its pincers together in anticipation"+
	" of the fine meal soon to come."}),1);
}

void poison(object targ)
{
	if(!random(3)) {
		tell_object(targ,"%^BOLD%^%^RED%^The centipede bites you!");
		tell_room(ETO,"%^BOLD%^%^RED%^The centipede sinks its"+
		" pincers into "+targ->query_cap_name()+".",targ);
			if(!"/daemon/saving_throw_d.c"->fort_save(targ,-12)){
			tell_object(targ,"%^RED%^The poison courses through your"+
			" veins, your muscles tighten spasmodically and you can"+
			" feel your control slip away.");
			tell_room(ETO,"%^RED%^"+targ->query_cap_name()+" gasps"+
			" in pain then stands motionless.",targ);
			targ->set_paralyzed(100,"You have been paralyzed by the"+
			" poison and cannot move!");
			return;
		}
		else {
			tell_object(targ,"%^BOLD%^%^GREEN%^The poison burns"+
			" your skin as the acid eats away your flesh.");
			tell_room(ETO,"%^BOLD%^%^GREEN%^"+targ->query_cap_name()+""+
			" screams in pain as the acid burns "+targ->query_possessive()+" flesh.",targ);
			targ->do_damage("torso",random(6)+5);
			return 1;
		}
	}
	return;
}
