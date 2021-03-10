// Ibrahim al-Shabazz, mullah of Azha
// Thorn@ShadowGate
// 4/13/96
// Town of Azha
// alshabazz.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/azha/azha.h"

inherit MONSTER;

create() {
	int level;
	object ob;
	
	::create();
        set_name("ibrahim al-shabazz");
	set_id(({ "mullah", "alshabazz", "ibrahim", "al-shabazz" }));
	set_short("Ibrahim al-Shabazz, Mullah of Azha");
	set_long(
@TSARVEN
  As the Mullah of Azha, al-Shabazz, leads the prayers of the the
faithful during the holy days in the Azha Mosque.  He is a young man
with an expression of committment and deep faith as he goes about his
duties in the Mosque and in the community.
TSARVEN
	);
	set_body_type("human");
	set_race("human");
	set_gender("male");
	set_class("cleric");
	level = 12;
	set_guild_level("cleric",level);
        set_hd(level, 6);
  set_alignment(1);
  set_size(2);
	set_level(level);
	set_guild_level("cleric", level);
	set_stats("strength", 20);
	set_stats("constitution", 17);
	set_stats("wisdom", 21);
	set_stats("charisma", 18);
	set_stats("intelligence", 14);
	set_stats("dexterity", 19);
	set_max_mp(0);
	set_mp(query_max_mp());
	set_hp(120);
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_spells( ({ "sticks into snakes", "call lightning" }) );
	set_spell_chance(75);
}

	
