// Imperial Foot Soldier of Tsarven (swarm)
// Thorn@ShadowGate
// 4/12/96
// Tsarvani Imperial Army
// s-impsoldier.c

#include <std.h>

inherit MONSTER;

int rushOK;



create() {
	int level;
	object ob;
	
	::create();
	set_name("soldier");
	set_id(({ "soldier", "guard", "tsarvani", "impsoldier" }));
	set_short("Imperial Foot Soldier");
	set_long(
@TSARVEN
This is a member of the Tsarvani Imperial Army.  Soldiers of the
Imperial Army are well-trained, well-equipped and numerous.  They
fight to protect the Empire and to promote the causes of justice
that the Empire seeks to promote.
TSARVEN
	);
	set_body_type("human");
	set_race("human");
	set_gender("male");
	set_class("fighter");
	level = random(5)+10;
	set_hd(level, 10);
	set_max_hp(random(75)+150);
	set_hp(query_max_hp());
	set_overall_ac(1);
	set_guild_level("fighter", level);
  set_property("swarm",1);
  set_alignment(1);
  set_size(2);
	set_stats("strength", random(4)+10);
	set_stats("constitution", random(9)+8);
	set_stats("wisdom", random(8)+9);
	set_stats("charisma", random(5)+9);
	set_stats("intelligence", random(7)+9);
	set_stats("dexterity", random(8)+9);
	set_max_mp(0);
	set_mp(query_max_mp());
	set_hd(level,1);
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	switch(random(3)+1) {
		case 1:
		new("/d/azha/equip/ipike.c")->move(TO);
		force_me("wield pike in right hand and left hand");
		case 2:
		new("/d/azha/equip/iscimitar.c")->move(TO);
		force_me("wield sword in right hand");
//		new("/d/tsarven/equip/ishield.c")->move(TO);
//		force_me("wear shield");
	}	
	new("/d/azha/equip/iarmor.c")->move(TO);
	force_me("wear armor");
	new("/d/azha/equip/ihelm.c")->move(TO);
	force_me("wear helm");
	rushOK = 1;
}

heart_beat() {
	::heart_beat();
   if(!objectp(TO)) return;
	if(rushOK) doRush();
}

int doRush() {
	object *atkrs;
	string atkrnames;
	int x;
	
	if(!rushOK) return 0;
	atkrs = TO->query_attackers();
	if(!(sizeof(atkrs))) return 1;
	for(x=0;x<sizeof(atkrs);x++) {
		force_me("rush "+atkrs[x]->query_name());
	}
	rushOK = 0;
	call_out("OkToRush", 60);
}
	
int OkToRush() {
	rushOK = 1;
	return rushOK;
}

	
