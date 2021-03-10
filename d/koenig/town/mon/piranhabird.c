#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_name("piranha bird");
  set_id( ({"piranha bird", "bird"}) );
  set_short("creepy piranha bird");
  set_long("This is one of the strangest things you've seen yet. This birdlike thing looks to be a fish with feathers instead of scales. It has wings, and a mouth with lots of SHARP teeth.");
  set_race("piranha bird");
  set_body_type("fowl");
  set_size(1);
  set_stats("strength", 10);
  set_stats("constitution", 8);
  set_stats("dexterity", 20);
  set_stats("wisdom", 6);
  set_stats("intelligence", 4);
  set_stats("charisma", 5);
  add_limb("mouth", "head", 20, 20, 10);
  add_wielding_limb("mouth");
  new("/d/koenig/town/mon/weapons/jaws1.c")->move(this_object());
  command("wield fangs in mouth");
  set_alignment(8);
  set_gender("female");
  set_hd(1,4);
  set_max_hp(12);
  set_hp(12);
  set_overall_ac(7);
  set_class("fighter");
  set_exp(40);
}