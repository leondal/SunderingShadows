#include <std.h>

inherit MONSTER;

void create(){
	object ob;	
	::create();
	set_name("elf");
	set_race("elf");
	set_id(({"elf","Elf","elven warrior","elven citizen"}));
	set("short","Elven citizen");
	set("long",
@OLI
	This is one of the few elven citizens who are willing to
stand up to the ruffians sent into the elven quarter to cause trouble.
OLI
	);
	set_hd(8,1);
	set_hp(30);
	set_exp(10);
	set_stats("strength",13);
	set_stats("dexterity",19);
    set_property("swarm",1);
	set_class("fighter");
	set_body_type("human");
	set_wielding_limbs(({"right hand","left and"}));
	new("/d/common/obj/weapon/two_hand_sword")->move(TO);
	command("wield sword in right hand and left hand");
	ob = new("/d/common/obj/armour/chain");
	ob->move(TO);
	command("wear armor");
}
