#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("drow");
    set_id(({"drow","fighter","drow fighter"}));
    set_short("Drow Fighter");
    set_long("
The drow fighters are more tactical in battle than the average
drow, so normally are leading and scouting a small group of fighters
and mages.  The drow look like surfaces elves, with darker skin
and white hair.");
    set_race("Drow");
    set_gender("male");
    set_hd(10,4);
    set_size(2);
    set_overall_ac(2);
    set_class("fighter");
    set_guild_level("fighter",10);
    set_max_hp(100);
    set_hp(100);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("no bump",1);
    set_stats("strength",17);
    set_stats("dexterity",19);
    set_stats("constitution",17);
    set_mob_magic_resistance("average");
    set_exp(1300);
    set_alignment(9);
    set("aggressive","aggfunc");
}

void aggfunc() {
  int PAL = this_player()->query_alignment();
  if((PAL == 3) || (PAL == 6) || (PAL == 9)) {
    force_me("say You do not belong here evil one!");
    this_player()->kill_ob(this_object(), 0);
  } else {
  force_me("bow");
  }
}

