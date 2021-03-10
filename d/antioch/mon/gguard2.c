//  Created by Ignatius, for ShadowGate
//  Coded on 25 June, 1995
//  Guard for Antioch Village
//  Heavy duty guard

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

create() {
   ::create();
  set_name("guardsman");
  set_id( ({ "guard", "village guard", "guardsman" }) );
  set("race", "human");
  set_gender("male");
  set_short("A garrison guardsman");
  set("long", "A member of the protective force of Antioch\n");
  set_body_type("human");
  set("aggressive",10);
  set_alignment(7);
  set_size(2);
  set_exp(1500);
   set_stats("intelligence", 6);
   set_stats("wisdom", 7);
   set_stats("strength", 15);
   set_stats("charisma", 5);
   set_stats("dexterity", 12);
   set_stats("constitution", 15);
   set_max_mp(0);
   set_mp(query_max_mp());
  set_hd(10, 5);
  set_level(15);
  set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_wielding_limbs( ({ "right hand", "left hand" }) );
     new("/d/shadow/obj/weapon/two_hand_sword")->move(this_object());
     command("wield sword in right hand and left hand");
    new(ARM+"chestplate")->move(this_object());
    command("wear armor");
  new(GAR+"obj/jail_key")->move(this_object());
  add_money("silver",random(10));
  add_money("copper",random(20));
  set_emotes(10, ({
    "The guard glances at you suspiciously.",
    "The guard looks over his shoulder.",
    "The guard adjusts his armor, trying to make himself more comfortable."
    }), 0);
}

void init(){
  ::init();
  add_action("get_player","open");
}

int get_player(string str){
  if(!str||str!="cell door") return 0;
  else{
    tell_room(ETP,"The guard says: HEY! What do you think you are doing?");
    kill_ob(TP,1);
    return 1;
  }
}
