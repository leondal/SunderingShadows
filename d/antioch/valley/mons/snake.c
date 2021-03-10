//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

void create(){
	::create();
	set_name("snake");
	set_id(({"snake","serpent","grass snake","monster"}));
	set_short("A vicious snake");
	set_long(
	"The snake is striped shades of green, it blends in perfectly"+
	" with the grass. It is rather large, probably about six"+
	" feet in length. It is definitely unhappy about being"+
	" disturbed and has decided to take its anger out on you!"+
	" Most likely this snake is poisonous and deadly."
	);
	set_race("snake");
	set_gender("neuter");
	set_body_type("snake");
	set_hd(20,4);
	set_max_level(25);
	set_size(2);
	set_overall_ac(-6);
	set("aggressive",25);
	set_property("swarm",1);
	set_alignment(8);
	set_level(30);
	set_class("fighter");
	set_mlevel("fighter",20);
	set_attack_limbs(({"mouth"}));
	set_attacks_num(1);
	set_hit_funcs((["mouth":(:TO,"bite":)]));
	set_damage(1,12);
	set_base_damage_type("piercing");
//	set_exp(14000);
	set_new_exp(20,"normal");
	set_max_hp(random(30)+100);
	set_hp(query_max_hp());
	set_emotes(10,({
	"The snake hisses at you.",
	"The snake coils itself up and gets ready to strike.",
	"The snake rears its head back.",
	"The snake lunges towards you!",
	}),1);
}

int bite(object targ)
{
	if(!random(4)) {
		if(!"/daemon/saving_throw_d.c"->fort_save(targ,-15)){
			tell_object(targ,"%^BOLD%^%^GREEN%^The snake's venom"+
			" is like molten lava as it courses through your veins.");
			tell_room(ETO,""+targ->query_cap_name()+" screams in"+
			" pain as the snake bites "+targ->query_objective()+".",targ);
			targ->add_poisoning(50);
			targ->do_damage("torso",random(20)+1);
			return 1;
		}
	}
}

void die(object ob)
{
	switch(random(501)) {
		case 0..200:
			add_money("electrum",random(1000));
			new(OBJ+"teardrop")->move(TO);
			break;
		case 201..300:
			new(OBJ+"snake_belt")->move(TO);
			break;
		case 301..400:
			new(OBJ+"snake_hide")->move(TO);
			break;
		case 401..500:
			new(OBJ+"snake_scale")->move(TO);
			break;
	}
	::die(ob);
}
