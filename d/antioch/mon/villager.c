//  Created by Ignatius, for ShadowGate
//  Coded on 24 June, 1995
//  Antioch village fodder

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

create() {
   ::create();
  set_name("villager");
  set_id( ({ "villager", "simple villager" }) );
  set("race", "human");
  set_gender("male");
  set("short", "A simple villager");
  set("long", 
    "This happy little guy stares blankly at the wonders of this village.  "
    "You guess he doesn't get out much\n");
  set_level(3);
  set_body_type("human");
  set("aggressive",10);
  set_alignment(1);
  set_size(2);
   set_stats("intelligence", 2);
   set_stats("wisdom", 3);
   set_stats("strength", 7);
   set_stats("charisma", 3);
   set_stats("dexterity", 3);
   set_stats("constitution", 9);
   set_max_mp(0);
   set_mp(query_max_mp());
  set_hd(3, 3);
  set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_wielding_limbs( ({ "right hand", "left hand" }) );
      new(WEAP+"stick")->move(this_object());
      command("wield stick in right hand");
  add_money("silver",random(5));
  add_money("copper",random(10));
  set_emotes(10, ({
    "The villager drools on himself.",
    "The villager picks up a pebble and puts it in his pocket.",
    "The simpleton stares at the clouds."
    }), 0);
  set_emotes(15, ({
    "'Why are you hurting me?' cries the villager.",
    "The villager bungles his attack.",
    "The villager tries to run away, but falls on his face.",
    "The villager cowers in the corner.  Bet you feel tough."
    }), 1);
}



