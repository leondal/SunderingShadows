//removed mylevel scoping to spell_effect(), global mylevel was not being set -- Yves 11/18
#include <std.h>
#include <priest.h>
#include <party.h>

inherit SPELL;

int myresist, resistflag, extra, flag, bonus, mybonus, mylevel;
object *party_members=({}),*oppressed=({});
string mytype;

void emote_em();

void create() {
    ::create();
    set_spell_name("form of doom");
    set_spell_level(([ "psywarrior" : 6 ]));
    set_syntax("cast CLASS form of doom");
    set_spell_sphere("psychometabolism");
    set_description("The manifester calls on the stuff of nightmares, disguising "
       "himself in a terrifying visage of sleek, lashing tentacles. Your horrific "
       "appearance is enough to shake the confidence of those who oppose you, while "
       "the form bolsters you, granting you some extra strength and protection from "
       "both physical attacks and fire-based assaults. This power does not stack with "
       "other damage resistance spells and powers (e.g. iron body, oak body, stoneskin, resist energy).");
    set_verbal_comp();
    set_arg_needed();
    set_save("will");
}

int preSpell() {
   if (caster->query_property("form of doom")) {
      tell_object(caster,"You are already under the effects of this power!");
      return 0;
   }
   if(caster->query_stoneSkinned() || caster->query_property("iron body") || caster->query_property("castspellresist")){
      tell_object(caster,"You already have protection of this nature!");
      return 0;
   }
   return 1;
}

void spell_effect(int prof) {
   mylevel = clevel;
   tell_room(environment(caster),"%^BOLD%^%^BLACK%^The s%^RESET%^h%^RED%^a"
      "%^BOLD%^%^RED%^d%^RESET%^%^RED%^o%^RESET%^w%^BOLD%^%^BLACK%^s %^BOLD%^"
      "%^BLACK%^embrace "+caster->QCN+", caressing "+caster->QO+" before "
      "elongating and taking the shape of horrifying t%^RED%^e%^RESET%^%^RED%^n"
      "%^RESET%^t%^BOLD%^%^BLACK%^a%^RESET%^c%^RED%^l%^BOLD%^e%^BLACK%^s obscuring "
      ""+caster->QP+" visage.%^RESET%^",caster);
   tell_object(caster,"%^BOLD%^%^BLACK%^You bend reality, pulling the very "
      "s%^RESET%^h%^RED%^a%^BOLD%^%^RED%^d%^RESET%^%^RED%^o%^RESET%^w%^BOLD%^%^BLACK%^s "
      "%^BOLD%^%^BLACK%^around you. They embrace you, elongating and taking the shape "
      "of horrifying t%^RED%^e%^RESET%^%^RED%^n%^RESET%^t%^BOLD%^%^BLACK%^a%^RESET%^c"
      "%^RED%^l%^BOLD%^e%^BLACK%^s obscuring your visage.%^RESET%^");
   if(caster->query_stats("strength") > 29){
      mybonus = 0;
   }else if(caster->query_stats("strength") > 28){
      mybonus = 1;
   }else{
      mybonus = 2;
   }
   if(mybonus){
      caster->add_stat_bonus("strength",mybonus);
   }
   bonus = mylevel/8;
   bonus++;
   if(bonus < 1) bonus = 1; //shouldn't be possible
   caster->set_property("spelled", ({TO}) );
   caster->set_property("iron body",1);
   caster->set_property("form of doom",1);
   caster->set_property("damage resistance",5); //iron body is 15, oak body is 10
   caster->set_resistance("fire",mylevel);
   caster->set_property("castspellresist",1);
   addSpellToCaster();
   spell_successful();
   environment(caster)->addObjectToCombatCycle(TO,1);
   call_out("emote_em",15*ROUND_LENGTH);
   spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 5 + 1800;
   set_end_time();
   call_out("dest_effect",spell_duration);
}

int party_filter(object obj){
    if(!objectp(obj)) { return 0; }
    if(member_array(obj,party_members) != -1) { return 0; }
    return 1;
}

