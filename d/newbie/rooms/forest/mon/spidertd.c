// newbie/mon/spidertd.c - Trap door spider 

#include <std.h>
inherit "/std/monster";

void create() {
  ::create();
  set_name("giant spider");
  set_id(( { "spider", "trap door spider" } ));
  set_race("giant spider");
  set_gender("female");
  set_short("giant trap door spider");
  set_long(
@STYX
%^ORANGE%^This giant arachnid's body is about the size of a human hand.  The hairy-looking body and eight legs are all a dark brown, which helps it hide well among tree branches.  The legs, when extended, are long enough to reach across a person's face or around their arm.  The long legs allow them to get a firm hold while they try to bite and paralyze the victim.  You can also see its fangs dripping with venom.
STYX
  );
  set_alignment(6);
  set_body_type("arachnid");
  set("aggressive", 19);
  set_size(1);
  set_hd(2,2);
  set_stats("dexterity",17);
  set_stats("strength",10);
  set_overall_ac(8);
  set_hp(20);
  set_exp(70 + random(30));
  set_wimpy(3);
  set_achats(5, ({ "%^BOLD%^The spider shoots a strand of web at you but misses.%^RESET%^", "%^ORANGE%^The spider backs away.", "The spider spits a %^BOLD%^%^BLACK%^blackish spray%^RESET%^ but misses." }) );
  set_funcs(({"poison"}));
  set_func_chance(20);
}

void poison(object targ) {
//    targ->add_poisoning(20);  approx. 13 pts. damage from one "dose"
    targ->do_damage("torso",random(6)+2);
    tell_object(targ, "The spider spits a %^BOLD%^%^BLACK%^blackish poisonous spray %^RESET%^in your face!\n");
    tell_room(ETO, "The spider spits a %^BOLD%^%^BLACK%^blackish spray%^RESET%^ in "+targ->query_cap_name()+"'s face!!", targ);
}
