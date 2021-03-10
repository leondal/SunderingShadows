#include <std.h>
inherit OBJECT;

void set_caster(object ob);
void set_spell(object ob);
void query_caster();
void query_spell();

object caster, spell;

void create(){
   ::create();
   set_name("curse breaker");
   set_short("");
   set_id(({"cursebreaker111"}));
   set_long(
      "This is a curse breaker. If you can see this, something "
      "has gone wrong. Please alert a wiz.");
   set_weight(0);
   set_property("no animate", 1);
}

int clean_up(){
    if(!objectp(TO)) { return 1; }
    if(objectp(ETO)) { return 1; }
    destruct(TO);
    return 1;
}

void dest_effect(){
    destruct(TO);
}

void set_caster(object ob){
   caster = ob;
}

void set_spell(object ob){
   spell = ob;
}

void query_caster(){
   return caster;
}

void query_spell(){
   return spell;
}

void init(){
   ::init();
   write("Please input the cursed item you would like to target, e.g., 'sword on John'.");
   write("If the item is in your inventory, use 'on me', e.g., 'sword on me'.");
   write("If the item is on the ground, the second object should be 'on room', e.g., 'sword on room'.");
   write("Type ** to quit.");
   input_to("break_em");
   return;
}

void break_em(string str){
   object ob, ob2;
   string what, who;
   int ench;
   if(!str){
      write("Please input the cursed item you would like to target, e.g., 'sword on John'.");
      write("If the item is in your inventory, use 'on me', e.g., 'sword on me'.");
      write("If the item is on the ground, the second object should be 'on room', e.g., 'sword on room'.");
      write("Type ** to quit.");
      input_to("break_em");
      return;
   }
   if(str == "**"){
      write("Unravel psionics aborted.");
      spell->dest_effect();
      TO->dest_effect();
      return;
   }

   caster = TO->query_caster();
   spell = TO->query_spell();
   if(sscanf(str,"%s on %s",what, who) != 2){
      tell_object(ETO,"Error: you must name the object and location, e.g., 'sword on me'.");
      spell->dest_effect();
      TO->dest_effect();
      return;
   }
   if(who == "me"){
      ob = present(what,ETO);
      ob2 = caster;
   }
   if(who == "room"){
      ob = present(what,EETO);
      ob2 = EETO;
   }
   if(who && ob2 != caster && ob2 != EETO){
      if((string)caster->realName(who) != "") who = (string)caster->realName(who);   
      if(!ob2 = present(who, EETO)) {
         tell_object(caster,"That person isn't here.");
         spell->dest_effect();
         TO->dest_effect();
         return;
      }
      ob = present(what,ob2);
   }
   if (!objectp(ob)) {
      tell_object(caster,"That object is not present");
      spell->dest_effect();
      TO->dest_effect();
      return;
   }
   ench = ob->query_property("enchantment");
   if (ench > -1) {
      tell_object(caster,"That object is not cursed.");
      spell->dest_effect();
      TO->dest_effect();
      return;
   }
   if(ob->query_property("no remove") || ob->query_property("no remove curse")) {
        tell_object(caster,"That curse is too powerful even for you to break.");
        spell->dest_effect();
        TO->dest_effect();
        return;
    }
    ob->remove_property("enchantment");
    tell_object(caster,"%^BOLD%^%^WHITE%^With a powerful thrust of mental "
       "%^CYAN%^energy%^WHITE%^, you break the curse on the "+what+"!%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^WHITE%^The %^CYAN%^air%^WHITE%^ around "
       ""+caster->QCN+" crackles with %^CYAN%^energy %^WHITE%^as "+caster->QS+" "
       "breaks a curse on the "+what+"!%^RESET%^",caster);
    spell->dest_effect();
    TO->dest_effect();
    return;
}

int drop(){
   return 1;
}

int is_detectable() { return 0; }
int query_invis() { return 1; }

