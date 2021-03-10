// Andrei Dubcheck
// Thorn@ShadowGate
// 4/12/96
// Azha Watch
// dubcheck.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/azha/azha.h"

inherit MONSTER;

create() {
	int level;
	object ob;
	
	::create();
	set_name("Chief Dubcheck");
	set_id(({ "dubcheck", "chief", "andrei" }));
	set_short("Andrei Dubcheck, Chief of the Azha Town Watch");
	set_long(
@AZHA
  Chief Dubcheck is a bearded, grizzled old man with shock white 
hair. A Watchman since he was 18, Dubcheck knows his territory
backwards and forwards.  Few in town share his experience, and fewer
have aspirations on his job.  Dispensing justice in a frontier
garrison and trading town is often difficult, and sometimes
dangerous.
AZHA
	);
	set_body_type("human");
	set_race("human");
	set_gender("male");
	set_class("fighter");
	level = 20;
	set_property("full attacks", 1);
	set_level(level);
	set_hd(level,8);
	set_property("swarm",1);
	set_alignment(1);
	set_size(2);
	set_stats("strength", 12);
	set_stats("constitution", 14);
	set_stats("wisdom", 16);
	set_stats("charisma", 16);
	set_stats("intelligence", 10);
	set_stats("dexterity", 9);
	set_max_mp(0);
	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	new(AEQUIP+"wsword.c")->move(TO);
	command("wield sword in left hand");
	new(AEQUIP+"warmor.c")->move(TO);
	command("wear armor");
}

	
