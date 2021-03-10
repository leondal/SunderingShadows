#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit OBJECT;

object caster,target,casting_spell;
int clevel, charges;

void checkDispel(object ob);
void dispel_em(object ob);

void create(){
    ::create();
    set_id( ({ "reaving_dispeller" }) );
    set_name("reaving_dispeller");
    set_short("");
    set_long("");
    set_weight(0);
    set_value(0);
    set_property("no animate",1);
    set_property("no offer", 1);
}

void set_caster(object obj){
    if(!objectp(obj)) { caster = 0; }
    else { caster = obj; }
    return;
}

void query_caster(){
   if(objectp(caster)){
      return caster;
   }
}

void set_target(object obj){
    if(!objectp(obj)) { target = 0; }
    else { target = obj; }
    return;
}

void set_clevel(int x){
   if(!intp(x)){
      clevel = 5;
   }else{
      clevel = x;
   }
   return;
}

void set_charges(int i){
   charges = i;
}

void set_casting_spell(object obj){
    if(!objectp(obj)) { casting_spell = 0; }
    else { casting_spell = obj; }
    return;
}

void dispel_em(object ob){
   object *myspells;
   int i, x;

   if(!objectp(TO)) { return; }
   target = ob;

   if(!objectp(ETO) || !living(ETO) || !objectp(caster) || target != ETO){
      TO->remove();
      return;
   }
   myspells = ({});
   if(charges > 0){
//      tell_object(caster,"%^B_BLUE%^%^BOLD%^%^GREEN%^You have "+charges+" charges available.%^RESET%^");
//for debugging only.
      myspells = target->query_property("spelled");
      if(myspells == ({}) || !sizeof(myspells)){
         tell_object(caster,"%^RED%^Your reaving dispel on "+target->QCN+" dissipates.%^RESET%^");
         target->remove_property("reaving dispel");
         TO->remove();
         return;
      }
      for(i=0;i<sizeof(myspells);i++){
         if(!objectp(myspells[i])) continue;
         if(!myspells[i]->is_spell()){
            myspells -= ({myspells[i]});
         }
      }

//      tell_object(caster,"%^B_BLUE%^%^BOLD%^%^GREEN%^Target has "+sizeof(myspells)+" spells to dispel.%^RESET%^");
//for debugging only
      x = random(sizeof(myspells));
      checkDispel(myspells[x]);
      charges -= 1;
      if(charges > 0){
         call_out("dispel_em",ROUND_LENGTH,target);
      }else{
         target->remove_property("reaving dispel");
         tell_object(caster,"%^RED%^Your reaving dispel on "+target->QCN+" dissipates.%^RESET%^");
//the above message can be removed after testing if we decide they shouldn't know.
         TO->remove();
         return;
      }
   }else{
      target->remove_property("reaving dispel");
      tell_object(caster,"%^RED%^Your reaving dispel on "+target->QCN+" dissipates.%^RESET%^");
//the above message can be removed after testing if we decide they shouldn't know.
      TO->remove();
      return;
   }
   return;
}

//Trying the standard dispel modifier from the books to see how it works.
//If this is balanced, I will likely update dispel magic to use the same formula.
//(Note: To make stats more meaningful, we might want to add the casting stat modifier)
//~Circe~ 11/19/15
//Per table top: You make a dispel check (1d20 + your caster level, maximum +10)
//against the spell or against each ongoing spell currently in effect on the object
//or creature. The DC for this dispel check is 11 + the spells caster level.
//Because we currently add 10 for greater dispel, I am not capping the level.
//We could revisit this as well.

void checkDispel(object ob){
   int roll, DC, buffered, mylvl,dam;
   object mycast;

   if(!objectp(ob)) return;
   if(!objectp(TO)) return;


   mycast = ob->query_caster();
   mylvl = ob->query_clevel();
   roll = roll_dice(1,20);

   DC = 11 + mylvl;

   dam = roll_dice(clevel,2);
   dam += clevel;
   if("/std/magic/dispel"->checkDispel(ob, clevel)){
      tell_object(caster,"%^BOLD%^You dispel "+target->QCN+"'s "+ob->query_spell_name()+"!%^RESET%^");
      target->remove_property_value("spelled", ({ob}));
      tell_object(target,"%^BOLD%^You feel a searing pain as your "+ob->query_spell_name()+" "
         "is ripped away from you!%^RESET%^");
      target->do_damage(target->return_target_limb(),dam);
      ob->dest_effect();
      return;
   }else{
      tell_object(caster, "%^BOLD%^You are unable to dispel a spell this round.%^RESET%^");
      return;
   }
}
