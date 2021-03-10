//  Created by Ignatius, for ShadowGate
//  Coded on 25 June, 1995
//  Antioch village fodder

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

create() {
   ::create();
  set_name("shopper");
  set_id( ({ "shopper", "careful shopper" }) );
  set("race", "human");
  set_gender("female");
  set("short", "Shopper");
  set("long", 
   "A careful shooper, looking for bargains.\n");
  set_level(2);
  set_body_type("human");
  set("aggressive", 5);
  set_alignment(2);
  set_size(2);
   set_stats("intelligence", 7);
   set_stats("wisdom", 9);
   set_stats("strength", 2);
   set_stats("charisma", 5);
   set_stats("dexterity", 3);
   set_stats("constitution", 9);
   set_max_mp(0);
   set_mp(query_max_mp());
  set_hd(2, 2);
  set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_wielding_limbs( ({ "right hand", "left hand" }) );
  add_money("silver",random(15));
  set_emotes(10, ({
    "The shopper hmms.\n",
    "The shopper looks around for a bargain.\n"
    }), 0);
  set_emotes(15, ({
    "'I am unarmed!', screams the shopper",
    "The shopper shouts for the guard!",
    "The shopper cowers in the corner.  Bet you feel mean."
    }), 1);
}
