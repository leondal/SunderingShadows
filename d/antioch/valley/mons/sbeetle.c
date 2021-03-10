//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

void create(){
	::create();
	set_name("slicer beetle");
	set_id(({"slicer beetle","beetle","monster","slicer","animal"}));
	set_short("A slicer beetle");
	set_long(
	"This is a gigantic beetle with mandibles that look razor-sharp."+
	" It has six legs and appears to rely on two antennas for"+
	" guidance rather than eyes. Its colors are mottled and"+
	" it blends in well with the dark foliage. The beetle looks"+
	" rather deadly."
	);
	set_gender("male");
	set_overall_ac(3);
	set_race("beetle");
	set_body_type("insectoid");
	set_hd(20,4);
	set_max_level(25);
	set_size(3);
	set_alignment(5);
	add_limb("mandibles","head",0,0,0);
	set_attack_limbs(({"mandibles"}));
	set_attacks_num(2);
	set_base_damage_type("piercing");
	set_damage(2,10);
	set_max_hp(random(175)+125);
	set_hp(query_max_hp());
	set_level(20);
	set_class("fighter");
	set_mlevel("fighter",15);
	set_stats("dexterity",20);
	set_stats("intelligence",3);
//	set_exp(13006);
	set_new_exp(15,"normal");
	set("aggressive",25);
	set_property("swarm",1);
   set_property("no bows",1);
	set_funcs(({"bite"}));
	set_func_chance(30);
	set_wimpy(40);
}

void run_away()
{
	tell_room(ETO,"%^ORANGE%^The slicer beetle"+
	" runs off into the bushes.");
	::run_away();
}

void bite(object targ)
{
	int roll, dex;
	roll = random(20);
	dex = targ->query_stats("dexterity");

	if(roll > dex) {
		tell_object(targ,"%^GREEN%^The slicer beetle bites deeply"+
		" into your leg, almost slicing it off!");
		tell_room(ETO,"%^GREEN%^The slicer beetle bites deeply"+
		" into "+targ->query_cap_name()+"'s leg, almost slicing"+
		" it off!",targ);
		targ->do_damage(random(15)+20);
		targ->set_paralyzed(100,"You are tending to your leg!");
		return 1;
	}
	else {
		tell_object(targ,"%^GREEN%^The slicer beetle makes a"+
		" lunge for your leg, but you nimbly dodge the slash.");
		tell_room(ETO,"%^GREEN%^The slicer beetle makes a lunge"+
		" for "+targ->query_cap_name()+"'s leg, but "+targ->query_subjective()+""+
		" manages to dodge out of the way.",targ);
		return 1;
	}
}

void die(object ob)
{
	if(!random(5)) {
		new(OBJ+"c_weapon")->move(TO);
	}
	::die(ob);
}
