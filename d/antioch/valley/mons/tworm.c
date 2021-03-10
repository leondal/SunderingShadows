//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

void create(){
	::create();
	set_name("tenebrous worm");
	set_id(({"worm","monster","tenebrous worm"}));
	set_short("Tenebrous worm");
	set_long(
	"This creature greatly resembles a giant caterpillar."+
	" Deadly bristles line the head and upper body of the worm,"+
	" making it dangerous for anyone to attempt striking it."+
	" The mandibles slowly click together, they seem to be wet"+
	" with some substance."
	);
	set_gender("male");
	set_race("worm");
	set_body_type("snake");
	set_hd(20,6);
	set_max_level(25);
	set_size(2);
//	set_exp(15000);
	set_new_exp(20,"normal");
	set_overall_ac(1);
	set_max_hp(random(140)+200);
	set_hp(query_max_hp());
	set_alignment(8);
	set_level(20);
	set_class("fighter");
	set_mlevel("fighter",20);
	set("aggressive",25);
	set_property("swarm",1);
   set_property("no bows",1);
	set_stats("strength",18);
	add_limb("mandibles","mouth",0,0,0);
	set_attack_limbs(({"mandibles"}));
	set_attacks_num(2);
	set_base_damage_type("piercing");
	set_damage(2,8);
	set_funcs(({"spines","bite"}));
	set_func_chance(30);
}

void spines(object targ)
{
	if(!random(3)) {
		tell_object(targ,"%^BOLD%^The tenebrous worm's bristles"+
		" pierce through your armor and into your skin.");
		tell_room(ETO,"%^BOLD%^The tenebrous worm's bristles"+
		" slice into "+targ->query_cap_name()+".",targ);
		if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
			tell_object(targ,"The poison from the spines burns"+
			" through your veins.");
			targ->do_damage("torso",(random(6)+1)*4);
			targ->add_poisoning(30);
			targ->set_paralyzed(50,"You have been paralyzed by the"+
			" poison and cannot move!");
			return;
		}
		else {
			tell_object(targ,"You stubbornly fight off the"+
			" paralyzing effects of the poison, but fire still"+
			" burns through your veins.");
			targ->do_damage("torso",(random(6)+1)*3);
			targ->add_poisoning(15);
			return;
		}
	}
}

void bite(object targ)
{
	if(!random(5)) {
		if(!"/daemon/saving_throw_d.c"->fort_save(targ,-14)){
			tell_object(targ,"%^BOLD%^%^BLUE%^Tenebrous worm lashes"+
			" out at you, it burries its mandibles in your skin"+
			" and injects you with its poison.");
			tell_room(ETO,"%^BOLD%^%^BLUE%^Tenebrous worm lashes"+
			" out at "+targ->query_cap_name()+", biting "+targ->query_objective()+""+
			" fiercely.",targ);
			targ->do_damage("torso",(random(7)+4)*3);
			targ->add_poisoning(30);
			return;
		}
		else {
			tell_object(targ,"%^BOLD%^%^BLUE%^Tenebrous worm lashes"+
			" out at you, but you manage to quickly shake it off"+
			" although some poison finds its way into your blood.");
			tell_room(ETO,"%^BOLD%^%^BLUE%^Tenebrous worm lashes"+
			" out at "+targ->query_cap_name()+", biting "+targ->query_objective()+""+
			" fiercely before he can shake loose.",targ);
			targ->do_damage("torso",random(5)+6);
			targ->add_poisoning(15);
			return;
		}
	}
}

void die(object ob)
{
	new(OBJ+"mandibles")->move(TO);
	::die(ob);
}
