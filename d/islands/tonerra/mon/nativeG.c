//Added set_max_level to retard cycling - Octothorpe 6/4/09
//native.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit MONSTER;

void create()
{
  object ob;
  ::create();
  set_name("Native Guard");
  set_id(({"native","Native","warrior","guard","hut guard"}));
  set_short("Jungle native guard");
  set_long(
@OLI
   These native guards look like brutes. They are brutes. Their
sole purpose in life is to stand watch over the village and the
important leaders in the village. They are over grown and very mean.
Evidentally the magic in this village is very strong as it allows
these beasts to be made.
OLI
);

  set_class("fighter");
  set_race("human");
  set_body_type("humanoid");
  set_gender("male");
  set_hd(20+random(15),8);
  set_hp(roll_dice(query_hd(),16));
  set_overall_ac(-3);
  set_size(3);
  set_exp(700*query_hd());
  set_new_exp(25,"very high");
set_max_level(25);
  set_wielding_limbs(({"right hand","left hand"}));
  ob=new(OBJ+"spear2.c");
if(random(4))
{
	ob->set_property("monsterweapon",1);
}
	ob->move(TO);
  command("wield spear in right hand");
  new("/d/common/obj/weapon/spear_lg.c")->move(TO);
  command("wield spear in left hand");
  new(OBJ+"hide.c")->move(TO);
  command("wear woven");
  set_property("full attacks",1);
  set_scrambling(1);
  set_max_level(32);
  set_property("swarm",1);
  set_stabbed_func((:TO,"stabbed":));
  set_stats("strength",20);
}

void stabbed(){
//   TP->set_disabled(5);  bugging on bad object, don't think it's needed *Styx* 3/30/06
   tell_room(ETO,"%^BOLD%^%^RED%^You see the guard in his buffness recover from the stab and partially block the exits");
   if(query_hp() < 0) set_hp(1);
   force_me("block out");
   force_me("block east");
}
