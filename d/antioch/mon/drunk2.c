//  Created by Ignatius, for ShadowGate
//  Coded 04 March, 1995
//  Wolf for Mountain Pass Random Encounters

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

create() {
   ::create();
  set_name("drunk");
  set_id( ({"drunk"  }) );
set("race", "human");
  set_gender("male");
  set("short","A drunk"     );
  set("long","He looks to be drunk.\n");
  set_level( 3 );
  set_body_type("human");
  set("aggressive", 6);
  set_alignment(6);
  set_size( 2 );
   set_stats("intelligence", 2);
   set_stats("wisdom", 1);
   set_stats("strength", 9);
   set_stats("charisma", 3);
   set_stats("dexterity", 6);
   set_stats("constitution", 6);
   set_max_mp(0);
   set_mp(query_max_mp());
  set_hd(3, 1);
  set_max_hp(12);
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_hp(query_max_hp());
  set_emotes(10, ({
    "The drunk stumbles around.",
    "The drunk snores.",
"AHHHHHHHHAHAHAHAHAH."
}), 0);
}
