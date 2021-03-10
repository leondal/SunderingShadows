// Imperial Ranger
// Thorn@ShadowGate
// 4/13/96
// Tsarvani Imperial Army
// impranger.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/azha/azha.h"

inherit MONSTER;

create() {
	int level;
	object ob;
	
	::create();
	set_name("Imperial Ranger");
	set_id(({ "ranger", "soldier", "guard" }));
	set_short("Imperial Ranger");
	set_long(
@TSARVEN
  This is a member of the Imperial Rangers, an elite corps in the
Imperial Army that specializes in special attacks, and frontier
defense.  Each member is trained in many forms of combat and
widerness survival.  Many of these troops were once frontiersmen from
all over the Empire, and are very at home on the fringes of the
Empire.
TSARVEN
	);
	set_class("ranger");
	level = random(5)+1;
	set_level(level);
  set_property("swarm",1);
  set_alignment(3);
  set_size(2);
	set_stats("strength", random(8)+10);
	set_stats("constitution", random(2)+16);
	set_stats("wisdom", random(1)+17);
	set_stats("charisma", random(9)+9);
	set_stats("intelligence", random(9)+9);
	set_stats("dexterity", random(2)+14);
	set_max_mp(0);
	set_mp(query_max_mp());
	set_hd(level,1);
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	new(SEQUIPDIR+"iscimitar.c")->move(TO);
	force_me("wield sword in left hand");
	new(SEQUIPDIR+"idagger.c")->move(TO);
	force_me("wield dagger in right hand");
	new(SEQUIPDIR+"irarmor.c")->move(TO);
	force_me("wear armor");
	new(SEQUIPDIR+"irhelm.c")->move(TO);
	force_me("wear helm");
}

	
