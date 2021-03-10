#include <std.h>

inherit OBJECT;

object myowner;
int query_myowner();
int count;

void create(){
   ::create();
   set_name("prismatic wall");
   set_id(({"wall","prismatic wall","dragon wall","dream wall","wall of dreams"}));
   set_short("A prismatic wall of dreams");
   set_long("%^CYAN%^This wall flickers with the changing images of "+
      "flitting dreams...and recurring nightmares.  The wall "+
      "gives off no heat and casts no shadow, seeming made of "+
      "some ephemeral matter that is backed by force.");
   set_weight(100000);
   set_property("no animate",1);
   set_value(0);
   count = 0;
}

void surround(object ob) {
   int k,j;
   object *foes;
   string wallname;
   ob = myowner;
   add_action("end_walls","remove");
   foes = ob->query_attackers();
   j = sizeof(foes);
   for(k=0;k<j;k++) {
      if(!present(TO,environment(myowner))) continue;
      tell_room(environment(foes[k]),"%^BOLD%^%^CYAN%^The images "+
         "slam into "+foes[k]->QCN+" as they swirl, knocking "+
         ""+foes[k]->QO+" back!",foes[k]);
      tell_object(foes[k],"%^BOLD%^%^CYAN%^You are knocked back "+
         "by the force of the swirling images!");
      foes[k]->do_damage(foes[k]->return_target_limb(),12+random(11));
      if(objectp(foes[k]))
         foes[k]->continue_attack();
   }
   call_out("monitor",7);
}

void monitor() {
   int k,j;
   object *foes;

   if((!objectp(myowner) || !present(myowner->query_name(),ETO))) {
      remove_call_out("monitor");
      TO->remove();
   }
   if(count > 6){
      remove_call_out("monitor");
      TO->remove_wall();
      return;
   }
   foes = myowner->query_attackers();
   j = sizeof(foes);
   if(j < 1){
      remove_call_out("monitor");
      TO->remove_wall();
      return;
   }
   for(k=0;k<j;k++) {
      if(!objectp(foes[k])) continue;
      tell_room(environment(foes[k]),"%^BOLD%^%^CYAN%^The images "+
         "slam into "+foes[k]->QCN+" as they swirl, knocking "+
         ""+foes[k]->QO+" back!",foes[k]);
      tell_object(foes[k],"%^BOLD%^%^CYAN%^You are knocked back "+
         "by the force of the swirling images!");
      foes[k]->do_damage(foes[k]->return_target_limb(),12+random(11));
      if(objectp(foes[k]))
         foes[k]->continue_attack();
   }
   count ++;
   call_out("monitor",7);
}

void remove_wall() {
   if(objectp(TO) && objectp(ETO)) {
      tell_room(ETO,"%^BOLD%^%^WHITE%^The wall shimmers "+
         "and fades away!");
   }
   destruct(TO);
   return;
}

void set_myowner(object obj){
   myowner = obj;
}

int query_myowner(){
   return myowner;
}