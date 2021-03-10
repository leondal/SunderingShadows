//cloak of the forests
//moved the hidden 1AC to an enchantment, nienne 05/07
#include <std.h>
inherit ARMOUR;
int hood;

void create(){
    ::create();
    set_name("%^RESET%^%^GREEN%^Cloak of the forests%^RESET%^");
    set_id(({"armor","cape","forest cloak","cloak of forests","Cloak of the forests","Forest Cloak","cloak of forest","cloak","Cloak of the Forests"}));
    set_short("%^RESET%^%^GREEN%^Cloak of the forests%^RESET%^");
    set_obvious_short("%^RESET%^%^GREEN%^A dark green cloak%^RESET%^");
    set_long("%^RESET%^%^GREEN%^This is a long green felt cloak.  It has a hood that can be pulled up over the"
" wearers head and is held in place by a simple green string that ties around the neck.  The cloak is thick"
" and warm looking, and would easily reach the ankles of an average sized person.  Within the green material"
" of the cloak, strange leaf patterns have been etched.  Once in a while, the cloak changes from one shade"
" of green to another.%^RESET%^\n");
   set_lore("%^RESET%^%^GREEN%^You recognize this as the fabled Cloak of the forests, designed by the"
" centaurs that still hide within the Yntala Forest.  Rumor has it that the centaurs have been backed into"
" hiding within their own glade, the only place within the forest that managed to escape the taint of the evil"
" mages that had taken over, and are extremely grateful to any that help them rid the forest of the summoned"
" yuan-ti.  This cloak is the reward given for returning the cloaks obtained by killing the vile yuan-ti.");
   set_weight(3);
   set_type("clothing");
   set_limbs(({"neck",}));
   set_property("enchantment",2);
   set_value(1000);
   set_wear((:TO,"wear_it":));
   set_remove((:TO,"unwear_it":));
   hood = 0;
}

int wear_it(string str){
    tell_object(ETO,"%^RESET%^%^GREEN%^You wear the cloak with pride as you remember the aid you've given the centaurs.%^RESET%^");
    tell_room(environment(ETO),"%^RESET%^%^GREEN%^"+ETO->query_cap_name()+" wraps the cloak around "+ETO->query_objective()+" with pride.%^RESET%^",ETO);
return 1;
}
int unwear_it(string str){
   if(ETO->query_hidden()){
      tell_object(ETO,"%^RESET%^%^GREEN%^You slowly remove the cloak and realize that you've lost the protection it gave you.%^RESET%^");
      ETO->set_hidden(0);
      hood = 0;
      return 1;
   }
   tell_object(ETO,"%^RESET%^%^GREEN%^A sense of disappointment overcomes you as you remove the cloak.%^RESET%^");
   return 1;
   if(hood == 1){
    hood = 0;
   }
   return 1;
}
void init() {
    ::init();
  if(!objectp(TP)) return;
  if (!objectp(ETO)) return;
  if (TP != ETO) return;
  if(interactive(TP) && !avatarp(TP)) {
     set_size(TP->query_size());
  }
    add_action("lift","lift");
    add_action("lower","lower");
}
void lower(string str){
   if(!objectp(ETO)){
   return 1; 
   }
   if(!str) notify_fail("What are you trying to do, lower the hood?");
   if(str == "hood"||str=="the hood"){             
      if(hood==1){
         if(ETO->query_hidden()){
             tell_object(ETO,"%^RESET%^%^GREEN%^You slowly lower the hood and realize that you've lost the protection it gave you.%^RESET%^");
             ETO->set_hidden(0);
             hood = 0;
         return 1;
         }
         tell_object(ETO,"%^RESET%^%^GREEN%^You slowly lower the hood.%^RESET%^");
         tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" slowly lowers the hood from "+ETO->query_objective()+" head.",ETO);
         hood = 0;
      return 1;
      }
      else if(hood==0){
         tell_object(ETO,"%^RESET%^%^GREEN%^You aren't wearing the hood!%^RESET%^");
      return 1;
      }
   }
}

void lift(string str){
   if(!objectp(ETO)){
   return 1; 
   }
   if(!str) notify_fail("What are you trying to do, lift the hood?");
   if(hood==1){
   	tell_object(ETO,"%^RESET%^%^GREEN%^You are already wearing the hood!%^RESET%^");
   return 1; 
   }
   if(!TO->query_worn()){ 
	tell_object(ETO,"%^RESET%^%^GREEN%^You must be wearing the cloak to lift the hood!%^RESET%^");
   return 1; 
   }
    if(environment(ETO)->query_property("indoors")) {
        tell_object(ETO,"You lift the hood over your head and realize that you must be outdoors to blend in with nature.");
        hood = 1;
        return 1;
   }
   else if(str == "hood"||str=="the hood"){             
   tell_object(ETO,"%^BOLD%^%^GREEN%^You lift the hood over your head and disappear into the surrounding wild!%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" lifts the hood over "+ETO->query_objective()+" head and suddenly blends in with the surrounding nature!",ETO);
   new("/cmds/spells/m/_meld_into_nature.c")->use_spell(ETO,ETO->query_name(),10,100,"ranger");
   hood = 1;
   return 1;
   }
   return 1;
}

