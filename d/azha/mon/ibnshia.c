// Lieutenant Ali ibn Sh'ia
// Thorn@ShadowGate
// 4/12/96
// Azha Garrison
// ibnshia.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/azha/azha.h"

inherit MONSTER;

create() {
	int level;
	object ob;
	
	::create();
	set_name("Lieutenant ibn Sh'ia");
	set_id(({ "shia", "sh'ia", "lieutenant", "ali" }));
	set_short("Ali ibn Sh'ia, Lieutenant of the Imperial Rangers");
	set_long(
@TSARVEN
  Lieutenant ibn Sh'ia is the newest officer in the garrison, recently
transferred from the 6th Imperial Rangers for a frontier tour before
he is promoted to Senior Lieutenant and given his own elite command.
Life on the frontier is rough, but such a life suits his training and
temperment perfectly.  As a Ranger officer, he is a very dangerous 
opponent in battle.
TSARVEN
	);
	set_class("ranger");
	level = 18;
	set_level(level);
  set_property("swarm",1);
	set_property("full attacks", 1);
  set_alignment(4);
  set_size(2);
	set_stats("strength", 14);
	set_stats("constitution", 18);
	set_stats("wisdom", 17);
	set_stats("charisma", 14);
	set_stats("intelligence", 14);
	set_stats("dexterity", 16);
	set_body_type("human");
	set_race("human");
	set_max_mp(0);
        set_spells( ({ "limb attack", "sticks into snakes" }) );
        set_spell_chance(35);
	set_mp(query_max_mp());
	set_hd(level,1);
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	new(SEQUIPDIR+"iscimitar.c")->move(TO);
	force_me("wield sword in left hand");
	new(SEQUIPDIR+"iscimitar.c")->move(TO);
	force_me("wield sword in right hand");
	new(SEQUIPDIR+"iarmor.c")->move(TO);
	force_me("wear armor");
	new(SEQUIPDIR+"ihelm.c")->move(TO);
	force_me("wear helm");
}

	
