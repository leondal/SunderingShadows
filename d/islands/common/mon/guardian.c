#include <std.h>

inherit MONSTER;

void create() {
   ::create();
   set_name("guardian");
   set_id(({"guardian","giant","fire giant"}));
   set_short("%^BOLD%^%^RED%^Guardian of the treasure%^RESET%^");
   set_long(
  "This is a massive fire giant. He is taller and heavier than most giants of his kind. It is built squat, resembling a large dwarf. It has coal black skin, fire red hair, eyes that are glazed over as if the fire giant is not under its own control. Clad in black steel and wielding a large sword, it is a formidable opponent."
   );
   set_gender("male");
   set_race("fire giant");
   set_body_type("human");
   set_size(3);
   set_class("fighter");
   set_mlevel("fighter",50);
   set_property("full attacks",1);
   set_hd(50,9);
   set_alignment(3);
   set_max_hp(1400);
   set_hp(1400);
   set_exp(0);
   set("aggressive",25);
   new("/d/dagger/derro/obj/flameblade.c")->move(TO);
   command("wield sword");
   set_overall_ac(-30);
   set_property("no bows", 1);
   set_property("no rush", 1);
   set_mob_magic_resistance("average");
   set_resistance("fire",15);
}
