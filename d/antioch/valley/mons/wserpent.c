//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

void create(){
	::create();
	set_name("winged serpent");
	set_id(({"serpent","winged serpent","monster","spark snake","reptile","snake"}));
	set_short("A %^BOLD%^%^RED%^c%^ORANGE%^o%^MAGENTA%^l%^YELLOW%^o%^RED%^r%^MAGENTA%^f%^CYAN%^u%^GREEN%^l%^RED%^ winged serpent");
	set_long(
	"This beautiful creature moves with the utmost grace. The"+
	" colors of the serpent are vibrant and lovely, blending"+
	" together in an intricate pattern. The little wings are"+
	" beating quickly like a hummingbird's and are almost"+
	" invisible they move so fast."
	);
	set_race("serpent");
	set_gender("neuter");
	set_body_type("snake");
	set_hd(15,4);
	set_max_level(25);
	set_size(3);
	add_limb("left wing","torso",0,0,0);
	add_limb("right wing","torso",0,0,0);
	set_alignment(8);
	set_overall_ac(5);
	set_max_hp(random(100)+50);
	set_hp(query_max_hp());
	set_property("swarm",1);
   set_property("no bows",1);
	set_level(20);
	set_class("mage");
	set_mlevel("mage",10);
	set_class("fighter");
	set_mlevel("fighter",15);
	set_stats("dexterity",25);
	set_stats("intelligence",18);
	set_attack_limbs(({"mouth"}));
	set_attacks_num(1);
	set_base_damage_type("piercing");
	set_damage(1,4);
	set_hit_funcs((["mouth":(:TO,"poison":)]));
	set_funcs(({"sparks"}));
	set_func_chance(80);
//	set_exp(8000);
	set_new_exp(15,"normal");
}

int query_watched()
{
	return 1000000;
}

int poison(object targ)
{
	if(!random(2)) {
		tell_object(targ,"%^BOLD%^The winged serpent poisons you with its"+
		" bite.");
		if(!"/daemon/saving_throw_d.c"->fort_save(targ,-12)){
			targ->do_damage("torso",random(16)+2);
			targ->add_poisoning(20);
		}
		else {
			targ->do_damage("torso",(random(16)+2)/2);
			targ->add_poisoning(15);
		}
	}
}

void sparks(object targ)
{
	int i,j;
	object *inven;

	inven = all_living(ETO);
	j = sizeof(inven);

	if(!random(2)) {
		for(i=0;i<j;i++) {
			if(!objectp(inven[i])) continue;
			if(inven[i] == TO) continue;

			tell_object(inven[i],"%^BOLD%^%^RED%^The winged serpent"+
			" beats its wings quickly to build up electricity"+
			" and sprays you with a %^YELLOW%^shower of sparks"+
			"%^RED%^!");
			inven[i]->do_damage("torso",random(20)+5);
			return 1;
		}
	}
	return;
}
