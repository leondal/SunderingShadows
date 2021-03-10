#include <std.h>
#include "/d/antioch/valley/valley.h"
inherit F_WANDER;

void create()
{
	::create();
	set_name("ghoul");
	set_id(({"ghoul","undead","monster"}));
	set_short("A disgusting ghoul");
	set_long(
	"This is a disgusting creature. He was once human but now"+
	" is deranged into a sick beast. The flesh is pale and"+
	" hangs from the bones, his claws are long and look adept"+
	" at tearing flesh. His teeth are yellow and sharp, his"+
	" tongue hangs from his mouth, strangely elongated. The"+
	" eyes of this beast are yellow and eerie and his hair is"+
	" disheveled and spikey. Some clothing still clings to"+
	" his frame, covered in blood from past meals."
	);
	set_property("undead",1);
	set_hd(15,3);
	set_max_level(20);
	set_body_type("fhuman");
	set_overall_ac(6);
	set_alignment(9);
	set_size(2);
	set_race("ghoul");
	set_max_hp(random(30)+75);
	set_hp(query_max_hp());
	set_level(15);
	set_class("fighter");
	set_mlevel("fighter",15);
	set_stats("dexterity",1);
	set_exp(875);
	set_gender("male");
	set_attack_limbs(({"right hand","left hand","mouth"}));
	set_attacks_num(3);
	set_base_damage_type("slashing");
	set_damage(1,6);
	add_money("copper",random(4000));
	set_property("swarm",1);
	set("aggressive",25);
	set_funcs(({"paralyze"}));
	set_func_chance(10);
	set_hit_funcs((["mouth":(:TO,"bite":)]));
}

int bite(object targ)
{
	targ->do_damage("torso",random(3)+1);
	return 1;
}

void paralyze(object targ)
{
	if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
		tell_object(targ,"%^ORANGE%^The cold touch of the ghoul"+
		" causes you to become paralyzed!");
		tell_room(ETO,"%^ORANGE%^The ghoul reaches out and"+
		" touches "+targ->query_cap_name()+".",targ);
  targ->set_paralyzed(random(25)+25,"The cold grip of the ghoul still holds you!");
	}
	else {
		tell_object(targ,"%^BOLD%^You grit your teeth and manage"+
		" to withstand the cold touch of the ghoul.");
		tell_room(ETO,"%^ORANGE%^The ghoul reaches out and"+
		" touches "+targ->query_cap_name()+".",targ);
	}
}

void reset()
{
	object ob;

	::reset();
	if(!present("scroll")) {
		if(random(2)) {
			ob=new("/d/magic/scroll");
			ob->set_spell(3);
			ob->move(this_object());
			return 1;
		}
	}
}
