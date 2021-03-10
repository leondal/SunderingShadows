#include <std.h>

inherit MONSTER;

void create(){
	object ob;	
	::create();
	set_name("elf");
	set_race("elf");
set_gender ("female");
set_id(({"elf", "Elf", "goldsmith"}));
set_short("A goldsmith");
	set("long",
@OLI
This is one of the many goldsmiths who craft fine jewellry and other items.
OLI
	);
set_property("swarm", 1);
set_hd(24,1);
set_hp(90);
	set_exp(250);
	set_stats("strength",13);
	set_stats("dexterity",19);
	set_class("fighter");
	set("aggressive",2);
	set_body_type("humanoid");
	set_wielding_limbs(({"right hand","left and"}));
	new("/d/shadow/obj/weapon/two_hand_sword")->move(TO);
	command("wield sword in right hand and left hand");
	ob = new("/d/shadow/obj/armor/chain");
	ob->set_weight(0);
	ob->move(TO);
	command("wear armor");
	add_money("silver", 500);
}
