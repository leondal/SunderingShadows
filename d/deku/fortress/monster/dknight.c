#include <std.h>

inherit "/std/monster";

void create() {
  ::create();
  set_name("death knight");
  set_id(({"death knight","knight"}));
  set("race","undead");
  set_gender("male");
  set("short","Death Knight");
  set("long","The death knight is a horrifying form of lich created by\n"+
             "a demon prince from a fallen human paladin.\n");
  set_level(9);
  set_body_type("human");
  set_class("fighter");
  set_alignment(3);
  set_size(2);
  set_hd(9,1);
  set_stats("strength",19);
  set_stats("charisma", 8);
    set_stats("dexterity",15);
  set_stats("constitution",14);
  set_stats("wisdom",13);
  set_stats("intelligence",9);
  set_hp(152);
  set_new_exp(10, "boss");
		// he touches for death .. this give a reason to fight him... and possibly die
               // will loose much more if you die.... here :)
  set_overall_ac(0);
  set_wielding_limbs(({"right hand","left hand"}));
  new("/d/common/obj/weapon/two_hand_sword")->move(TO);
  command("wield sword");
  new("/d/common/obj/misc/pouch")->move(TO);
  new("/d/deku/armours/leather")->move(TO);
  command("wear leather");
  add_money("silver",random(100));
  add_money("gold",random(20));
  set_funcs(({"point"}));
  set_func_chance(10);
}

void point(object targ) {
if(!"/daemon/saving_throw_d.c"->fort_save(targ,-15))
        return 1;
    tell_room(environment(targ), "The death knight chills "+
        targ->query_cap_name()+" with his fingers.", targ);
    tell_object(targ, "The death knight chills you with his "+
        "fingers.");
     set_property("magic",1);
  targ->cause_typed_damage(targ, "torso", 10000, "cold");
     remove_property("magic");
  return 1;
}
