//Added set_max_level to retard cycling - Octothorpe 6/4/09
//native.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit MONSTER;

void create()
{
  object ob;
  ::create();
  set_name("Jungle native");
  set_id(({"native","Native","warrior"}));
  set_short("Jungle native warrior");
  set_long(
@OLI
    This smallish man stands before. An occasional screach of anger 
eminate from his mishapened mouth. Distrust and fear cross his face.
This is quite obviously his home and his place to live. He will defend
it from intruders with his life. He wields a spear or a small sword.
Once in a while you find one wielding a dagger or a bow. The hides he
wears seems to offer little protection but he does manage to avoid and 
move quickly.
OLI
          );
  
  set_class("fighter");
  set_race("human");
  set_body_type("humanoid");
  set_gender("male");
  set_hd(17+random(5),8);
  set_hp(roll_dice(query_hd(),16));
  set_overall_ac(-10);
  //set_exp(400*query_hd());
  set_new_exp(query_hd(),"normal");
  set_max_level(25);
  set_wielding_limbs(({"right hand","left hand"}));
  ob=new(OBJ+"spear1.c");
if(random(4))
{
	ob->set_property("monsterweapon",1);
}
	ob->move(TO);
command("wield spear in right hand");
  new("/d/common/obj/weapon/spear_sm.c")->move(TO);
  command("wield spear in left hand");
  set_property("full attacks",1);
  set_scrambling(1);
  set_property("swarm",1);

  set_stats("strength",20);
}

