#include <std.h>
inherit MONSTER;

// void bite(object targ);

void create()
{
  ::create();
  set_name("skeleton hound");
   set_id( ({"hound","skeleton hound"}) );
  set_short("A Skeletal Hound");
   set_long("These are the bones of some very large hounds with sharp teeth. But, you notice, not all the skeleton structure is completed with dog bones, some human and other bones were thrown in to make it complete and rather odd looking. You get the feeling this hound can be very dangerous.");
  set_race("skeleton hound");
  set_gender("male");
  set_body_type("quadruped");
  set_size(2);
  set_alignment(5);
  set_hd(9,5);
  set_max_hp(77);
  set_hp(77);
  set_overall_ac(8);
  set_new_exp(10, "normal");
  set_class("fighter");
  set_achats(20, ({"%^GREEN%^The hound harries you, drawing your attention from the others.\n", "%^GREEN%^The hound bites you in the butt to make you HHOOOOWWWWLLL like a mad man.\n", "%^GREEN%^The skeletal hound rushes you.\n", "%^GREEN%^The hound snaps its jaws inches from your most tender of areas.\n"}) );
  set_funcs( ({"bite"}) );
  set_func_chance(50);
  set_property("undead",1);
}
void bite(object targ)
{
 if(!targ) return 0;
  tell_room(environment(targ),"The skeletal hound takes a chunk out of "+targ->query_cap_name()+"'s hide!", targ);
  targ->do_damage("torso", random(8)+2);
  tell_object(targ, "%^BOLD%^%^RED%^The skeletal hound takes a bite out of your hide!");
  return 1;
}
