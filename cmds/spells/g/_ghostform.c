//New repose domain spell to replace Death Watch, which is now
//a general cleric spell.  Based on the psion power Concealing
//Amorpha ~Circe~ 4/26/08 Rebalancing priest domains
#include <std.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

int mychance;

void create() {
    ::create();
    set_spell_name("ghostform");
    set_spell_level(([ "classless" : 8 ]));
    set_spell_sphere("conjuration_summoning");
    set_spell_domain("repose");
    set_syntax("cast CLASS ghostform");
    set_description("Drawing forth the power of his deity, the caster is imbued with a spectral presence, causing him to "
"be harder to see and therefore more difficult to hit.  This spell will last for a time depending upon the caster's "
"level.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string(){
   return "%^CYAN%^"+caster->QCN+"'s eyes %^BOLD%^flash %^RESET%^"+
      "%^CYAN%^as "+caster->QS+" begins to chant.%^RESET%^";
}

int preSpell(){
    if (caster->query_property("amorpha") || caster->query_property("timeless body")) {
        tell_object(caster, "You are already protected by a spell similar to this one.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {

    if (caster->query_property("amorpha")) {
        tell_object(caster, "You are already protected by a spell "+
           "similar to this one.");
        if(objectp(TO)) TO->remove();
        return;
    }
    tell_object(caster,"%^BOLD%^Your skin s%^RESET%^h%^BOLD%^i"+
       "%^RESET%^m%^BOLD%^m%^RESET%^e%^BOLD%^r%^RESET%^s %^BOLD%^"+
       "and becomes %^RESET%^translucent %^BOLD%^as you call forth "+
       "your deity's protection!%^RESET%^");
    tell_room(place,"%^BOLD%^"+caster->QCN+"'s skin s%^RESET%^h%^BOLD%^i"+
       "%^RESET%^m%^BOLD%^m%^RESET%^e%^BOLD%^r%^RESET%^s %^BOLD%^"+
       "and becomes %^RESET%^translucent %^BOLD%^as "+caster->QS+" "+
       "finishes "+caster->QP+" prayer!%^RESET%^",caster);
    mychance = 10+clevel;
    if(mychance > 50) mychance = 50;
    caster->set_property("spelled", ({TO}) );
    caster->set_property("amorpha",1);
    caster->set_missChance(caster->query_missChance()+ 35);
    caster->set_property("added short",({"%^BOLD%^%^WHITE%^ (ghostly)%^RESET%^"}));
    spell_successful();
    addSpellToCaster();
    spell_duration = (clevel / 2 + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
    return;
}

void dest_effect() {
    if(objectp(caster)){
       tell_object(caster,"%^BOLD%^You feel your body become more "+
          "substantial as your deity's protection fades.");
       tell_room(place,"%^BOLD%^"+caster->QCN+" suddenly seems more "+
          "substantial as "+caster->QP+" skin loses its "+
          "transluscence.%^RESET%^",caster);
       caster->set_missChance(0);
       caster->remove_property("amorpha");
       caster->remove_property("added short",({"%^BOLD%^%^WHITE%^ (ghostly)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
    return;
}
