#include <std.h>
inherit "/std/monster";

create() {
  ::create();
  set_name("knight");
  set_id(({"knight","skeleton knight"}));
  set_gender("male");
  set("short","Skeleton knight");
  set("long", "This is the Knight that protects the Fortress from bandits.\n"+
              "Dressed in black plate, this figure looks very much dead.\n"+
              "Without any skin the bones are very noticeable through the armor.\n");
  set_level(10);
  set_class("fighter");
  set("aggressive",18);
  set_size(2);
  set_race("undead");
  set_hd(10,3);
  set_hp(159);
  set_alignment(9);
  set_body_type("human");
  set_new_exp(10, "low");
  set_overall_ac(0);
  set_guild_level("fighter", 10);
  set_wielding_limbs(({"right hand","left hand"}));
  new("/d/common/obj/weapon/longsword")->move(TO);
  command("wield longsword");
  if(!random(8)) {
    new("/d/deku/armours/cloak2")->move(TO);
    command("wear cloak");
  }
}
