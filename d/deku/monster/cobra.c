#include <std.h>
inherit WEAPONLESS;

create() {
  ::create();
  set_name("cobra");
  set_id(({"cobra","giant","giant cobra","Cobra"}));
  set_race("snake");
  set_gender("female");
  set_short("A giant cobra");
  set_long("A 30 foot long monstrosity that used to resemble a King \n"+
             "cobra.  It has lost almost all of its magnificence, but\n"+
               "you can still see poison dripping from its fangs.");
  set("aggressive",18);
  set_size(3);
  set_body_type("snake");
  set_alignment(8);
  set_hd(4,2);
  set_stats("dexterity",10);
  set_stats("strength",14);
  set_stats("intelligence",5);
  set_stats("wisdom",8);
  set_stats("charisma",3);
  set_stats("constitution",15);
  set_attacks_num(1);
  set_damage(1,8);
  set_hp(36);
}
