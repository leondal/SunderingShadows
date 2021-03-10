#include <std.h>
#include "../keep.h"
inherit WEAPONLESS;

void create()
{
  ::create();
  set_name("rat");
  set_id(({"rat","large rat"}));
  set_short("A large rat");
  set_long("A dirty grey rat stares up at you with his "+
	"beady little eyes.  His fat little body is covered "+
	"with filthy, greasy hair.  A long pink tail twitches "+
	"anxiously as he bares his teeth at you.");
  set_race("rat");
  set_body_type("quadruped");
  set_gender("male");
  set_size(1);
  set("aggressive",25);
  set_property("swarm",1);
  set_level(2);
  set_class("fighter");
  set_mlevel("fighter",2);
  set_max_hp(20);
  set_hp(20);
   set_exp(75);
   set_max_level(3);
  set_damage(1,6);
  set_attacks_num(1);
  set_base_damage_type("piercing");
  set_attack_limbs(({"right forepaw","left forepaw","mouth"}));
  set_ac(8);
  set_alignment(9);
   add_money("gold",random(11)+1);
   add_money("silver",random(10));
   add_money("copper",random(50)+10);
}
