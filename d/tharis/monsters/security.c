//security.c

#include <std.h>

inherit "/d/tharis/monsters/wonder";

int count;

void create(){
	object ob;
	::create();
	
	set_name("security guard");
	set_id(({"security","guard","security guard"}));
	set("short","A paid security guard");
	set("long",
@OLI
	This warrior of sorts makes his living today as a security guard
for the warehouses of private merchants. Always taking the highest bid,
these mercenaries could form a large army. 
OLI
	);
	set_hd(27,3);
	set_hp(120);
        set_exp(2000);
    set_mob_magic_resistance("average");
	set_property("swarm",1);
	set_stats("strength",19);
	set_stats("constitution",17);
	set_stats("dexterity",16);
	set_stats("intelligence",7);
	set_stats("wisdom",15);
	set_stats("charisma",5);
	set_body_type("human");
   set_max_level(17);
	set_race("human");
	set_alignment(7);
set_overall_ac(7);
	set_gender("male");
	set_wielding_limbs(({"right hand","left hand"}));
	new("/d/common/obj/weapon/longsword")->move(TO);
	command("wield sword in right hand");
	new("/d/common/obj/weapon/longsword")->move(TO);
	command("wield sword in left hand");
	ob=new("/d/common/obj/armour/fullplate");
	ob->set_property("monsterweapon",1);
	ob->move(TO);
	command("wear armor");
}
