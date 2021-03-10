#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_name("assistant");
   set_id( ({"assistant", "cook","assistant head cook"}) );
  set_short("The Assistant Head Cook");
   set_long("He's UGLY and looking to help slice and dice you, what more do you need to know?");
   set_race("ogre");
  set_gender("male");
  set_body_type("human");
  set_size(2);
  set_stats("strength", 18);
  set_stats("constitution", 20);
  set_stats("dexterity", 12);
  set_stats("wisdom", 13);
  set_stats("intelligence", 12);
  set_stats("charisma", 1);
  set_alignment(9);
  set("aggressive", 10);
  set_hd(10,20);
  set_max_hp(100);
  set_hp(100);
  set_overall_ac(5);
  set_wielding_limbs( ({"left hand", "right hand"}) );
  new("/d/koenig/town/mon/weapons/carvknife.c")->move(this_object());
  new("/d/koenig/town/mon/weapons/kitknife.c")->move(this_object());
  command("wield carving knife in right hand");
  command("wield kitchen knife in left hand");
  set_class("fighter");
  set_new_exp(12, "normal");
  add_money("gold", 50);
  set_emotes(10, ({"%^MAGENTA%^
  The Assistant Head Cook sings: %^RESET%^Oho, a fine, strong dish. A rare good feast.
                        This one for the ovens, my dears. Oh, theres nothing so
                        fine as the sound of human fat sizzling. To the cages,
                        my dears, and then to the ovens, and to the millwheels
                        with the bones. Theres nothing so fine as flour made
                        with the bones of humans. Light the fires, my dears!"}), 0);
}
