#include "/d/dagger/cave2/short.h"

inherit "/d/dagger/cave2/mon/wonder.c";

void create() {
    object ob;
    ::create();
    set_id(({"crone", "withered crone", "woman", "demon", "demoness", "cavemon"}));
    set_name("Ancient Crone");
    set_short("Ancient withered crone");
    set_long(
      "This ancient hag is a withered bag of bones and skin.  Just looking at the rotting skin on her spindly limbs make you wretch.  Dressed in a blackened robe trimmed in a red, the first thing that strikes you is the blazing red pentagram engraved on her forehead, above her red blazing eyes.  This is no ordinary woman, this crone is one of the spawns of asmodeus, sent to destroy you."
    );
    set_body_type("human");
    set_race("human");
    set_gender("female");
    set_size(2);
    set_alignment(9);
    set_hd(15,2);
    set_exp(4500);
    set_max_hp(220);
    set_hp(220);
    set_overall_ac(7);
    set("aggressive",19);
    set_property("swarm",1);
    set_funcs(({"curse"}));
    set_func_chance(35);
    if(!random(4)) new("/d/dagger/cave2/obj/c_wand.c")->move(TO);
    if(!random(3)) {
       new("/d/common/obj/special/sp_randwpn")->move(TO);
       command("wield weapon");
    }
   if(!random(15)) {
     ob = new("/d/common/obj/brewing/herb_special_inherit");
     ob->set_herb_name("patch of demonskin");
     ob->move(TO);
   }
}

void curse(object targ){

    object *inv;
    int num;
    int i;
    object item;
    int val2;

    if("daemon/saving_d"->saving_throw(targ,"spell",-2)) {
	tell_object(targ, "%^BLUE%^The old crone points her finger at you, and nothing happens!");
	tell_room(ETO, "%^BLUE%^The crone points her finger at "+targ->query_cap_name()+", but nothing happens.", targ);
	return 1;
    } else {

	tell_object(targ, "%^BLUE%^The crone raises a withered hand and points it at you.\n A great black beam shoots from her fingers and strikes you!");
	tell_room(ETO, "%^BLUE%^The crone points her finger at "+targ->query_cap_name()+", and a black beam flies from her finger striking "+targ->query_objective()+"!",targ);

	inv = all_inventory(targ);
	num = sizeof(inv);
	i = 0;

	if (!num) {
	    tell_object(targ, "%^BLUE%^The beam from the crone's hand disperses around you!");
	    tell_room(ETO, "%^BLUE%^The black beam disperses around "+targ->query_cap_name()+".", targ);
	    return 1;
	}
	else {
	    item=inv[random(num)];
	    while( !(item->query_wielded()) && !(item->query_worn()) && (i < 3) ) {
		item=inv[random(num)];
		i++;
	    }

	    if( !(item->query_wielded()) && !(item->query_worn()) ) {
		tell_object(targ, "%^BLUE%^The beam from the crone's hand disperses around you!");
		tell_room(ETO, "%^BLUE%^The black beam disperses around "+targ->query_cap_name()+".", targ);
		return 1;
	    }

	    tell_object(targ, "%^BLUE%^The beam of blackness strikes your "+item->query_short()+" causing it to briefly glow black.");
	    tell_room(ETO, "%^BLUE%^The beam of blackness strikes "+targ->query_cap_name()+"'s "+item->query_short()+" causing it to glow black", targ);
	    val2 = item->query_property("enchantment");
	    val2 = random(3) - val2;
	    val2 = (-1*val2);
	    if (val2 < -5) { val2 = -5; }
	    while ((int)item->query_property("enchantment") != val2) {
		item->set_property("enchantment", -1);
	    }
	    tell_object(targ, "%^BLUE%^You have been cursed!!");
	    return 1;
	}
    }
}
