//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

void create(){
      object ob;
	::create();
	set_name("neogi");
	set_id(({"neogi","monster","aberration"}));
	set_short("A neogi");
	set_long(
	"This odd creature is a strange cross between a wolf spider"+
	" and a moray eel. The body of the creature is short and furry"+
	" with eight slender limbs and an eel-like head. Its mouth"+
	" is filled with needle-sharp teeth and the ends of the limbs"+
	" are adorned with claws. The creatures fur is tan in color"+
	" but has been dyed various colors to signify different"+
	" things important to its culture."
	);
	set_race("neogi");
	set_gender("male");
	set_body_type("arachnid");
	set_hd(18,4);
	set_max_level(25);
	set_size(1);
	set_overall_ac(5);
	set_max_hp(random(25)+175);
	set_hp(query_max_hp());
	set_alignment(3);
//	set_exp(14505);
	set_new_exp(18,"normal");
	set_level(25);
	set_class("fighter");
	set_mlevel("fighter",18);
	set_class("mage");
	set_mlevel("mage",15);
	add_limb("mouth","head",0,0,0);
	set_attack_limbs(({"mouth","right fore leg","left fore leg"}));
	set_attacks_num(3);
	set_base_damage_type("piercing");
	set_damage(1,6);
	set_hit_funcs((["mouth":(:TO,"poison":)]));
	set_stats("strength",18);
	set_spells(({
	"magic missile",
	}));
	set_spell_chance(50);
	set("aggressive",20);
	set_property("swarm",1);
   set_property("no bows",1);
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}

int poison(object targ)
{
	if(!random(8)) {
		tell_object(targ,"%^BOLD%^%^GREEN%^The poison in the neogi's"+
		" bite burns through your blood.");
		targ->do_damage("torso",random(5)+6);
		targ->add_poisoning(10);
	}
	else {
		targ->do_damage("torso",random(3)+1);
		return 1;
	}
}

void reset()
{
	::reset();
	if(!present("gem")) {
		if(random(2)) {
			switch(random(400)) {
				case 0..300:
					new(OBJ+"gem")->move(TO);
					break;
				case 301..350:
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					break;
				case 351..375:
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					break;
				case 376..400:
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					break;
			}
		}
	}
}
