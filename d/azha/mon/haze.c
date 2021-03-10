// Colonel Tariq al-Hazen
// Thorn@ShadowGate
// 4/12/96
// Azha Garrison
// alhazen.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/azha/azha.h"

inherit MONSTER;

create() {
	int level;
	object ob;
	
	::create();
	set_name("Colonel al-Hazen");
	set_id(({ "alhazen", "al-hazen", "colonel", "tariq" }));
	set_short("Tariq al-Hazen, Colonel of the Imperial Infantry");
	set_long(
@TSARVEN
	Colonel al-Hazen is the commander of the Azha garrison.  A veteran
of many battles, he is a wise commander and a fierce fighter.  Only a
man of his abilities can be trusted to guard the dangerous northern
frontiers of the Empire.
TSARVEN
	);
	set_body_type("human");
	set_race("human");
	set_gender("male");
	set_class("ranger");
	level = 30;
	set_hd(level, 10);
	set_max_hp(280);
	set_hp(query_max_hp());
	set_overall_ac(1);
  set_property("swarm",1);
  set_alignment(1);
  set_size(2);
	set_stats("strength", 14);
	set_stats("constitution", 14);
	set_stats("wisdom", 13);
	set_stats("charisma", 11);
	set_stats("intelligence", 16);
	set_stats("dexterity", 15);
	set_max_mp(0);
	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	ob=new(SEQUIPDIR+"iscimitar.c");
	ob->set_id(({ "sword", "glittering scimitar", "scimitar" }));
  ob->set_short("A glittering scimitar");
  ob->set_property("enchantment", 2);
  ob->set_long(
@ALHAZEN
	This is a unique blade, obviously of a high grade of workmanship.
The hilt appears to be of jewel encrusted gold, wrapped in velvet.
In addition to the obvious value of this sword, it seems to be
perfectly balanced.  The blade glitters with an unearthly
light.
ALHAZEN
	   );
	ob->set("value", 200);
	ob->move(TO);
	force_me("wield sword in right hand");
	new(SEQUIPDIR+"iscimitar.c")->move(TO);
	force_me("wield sword in left hand");
	new(SEQUIPDIR+"iarmor.c")->move(TO);
	force_me("wear armor");
	new(SEQUIPDIR+"ihelm.c")->move(TO);
	force_me("wear helm");
}

