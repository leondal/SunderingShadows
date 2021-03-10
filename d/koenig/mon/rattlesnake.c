#include <std.h>
#include <daemons.h>
inherit MONSTER;

create() {
    	::create();
   	set_name("snake");
   	set_id( ({ "rattlesnake","rattler","snake" }) );
   	set_short("A big rattlesnake");
   	set_level(3);
   	set("long", "A big rattlesnake. It is hissing and its rattles are shaking "+
   		"violently. It looks very upset, and dangerous.\n");
   	set_race("snake");
    	set_gender(random(2)?"male":"female");
   	set_body_type("snake");
   	set_wielding_limbs(({"mouth"}));
   	set_alignment(2);
   	set("aggressive",20);
   	set_size(1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",5);
   	set_stats("charisma",3);
   	set_stats("dexterity",18);
   	set_stats("constitution",14);
   	set_hd(3,8);
   	set_max_hp(random(35) + 35);
   	set_hp(query_max_hp());
   	set_max_level(7);
   	//set_exp(100);
    set_exp(350);
   	new("/d/shadow/mon/obj/fangs")->move(TO);
   		command("wield fangs in mouth");
    	set_funcs(({"strike"}));
    	set_func_chance(30);
}
void strike(object targ){
	int dex,poison;
	dex = targ->query_stats("dexterity");
	if(random(20) > dex) {
		tell_object(targ,"%^BOLD%^%^GREEN%^The snake lunges at you suddenly "+
			"and sinks his fangs into your flesh!  You can feel the venom "+
			"burn as it pumps through into your wound.");
		tell_room(ETO,"%^BOLD%^%^GREEN%^The snake lunges at "+TPQCN+""+
			" landing the venom in "+targ->query_cap_name()+"'s eyes.",targ);
		targ->force_me("emote %^BOLD%^%^RED%^screams in pain as the venom "+
			"does its work!%^RESET%^");
		poison = roll_dice(5,10);
		targ->do_damage("torso",roll_dice(3,3));
		targ->add_poisoning(poison);
		targ->setPoisoner(TO);
		targ->add_attacker(TO);
		targ->continue_attack();
	}
	else {
		tell_object(targ,"%^BOLD%^%^RED%^The snake strikes at you, but you"+
			" manage to dodge out of the way in the nick of time.");
		tell_room(ETO,"The snake strikes at "+TPQCN+", but "+
		" "+targ->query_subjective()+" manages to dodge out of the way.",targ);
	}
}
