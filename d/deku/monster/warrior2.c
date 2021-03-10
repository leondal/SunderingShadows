#include <std.h>
inherit "/std/monster";

create() {
  ::create();
  set_name("Warrior");
  set_id(({"warrior", "darkelf", "drow", "elf"}));
  set("race", "undead");
  set_gender("male");
  set("short", "Darkelf Warrior");
    set("long", "This warrior died long ago, but his skin has not rotted.\n"+
                "He was a fine warrior many years ago.\n");
  set_level(17);
  set_body_type("elf");
  set_class("ranger");
  set("aggressive", 20);
  set_alignment(9);
  set_hd(17,5);
  set_size(2);
  set_stats("strength",23);
  set_stats("wisdom",15);
  set_stats("intelligence",15);
  set_stats("dexterity",20);
  set_stats("constitution",20);
  set_stats("charisma",10);
  set_hp(205);
  set_wielding_limbs(({"right hand","left hand"}));
   add_money("gold",random(300));
  set_gender("male");
  new("/d/deku/weapons/elf_slayer")->move(this_object());
  command("wield sword in right hand");
  new("/d/deku/armours/bracers")->move(this_object());
   command("wear bracers");
  set_exp(5000);
  set_funcs(({"hack"}));
  set_func_chance(50);
}

void hack(object targ) {
  int need, i, tac, tlevel, roll;
  tlevel = this_object()->query_level();
  roll = roll_dice(1,20) + 4;
  need = "/daemon/bonus_d.c"->thaco(tlevel, "fighter");
  tac = targ->query_ac();
  if(!( (roll >= (need - tac)) || (roll == 24) )) {
    tell_room(environment(targ), "%^GREEN%^The Drow warrior recieves a burst of power, but nothing happens!");
    return 1;
  }
  tell_room(environment(targ), "%^RED%^The Drow Warrior receives a burst of power, and hacks upon "+targ->query_cap_name()+"!");
  set_func_chance(0);
	for(i=0;i<5;i++){
        this_object()->execute_attack();
}
  set_func_chance(40);
  tell_room(environment(targ), "%^RED%^The Drow's power fades away!\n");
  return 1;
}
