#include <std.h>
#include "../squires_trial.h"

inherit MONSTER;

void create(){
  ::create();
  set_name("tiny rock elemental");
  set_short("%^RESET%^%^ORANGE%^Tiny Rock Elemental%^BOLD%^%^RED%^");
  set_long(
      "%^RESET%^%^ORANGE%^" +
      "This tiny elemental stands about two feet tall.  " +
      "It appears very roughly bipedal, with a substance " +
      "and texture like brown sandstone.  It appears strange " +
      "that such a creature could exist, yet despite the " +
      "cracking stone form, this creature manages to move!  " +
      "This one seems particularly interested in hurting you."
  ); 
  set_id( ({"elemental","rock elemental","tiny elemental","tiny rock elemental"}) );
  set_race("rock elemental");
  set_body_type("human");
  set_gender("neuter");
  set_size(1);
  set_hd(15,10);
  set_alignment(5);
  set_stats("strength",17);
  set_stats("dexterity",8);
  set_stats("constitution",13);
  set_stats("intelligence",4);
  set_stats("wisdom",11);
  set_stats("charisma",11);
  set_class("fighter");
  set_guild_level("fighter",15);
  set_property("full attacks",1);
  set_hp(125 + random(25));
//  set_exp(1500);
  set_speed(10);
  set_moving(1);
  set("aggressive","killtime");
  set_overall_ac(6);
  set_property("swarm",1);
  set_nogo(NOGO);
  set_new_exp(20, "low");
}

int killtime(){
  if(!objectp(TP)) return 0;
  if(TP->query_true_invis()) return 0;
  if(TP->query_invis()) return 0;
  command("kill "+TPQN);
  return 1;
}


