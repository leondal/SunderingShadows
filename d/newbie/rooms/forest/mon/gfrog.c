// newbie/mon/gfrog.c - Giant frog for around newbie forest lake

#include <std.h>
inherit "/std/monster";

void create() {
  ::create();
  set_name("frog");
  set_id(( { "frog", "giant frog" } ));
  set_race("amphibian");
  set_body_type("reptile");
  set_gender("male");
  set_short("Giant frog");
  set_long(
@STYX
%^GREEN%^This giant frog is about four foot long and looks like it might weigh as much as an average human.  It has a sticky tongue two to three times its body length that flicks out and drags victims back to its mouth.
STYX
  );
  set_alignment(6);
  set_body_type("reptile");
  set("aggressive", 11);
  set_size(2);
  set_hd(3,2);
  set_stats("dexterity",12);
  set_stats("strength",16);
  set_overall_ac(8);
  set_hp(random(10)+15);
  set_exp(80+random(20));
  add_money("gold",random(80));
  add_money("silver",random(80));
  add_money("copper",random(20));
  set_wimpy(3);
  set_emotes(1, ({ "The frog's tongue flicks out at a bird, snaring it and dragging it back to its mouth.","The frog hops about 20 feet to chase a rabbit scurrying past.", "The frog's throat bellows in and out as it makes a deep croaking sound." }), 0 );
  
/* Goblin gatekeepers were AC 5, level 2, 32 hp, 125 exp. */

   set_funcs(({"snag"}));
   set_func_chance(20);
}

void snag(object targ) {
    targ->do_damage("torso",random(4)+1);
    tell_object(targ, "%^GREEN%^The giant frog's sticky tongue snags you, wrapping tightly and pulling you toward it.  It nearly smothers you until you break free.\n");
	targ->set_paralyzed(random(8),"%^GREEN%^The giant frog's sticky tongue holds you fast.\n"); 
    tell_room(ETO, "%^GREEN%^The giant frog's sticky tongue snags "+targ->query_cap_name()+" around the torso and face.\n"+capitalize(targ->query_subjective())+" struggles while being drug toward the frog's mouth.", targ);
}
