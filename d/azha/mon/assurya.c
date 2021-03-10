// Captain Sulaymen as-Surya
// Thorn@ShadowGate
// 4/12/96
// Azha Garrison
// assurya.c

#include <std.h>

inherit MONSTER;

create() {
	int level;
	object ob;
	
	::create();
	set_name("Captain as-Surya");
	set_id(({ "assurya", "as-surya", "captain", "sulaymen" }));
	set_short("Sulaymen as-Surya, Captain of the Imperial Infantry");
	set_long(
@TSARVEN
  Captain as-Surya commands the infantry company of the Azha Garrison.
He is a tall, handsome man, and his bearing betrays a noble lineage,
even if his rank does not.  His features betray a hint of both
sadness and resolve, common among frontier soldiers.
TSARVEN
	);
	set_class("fighter");
	level = 7;
	set_level(level);
  set_property("swarm",1);
  set_alignment(1);
  set_size(2);
	set_stats("strength", 15);
	set_stats("constitution", 14);
	set_stats("wisdom", 13);
	set_stats("charisma", 13);
	set_stats("intelligence", 13);
	set_stats("dexterity", 14);
	set_max_mp(0);
	set_mp(query_max_mp());
	set_hd(level,1);
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	new("/d/azha/equip/iscimitar.c")->move(TO);
	force_me("wield sword in right hand");
	new("/d/azha/equip/iarmor.c")->move(TO);
	force_me("wear armor");
	new("/d/azha/equip/ihelm.c")->move(TO);
	force_me("wear helm");
}

	
