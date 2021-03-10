//  Created by Demonforce, for Shadowgate
//  Coded 25 June, 1995
// Personal pony/demon

#include <std.h>
#include </d/antioch/areadefs.h>
inherit MONSTER;

create() {
   ::create();
set_name("thorn");
  set_id( ({
"thorn", "sharp thorn"
  }) );
set("race", "rose");
  set_gender("male");
  set("short",
"A sharp thorn"
     );
  set("long",
"This is a big demon.\n"
     );
set_level( 8 );
  set_body_type("human");
  set("aggressive", 18);
set_property("swarm", 1);
  set_alignment( 50 );
  set_size( 2 );
	set_stats("intelligence", 5);
	set_stats("wisdom", 5);
	set_stats("strength", 18);
	set_stats("charisma", 6);
	set_stats("dexterity", 12);
	set_stats("constitution", 12);
set_hd(24,1);
set_hp(75);
	add_money("gold", 500);
set_exp(1000);
  set_max_hp(query_hd());
}
