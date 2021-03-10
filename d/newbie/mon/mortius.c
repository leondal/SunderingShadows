#include "../newbie.h"

inherit "/std/trainer";

void create(){
   ::create();
   set_name("mortius Skevenchoff");
   set_short("Mortius Skevenchoff, the weapon skill trainer");
   set_long("Before you is this average built human.  He is currently weaponless and standing near the entrance, leaning against the wall.  Though he does not look like a strong person, he is well known for his fighting skills and mastery of the art of all types of fighting.  He is always willing to train people.  He is not a karate enthusiast, he prefers fighting any one who has a weapon.  That way, he can be proved of his combat mastery.");
   set_hd(30,4);
   set_exp(1);
   set_property("no bows",1);
   set_stats("strength",10);
   set_stats("dexterity",20);
   set_max_hp(300);
   set_hp(300);
   set_id(({"mortius","skevenchoff","Mortius","trainer","weapon skill trainer"}));
   set_attack_limbs(({"right hand","left hand"}));
   set_attacks_num(1);
   set_damage(1,1);
   set_race("human");
   set_gender("male");
   set_base_damage_type("bludgeoning");
   set_overall_ac(0);
   remove_std_db();
   set_random_act_chance(10);
        new("/d/newbie/obj/misc/lpouch.c")->move(TO); //added in on advice of Tristan that we need more stealable things in newbieland Ts
}
