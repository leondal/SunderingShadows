// Lieutenant Hamid al-Hazen
// Thorn@ShadowGate
// 4/12/96
// Azha Garrison
// h_alhazen.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/azha/azha.h"

inherit MONSTER;

int rushOK;



create() {
	int level;
	object ob;
	
	::create();
	set_name("Lieutenant al-Hazen");
	set_id(({ "alhazen", "al-hazen", "lieutenant", "hamid" }));
	set_short("Hamid al-Hazen, Lieutenant of the Imperial Infantry");
	set_long(
@TSARVEN
  Lieutenant al-Hazen is the nephew of the garrison commander of Azha.
He is young and inexperienced, but eager.  This is his first assignment
on the frontier, but underestimating him is probably a bad idea.  
TSARVEN
	);
	set_body_type("human");
	set_race("human");
	set_gender("male");
	set_class("fighter");
	level = 17;
	set_hd(level, 10);
  set_property("swarm",1);
  set_alignment(1);
  set_size(2);
	set_stats("strength", 14);
	set_stats("constitution", 14);
	set_stats("wisdom", 12);
	set_stats("charisma", 16);
	set_stats("intelligence", 14);
	set_stats("dexterity", 17);
	set_max_mp(0);
	set_mp(query_max_mp());
	set_hp(200);
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	add_search_path("/cmds/fighter");
	rushOK = 1;
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	new(SEQUIPDIR+"iscimitar.c")->move(TO);
	force_me("wield sword in left hand");
	new(SEQUIPDIR+"iarmor.c")->move(TO);
	force_me("wear armor");
	new(SEQUIPDIR+"ihelm.c")->move(TO);
	force_me("wear helm");
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
