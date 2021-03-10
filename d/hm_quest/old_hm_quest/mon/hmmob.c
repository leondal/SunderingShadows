#include <std.h>
inherit "/std/monster";
void create() {
  ::create();
  set("aggressive",10);
  set_alignment(5);
  set_body_type("human");
  if (random(2))
    set_gender("male");
  else
    set_gender("female");
  set_size(2);
  set_sp(query_max_sp());
  set_race("human");
  set_exp(5);
  set_money("gold",random(100));
  set_money("electrum",random(50));
  set_money("platinum",random(20));
  set_money("silver",random(500));

}

void init() {
  ::init();
// This add_action needs to be taken out before they go 'live'
// So that Avatars can get rid of them.
  add_action("do_nuke","zot");  

}

int do_nuke() {
  if (!avatarp(TP))
    return 0;
  TO->remove();
  return 1;
}

void die(object ob) {
  int i;
  object *inv, killer;

  if (objectp(killer=TO->query_current_attacker())) {
    tell_object(killer,"%^BOLD%^You see a startling transformation take place just as you expect your opponent to fall to the ground, dead!");
    tell_object(killer,"%^BOLD%^You can't seem to recall the face at first.... then you realize that it is the one who began your adventures here.");
  }
  remove_call_out("do_kill");
  inv = all_inventory(ETO);
  for(i=0; i<sizeof(inv); i++) {
    if(!living(inv[i])) continue;
    inv[i]->cease_all_attacks();
  }
  set_property("no kill",1);
//  set_max_hp(10000);
  set_hp(10000);
  TO->set_tripped(0,"");
  TO->set_paralyzed(0,"");
  TO->set_unconsious(0,"");
  TO->remove_paralyzed();
  return;
}
