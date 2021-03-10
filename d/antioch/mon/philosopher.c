//  Created by Ignatius, for ShadowGate
//  Coded on 19 February, 1995
//  Philosopher for Antioch Village

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

create() {
   ::create();
  set_name( "philosopher" );
  set_id( ({ "old coot", "philosopher", "old philosopher" }) );
  set("race", "human");
  set_gender("male");
  set("short", "Philosopher");
  set("long", 
      "An old coot who will bend your ear for weeks!\n");
  set_level(5);
  set_body_type("human");
  set("aggressive",14);
  set_alignment(9);
  set_size(2);
   set_stats("intelligence", 12);
   set_stats("wisdom", 14);
   set_stats("strength", 6);
   set_stats("charisma", 9);
   set_stats("dexterity", 5);
   set_stats("constitution", 7);
   set_max_mp(0);
   set_mp(query_max_mp());
  set_hd(5, 2);
  set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_wielding_limbs( ({ "right hand", "left hand" }) );
  add_money("silver",random(30));
  add_money("copper",random(10));
  set_emotes(10, ({
    "The philosopher asks, 'Have you ever seen the inside of your eyelids?'",
    "'What type of person stands here all day, asking questions?' he asks.",
    "The philosopher Hmms."
    }), 0);
  set_emotes(15, ({
    "The philosopher shouts for help!!",
    "The philosopher demonstrates a fascinating karate move on your face!",
    "The philosopher claws for your heart!!!"
    }), 1);
}
