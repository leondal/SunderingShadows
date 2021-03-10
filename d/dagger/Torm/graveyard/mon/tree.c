//tree.c

#include <std.h>

inherit MONSTER;

void create ()  {
 :: create ();


	
	set_name("a Tree");
  set_id(({"tree","A tree","evil tree",
  }));
set("short","An evil tree");
	set("long",
  "  This gnarled old tree casts a spooky shadow over you. You could swear that those "+
"branches could snatch you up and crush you. Suddenly, the tree moves!!!");
  set_overall_ac(3);
	set_race("tree");
	set_hd(10,20);
	add_limb("right limb","trunk",0,0,0);
	add_limb("foliage","trunk",0,0,0);
	add_limb("root","trunk",0,0,0);
	add_limb("left limb","trunk",0,0,0);
	set_wielding_limbs(({"right limb","left limb"}));
set_level(15);
set_hp(100);
	}
