//  Created by Ignatius, for ShadowGate
//  Coded 04 March, 1995
//  Wolf for Mountain Pass Random Encounters

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

create() {
   ::create();
  set_name("wolf");
  set_id( ({
    "wolf", "big wolf"
  }) );
  set("race", "dog");
  set_gender("male");
  set("short",
      "A big wolf"
     );
  set("long",
      "This wild wolf looks at you with a gleam in his eye.\n"
     );
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
  set_property("swarm",1);
   set_mp(query_max_mp());
  set_hd(3, 1);
  set_max_hp(12);
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_hp(query_max_hp());
  set_wielding_limbs( ({ "right hand", "left hand" }) );
  new(ARM + "wolfskin")->move(this_object());
    command("wear armor");
  add_money("silver",random(2));
  add_money("copper",random(3));
  set_emotes(10, ({
    "The wolf paces around you, looking at your legs hungrily.",
    "The wolf throws his head back and howls.  The mountains fill with "
    "the sound of the pack howling.",
    "The wolf looks toward the north and whines."
    }), 0);
  set_emotes(15, ({
    "The wolf jumps for you!!",
    "The wolf is caught by your attack, and shies away from you."
    }), 1);
}
