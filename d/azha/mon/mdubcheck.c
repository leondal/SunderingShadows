// Michael Dubcheck
// Thorn@ShadowGate
// 4/13/96
// Town of Azha 
// mdubcheck.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/azha/azha.h"

inherit MONSTER;

create() {
	int level;
	object ob;
	
	::create();
	set_name("Michael Dubcheck");
	set_id(({ "dubcheck", "librarian", "michael" }));
	set_short("Michael Dubcheck, Librarian of Azha");
	set_long(
@AZHA
  Michael Dubcheck is a frail old man with silver grey hair. While his
younger brother, Chief Dubcheck, chose to help keep law and order in
the town, Michael chose to record its history and keep up the ancient
Azha Library, a relic from before the Tsarvani conquest of Azha. 
With funding coming in from the Provincial Government, Michael is
able to make a reasonable living and keep the library in good order.
In addition to his duties, he has become somewhat of a dabbler in
magic, a useful tool for entertaining the young, and living in this
frontier town.
AZHA
	);
	set_class("mage");
	level = 3;
	set_level(level);
  set_alignment(1);
  set_size(2);
	set_guild_level("mage", level);
	set_stats("strength", 9);
	set_stats("constitution", 14);
	set_stats("wisdom", 16);
	set_stats("charisma", 12);
	set_stats("intelligence", 14);
	set_stats("dexterity", 8);
	set_max_mp(0);
	set_mp(query_max_mp());
	set_hd(level,1);
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        set_spells(({ "magic missile" }));
	set_spell_chance(10);
}

	
