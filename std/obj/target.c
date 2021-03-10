//

#include <std.h>
#include <daemons.h>

inherit MONSTER;


int difficulty;

void set_difficulty(int i){
    difficulty = i;

}


bow_hit(object bow){
   int i;

   string skill = bow->query_lr_prof_type();

   for (i = 0;i<(difficulty*1);i++) {
      SKILLS_D->training_formula(TP, skill);
   }
  tell_room(ETP,"%^BOLD%^"+TPQCN+" hits the "+query_cap_name()+"!",TP);
}


create(){
   ::create();

   set_name("Archery Target");
   set_short("Archery Target");
   set_id(({"target","archery target",}));
   set_long(
@OLI
   This is an Archery target. Archers shoot from varying distances to attempt to hit this target.
OLI
   );
   set_hp(9999999);
    set_ac(10);
   add_limb("target","target",0,0,0);
   
}

int query_paralyzed(){
   return 1;
}




