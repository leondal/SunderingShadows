//  Created by Ignatius, for ShadowGate
//  Coded on 24 June, 1995
//  Antioch village fodder

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

create() {
   ::create();
  set_name("merchant");
  set_id( ({ "merchant", "happy merchant" }) );
  set("race", "human");
  set_gender("male");
  set("short", "Merchant");
  set("long", 
   "A merchant of Antioch.  He represents the backbone of Antioch's economy."  
   "Without him, the village would be poor.\n");
  set_level(3);
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
  set_hd(3);
  set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_wielding_limbs( ({ "right hand", "left hand" }) );
  add_money("silver",random(15));
  set_emotes(10, ({
    "%^MAGENTA%^Merchant says: %^RESET%^These are the finest silks anywhere!",
    "%^MAGENTA%^Merchant says: %^RESET%^My wares are of the highest quality.",
    "Merchant smiles at you."
    "Merchant says, 'My wares are of the highest quality.",
    "The merchant smiles at you."
    }), 0);
  set_emotes(15, ({
    "'I am unarmed!', screams the merchant",
    "The merchant shouts for the guard!",
    "The merchant scurries around, trying to get away.",
    "The merchant cries in pain."
    }), 1);
}
