#include <std.h>
#include "/d/common/common.h"

inherit "/std/monster";

int num;
create() {
  ::create();
  set_name("anti-paladin");
  set_id(({"ingmar","Ingmar","anti paladin","anti-paladin"}));
  set("race","human");
  set_gender("male");
  set("short","Ingmar, anti-paladin");
  set("long","This figure of death in black plate mail armor is Ingmar, \n"+
              "lord of the Dark fighters.  He is an enchanted Anti-Paladin\n"+
            "a magically powered defender of evil.  Upon his shoulder is\n"+
              "an emblem, a black background with a red hawk in front.\n");
  set_class("antipaladin");
  set_level(13);
  set_body_type("human");
  set("aggressive", 16);
  set_alignment(9);
  set_size(2);
  set_hd(12,3);
  set_stats("strength", 19);
  set_stats("wisdom", 15);
  set_stats("intelligence", 16);
  set_stats("charisma", 17);
  set_stats("dexterity", 18);
  set_stats("constitution", 18);
  set_wielding_limbs(({"right hand","left hand"}));
  new("/d/deku/armours/plate")->move(TO);
  command("wear platemail");
  RANDGEAR->arm_me(TO, "edgedm", 15, 1);
//  new("/d/common/obj/weapon/two_hand_sword")->move(TO);
//  command("wield sword in right hand and left hand");
  add_money("gold", random(200));
  set_hp(115);
  set_overall_ac(2);
  set_mob_magic_resistance("average");
  set_funcs(({"thrust","heal_self"}));
  set_func_chance(50);
  num = 1;
  set_max_level(15);
}

void thrust(object targ) {
  if(targ->query_level() < 10) {
    tell_room(environment(targ), "%^GREEN%^The Anti-paladan thrusts his weapon towards "+targ->query_cap_name()+"!\n",targ);
    tell_object(targ, "The Anti-paladin thrusts his weapon at you!\n");
    targ->do_damage("torso", roll_dice(2,10)+2);
    return 1;
  }
    tell_room(environment(targ), "%^RED%^The Anti-paladin thrusts his weapon towards "+targ->query_cap_name()+" inflicting extreme damage!\n",targ);
  tell_object(targ, "The Anti-paladin thrusts his weapon toward you doing extreme damage!\n");
  targ->do_damage("torso", roll_dice(3,10)+4);
  return 1;
}

void heal_self() {
  if(num == 0 ) {
    tell_room(ETO, "The Anti-paladin places his hands upon his breastplate.\n");
    add_hp(random(6));
    return 1;
  }
  tell_room(ETO, "%^MAGENTA%^The Anti-paladin places his hands upon his breastplate.\n");
  add_hp(12);
  num = 0;
  return 1;
}
void reset(){
   object ob;
   ::reset();
   if(!present("scroll")){
	  ob = new("/d/magic/scroll");
     ob->set_spell(3);
     ob->move(TO);
   }
}
