#include <std.h>

inherit MONSTER;

void create(){
	object ob;
	::create();
	
	set_name("Guard for Elven gate");
	set_id(({"elven gate guard","guard","gate guard"}));
	set("short","Elite guard of the Elven gate");
	set_mob_magic_resistance("average");
	set("long",
@OLI
	These guards are picked by the duke himself to keep elves
out of the city.  They are picked both for their skill and for 
their hatred of the elves.  This hatred might be bred in fear,
jealousy, or maybe just because they were told to.
OLI
	);
	set_race("human");
	set_property("swarm",1);
	set_size(2);
	set_alignment(3);
	set_gender("male");
    set_max_level(16);
	set_hd(14,3);
	
	set_body_type("human");
	set_wielding_limbs(({"right hand","left hand"}));
	ob = new("/d/common/obj/weapon/longsword");
	ob->set_property("enchantment",1);
	ob->set_property("monsterweapon",1);
	ob->move(TO);
	command("wield sword in right hand");
	ob = new("/d/common/obj/weapon/shortsword");
	ob->set_property("enchantment",1);
	ob->set_property("monsterweapon",1);
	ob->move(TO);
	command("wield sword in left hand");
 	ob=new("/d/common/obj/armour/plate");
	ob->set_property("enchantment",2);
	ob->set_property("monsterweapon",1);
	ob->move(TO);
	command("wear armor");
	set_property("aggressive",7);
	set_hp(100);
	set_exp(2500);
   set_property("full attacks",1);
	set_funcs(({"berserk"}));
	set_func_chance(50);
	add_money("gold",random(70));
	add_money("platinum",random(5));
	set_stats("strength",18);
	set_stats("dexterity",19);
}

void berserk(object targ){
	set_func_chance(0);
   if((string)targ->query_race() == "elf" ||(string)targ->query_race() == "drow"){
		tell_room(ETO,"%^BOLD%^%^RED%^The guard's hatred overwelms him!!");
      tell_object(targ,"The guard looks at you with a hatred unmatched!");
      tell_object(targ,"%^BOLD%^%^YELLOW%^SNARLS LOUDLY and ATTACKS furiously!!\n");
		TO->execute_attack();
		TO->execute_attack();
		TO->execute_attack();
	}else
		TO->execute_attack();
		TO->execute_attack();
	set_func_chance(50);
}

void die(object ob){
   tell_room(ETO, "%^BOLD%^In his last breath the Guard utters"
			+" an oath and offers his armors and weapons to the gods!");
   ::die(ob);
}
	
/* changed to use the die function like Thorby & aramanth critters instead of hb
hoping to fix the bug where they apparently don't always vape on dying.
void heart_beat(){
	if((int)TO->query_hp() < 1){
		tell_room(ETO,"%^BOLD%^In his last breath the Guard utters"
			+" an oath and offers his armors and weapons to the gods!");
	}
	::heart_beat();
}
*/