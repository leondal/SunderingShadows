// Samir al-Emir, Imperial Customs Officer
// Thorn@ShadowGate
// 4/13/96
// Azha Garrison
// alemir.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/azha/azha.h"

inherit MONSTER;

create() {
	int level;
	object ob;
	
	::create();
	set_name("Customs Officer");
	set_id(({ "officer", "alemir", "samir", "al-emir" }));
	set_short("Samir al-Emir, Imperial Customs Officer");
	set_long(
@TSARVEN
	Governor ibn Shiraz is an elderly man of about 70 years.  This is
his final post in the service of the Empire before retiring to his
home in Tsarven.  He is a thin man, somewhat frail looking, with
white hair and a matching beard.  At first glance, he seems to be
very unthreatening and weak.  Another glance, though, will hint at
something that is a bit more formidable in this old man.
TSARVEN
	);
        set_race("human");
	set_body_type("human");
	set_class("mage");
	level = 1;
  set_alignment(1);
  set_size(2);
	set_level(level);
	set_guild_level("mage", level);
	set_stats("strength", 8);
	set_stats("constitution", 10);
	set_stats("wisdom", 12);
	set_stats("charisma", 12);
	set_stats("intelligence", 14);
	set_stats("dexterity", 12);
	set_max_mp(0);
	set_mp(query_max_mp());
	set_hd(level,1);
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
  set_spells(({ "magic missile" }));
	set_spell_chance(5);
}

	
