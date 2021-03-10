#include <std.h>

inherit MONSTER;

void create(){
	object ob;	
	::create();
	set_name("elf");
	set_race("elf");
set_gender ("female");
set_id(({"elf", "Elf", "silversmith"}));
set_short("A silversmith");
	set("long",
@OLI
This is one of the many silversmiths who craft fine jewellry and other items.
OLI
	);
set_property("swarm", 1);
	set_hd(19,1);
set_size(2);
	set_hp(75);
	add_money("silver", 500);
	set_exp(200);
	set_stats("strength", 25);
	set_stats("dexterity", 25);
	set_class("fighter");
	set("aggressive",2);
	set_body_type("humanoid");
	set_wielding_limbs(({"right hand","left and"}));
	new("/d/shadow/obj/weapon/two_hand_sword")->move(TO);
	command("wield sword in right hand and left hand");
new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(TO);
	command("wear armor");
}
