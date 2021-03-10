#include <std.h>

inherit "/std/trainer";

void create(){
   ::create();

   set_name("masjock");
   set_short("Masjock, the trainer");
   set_long(
@OLI
   This tightly muscled man, walks lightly. He is the
weapon master of Shadow. Here is where people come to
learn to become truly masterful in the weapons they
choose to use. He knows most common weapons well beyond
most peoples hopes. He trains without weapons, hoping to
give students instructions as he shows common problems.
OLI
   );
   set_hd(35,5);
    set_exp(1);
   set_property("no bows",1);
    set_stats("strength", 11);
   set_max_hp(300);
   set_attack_limbs(({"right hand","left hand"}));
   set_attacks_num(1);
   set_damage(1,1);
   set_stats("strength",15);
   set_race("human");
   set_gender("male");
   set_id(({"masjock","Masjock","trainer","master"}));
   set_base_damage_type("bludgeoning");
   set_overall_ac(0);
   remove_std_db();
  set_exp(0);
}
