#include <std.h>

inherit "/std/monster";

void create() {
  ::create();
  set_name("nightmare");
  set_id(({"demon horse","nightmare","hell horse"}));
  set("race","equine");
  set_gender("female");
  set("short","Nightmare");
  set("long", "Nightmares are also known as 'demon horse' and 'hell horse', \n"+
              "are creatures from the lower plains.  It is gaunt and skeletal\n"+
              "with a huge head, glowing red eyes, flaming orange nostrils\n"+
              "and hooves which burn like embers.  The coat is dead black, \n"+
              "and the creature's mane and tail are wild and rugged.\n");
  set_level(6);
  set_class("fighter");
  set_body_type("equine");
  set("aggressive", 1);
  set_alignment(3);
  set_size(3);
  set_hd(6,6);
  set_overall_ac(-3);
  set_stats("strength", 16);
  set_stats("intelligence", 17);
  set_stats("wisdom", 13);
  set_stats("charisma", 10);
  set_stats("dexterity", 14);
  set_stats("constitution", 15);
  set_hp(89);
  set_new_exp(10, "low");
  set_funcs(({"breathe"}));
  set_func_chance(50);
}

void breathe(object targ) {
  tell_object(targ, "%^GREEN%^The nightmare breathes out a smoking, hot cloud upon you.");
  tell_room(environment(targ), "%^BOLD%^The Nightmare breathes a smoking, hot cloud upon "+targ->query_cap_name()+"!");
  if("/daemon/saving_d"->saving_throw(targ,"poison")) {
    return 1;
  } else {
    targ->set_temporary_blinded(3);
    tell_object(targ, "%^GREEN%^The smoke causes you to become blind!");
    return 1;
  }
  return 1;
}
