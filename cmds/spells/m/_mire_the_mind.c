// this is basically a slow aura - same save and similar penalties; however the 1 action/round books seemed too harsh so it's only a -1 attack, as a reverse of haste.
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

object *affected, *immune;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("mire the mind");
    set_spell_level(([ "warlock" : 3 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS mire the mind");
    set_description("The caster creates a chilling aura around themselves, which insinuates "
"itself into the minds of nearby foes, should they not have the willpower to resist. It will "
"apply itself as a fog upon their thoughts, slowing their combat reactions considerably. "
"Creatures with only a single attack will not be able to be slowed further.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
    set_save("will");
    splash_spell(2);
}

int preSpell(){
   if(caster->query_property("slow aura")) { // only really needs specific to this spell, nothing else like it
      tell_object(caster,"You already have this effect active.");
      return 0;
   }
   return 1;
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^BLACK%^An eerie %^RESET%^%^CYAN%^c%^RESET%^hi%^CYAN%^ll%^BOLD%^%^BLACK%^ descends upon the area as you utter an invocation.%^RESET%^");
    tell_room(place,"%^BOLD%^%^BLACK%^An eerie %^RESET%^%^CYAN%^c%^RESET%^hi%^CYAN%^ll%^BOLD%^%^BLACK%^ descends upon the area as "+caster->QCN+" utters an invocation.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    tell_object(caster,"%^BOLD%^%^BLACK%^The air around you %^RESET%^%^BLUE%^thickens %^BOLD%^%^BLACK%^perceptibly, enshrouding you in a %^BOLD%^%^CYAN%^fr%^BOLD%^%^WHITE%^ig%^BOLD%^%^CYAN%^id a%^BOLD%^%^WHITE%^ur%^BOLD%^%^CYAN%^a%^BOLD%^%^BLACK%^.%^RESET%^");
    tell_room(place,"%^BOLD%^%^BLACK%^The air around "+caster->QCN+" %^RESET%^%^BLUE%^thickens %^BOLD%^%^BLACK%^perceptibly, enshrouding "+caster->QO+" in a %^BOLD%^%^CYAN%^fr%^BOLD%^%^WHITE%^ig%^BOLD%^%^CYAN%^id a%^BOLD%^%^WHITE%^ur%^BOLD%^%^CYAN%^a%^BOLD%^%^BLACK%^.%^RESET%^",caster);
    caster->set_property("spelled", ({TO}) );
    caster->set_property("slow aura",1);
    spell_successful();
    addSpellToCaster();
    affected = ({});
    immune = ({});
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
    call_out("test", ROUND_LENGTH);
}

void test() {
    object *temphere, *newaffected;
    int i, attacksnum;
    string testname;
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    newaffected = ({});
//    temphere = all_living(environment(caster));
// let's see if we can make it more useful on attackers!
    temphere = target_selector();
    if(member_array(caster,temphere) != -1) temphere -= ({ caster });

    if(sizeof(affected)) { // firstly, for any that were affected last round, if they've left, remove the effect
      for(i=0;i<sizeof(affected);i++) {
        if(!objectp(affected[i])) continue;
        if(environment(affected[i]) != environment(caster)) {
          tell_object(affected[i],"%^CYAN%^Your clarity of thought returns as you move away from the chilling miasma.%^RESET%^");
          tell_room(environment(affected[i]),"%^CYAN%^"+affected[i]->QCN+"'s movements return to normal.%^RESET%^",affected[i]);
          if(userp(affected[i])) affected[i]->set_property("fighter_attacks_mod",1); // extra attack! users syntax
          else {
            attacksnum = affected[i]->query_attacks_num();
            attacksnum++;
            affected[i]->set_attacks_num(attacksnum); // extra attack!
          }
          affected[i]->add_attack_bonus(1); // +1 BAB!
          affected[i]->add_ac_bonus(1); // +1 dodge to AC!
          affected[i]->add_saving_bonus("reflex",1); // +1 reflex save!
          affected[i]->add_skill_bonus("athletics",2); // +2 athletics skill!
        }
        else newaffected += ({ affected[i] });
      }
    }

    if(sizeof(temphere)) { // secondly, for all that are still here, let them attempt a saving throw IF they are new
      for(i=0;i<sizeof(temphere);i++) {
        if(!objectp(temphere[i])) continue;
        if(member_array(temphere[i],immune) != -1) continue; // these targets have already saved & succeeded in past rounds
        if(member_array(temphere[i],affected) != -1) continue; // these targets are already affected by the aura
        if(!userp(temphere[i])) { // weed out greebles with only 1 attack already, let's not make them do zero!
          if((int)temphere[i]->query_attacks_num() < 2) continue;
        }
        if(do_save(temphere[i],0)) {
          tell_object(temphere[i],"%^CYAN%^You shrug off the chill in the air, unaffected.%^RESET%^");
          tell_room(environment(temphere[i]),"%^BOLD%^%^CYAN%^"+temphere[i]->QCN+" seems to shrug off the chill in the air!%^RESET%^",temphere[i]);
          immune += ({ temphere[i] });
        }
        else {
          tell_object(temphere[i],"%^BOLD%^%^CYAN%^The chill seeps into your body, and your senses seem suddenly sluggish!%^RESET%^");
          tell_room(environment(temphere[i]),"%^BOLD%^%^CYAN%^"+temphere[i]->QCN+"'s reactions seem to grow suddenly sluggish!%^RESET%^",temphere[i]);
          if(userp(temphere[i])) temphere[i]->set_property("fighter_attacks_mod",-1); // extra attack! users syntax
          else {
            attacksnum = temphere[i]->query_attacks_num();
            attacksnum--;
            temphere[i]->set_attacks_num(attacksnum); // extra attack!
          }
          temphere[i]->add_attack_bonus(-1); // +1 BAB!
          temphere[i]->add_ac_bonus(-1); // +1 dodge to AC!
          temphere[i]->add_saving_bonus("reflex",-1); // +1 reflex save!
          temphere[i]->add_skill_bonus("athletics",-2); // +2 athletics skill!
          newaffected += ({ temphere[i] });
        }
      }
    }
    affected = newaffected;
    call_out("test", ROUND_LENGTH);
}

void dest_effect() {
    if(objectp(caster)){
      tell_object(caster,"%^BOLD%^%^BLACK%^The %^RESET%^%^CYAN%^f%^RESET%^r%^CYAN%^o%^RESET%^st%^CYAN%^y%^BOLD%^%^BLACK%^ bite in the air eases.%^RESET%^");
      tell_room(environment(caster),"%^BOLD%^%^BLACK%^The %^RESET%^%^CYAN%^f%^RESET%^r%^CYAN%^o%^RESET%^st%^CYAN%^y%^BOLD%^%^BLACK%^ bite in the air eases from around "+caster->QCN+".%^RESET%^",caster);
      caster->set_property("slow aura",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
