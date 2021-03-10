#include <std.h>
inherit WEAPONLESS;

void create() {
  ::create();
  set_name("bear");
  set_id(({"bear","black bear"}));
  set_short("A black bear");
  set_long("Black bears are smaller and generally more docile than their cousins, the feared brown grizzly bear.  Around 6 ft. tall when she stands on her hind legs to defend herself, this one still has claws and teeth that look dangerous.");
  set_race("bear");
  set_body_type("quadruped");
  set_gender("female");
  set_hd(2,2);
  set_size(2);
  set("aggressive",14);
  set_class("fighter");
  set_mlevel("fighter",2);
  add_limb("mouth","head",0,0,0);
  set_attack_limbs(({"right forepaw","left forepaw","mouth"}));
  set_attacks_num(2);
  set_base_damage_type("slashing");
  set_damage(1,6);
  set_stats("strength",16);
  set_hp(random(10)+20);
  set_exp(80);
  set_overall_ac(7);
  set_alignment(5);
  set_emotes(5,({
        "%^BOLD%^%^BLACK%^The bear growls angrily and lunges at you.",
        "%^BOLD%^The bear raises up on her hind legs as she swipes at you with a huge paw."
    }),1);
  set_emotes(2,({
        "The bear pokes around in the berry bush nibbling on some berries.",
        "The bear raises up on her hind legs, growling and baring her teeth threateningly.",
		"The bear sharpens her claws on the trunk of a pine tree.",
    }),0);
}