void execute_attack(){
   object *inven,room,*tmp,ppl;
   string party,baddie;
   int i;
   if(!flag){
      ::execute_attack();
      flag = 1;
      return;
   }
   if(!objectp(caster)){
      dest_effect();
      return;
   }
   ppl = caster->query_current_attacker();
   if (ppl && objectp(ppl)){
      baddie = ppl->QCN;
      extra = ((mylevel*2)/3);
      if(!objectp(ppl)) return;
      tell_room(environment(caster),"%^BOLD%^%^BLACK%^The writhing t%^RED%^e%^RESET%^%^RED%^n"
      "%^RESET%^t%^BOLD%^%^BLACK%^a%^RESET%^c%^RED%^l%^BOLD%^e%^BLACK%^s surrounding "
         ""+caster->QCN+" lash out at "+baddie+" with a sickening %^RESET%^%^RED%^sm%^BOLD%^a"
         "%^RESET%^%^RED%^ck%^BOLD%^%^BLACK%^!%^RESET%^",({caster,ppl}));
      tell_object(caster,"%^BOLD%^%^BLACK%^The writhing t%^RED%^e%^RESET%^%^RED%^n"
      "%^RESET%^t%^BOLD%^%^BLACK%^a%^RESET%^c%^RED%^l%^BOLD%^e%^BLACK%^s surrounding "
         "you lash out at "+baddie+" with a sickening %^RESET%^%^RED%^sm%^BOLD%^a"
         "%^RESET%^%^RED%^ck%^BOLD%^%^BLACK%^!%^RESET%^");
      tell_object(ppl,"%^BOLD%^%^BLACK%^You gasp in pain as the writhing t%^RED%^e%^RESET%^%^RED%^n"
      "%^RESET%^t%^BOLD%^%^BLACK%^a%^RESET%^c%^RED%^l%^BOLD%^e%^BLACK%^s surrounding "
         ""+caster->QCN+" lash out at you with a sickening %^RESET%^%^RED%^sm%^BOLD%^a"
         "%^RESET%^%^RED%^ck%^BOLD%^%^BLACK%^!%^RESET%^");
      damage_targ(ppl,ppl->return_target_limb(),extra,"mental");
   }
   room  = environment(caster);
   party = (string)caster->query_party();
   if(party) { party_members = (object *)PARTY_OB->query_party_members(party); }
   inven = target_selector();
   inven -= ({caster});
   inven = filter_array(inven,"party_filter",TO);

   if(caster->query_followers())
      inven -= caster->query_followers();
   if(sizeof(oppressed)){
      tmp = oppressed;
      for(i=0;i<sizeof(tmp);i++){
         if(!objectp(tmp[i])) { continue; }
         if(!present(tmp[i],room)){
            tell_object(tmp[i],"%^RED%^You feel an incredible relief as you leave "
               ""+caster->QCN+"'s presence!%^RESET%^");
            tmp[i]->remove_property("oppressed");
            tmp[i]->add_attack_bonus(bonus);
            tmp[i]->add_damage_bonus(bonus);
            oppressed -= ({ tmp[i] });
         }
      }
   }
   if(!sizeof(inven)){
      room->addObjectToCombatCycle(TO,1);
      return;
   }
   for(i=0;i<sizeof(inven);i++){
      if(!objectp(inven[i])) { continue; }
      if(!inven[i]->query_property("oppressed")){
//         tell_object(inven[i],"%^BOLD%^%^BLACK%^You can't help but recoil "
//            "from "+caster->QCN+"'s horrific visage!%^RESET%^");
         if(!do_save(inven[i],0) && !PLAYER_D->immunity_check(inven[i], "fear") && !inven[i]->query("no pk")) {
            tell_object(inven[i],"%^BOLD%^%^RED%^You cower away from "+caster->QCN+"!%^RESET%^");
            tell_object(caster,"%^BOLD%^%^RED%^"+inven[i]->QCN+" cowers in fear of your "
               "mighty presence!%^RESET%^");
           tell_room(room,"%^BOLD%^%^RED%^"+inven[i]->QCN+" cowers in fear of "+caster->QCN+"!%^RESET%^",({caster,inven[i]}));
            oppressed += ({ inven[i] });
            inven[i]->set_property("oppressed",1);
            inven[i]->add_attack_bonus(-1*bonus);
            inven[i]->add_damage_bonus(-1*bonus);
         }
      }
   }
   environment(caster)->addObjectToCombatCycle(TO,1);
}

void dest_effect(){
   if(objectp(caster)){
      tell_object(caster,"%^BOLD%^%^WHITE%^The %^BLACK%^sha%^RESET%^d%^BOLD%^"
         "%^BLACK%^ows %^WHITE%^recede, leaving you in a world too bright.%^RESET%^");
      tell_room(environment(caster),"%^BOLD%^%^WHITE%^The area brightens as the "
         "%^BLACK%^sha%^RESET%^d%^BOLD%^%^BLACK%^ows %^WHITE%^recede from "+caster->QCN+".%^RESET%^",caster);
      caster->set_resistance("fire",-mylevel);
      caster->remove_property("iron body");
      caster->remove_property("castspellresist");
      caster->add_stat_bonus("strength",(-1*mybonus));
      caster->set_property("damage resistance",-5);
      caster->remove_property("form of doom");
   }
   ::dest_effect();
    if(objectp(TO)) TO->remove();
}

