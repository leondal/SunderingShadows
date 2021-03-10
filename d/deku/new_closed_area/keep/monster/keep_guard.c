#include <std.h>
inherit "/std/monster";

create() {
  ::create();
  set_name("keep guard");
  set_id(({"guard","keep guard","orc","orc guard", "kguard"}));
  set("short","Keep guard");
  set("long","This is a guard of Keep Blacktongue.  Obviously an orc because "
             "of his extreme smell and stupid look.  His armor looks old and "
             "beaten up but looks like it would still protect decently.  He "
             "seems bored but without motivation to bother with much.\n");
  set_race("orc");
  set_gender("male");
  set_body_type("human");
  set_class("fighter");
  set("aggressive", 0);
  set_alignment(6);
  set_size(2);
  set_hd(8,1);
  set_stats("strength",17);
  set_stats("intelligence",8);
  set_stats("wisdom",5);
  set_stats("charisma",4);
  set_stats("dexterity", 11);
  set_stats("constitution",12);
  set_overall_ac(6);
  set_wielding_limbs(({"right hand","left hand"}));
  switch(random(3)) {
    case 0:  new("/d/common/obj/weapon/scimitar")->move(TO);      break;
    case 1:  new("/d/common/obj/weapon/shortsword")->move(TO);    break;
    case 2:  new("/d/common/obj/weapon/bastard")->move(TO);       break;
  }
  command("wield sword");
  set_hp(57);
}
