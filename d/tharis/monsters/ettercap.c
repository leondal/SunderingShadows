//ettercap

#include <std.h>

inherit WEAPONLESS;

void create(){
	::create();

	set_name("ettercap");
	set_id(({"ettercap","Ettercap","aberration"}));
	set_short("An Ettercap");
	set_long(
@OLI
	This mostly black humanoid has a dark brown abdomen with black
spots. The body of this creature is covered in a spike like hair.
Four extemely long fingers extend from each hand. Its jewel like
eyes are black with a hate for you. You take note of two great fangs
protruding from its mouth. This creature reminds you for some reason
of a spider.
OLI
	);
	set_body_type("human");
	set_race("ettercap");
	set_gender("male");
	set_attack_limbs(({"right hand","left hand","mouth"}));
	set_attacks_num(3);
	set_hit_funcs((["mouth":(:TO,"poison":)]));
	set_hd(7,1);
	set_hp(50);
	set_exp(1000);
	set_base_damage_type("slashing");
	set_damage(1,8);
	set_overall_ac(4);
	set_stats("intelligence",6);
	set_stats("strength",16);
	set_stats("wisdom",19);
	set_stats("constitution",18);
	set_alignment(3);

}

int poison(object targ){
	tell_object(targ,"%^BOLD%^RED%^The Ettercap sinks it's large fangs into and injects it's poison into you!");
	if("daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death",0)){
		tell_object(targ,"%^BOLD%^%^CYAN%^You feel your body fighting off the poison!");
		return 0;
	}

	tell_object(targ,"%^BOLD%^%^RED%^You feel the poison racing toward your heart. You need to have the poison neutralized FAST.");
	targ->add_poisoning(query_hp()/4);
	return 5;
}
