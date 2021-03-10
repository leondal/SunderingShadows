#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_property("swarm", 1);
  set_name("gremishka");
  set_id( ({"gremishka"}) );
   set_short("%^RESET%^%^ORANGE%^A furry gremishka%^RESET%^");
  set_long("%^YELLOW%^This ugly beast is furry, with pointed ears and a protruding "+
           "muzzle. Its mouth is overly large for the face, as are the cat "+
           "slitted %^RESET%^%^ORANGE%^yellow eyes%^YELLOW%^. Its forepaws look to have digits almost "+
           "long enough to be considered fingers.%^RESET%^");
  set_race("gremishka");
  set_body_type("quadruped");
  set_gender("male");
  set_size(1);
  set_alignment(9);
  add_limb("mouth", "head", 20, 20, 10);
  add_wielding_limb("mouth");
  set_wielding_limbs( ({"mouth"}) );
  set_hd(5,0);
  set_new_exp(5, "normal");
  set_stats("dexterity", 20);
  set_stats("strength", 10);
  set_stats("constitution", 10);
  set_stats("charisma", 1);
  set_stats("wisdom", 12);
  set_stats("intelligence", 12);
  set_max_hp(40);
  set_hp(40);
  set_overall_ac(4);
  new("/d/koenig/town/mon/weapons/jaws1.c")->move(this_object());
  command("wield fangs in mouth");
  set_exp(20);
  add_money("gold", 10);
}
