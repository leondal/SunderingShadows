//Added set_max_level to retard cycling - Octothorpe 6/4/09
//native.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit MONSTER;

void create()
{
object obj;
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
  set_hd(20+random(15),8);
  set_hp(roll_dice(query_hd(),16));
  set_overall_ac(-3);
  set_exp(700*query_hd());
  set_new_exp(25,"very high");
set_max_level(25);
  set_wielding_limbs(({"right hand","left hand"}));
  if(!random(2)){
     new(OBJ+"spear2.c")->move(TO);
  }else{
     obj = new("/d/common/obj/weapon/spear_lg");
     obj->set_property("enchantment",3);
     obj->move(TO);
  }
  command("wield spear in right hand and left hand");
  obj = new(OBJ+"hide.c");
  if(random(3)){
     obj->set_property("monsterweapon",1);
  }
  obj->move(TO);
  command("wear woven");
  set_property("full attacks",1);
  set_scrambling(1);
  set_property("swarm",1);
  new(OBJ+"gpouch")->move(TO);
  command("wear pouch");
  new(OBJ+"gem")->move(TO);
  command("put gem in pouch");
  set_stats("strength",20);
}

