//goblinp.c

#include <std.h>
#include <daemons.h>

inherit WEAPONLESS;


void create(){
   int flag1,i;
   string *tmp;
   ::create();
   set_long(
@OLI
   This little creature died while a prisoner here. He died from
either being tortured to death or starvation or in a prisoner
fight. Pain creases his face. His only wish is to show you his pain.
OLI
   );
   flag1 = random(4);
   switch (random(10)) {
   case 0:
      set_name("goblin spirit");
      set_short("Goblin Spirit");
      set_id(({"goblin","spirit","goblin spirit"}));
      break;
   case 1:
      set_name("kobold ghost");
      set_short("Kobold ghost");
      set_id(({"ghost","kobold","kobold ghost"}));
      break;
   case 2:
      set_name("gnomish shade");
      set_short("Gnomish Shade");
      set_id(({"shade","gnome","gnomish shade"}));
      break;
   case 3:
      set_name("dwarven spirit");
      set_short("Dwarven spirit");
      set_id(({"spirit","dwarf","dwarven spirit"}));
      break;
   case 4:
      set_name("halfling ghost");
      set_short("Halfling ghost");
      set_id(({"ghost","halfling","halfling ghost"}));
      break;
   case 5:
      set_name("kobold wraith");
      set_short("Kobold wraith");
      set_id(({"kobold","wraith","kobold wraith"}));
      break;
   case 6:
      set_name("dwarven ghost");
      set_short("Dwarven ghost");
      set_id(({"ghost","dwarf","dwarven ghost"}));
      break;
   case	7:
      set_name("gnomish wraith");
      set_short("Gnomish wraith");
      set_id(({"gnome","wraith","gnomish wraith"}));
      break;
   case	8:
      set_name("goblin shade");
      set_short("Goblin shade");
      set_id(({"goblin","shade","goblin shade"}));
      break;
   case	9:
      set_name("halfling wraith");
      set_short("Halfling wraith");
      set_id(({"halfling","wraith","halfling wraith"}));
      break;
      }
   set_size(1);
   set_attack_bonus(3);
   set_property("swarm",1);
   set_moving(1);
   set_speed(40);
   set_mob_magic_resistance("average");
   set_gender("male");
   set_race("undead");
   set_hd(random(6)+6,8);
   set_hp(query_hd()*8);
   set_exp((query_hd()*100) + flag1*200);
   set_max_level(16);
   tmp = ({});
   set_body_type("human");
   add_money("silver",random(300));
   add_money("electrum",random(150));
   for(i=0;i<flag1;i++){
      switch (random(4)) {
      case 0:
	 set_hit_funcs((["right hand":(:TO,"ED":),"left hand":(:TO,"ED":)]));
	 set_exp(query_exp() + 1500);
      case 1:
         tmp += ({"scream"});
      case 2:
	 tmp += ({"fear"});
      case 3:
	 tmp += ({"berserk"});
      }
   }
   set_funcs(tmp);
   add_id("small thing");
   if(sizeof(tmp)) set_func_chance(30);
   set_overall_ac(0);
   set_stats("strength",17);
   set_stats("dexterity",15);
   set_attack_limbs(({"right hand","left hand"}));
   set_attacks_num(2);
   set_damage(2,4);
   set_base_damage_type("bludgeoning");
}

int query_watched() {
   return random(100);
}

int ED(object targ){
   string *classes, curclass;
   int i,hp_loss;
   if(!random(2)){
      if (targ->query_exp()>1000) {
          tell_object(targ,"%^RED%^You are hit with an energy drain.");
          targ->add_exp(-1000);
          classes = targ->query_classes();
          for(i=0;i<sizeof(targ->query_classes());i++){
	     curclass = classes[i];
             while((int)ADVANCE_D->get_exp(targ->query_class_level(curclass),curclass, targ) > ((int)targ->query_exp()/sizeof(classes))){
                targ->set_mlevel(curclass,(int)targ->query_class_level(curclass) - 1);
                hp_loss = ADVANCE_D->get_hp_bonus(curclass,targ->query_stats("constitution"),targ->query_cass_level(curclass),TO);
                targ->set_max_hp(((int)targ->query_max_hp() - hp_loss));
                targ->reduce_my_skills(curclass);
                targ->reduce_my_skills(curclass);
                if(interactive(targ)){
                    if(!wizardp(targ)){
	    	       ADVANCE_D->class_news(curclass,targ->query_cap_name()+" has lost a level to energy drain!");
                    }
		}
	     }
	  }
      }
   }
   return 1;
}

int scream(object targ){
int i,j;
   object *inven;

   inven = all_living(ETO);

   j = sizeof(inven);
   tell_room(ETO,"The "+query_name()+" screams horribly with a cold seering scream.");
      for(i=0;i<j;i++){
      if(!objectp(inven[i])) continue;
      if(inven[i] == TO) continue;
      set_property("magic",1);

      tell_object(inven[i],"The keening wail strikes you down shaking your soul.\n");
      if("daemon/saving_d"->saving_throw(inven[i],"breath_weapon",-5))
         inven[i]->do_damage("torso",roll_dice(2,6));
      else {
         inven[i]->do_damage("torso",roll_dice(1,6));

         if ( "daemon/saving_d"->saving_throw(inven[i],"breath_weapon",-5)) {
            inven[i]->set_paralyzed((8+roll_dice(1,4))*8,"The fear from the scream still paralyzes you.");

         } else
            inven[i]->add_attack_bonus(-1);
      }
      remove_property("magic");
   }
   return 1;
}

int berserk(object targ){
   set_func_chance(0);
   tell_room(ETO,"%^BOLD%^The "+query_name()+"'s anger rises and it suddenly explodes in a massive attack.");
   execute_attack();
   execute_attack();
   execute_attack();
   set_func_chance(30);
   return 1;
}

int fear(object targ){
   if(!objectp(targ)) return 1;

   tell_room(ETO,"%^BOLD%^Suddenly fear overcomes "+targ->query_cap_name()+", and "+targ->query_subjective()+" flees.",targ);
   tell_object(targ,"You are over come with fear.");
   targ->run_away();
   targ->run_away();
   targ->run_away();
   targ->run_away();
   return 1;
}