#include <std.h>
#include "/d/dagger/arctic/arctic.h"
inherit CREATURE;

void create(){
    ::create();
    set_name("Shark");
    set_id(({"shark","Shark","fish","giant shark","arcticmon"}));
    set_race("shark");
    set_body_type("snake");
    set_gender("male");
    set_size(5);
    set_short("A giant shark");
    set_long("%^BOLD%^%^BLACK%^This massive shark is over fifty "+
		"feet long.  Its skin is a sleek, glistening %^RESET%^gray "+
		"%^BOLD%^%^BLACK%^and it moves with disturbing agility.  The "+
		"massive dorsal fin along its back is the size of the "+
		"%^RESET%^sail %^BOLD%^%^BLACK%^on a small ship, and its "+
		"jaws look as if they could swallow a full grown giant with "+
		"ease.  The shark has huge %^RESET%^%^BLUE%^black eyes"+
		"%^BOLD%^%^BLACK%^ that are absent any pupils.%^RESET%^");
    set_hd(20,1);
    set_level(20);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_hp(1000);
    set_exp(3000);
    set_property("swarm", 1);
    set_property("water breather",1);
    set_overall_ac(-5);
    set_stats("strength",18);
    set_stats("dexterity",22);
    set_stats("intelligence",4);
    set_stats("wisdom",6);
    set_stats("constitution",22);
    set_stats("charisma",5);
    set_attacks_num(1);
    set_damage(5,10);
    set_base_damage_type("piercing");
    add_limb("razor sharp teeth", "head", 0, 0, 0);
    set_attack_limbs(({"razor sharp teeth"}));
    set("aggressive", 25);
}

void heart_beat(){
	::heart_beat();
		if(!objectp(TO)){return;}
		if(!objectp(ETO)){return;}
		if(base_name(ETO) == ROOMS"coral_b2" || 
			base_name(ETO) == ROOMS"coral_b5" || 
			base_name(ETO) == ROOMS"coral_s4" || 
			base_name(ETO) == ROOMS"coral_s8" || 
			base_name(ETO) == ROOMS"coral_s10" || 
			base_name(ETO) == ROOMS"coral_s2"){
		tell_room(ETO,"%^BOLD%^%^BLACK%^The shark swims "+
			"off, looking for an easier meal.%^RESET%^");
		TO->move("/d/shadowgate/void");
		TO->remove();
	}
}