#include <std.h>
#include "/d/common/common.h"
#include "../tecqumin.h"

inherit MONSTER;

int dlvl;
object ob;

void create(){
   ::create ();
      set_name("Yuan-ti Abomination");
      set_id(({"yuan-ti","abomination","yuan-ti abomination","Abomination","Yuan-ti Abomination"}));
      set_short("A hulking yuan-ti");
      set_long("%^GREEN%^This massive creature would appear to be purely "
         "snake, were it not for the two well-muscled, scaled arms "
         "growing from its torso.  The creature moves quickly upon "
         "a snake's tail but stands upright - truly the stuff of "
         "nightmares for many.  Its cold, %^BOLD%^%^BLACK%^black "
         "eyes %^RESET%^%^GREEN%^glitter with a calculating "
         "intelligence, and in its countenance is malice.");
      set_race("yuan-ti");
      set_gender("male");
      set_body_type("snake");
      add_limb("left arm","torso",0,0,0);
      add_limb("right arm","torso",0,0,0);
      add_limb("left hand","left arm",0,0,0);
      add_limb("right hand","right arm",0,0,0);
      remove_limb("mouth");
      set_wielding_limbs(({"right hand","left hand"}));
      set_overall_ac(-12);
      set_size(2);
      dlvl = random(11)+55;
      set_hd(dlvl,12);
      set_money("gold",random(300)+121);
      set_money("silver",random(100)+23);
      set_money("copper",random(50)+175);
      set_money("electrum",random(75)+50);
      set_class("ranger");
      set_exp(dlvl*275);
      set_hp(dlvl*12);
      set_max_hp(query_hp());  
      set_alignment(9);
      set_property("full attacks",1);
      set_mlevel("ranger",dlvl);
  	set("aggressive",25);
      set_func_chance(30);
      set_funcs(({"bite","bite","bite","bite","constrict","constrict","spray","poison","poison"}));

//necklace of teeth/finger bones - +2 or 3 amulet/doesn't like goodies
//Spear of the Eclipse - obsidian headed spear decorated with roc feathers (taken from the neck)
//sickle of some sort
//Amulet of sun/dark god - changes depending on who wears it? - possibly put this on the mini-boss in the larger area
      switch(random(10)){
         case 0..9:  ob = new(OBJ+"macana");
                     ob->move(TO);
                     if(random(2)) ob->set_property("monsterweapon",1);
                     force_me("wield macana in left hand");
                     RANDGEAR->arm_me(TO,"edgeds",100,3,50);
                     break;
        default: break;
      }
}

//change bite
void bite(object target){
   tell_room(ETO,"%^RESET%^%^GREEN%^The Yuan-ti sinks its %^RESET%^fangs %^GREEN%^deep into "+target->query_cap_name()+"'s neck.",target);
   tell_object(target, "%^RESET%^%^GREEN%^The Yuan-ti lunges forward and sinks its %^RESET%^fangs %^GREEN%^deep into your neck!");
   target->cause_typed_damage(target, "torso", roll_dice(2, 8), "piercing");
   if(!"daemon/saving_d"->saving_throw(target,"paralyzation_poison_death",-2)){
      tell_object(target,"%^BOLD%^%^RED%^You feel poison "+
         "burning through your veins!%^RESET%^");
         target->add_poisoning(20);
   }
}

void constrict(object targ){
   return;
}

void spray(object *baddies){
   return;
}

/*Done as:
int ugly(object *baddies){
   int i;
   baddies = TO->query_attackers();
   if(!baddies) return 0;
   if(!objectp(TO)) return 0;
   tell_room(ETO,"The hag parts her sickly "+
      "green hair, revealing her horrific face!");
   for(i=0;i<sizeof(baddies);i++){
      if(!objectp(baddies[i])) continue;
      if(!objectp(TO)) continue;
      if((int)baddies[i]->query_stats("constitution") < random(22)){
         tell_object(baddies[i],"You are horrified by what you see!");
        
baddies[i]->do_damage(baddies[i]->return_target_limb(),roll_dice(1,6));
         baddies[i]->set_paralyzed(3+random(3),"You are shaking from the
sight!");
      }else{
         tell_object(baddies[i],"You resist the disgusting "+
            "appearance of the hag!");
      }
   }
   return 1;
}
*/

void poison(object targ){
   return;
}