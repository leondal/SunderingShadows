#include <std.h>
inherit OBJECT;

int stack,counter,healskill,i;
object *targweapon;
string *ids;

void create(){
   ::create();  
   set_name("");
   set_id(({"wound"}));
   set_short("");
   set_long("%^RESET%^%^RED%^This seething wound is bleeding profusely and causes you great pain. Maybe you can %^BOLD%^%^CYAN%^neutralize %^RESET%^%^RED%^the %^BOLD%^%^CYAN%^wound%^RESET%^%^RED%^.");
   set_value(0);
   set_weight(0);
   set_property("no animate", 1);
   counter = 0;
   set_heart_beat(1);
}

void init(){
   ::init();
   add_action("negative","give");
   add_action("negative","offer");
   add_action("neutralize","neutralize");
   ETO->set_property("esaucursed",1);
}

int neutralize(string str){
 if(str == "wound") {
   healskill = ETO->query_skill("healing");
   if((object)ETO->query_attackers() != ({})) {
      write("%^BOLD%^%^RED%^Not in the middle of a fight!");
      return 1;
   }
   if(healskill > 30) {
      write("%^BOLD%^%^CYAN%^You manage to treat the wound and stop the bleeding%^RESET%^!");
      tell_room(environment(ETO),"%^BOLD%^%^CYAN%^You see "+ETOQCN+" patch up "+ETO->query_possessive()+" wound and stop the bleeding%^RESET%^!",ETO);
      ETO->remove_property("woundstack");
      ETO->remove_propery("esaucursed");
      TO->remove();
      return 1;
   }else{
   write("%^BOLD%^%^RED%^You fail to treat the wound.");
   return 1;
   }
  }else{
  write("%^RESET%^%^CYAN%^Neutralize what%^RESET%^?");
  return 1;
  }
}

void bleed(){
   if(!objectp(ETO)){return;}
   if(ETO->query_hp() < 1 && (!ETO->is_player()) ){
      ETO->remove_property("woundstack");
      ETO->remove_property("esaucursed");
      TO->remove();
      return 1;
   }
   if(ETO->query_ghost()){
      ETO->remove_property("woundstack");
      ETO->remove_property("esaucursed");
      TO->remove();
      return 1;
   }
   tell_object(ETO,"%^RESET%^%^RED%^You have a gaping wound that will not stop bleeding%^RESET%^!");
   tell_room(environment(ETO),"%^RESET%^%^RED%^"+ETOQCN+" has a gaping wound that will not stop the bleeding%^RESET%^!",ETO);
   stack = ETO->query_property("woundstack");
   set_property("magic",1);
   ETO->do_damage("torso",stack);
   set_property("magic",-1);
   counter ++;
   return 1;
}

void death1(){
if(!objectp(ETO)){ return;}
   if(ETO->query_hp() < 1 && (!ETO->is_player()) ){
      ETO->remove_property("woundstack");
      ETO->remove_property("esaucursed");
      TO->remove();
      return 1;
   }
   if(ETO->query_ghost()){
      ETO->remove_property("woundstack");
      ETO->remove_property("esaucursed");
      TO->remove();
      return 1;
   }
tell_object(ETO,"%^RESET%^%^GREEN%^An %^BOLD%^%^BLACK%^u%^BOLD%^%^GREEN%^n%^BOLD%^%^BLACK%^b%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^r%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^b%^BOLD%^%^BLACK%^l%^RESET%^%^GREEN%^e pain shoots through your entire body and it brings you to your knees%^RESET%^!");
tell_room(environment(ETO),"%^RESET%^%^GREEN%^"+TPQCN+" tumbles down to "+TP->query_possessive()+" knees%^RESET%^!",ETO);
set_property("magic",1);
ETO->do_damage("torso",random(100)+1);
set_property("magic",-1);
ETO->set_paralyzed(7,"%^BOLD%^%^GREEN%^The pain is overwhelming%^RESET%^!");
call_out("death2",10);
return 1;
}

void death2(){
if(!objectp(ETO)){ return;}
   if(ETO->query_hp() < 1 && (!ETO->is_player()) ){
      ETO->remove_property("woundstack");
      ETO->remove_property("esaucursed");
      TO->remove();
      return 1;
   }
   if(ETO->query_ghost()){
      ETO->remove_property("woundstack");
      ETO->remove_property("esaucursed");
      TO->remove();
      return 1;
   }
tell_object(ETO,"%^RESET%^%^CYAN%^You begin to clasp at your throat as you feel the airwaves to your lungs close from the swelling in your throat%^RESET%^!");
tell_room(environment(ETO),"%^RESET%^%^CYAN%^"+TPQCN+" frantically rips and grabs at "+TP->query_possessive()+" throat%^RESET%^!",ETO);
set_property("magic",1);
ETO->do_damage("torso",random(100)+1);
set_property("magic",-1);
ETO->set_paralyzed(7,"%^BOLD%^%^GREEN%^The pain is overwhelming%^RESET%^!");
call_out("death3",10);
return 1;
}

