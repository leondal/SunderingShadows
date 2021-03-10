#include <priest.h>
inherit SPELL;

int newhp;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("heart of darkness");
    set_spell_level(([ "warlock" : 3 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS heart of darkness");
    set_description("By means of this invocation, the caster attunes their soul to withstand the darkest of energies. "
"It will grant them the hitpoints of a warrior of their level, and render them immune to death spells and spell-like "
"effects. It will also cause negative energy to heal them, rather than harm them.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
   if((int)caster->query_property("heart of darkness")){
      tell_object(caster,"You are already under the influence of such spellcraft.");
      return 0;
   }
   return 1;
}

string query_cast_string() {
    tell_object(caster,"%^RED%^A swift motion as you prick your skin, drawing %^BOLD%^%^RED%^b%^RESET%^%^RED%^l%^BOLD%^%^RED%^o%^RESET%^%^RED%^o%^BOLD%^%^RED%^d%^RESET%^%^RED%^.%^RESET%^");
    tell_room(place,"%^RED%^A swift motion as "+caster->QCN+" pricks "+caster->QP+" skin, drawing %^BOLD%^%^RED%^b%^RESET%^%^RED%^l%^BOLD%^%^RED%^o%^RESET%^%^RED%^o%^BOLD%^%^RED%^d%^RESET%^%^RED%^.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    int i, dice, roll_1, roll_2, bonuses, targlevel;
    string file;
    if (!objectp(caster)) {
      dest_effect();
      return;
    }
    if (interactive(caster)) {
      tell_object(caster, "%^BOLD%^%^RED%^You feel a moment of %^RESET%^%^RED%^pa%^BOLD%^%^RED%^i%^RESET%^%^RED%^n %^BOLD%^%^RED%^as your body attunes itself to the dark energy that floods through it!%^RESET%^");
      tell_room(place,"%^BOLD%^%^RED%^A momentary flash of %^RESET%^%^RED%^pa%^BOLD%^%^RED%^i%^RESET%^%^RED%^n %^BOLD%^%^RED%^passes over "+caster->QCN+"'s face.%^RESET%^",caster);
    }
    caster->set_property("heart of darkness",1);
    caster->set_property("no death",1);

    caster->add_max_hp_bonus(clevel*5/2);
    spell_successful();
    addSpellToCaster();
}

void dest_effect(){
    int i;
    if(objectp(CASTER)) {
      tell_object(caster,"%^RED%^It feels as though a weight has been lifted from your soul.%^RESET%^");
      tell_room(environment(caster),"%^RED%^"+caster->QCN+" lets out a sigh and seems to relax.%^RESET%^",caster);
      caster->set_property("no death",-1);
      caster->set_property("heart of darkness",-1);
      caster->add_max_hp_bonus(-clevel*5/2);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
