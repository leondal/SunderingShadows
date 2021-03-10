#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_name("guard");
  set_property("swarm",1);
  set_id( ({"guard","guard2"}) );
  set_short("%^BOLD%^%^BLACK%^A half-ogre guard%^RESET%^");
  set_long("This is one of the guards that has answered the call of the "
   "Gatekeeper. He looks tough and ready for battle, so does the "
           "hyena he has on a chain leash!");
  set_race("half-ogre");
  set_gender("male");
  set_body_type("human");
  set_size(3);
  set_alignment(5);
  set_hd(20,20);
  set_max_hp(180);
  set_hp(180);
  set_overall_ac(2);
  set_wielding_limbs( ({"left hand", "right hand"}) );
  new("/d/koenig/town/mon/weapons/waraxe.c")->move(this_object());
  command("wield axe in right hand");
  set_class("fighter");
  set_exp(4540);
}
