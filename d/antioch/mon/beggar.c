//  Created by Ignatius, for ShadowGate
//  Coded on 24 June, 1995
//  Antioch village fodder

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

create() {
   ::create();
  set_name("beggar");
  set_id( ({ "beggar", "drunken beggar" }) );
  set("race", "human");
  set_gender("male");
  set("short", "A drunken beggar");
  set("long", 
   "A rancid smelling beggar.  He looks quite drunk too.\n");
  set_level(2);
  set_body_type("human");
  set("aggressive", 5);
  set_alignment(5);
  set_size(2);
   set_stats("intelligence", 2);
   set_stats("wisdom", 6);
   set_stats("strength", 11);
   set_stats("charisma", 5);
   set_stats("dexterity", 7);
   set_stats("constitution", 9);
   set_max_mp(0);
   set_mp(query_max_mp());
  set_hd(2);
  set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_wielding_limbs( ({ "right hand", "left hand" }) );
  add_money("silver",random(5));
  set_emotes(10, ({
    "The beggar passes gas.",
    "The beggar says, 'Leave me 'lone....hic..'",
    "The beggar pulls down his pants and waters the lawn."
    }), 0);
  set_emotes(15, ({
    "The beggar spits on you.",
    "The beggar falls on your feet."
    }), 1);
}



