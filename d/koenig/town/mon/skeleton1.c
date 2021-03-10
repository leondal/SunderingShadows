#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_name("skeleton");
  set_id( ({"skeleton"}) );
  set_short("An Angry Skeleton");
  set_long("This strange assembly of bones has formed a fighter of the UNDEAD!");
  set_race("skeleton");
  set_body_type("human");
  set_gender("male");
  set_property("undead",1);
  set_stats("strength", 20);
  set_stats("dexterity", 18);
  set_stats("constitution", 12);
  set_stats("intelligence", 6);
  set_stats("wisdom", 6);
  set_stats("charisma", 1);
  set_class("fighter");
  set_alignment(5);
  set_hd(8,6);
  set_max_hp(70);
  set_hp(70);
  set_overall_ac(6);
  set_size(2);
  set_wielding_limbs( ({"left hand"}) );
  new("/d/koenig/town/mon/weapons/bonesword.c")->move(this_object());
  command("wield sword in left hand");
  set_new_exp(10, "normal");
  add_money("gold",random(5));
}
