//  Created by Ignatius, for ShadowGate
//  Coded 25 June, 1995
//  Antioch stable fodder

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

create() {
   ::create();
  set_name("grey");
  set_id( ({
    "grey", "horse",  "grey horse"
  }) );
  set("race", "horse");
  set_gender("male");
  set("short",
      "Grey horse"
     );
  set("long",
      "This horse looks underfed and weak.\n"
     );
  set_level( 2 );
  set_body_type("human");
  set("aggressive", 6);
  set_alignment(5);
  set_size( 3 );
   set_stats("intelligence", 2);
   set_stats("wisdom", 1);
   set_stats("strength", 9);
   set_stats("charisma", 3);
   set_stats("dexterity", 6);
   set_stats("constitution", 6);
   set_max_mp(0);
   set_mp(query_max_mp());
  set_hd(3, 1);
  set_max_hp(query_hd());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_wielding_limbs( ({ "right hand", "left hand" }) );
  new(ARM + "saddle")->move(this_object());
    command("wear saddle");
  add_money("silver",random(2));
  add_money("copper",random(3));
  set_emotes(10, ({
    "The horse is a horse of course of course..\n",
    "The horse whinnies"
    }), 0);
}