void emote_em()
{
    if(!objectp(caster)) { return; }
   if(sizeof(caster->query_attackers()) > 0){
      call_out("emote_em",5*ROUND_LENGTH);
      return;
   }
   switch(random(5)){
      case 0: tell_room(environment(caster),"%^RESET%^%^RED%^The %^BOLD%^%^BLACK%^t%^RED%^e%^RESET%^%^RED%^n"
      "%^RESET%^t%^BOLD%^%^BLACK%^a%^RESET%^c%^RED%^l%^BOLD%^e%^BLACK%^s %^RESET%^%^RED%^surrounding "+caster->QCN+" "
                 "briefly part, revealing a vi%^BOLD%^s%^RESET%^%^RED%^age that makes your %^BOLD%^blood"
                 "%^RESET%^%^RED%^ freeze in your veins.%^RESET%^",caster);
              tell_object(caster,"%^RESET%^%^RED%^The %^BOLD%^%^BLACK%^t%^RED%^e%^RESET%^%^RED%^n"
                 "%^RESET%^t%^BOLD%^%^BLACK%^a%^RESET%^c%^RED%^l%^BOLD%^e%^BLACK%^s %^RESET%^%^RED%^around your "
                 "face briefly part, giving you a clear view.%^RESET%^");
              break;
      case 1: tell_room(environment(caster),"%^RESET%^%^CYAN%^Light gl%^BOLD%^i%^RESET%^%^CYAN%^nts "
                 "on "+caster->QCN+"'s tentacles, making them glisten wetly.%^RESET%^",caster);
              tell_object(caster,"%^RESET%^%^CYAN%^Your tentacles writhe, glistening wetly in the light.%^RESET%^");
                 break;
      case 2: tell_room(environment(caster),"%^RESET%^%^GREEN%^Oo%^YELLOW%^z%^RESET%^%^GREEN%^e drips from the "
                 "%^BOLD%^%^BLACK%^t%^GREEN%^e%^RESET%^%^GREEN%^n%^RESET%^t%^BOLD%^%^BLACK%^a"
                 "%^RESET%^c%^GREEN%^l%^BOLD%^e%^BLACK%^s %^RESET%^%^GREEN%^surrounding "
                 ""+caster->QCN+", puddling on the floor before vanishing.%^RESET%^",caster);
              tell_object(caster,"%^RESET%^%^GREEN%^You hear a steady drip, drip, drip as "
                 "%^BOLD%^oo%^YELLOW%^z%^GREEN%^e %^RESET%^%^GREEN%^weeps from your tentacles, horrifying onlookers "
                 "before disappearing into the ether.%^RESET%^");
              break;
      case 3: tell_room(environment(caster),"%^RESET%^%^RED%^The %^BOLD%^%^BLACK%^t%^RED%^e%^RESET%^%^RED%^n"
                 "%^RESET%^t%^BOLD%^%^BLACK%^a%^RESET%^c%^RED%^l%^BOLD%^e%^BLACK%^s "
                 "%^RESET%^%^RED%^sprouting from "+caster->QCN+"'s body writhe like a "
                 "nest of snakes, creating an unnerving sibilance.%^RESET%^",caster);
              tell_object(caster,"%^RESET%^%^RED%^The %^BOLD%^%^BLACK%^t%^RED%^e%^RESET%^%^RED%^n"
                 "%^RESET%^t%^BOLD%^%^BLACK%^a%^RESET%^c%^RED%^l%^BOLD%^e%^BLACK%^s "
                 "%^RESET%^%^RED%^sprouting from your body writhe like a "
                 "nest of snakes, creating an eerie sibilance.%^RESET%^");
              break;
      default: tell_room(environment(caster),"%^BOLD%^%^BLACK%^The t%^RED%^e%^RESET%^%^RED%^n"
                 "%^RESET%^t%^BOLD%^%^BLACK%^a%^RESET%^c%^RED%^l%^BOLD%^e%^BLACK%^s "
                 "embracing "+caster->QCN+" sprout countless %^RED%^mouths %^BLACK%^filled "
                 "with rows upon rows of jagged %^WHITE%^teeth%^BLACK%^. Between each pair of "
                 "nightmarish lips slithers a forked %^RESET%^%^RED%^to%^BOLD%^n%^RESET%^%^RED%^"
                 "gue%^BOLD%^%^BLACK%^.%^RESET%^",caster);
               tell_object(caster,"%^BOLD%^%^BLACK%^You feel an unearthly warmth from within "
                 "as your t%^RED%^e%^RESET%^%^RED%^n%^RESET%^t%^BOLD%^%^BLACK%^a%^RESET%^c%^RED%^l"
                 "%^BOLD%^e%^BLACK%^s writhe, driven by a will of their own.%^RESET%^");
               break;
   }
   call_out("emote_em",15*ROUND_LENGTH);
   return;
}