void death3(){
if(!objectp(ETO)){ return;}
   if(ETO->query_hp() < 1 && (!ETO->is_player()) ){
      ETO->remove_property("woundstack");
      ETO->remove_property("esaucursed");
      TO->remove();
      return 1;
   }
   if(ETO->query_ghost()){
      ETO->remove_property("woundstack");
      ETO->remove_property("esaucursed");
      TO->remove();
      return 1;
   }
tell_object(ETO,"%^BOLD%^%^RED%^You can feel your heart beat speeding up, each thump bringing excruciating pain to your chest%^RESET%^!");
tell_room(environment(ETO),"%^BOLD%^%^RED%^"+TPQCN+" begins to claw at "+TP->possessive()+" in a mad panic%^RESET%^!",ETO);
set_property("magic",1);
ETO->do_damage("torso",random(100)+1);
set_property("magic",-1);
ETO->set_paralyzed(7,"%^BOLD%^%^GREEN%^The pain is overwhelming%^RESET%^!");
call_out("death4",10);
return 1;
}

void death4(){
if(!objectp(ETO)){ return;}
   if(ETO->query_hp() < 1 && (!ETO->is_player()) ){
      ETO->remove_property("woundstack");
      ETO->remove_property("esaucursed");
      TO->remove();
      return 1;
   }
   if(ETO->query_ghost()){
      ETO->remove_property("woundstack");
      ETO->remove_property("esaucursed");
      TO->remove();
      return 1;
   }
tell_object(ETO,"%^RESET%^%^RED%^Everything around is starting to be come %^BOLD%^%^BLACK%^h%^RESET%^a%^BOLD%^%^BLACK%^z%^RESET%^y %^RESET%^%^RED%^and you are losing your orientation%^RESET%^!");
tell_room(environment(ETO),"%^RESET%^%^BLUE%^"+TPQCN+" appears highly disoriented%^RESET%^.",ETO);
call_out("death5",10);
return 1;
}

void death5(){
if(!objectp(ETO)){ return;}
   if(ETO->query_hp() < 1 && (!ETO->is_player()) ){
      ETO->remove_property("woundstack");
      ETO->remove_property("esaucursed");
      TO->remove();
      return 1;
   }
   if(ETO->query_ghost()){
      ETO->remove_property("woundstack");
      ETO->remove_property("esaucursed");
      TO->remove();
      return 1;
   }
tell_object(ETO,"%^BOLD%^%^RED%^Blood %^BOLD%^%^BLACK%^pours out from all of your orifices and your world turns utterly dark%^RESET%^!");
tell_room(environment(ETO),"%^BOLD%^%^RED%^Blood %^BOLD%^%^BLACK%^pours out from all of "+ETOQCN+"'s orifices and "+ETO->query_possessive()+" collapses%^RESET%^!",ETO);
set_property("magic",1);
ETO->do_damage("torso",random(100)+10000);
set_property("magic",-1);
return 1;
}

void heart_beat(){
 if(!objectp(ETO)){ return;}
   if(ETO->query_ghost()){
      ETO->remove_property("woundstack");
      ETO->remove_property("esaucursed");
      TO->remove();
      return 1;
   }
   if(counter > 10) {
      ETO->remove_property("woundstack");
      ETO->remove_property("esaucursed");
      TO->remove();
      return 1;
   }
   if(!random(999)) {
      call_out("death1",1);
      return 1;
      }else{
         if(!random(30)) {
            if((!sizeof(ETO->query_wielded())) || (!ETO->is_player())) {
              return 1;
              }else{
            tell_object(ETO,"%^RESET%^%^GREEN%^A pain shoots through your hands that causes to drop your weapon%^RESET%^!");
            tell_room(environment(ETO),"%^RESET%^%^GREEN%^"+ETOQCN+" winces and drops "+ETO->query_possessive()+" weapon%^RESET%^!",ETO);
         targweapon = ETO->query_wielded();
         i = random(sizeof(targweapon));
         ids = targweapon[i]->query_id();
         ETO->force_me("unwield "+ids[0]);
         return 1;
             }
            }else{
               call_out("bleed",1);
               return 1;
            }
      }
}

int drop(){
        return 1;
        }
int give(){
        return 1;
        }
int negative(string str){
        if(id(str)) return 1;
        }