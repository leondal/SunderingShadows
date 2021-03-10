//  Created by Ignatius, for ShadowGate
//  Coded on 19 February, 1995
//  Guard for Antioch Village

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

create() {
   ::create();
  set_name("guard");
  set_id( ({ "guard", "village guard", "guardsman" }) );
  set("race", "human");
  set_gender("male");
  set("short", "A village guardsman");
  set("long", "A member of the protective force of Antioch\n");
  set_body_type("human");
  set("aggressive",20);
  set_alignment(3);
    set_hd(10,1);
    set_level(10);
  set_size(2);
   set_stats("intelligence", 6);
   set_stats("wisdom", 7);
   set_stats("strength", 18);
   set_stats("charisma", 5);
   set_stats("dexterity", 9);
   set_stats("constitution", 7);
   set_max_mp(0);
   set_mp(query_max_mp());
   set_hp(60);
    set_exp(600);
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_wielding_limbs( ({ "right hand", "left hand" }) );
      new("/d/shadow/obj/weapon/longsword")->move(this_object());
      command("wield longsword in right hand");
      new(ARM+"robes")->move(this_object());
    	command("wear armor");
  add_money("silver",random(10));
  add_money("copper",random(20));
  set_emotes(10, ({
    "The guard glances at you suspiciously.",
    "The guard looks over his shoulder.",
    "The guard adjusts his armor, trying to make himself more comfortable."
    }), 0);
  set_emotes(15, ({
    "The guard shouts for help!!",
    "The guard dodges your blow and lunges for your throat!!",
    "The guard rips your stomach open.\nYour intestines fall out in a heap.",
    "The guard gags on his own blood as your attack wounds him."
    }), 1);
}
