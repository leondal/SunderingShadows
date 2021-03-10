//  Created by Demonforce, for Shadowgate
//  Coded 25 June, 1995
// Personal pony/demon

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

create() {
   ::create();
set_name("fog golem");
  set_id( ({
"a fog golem", "golem", "fog golem"
  }) );
set("race", "golem");
  set_gender("male");
  set("short",
"A fog golem"
     );
  set("long",
"He stands in the center of the room eating fog.\n"
     );
     set_level( 14 );
  set_body_type("human");
  set("aggressive", 18);
  set_alignment(6);
  set_size( 2 );
     set_stats("intelligence", 14);
     set_stats("wisdom", 20);
     set_stats("strength", 16);
set_stats("charisma", 21);
set_stats("dexterity", 18);
     set_stats("constitution", 22);
   set_max_mp(0);
   set_mp(query_max_mp());
     set_hd(10,3);
  set_max_hp(query_hd());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
     set_wielding_limbs( ({ "left fog arm" }) );
     new("/d/antioch/weapon/fogdagger.c")->move(this_object());
     command("wield sword in left fog arm");
}
