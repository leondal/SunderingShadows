#include <std.h>

inherit "/std/monster";

create() {
  ::create();
  set_name("captain");
  set_id(({"captain","Captain","orc","orc guard", "kcaptain"}));
  set("short","Captain of the guard");
  set("long","This is a captain of Keep Blacktongue.  Obviously an orc because\n"+
             "of his extreme smell and stupid look.  He would do anything to\n"+
             "serve his king.\n");
  set_race("orc");
  set_gender("male");
  set_level(7);
  set_body_type("human");
  set_class("fighter");
  set("aggressive", 18);
  set_alignment(6);
  set_size(2);
  set_hd(9,1);
  set_stats("strength",18);
  set_stats("intelligence",8);
  set_stats("wisdom",5);
  set_stats("charisma",4);
  set_stats("dexterity", 17);
  set_stats("constitution",19);
  set_wielding_limbs(({"right hand","left hand"}));
  set_overall_ac(4);
  set_hp(65);
  new("/d/common/obj/weapon/trident")->move(this_object());
  command("wield trident");
}
