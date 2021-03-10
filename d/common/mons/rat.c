//rat.c - updated to use current code by Circe - 11/8/03
#include <std.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("rat");
   set_id(({"rat","rodent","monster"}));
   set_short("A big rat");
   set_level(1);
   set_long(
      "This overgrown rodent is a little larger than an ordinary "+
      "sewer rat.  He has shiny, coarse fur in shades of black and "+
      "gray, and his long tail is a fleshy pink.  His small, beady "+
      "eyes are solid black with no pupils, and he makes small squeaky "+
      "noises as his nose twitches."
    );
   set_gender("male");
   set_race("rat");
   set_body_type("quadruped");
   set_alignment(2);
   set("aggressive",20);
   set_size(1);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",3);
   set_stats("charisma",3);
   set_stats("dexterity",8);
   set_stats("constitution",7);
   set_hd(4,1);
   set_exp(25);
   set_hp(25);
   set_max_hp(query_hp());
   add_money("copper",random(2));
   set_overall_ac(10);
   set_max_level(8);
}

