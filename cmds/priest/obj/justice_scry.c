//Adapted from shadowlistener for use with Mark 
//of Justice by ~Circe~ - rebalancing the domains
//4/26/08

#include <std.h>

inherit MONSTER;

object caster, follower,controller;
void self_destruct();
void set_scry_power(int x);
void query_scry_power();
void query_mycaster();
void set_controller(object obj);

int power;

void create(){
   ::create();

   set_name("justicescry");
   set_property("no detect",1);
   set_id(({"JusticeScry"}));
   set_short(0);
   set_invis();
   add_limb("body","",0,0,0);
}

int move(mixed dest){
   ::move(dest);
}

set_caster(object cas){
   caster = cas;
}

void query_mycaster(){
   return caster;
}

set_target(object ob){
   follower = ob;
}

set_controller(object obj){
   controller = obj;
}

void die(object ob){
}

void heart_beat(){
	if(!objectp(caster)) { self_destruct(); return; }
   if(!objectp(follower)) { self_destruct(); return; }
   if(ETO != environment(follower))
      move(environment(follower));
   if(ETO->query_property("no scry")) { self_destruct(); return; }
   if(present("blockerx111", ETO)) { self_destruct(); return; }
   if(!objectp(controller))  { self_destruct(); return; }
}

dest_me(){
//   tell_object(follower,"%^YELLOW%^A strange, oppressive weight you "+
//      "hardly noticed is suddenly lifted from you!%^RESET%^");
   remove();
}

catch_tell(string str){
   if(!objectp(caster)){
      self_destruct();
      return;
   }
   tell_object(caster,"%^YELLOW%^You see:%^RESET%^   "+str);

}

int do_damage(string str, int i){
    return 0;
}

int is_invincible(){ return 1;}
int is_detectable(){ return 0;}

int id(string str){
    if(objectp(TP) && !avatarp(TP)) return 0;
    else return ::id(str);
}
object query_caster() { return caster; }

void set_invis() {
  if (TO->query_invis())
    return;
  else ::set_invis();
  return;
}

void set_scry_power(int x){
   power = x;
}

void query_scry_power(){
   return power;
}

void self_destruct() {
int i;
object casterobj,*spells = ({});
   casterobj = find_player(caster);
   if(objectp(follower)){
      tell_object(casterobj,"Removing property from marked.");
      follower->remove_property("justice marked");
   }
   if(objectp(controller)){
      tell_object(casterobj,"Removing controller object.");
      controller->remove();
   }
   if(objectp(casterobj)){
      casterobj->remove_property("justice marker");
      spells += casterobj->query_property("dispellable spells");
      for(i=0;i<sizeof(spells);i++){  
         if(objectp(spells[i])){
            if(!spells[i]->query_target_object()){
               if((string)spells[i]->query_spell_name() == "mark of justice"){
                  if(!objectp(spells[i])) return notify_fail("Your mark of justice seems to have been lost.\n");
                  tell_object(casterobj,"Something seems to have blocked your mark of justice!", TP);
                  if(objectp(TO)) dest_me();
                  spells[i]->removeSpellFromCaster();
               }
            }
         }
      }
   }
   if(objectp(TO)) dest_me();
   return;
}

int is_priest_scry(){ return 1; }