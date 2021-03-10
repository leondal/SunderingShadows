//  Created by Ignatius, for ShadowGate
//  Coded 25 June, 1995
//  Antioch Stable fodder

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

create() {
   ::create();
  set_name("pony");
  set_id( ({
    "pony", "little pony"
  }) );
  set("race", "horse");
  set_gender("male");
  set("short",
      "A little pony"
     );
  set("long",
      "This is just a little pony.\n"
     );
  set_level( 2 );
  set_body_type("human");
  set("aggressive", 18);
  set_alignment(4);
  set_size( 2 );
   set_stats("intelligence", 2);
   set_stats("wisdom", 1);
   set_stats("strength", 9);
   set_stats("charisma", 3);
   set_stats("dexterity", 6);
   set_stats("constitution", 6);
   set_max_mp(0);
   set_mp(query_max_mp());
  set_hd(2, 1);
  set_max_hp(query_hd());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_wielding_limbs( ({ "right hand", "left hand" }) );
  new(ARM + "saddle")->move(this_object());
    command("wear saddle");
}
