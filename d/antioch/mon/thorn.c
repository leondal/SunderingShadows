//  Created by Demonforce, for Shadowgate
//  Coded 25 June, 1995
// Personal pony/demon

#include <std.h>
#include "/d/antioch/areadefs.h"
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
  set_alignment(9);
  set_size( 2 );
   set_stats("intelligence", 2);
   set_stats("wisdom", 1);
   set_stats("strength", 9);
   set_stats("charisma", 3);
   set_stats("dexterity", 6);
   set_stats("constitution", 6);
   set_max_mp(0);
   set_mp(query_max_mp());
set_hd(8,1);
  set_max_hp(query_hd());
}
