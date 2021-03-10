#include <std.h>

inherit MONSTER;

void make_me();

void create(){
	::create();
	set_name("City ruffian");
	set_id(({"ruffian","city ruffian","elf hater"}));
	set("short","Common ruffian");
	set("long",
@OLI
	This ruffian is a member of a large group of people who 
hunt through Tharis for elves and beats them, sometimes to death.
Rumors have it that these ruffians are paid by the duke himself.
But rumors will be rumors.  They are large burly men.  Most of these
ruffians are mere fighters, some have been granted small abilities 
to cast spells.  The hatred of elves has been bred deeply into these
people.  Once again you are forced to wonder if such hatred is a 
result of natural things or unnatural things.
OLI
	);
	set_hd(10,1);
	set_exp(1000);
	set_stats("strength",19);
	set_alignment(3);
	set_size(2);
	set_body_type("humanoid");
	set_wielding_limbs(({"right hand","left hand"}));
	set_gender("male");
	set("aggressive",17);
	make_me();
	add_money("gold",random(50));
	add_money("silver",random(50));
	add_money("electrum",random(50));
	set_invis();
	call_out("set_invis",200);
	
}
void make_me(){
	object ob;
	int i,j,k;
	string theclass,race;
	i = random(5);
	switch(i){
	case 0: race = "dwarf";
		break;
	case 1: race = "human";
		break;
	case 2: race = "half orc";
		break;
	case 3: race = "gnome";
		break;
	case 4: race = "human";
		break;
	}
	
	set_race(race);
	i = random(4);
	switch(i){
	case 0: 
	case 1: theclass = "fighter";
		break;
	case 2: theclass = "cleric";
		break;
	case 3: theclass = "mage";
	}
	set_class(theclass);
	
	switch(theclass){
	case "fighter":
		set_hp(85);
		new("/d/tharis/obj/mrmedalion")->move(TO);
		command("wear medallion");
		ob = new("/d/common/obj/weapon/longsword");
		ob->set_property("enchantment",1);
		ob->set_property("monsterweapon",1);
		ob->move(TO);
		command("wield sword in right hand");
		new("/d/common/obj/armour/chain")->move(TO);
		command("wear armor");
		break;
	case "cleric":
		set_hp(75);
		new("/d/tharis/obj/mrmedalion")->move(TO);
		command("wear medallion");
		ob = new("/d/common/obj/weapon/mace");
		ob->set_property("enchantment",1);
		ob->set_property("monsterweapon",1);
		ob->move(TO);
		command("wield mace in right hand");
		new("/d/common/obj/armour/chain")->move(TO);
		command("wear armor");
		set_spells(({ "cause light wounds","call lightning"}));
		set_spell_chance(50);
		break;
	case "mage":
		set_hp(55);
		new("/d/tharis/obj/mrmedalion")->move(TO);
		command("wear medallion");
		ob = new("/d/common/obj/weapon/dagger");
		ob->set_property("enchantment",1);
		ob->set_property("monsterweapon",1);
		ob->move(TO);
		command("wield dagger in right hand");
		set_spells(({"magic missile",
				"lightning bolt",
				"burning hands"}));
		set_spell_chance(90);
		break;
	}
}

void heart_beat(){
	object ob;
	::heart_beat();
	
    if(!objectp(TO)) return;
	if(ob = present("elf",environment(TO))) kill_ob(ob,1);
	if(ob = present("elf 2",environment(TO))) kill_ob(ob,1);
	if(ob = present("elf 3",environment(TO))) kill_ob(ob,1);
	if(ob = present("elf 4",environment(TO))) kill_ob(ob,1);

	}
