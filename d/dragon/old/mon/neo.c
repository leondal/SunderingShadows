// neo-otyugh.c

#include <std.h>

inherit WEAPONLESS;


void create(){
  ::create();
  set_name("neo-otyugh");
  set_id(({"neootyugh","neo otyugh","neo-otyugh","neo","otyugh"}));
  set_short("A large Neo-otyugh");
  set_long("%^BOLD%^%^BLUE%^
This weird monster is an omnivorous scavenger, not at all hesitant about
adding an adventurer such as yourself to their diet of dung, offal and
carrion. He hates the direct sunlight, so resides here in the sewers of 
Sanctuary, scavenging off the little children of the townsfolk.
  ");
  set_overall_ac(2);
  set_race("otyugh");
  add_limb("right tentacle","body",0,0,0);
  add_limb("center tentacle","body",0,0,0);
  add_limb("left tentacle","body",0,0,0);
  add_limb("body","body",0,0,0);
  add_limb("right front leg","body",0,0,0);
  add_limb("left front leg","body",0,0,0);
  add_limb("left rear leg","body",0,0,0);
  add_limb("right rear leg","body",0,0,0);
  set_attack_limbs(({"right tentacle","left tentacle","center tentacle"}));
  set_attacks_num(3);
  set_funcs(({"bite"}));
  set_func_chance(50);
  set_size(3);
  set_alignment(5);
  set_damage(2,12);
  set_hd(10,14);
  set_hp(110);
}

void init() {
  string *exits;
  int i;
  object *inven;
  if(avatarp(TP)) return;
  kill_ob(TP,1);
  tell_room(ETO, "%^BOLD%^BLUE%^You see a monster with large tentacles coming towards you.");
  exits = (string *)environment(TO)->query_exits();
  for(i = 0;i<sizeof(exits);i++)
    add_action("chase",exits[i]);
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

