// Imperial Guardsman of Tsarven (swarm)
// Thorn@ShadowGate
// 4/12/96
// Tsarvani Imperial Guard
// s-impguard.c

#include <std.h>

inherit MONSTER;

create() {
	int level;
	object ob;
	
	::create();
	set_name("guardsman");
	set_id(({ "guardsman", "guard", "impguard" }));
	set_short("Tsarvani Imperial Guard");
	set_long(
@TSARVEN
This is a member of the elite Tsarvani Imperial Guard.  Few in
number, they are nevertheless the best fighting unit in the Empire,
and probably beyond.  Each is a paladin sworn to the service of
Emperor and to preserving the order and goodness of the Empire.  
The %^RED%^crimson%^RESET%^ of the Imperial Guard is both the nightmare of those
who would do evil, and the hope of the good citizens of the Empire.
TSARVEN
	);
	set_class("paladin");
	level = random(6)+9;
	set_level(level);
  set_property("swarm",1);
  set_alignment(1);
  set_size(2);
	set_guild_level("cleric", level-8);
	set_stats("strength", random(4)+14);
	set_stats("constitution", random(8)+9);
	set_stats("wisdom", random(4)+13);
	set_stats("charisma", random(2)+17);
	set_stats("intelligence", random(9)+9);
	set_stats("dexterity", random(8)+10);
	set_max_mp(0);
	set_mp(query_max_mp());
	set_hd(level,1);
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	switch(random(3)+1) {
		case 1:
		new("/d/tsarven/equip/ghalberd.c")->move(TO);
		force_me("wield halberd in right hand and left hand");
		case 2:
		new("/d/tsarven/equip/gsword1.c")->move(TO);
		force_me("wield sword in right hand");
		new("/d/tsarven/equip/gshield.c")->move(TO);
		force_me("wear shield");
		case 3:
		new("/d/tsarven/equip/gsword2.c")->move(TO);
		force_me("wield sword in right hand and left hand");
	}	
	new("/d/tsarven/equip/garmor.c")->move(TO);
	force_me("wear armor");
	new("/d/tsarven/equip/ghelm.c")->move(TO);
	force_me("wear helm");
}

	
