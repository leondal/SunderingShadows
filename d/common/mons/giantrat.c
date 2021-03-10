//giantrat.c - updated to current code by Circe - 11/8/03
#include <std.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("giant rat");
   set_id(({"giantrat","rat","giant rat","monster"}));
   set_short("A giant rat");
   set_level(6);
   set_long("This massive, mangy looking rat has mottled brown "+
      "and gray fur that seems patchy.  His small, beady eyes are "+
      "deep black and lack pupils, giving him an eerie appearance.  "+
      "This rat has grown to monstrous proportions, and it seems safe "+
      "to say that his diseases have only grown with him.");
   set_gender("male");
   set_race("rat");
   set_body_type("quadruped");
   set_alignment(2);
   set_hd(6,0);
   set("aggressive",20);
   set_size(1);
   set_stats("intelligence",1);
   set_stats("wisdom",4);
   set_stats("strength",12);
   set_stats("charisma",3);
   set_stats("dexterity",8);
   set_stats("constitution",17);
   set_max_hp(query_hp());
   add_money("copper",random(5));
   set_max_level(10);
   set_exp(75);
   set_hp(random(10)+45);
}

