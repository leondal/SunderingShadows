//updated to be similar to Spell Turning, which is more in line with source material ~Circe~ 1/14/2020
#include <priest.h>
#include <magic.h>
inherit SPELL;

int feattracker;

void create() {
    ::create();
    set_spell_name("reddopsi");
    set_spell_level(([ "psion" : 7 ]));
    set_spell_sphere("psychokinesis");
    set_discipline("kineticist");
    set_damage_desc("clevel/6+5 spell reflection chance.");
    set_syntax("cast CLASS reddopsi");
    set_description("Talented kineticists can manipulate the area around them, causing spells and powers to rebound upon their originators. While this power holds, it will have a chance to reflect any spells which are directly aimed at the caster, regardless of whether they are hostile or friendly. The ward will not reflect splash damage or AOE, but only direct-targetted spells. This spell will override spell reflection and reflection feats.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
    if(caster->query_property("spellturning")){
      tell_object(CASTER,"You are already under the influence of such an effect.");
      return 0;
   }
   return 1;
}

string query_cast_string() {
    return "%^RESET%^%^CYAN%^"+caster->QCN+" closes "+caster->QP+" eyes and focuses in silence.%^RESET%^";
}

void spell_effect(int prof) {
    int i;
    if (!objectp(caster)) {
      dest_effect();
      return;
    }
    if (interactive(caster)) {
      tell_object(caster, "%^RESET%^%^MAGENTA%^You close your eyes, inhaling deeply as you bring into being a %^CYAN%^rune of protection%^MAGENTA%^. A faint hint of %^ORANGE%^saffron %^MAGENTA%^hangs in the air before being subsumed by the fragrance of %^BOLD%^%^CYAN%^ozone%^RESET%^%^MAGENTA%^.%^RESET%^");
    }
    tell_room(place,"%^RESET%^%^MAGENTA%^You smell %^ORANGE%^saffron %^MAGENTA%^followed by a strong scent of %^BOLD%^%^CYAN%^ozone%^RESET%^%^MAGENTA%^ as a %^CYAN%^rune %^MAGENTA%^appears by sweeps and loops in the air before "+caster->QCN+"!%^RESET%^",caster);
    caster->set_property("spellturning",clevel/6+5);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 5 + 1800;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
    addSpellToCaster();
}

void dest_effect(){
    int i;
    if(objectp(CASTER)){
      tell_object(caster,"%^MAGENTA%^You feel the protective spell ward fade from you.%^RESET%^");
      caster->set_property("spellturning",-(clevel/6+5));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
