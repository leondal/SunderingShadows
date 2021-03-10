#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_name("head cook");
  set_id( ({"head cook", "cook"}) );
  set_short("%^BOLD%^%^RED%^The Head Cook%^RESET%^");
  set_long("This is one HUGE and very UGLY head cook! He seems to be eyeing you over for the table...");
  set_race("ogre");
  set_gender("male");
  set_body_type("human");
  set_size(3);
  set_alignment(9);
  set("aggressive", 1);
  set_hd(20,20);
  set_max_hp(180);
  set_hp(180);
  set_stats("strength", 19);
  set_stats("constitution", 17);
  set_stats("dexterity", 15);
  set_stats("wisdom", 12);
  set_stats("intelligence", 10);
  set_stats("charisma", 2);
  set_overall_ac(4);
  set_wielding_limbs( ({"left hand", "right hand"}) );
  new("/d/koenig/town/mon/weapons/carvknife.c")->move(this_object());
  new("/d/koenig/town/mon/weapons/butknife.c")->move(this_object());
  command("wield carving knife in right hand");
  command("wield butcher knife in left hand");
  set_class("fighter");
  set_new_exp(12, "high");
  add_money("gold", 200);
  set_emotes(10, ({"%^MAGENTA%^
  Head Cook sings: %^RESET%^%^BOLD%^Silver platters for human bones...%^RESET%^
                   %^BOLD%^%^YELLOW%^Golden goblets for human blood...%^RESET%^
                   %^RED%^And someone will be devoured this night!"}), 0);
}
