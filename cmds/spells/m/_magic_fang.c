#include <std.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

object *pets;
void execute_me();

void create() {
    ::create();
    set_spell_name("magic fang");
    set_spell_level(([ "ranger" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS magic fang");
    set_description("This spell lets the caster siphon some of his own will into his creatures, giving them minor bonuses "
"in combat.  It does not stack with similar spells or abilities, such as the hardenedminions feat.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

int preSpell(){
   if(caster->query_property("magic fang") || FEATS_D->is_active(caster,"hardenedminions")) {
      tell_object(caster,"You already have a similar effect active.");
      return 0;
   }
   return 1;
}

string query_cast_string() {
    return "%^BOLD%^"+caster->QCN+" closes "+caster->QP+" eyes and concentrates.%^RESET%^";
}

void spell_effect(int prof) {
    object myshort, *minions;
    int i, bonus;

    if(!objectp(caster)) {
        dest_effect();
        return;
    }

    minions = all_living(place);
    if(!sizeof(minions)){
      tell_object(caster,"You have no creatures by your side.");
      dest_effect();
      return;
    }
    pets = ({});
    myshort = caster->query_name()+"'s ally";
    for(i=0;i<sizeof(minions);i++) {
      if(minions[i]->id(myshort)) pets += ({ minions[i] });
    }
    if(!sizeof(pets)){
      tell_object(caster,"You have no creatures by your side.");
      dest_effect();
      return;
    }

    spell_successful();
    tell_object(caster,"%^BOLD%^You close your eyes and concentrate, letting your will lend strength to your "
"creatures.%^RESET%^");
    for(i=0;i<sizeof(pets);i++) {
        if(!objectp(pets[i])) continue;
        if(interactive(pets[i])) continue;
        if(!present(pets[i],place)) continue;
        if(pets[i]->query_property("hardened_minion")) continue;

        pets[i]->set_property("hardened_minion",1);
        pets[i]->set_max_hp((int)pets[i]->query_true_max_hp() + 50);
        pets[i]->set_hp((int)pets[i]->query_hp() + 50);
        pets[i]->add_attack_bonus(1);
        pets[i]->add_damage_bonus(1);

        tell_object(caster,"%^ORANGE%^Your "+pets[i]->QCN+"'s eyes gleam %^RED%^crim%^BOLD%^s%^RESET%^%^RED%^on"
"%^ORANGE%^!%^RESET%^");
        tell_room(environment(caster),"%^ORANGE%^"+pets[i]->QCN+"'s eyes gleam %^RED%^crim%^BOLD%^s%^RESET%^%^RED%^on"
"%^ORANGE%^!%^RESET%^",caster);
    }
    caster->set_property("magic fang",1);
    addSpellToCaster();
    call_out("execute_me",ROUND_LENGTH);
}

void execute_me() {
    object *newpets;
    int i;

    if(!objectp(caster) || !objectp(environment(caster))) {
        dest_effect();
        return;
    }
    if(!sizeof(pets)) {
        dest_effect();
        return;
    }
    newpets = ({});

    for(i=0;i<sizeof(pets);i++) {
        if(objectp(pets[i])) newpets += ({ pets[i] });
    }

    if(!sizeof(newpets)) {
        dest_effect();
        return;
    }
    pets = newpets;
    call_out("execute_me",ROUND_LENGTH);
}

void dest_effect() {
    int i;
    for(i=0;i<sizeof(pets);i++) {
        if(!objectp(pets[i])) continue;
        pets[i]->set_property("hardened_minion",-1);
        pets[i]->set_max_hp((int)pets[i]->query_true_max_hp() - 50);
        pets[i]->set_hp((int)pets[i]->query_hp() - 50);
        pets[i]->add_attack_bonus(-1);
        pets[i]->add_damage_bonus(-1);
        tell_room(environment(pets[i]),"%^ORANGE%^"+pets[i]->QCN+"'s eyes stop glowing.%^RESET%^");
    }
    if(objectp(caster)) caster->remove_property("magic fang");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
