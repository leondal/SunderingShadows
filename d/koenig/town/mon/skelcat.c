//made undead and fixed typos in the rake function
//Circe 12/1/07
#include <std.h>
inherit MONSTER;

// void rake(object targ);

void create()
{
  ::create();
  set_mob_magic_resistance("average");
  set_name("cat");
  set_id( ({"cat","skeletal cat","skelcat"}) );
  set_short("%^BOLD%^%^WHITE%^A Skeletal Cat%^RESET%^");
  set_long("These are the animated remains of a domestic house cat. You can see its bones peeking through its decaying flesh and the stench is that of decay!");
  set_alignment(5);
  set_race("cat");
  set_stats("strength", 12);
  set_stats("dexterity", 20);
  set_stats("constitution", 8);
  set_stats("wisdom", 5);
  set_stats("intelligence", 5);
  set_stats("charisma", 1);
  set_body_type("quadruped");
  set_property("undead",1);
  set_hd(2,2);
  set_max_hp(20);
  set_hp(40);
  set_overall_ac(6);
  set_size(1);
  set_new_exp(10, "normal");
  set_funcs( ({"rake"}) );
  set_func_chance(50);
}

void rake(object targ) {
  tell_room(ETO,"%^BOLD%^%^RED%^The skeletal cat jumps up on "+targ->QCN+" and "
            "rakes "+targ->QO+" badly!",targ);
  targ->do_damage("torso", random(10)+2);
  tell_object(targ,"%^BOLD%^%^RED%^The skeletal cat jumps up on you and rakes "
              "you painfully!");
  return 1;
}
