// newbie/mon/beegk.c - Giant killer bees for newbie forest

#include <std.h>

inherit "/std/monster";

void create() {
  ::create();
  set_name("bee");
  set_id(( { "bee", "giant bee"} ));
  set_race("bee");
  set_gender("female");
  set_short("Giant bee");
  set_long("A giant bee with a body around six inches long and %^YELLOW%^yellow stripes %^RESET%^%^CYAN%^circling the abdomen and head.  This one is a worker bee, an undeveloped female.  It has a nasty sting and is fiercely protective of the hive.\n");
  set_hd(1,1);
  set_alignment(6);
  set_body_type("insectoid-winged");
  set_size(1);
//  set_hp(10);  (They seem to get 5-8 without a setting.)
  set_stats("dexterity",20);
  set_overall_ac(6);
  set_exp(30); /* note - gives 35 with nothing set */
  set("aggressive", 19);
  set_achats(6, ({ 
	"%^YELLOW%^The bee buzzes and flies around you angrily, diving in to try to sting!",
 	"%^YELLOW%^The bee buzzes around her hive protectively.", 
	"%^YELLOW%^The bees swarm around your face and head!!!!" 
  }) );
  set_funcs(({"sting"}));
  set_func_chance(10);
}

void sting(object targ) {
    targ->do_damage("torso",random(4)+2);
    tell_object(targ, "%^BOLD%^%^RED%^The bee finds exposed skin to sting!\nIt feels like you've been hit hard with a red-hot dart as the stinger and venom shoot into you!\n");
    tell_room(ETO, "%^BOLD%^%^RED%^The bee finds some exposed skin and slams into "+targ->query_cap_name()+".\nIt leaves a nasty welt from the sting!", targ);
}
