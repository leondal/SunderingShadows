#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_name("geonid");
  set_id( ({"geonid"}) );
  set_short("little geonid");
  set_long("This strange creature reminds you of a hermit crab except instead of a shell it wears a hollowed boulder of a rather unique shape.");
  set_alignment(8);
  set_race("geonid");
  set_gender("male");
  set_stats("strength", 20);
  set_stats("dexterity", 10);
  set_stats("constitution", 20);
  set_stats("intelligence", 8);
  set_stats("wisdom", 8);
  set_stats("charisma", 6);
  set_body_type("human");
  set_wielding_limbs( ({"left hand", "right hand"}) );
  set_hd(8,6);
  set_max_hp(70);
  set_hp(70);
  set_overall_ac(-2);
  set_new_exp(10, "normal");
  new("/d/koenig/town/mon/weapons/claws2.c")->move(this_object());
  new("/d/koenig/town/mon/weapons/spear.c")->move(this_object());
  command("wield claws in left hand");
  command("wield spear in right hand");
}
