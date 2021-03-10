// Senior Lieutenant Jaffar ibn Pasha
// Thorn@ShadowGate
// 4/12/96
// Azha Garrison
// ibnpasha.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/azha/azha.h"

inherit MONSTER;

int rushOK;



create() {
	int level;
	object ob;
	
	::create();
	set_name("Senior Lieutenant ibn Pasha");
	set_id(({ "ibnpasha", "pasha", "lieutenant", "jaffar" }));
	set_short("Jaffar ibn Pasha, Senior Lieutenant of the Imperial Infantry");
	set_long(
@TSARVEN
  Lieutenant ibn Pasha is the second in command of the 37th Imperial
Infantry Battalion, based in Azha Keep.  He is responsible for the
training and discipline of the men under him.  Right now, he is on
rounds, supervising the detachment of Infantry that is guarding the
inner gates of the Fortress.
TSARVEN
	);
	set_body_type("human");
	set_race("human");
	set_gender("male");
	set_class("fighter");
	level = 18;
	set_hd(level, 10);
  set_property("swarm",1);
  set_alignment(1);
  set_size(2);
	set_stats("strength", 14);
	set_stats("constitution", 13);
	set_stats("wisdom", 15);
	set_stats("charisma", 17);
	set_stats("intelligence", 12);
	set_stats("dexterity", 15);
	set_max_mp(0);
	set_mp(query_max_mp());
	add_search_path("/cmds/fighter");
	rushOK = 1;
	set_hp(225);
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_overall_ac(1);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	new(SEQUIPDIR+"iscimitar.c")->move(TO);
	force_me("wield sword in right hand");
	new(SEQUIPDIR+"iarmor.c")->move(TO);
	force_me("wear armor");
	new(SEQUIPDIR+"ihelm.c")->move(TO);
	force_me("wear helm");
	add_search_path("/cmds/fighter");
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
	
