// aurumvorax.c

#include <std.h>

inherit WEAPONLESS;

create() {
  ::create();
  set_name("aurumvorax");
  set("id", ({"gorger", "aurumvorax"}) );
  set_short("An Aurumvorax");
  set_long("
This aurumvorax, or as legand has recalled a golden gorger, is mean and
very vicious.  You notice that its 8 legs are tipped with copper-colored
claws, and coppery teeth as well.  Its whiskers and mane guard hairs that
are a tawny bronze color, and its eyes are silvery with golden pupils.");
  set("race", "gorger");
  set_gender("female");
  set_hd(13,5);
  add_limb("right front leg","body",0,0,0);
  add_limb("left front leg","body",0,0,0);
  add_limb("right back leg","body",0,0,0);
  add_limb("left back leg","body",0,0,0);
  add_limb("body","body",0,0,0);
  add_limb("head","body",0,0,0);
  add_limb("right middle leg","body",0,0,0);
  add_limb("left middle leg","body",0,0,0);
  add_limb("mouth","head",0,0,0);
  add_limb("right middle back leg","body",0,0,0);
  add_limb("left middle back leg","body",0,0,0);
  set_alignment(5);
  set_overall_ac(0);
  set_size(1);
  set_damage(2,4);
  set_stats("strength", 17);
  set_stats("intelligence", 9);
  set_stats("dexterity", 15);
  set("aggressive", 15);
  set_attack_limbs(({"mouth","left leg","right leg","left middle leg","right middle leg","left middle back leg","right middle back leg","left back leg","right back leg"}));
  set_attacks_num(5);
  set_money("electrum",random(200));
  set_money("gold",random(100));
  set_hp(160);
  set_exp(4500);
}

void init() {
  string *exits;
  int i;
  object *inven;
  if(wizardp(TP)) return;
  kill_ob(TP, 1);
  tell_room(ETO, "%^GREEN%^You notice a small monster with many legs rushing towards you!");
  exits = (string *)environment(TO)->query_exits();
  for(i = 0;i<sizeof(exits);i++)
    add_action("chase", exits[i]);
  ::init();
}

int chase() {
  string verb;
  verb = query_verb();
  if((object *)TO->query_attackers() != ({}))
    call_out("go",1,verb);
  return 0;
}

void go(string verb) {
  command(verb);
}
