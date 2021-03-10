//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
inherit MONSTER;

void create() {
  ::create();
  set_name("lizard");
  set_id(({"lizard","Lizard"}));
  set_gender("male");
  set_short("Lizard");
  set_long("This gigantic lizard is over eight feet long from tip to tail.  "+
      "He is a bright green color, fading to darker shades near his feet, which "+
      "end in long, dangerous looking claws.  He has offset eyes that seem to "+
      "move independently of each other, the bulbous orbs examining his surroundings.");
  set_level(5);
  set_race("lizard");
  set_class("fighter");
  set("aggressive",10);
  set_body_type("quadruped");
  set_size(3);
  set_hd(6,3);
  set_hp(35+random(15));
//  set_exp(150);
  set_new_exp(5,"normal");
  set_overall_ac(4);
  set_alignment(5);
  add_money("gold",random(40));
  set_moving(1);
  set_speed(80+random(10));
  set_emotes(1, ({"The lizard tests the air with his long, forked tongue.",
      "The lizard's bulbous eyes study his surroundings."}), 0);
}
