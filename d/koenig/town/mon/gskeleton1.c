#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_name("skeleton");
  set_id( ({"giant skeleton", "skeleton"}) );
  set_short("%^BOLD%^%^WHITE%^A Massive Skeleton%^RESET%^");
  set_long("This colossal assembly of bones has formed a GIANT for you to contend with!");
  set_race("skeleton");
  set_body_type("human");
  set_alignment(5);
  set_gender("male");
  set_stats("strength", 25);
  set_stats("dexterity", 20);
  set_stats("constitution", 18);
  set_stats("wisdom", 10);
  set_stats("intelligence", 10);
  set_stats("charisma", 1);
  set_hd(10,5);
  set_max_hp(85);
  set_hp(85);
  set_overall_ac(4);
  set_size(3);
  set_class("fighter");
  set_wielding_limbs( ({"left hand", "right hand"}) );
  new("/d/koenig/town/mon/weapons/starbone1.c")->move(this_object());
  new("/d/koenig/town/mon/weapons/bonedagger.c")->move(this_object());
  command("wield sword in left hand");
  command("wield dagger in right hand");
  set_new_exp(10, "boss");
}
