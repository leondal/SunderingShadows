#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_name("assistant underling");
  set_id( ({"assistand underling","underling"}) );
  set_short("%^RESET%^%^GREEN%^Assistant Underling%^RESET%^");
   set_long("This guy is a bit smaller then the assistant cook but just as UGLY. He is filling the serving bowls and platters with food...Upon spotting you he thinks about adding steak tar tar to the menu...");
  set_race("goblin");
  set_gender("male");
  set_size(1);
  set_stats("strength", 14);
  set_stats("constitusion", 18);
  set_stats("dexterity", 17);
  set_stats("wisdom", 10);
  set_stats("intelligence", 8);
  set_stats("charisma", 2);
  set_alignment(3);
  set("aggressive", 15);
  set_body_type("human");
  set_class("fighter");
  set_hd(5,4);
  set_max_hp(45);
  set_hp(45);
  set_overall_ac(8);
  set_wielding_limbs( ({"left hand", "right hand"}) );
  new("/d/koenig/town/mon/weapons/carvknife.c")->move(this_object());
  command("wield knife in right hand");
  set_new_exp(10, "normal");
  add_money("gold", 25);
  set_emotes(10, ({"The underling licks his lips as he approaches, knife at the ready to carve a slice of you to eat...\n","The underling places food in the still empty bowls.\n","The underling places more food on the platters.\n","hehehe\n"}), 0);
}
