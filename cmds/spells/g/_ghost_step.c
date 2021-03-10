#include <std.h>
#include <magic.h>
inherit SPELL;

int reversed, duration;

void create() {
   ::create();
    set_spell_name("ghost step");
    set_spell_level(([ "ranger" : 1, "monk" : 3, "assassin" : 2]));
    set_spell_sphere("alteration");
    set_monk_way("way of the shadow");
    set_syntax("cast CLASS ghost step");
    set_description("This spell allows you to become one with nature, as a ghost of the forest, leaving no traces of "
    "where you have walked.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell() {
    if(caster->query_property("untrackable"))
    {
        tell_object(caster,"%^GREEN%^Your footsteps are already untrackable!%^RESET%^");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    if(spell_type == "monk")
    {
        tell_object(caster, "%^BOLD%^%^BLACK%^You focus deeply, manipulating "+
        "the very fabric of yourself!%^RESET%^");
        tell_room(place, caster->QCN+"%^BOLD%^%^BLACK%^ begins focusing deeply!%^RESET%^", caster);
    }
    else
    {
        tell_object(caster,"%^GREEN%^%^You invoke the wilderness to aid you.");
        tell_room(place,"%^GREEN%^"+caster->QCN+" invokes the wilderness "+
        "to aid "+caster->QO+"!",caster);
    }
    return "display";
}

void spell_effect(int prof) {
    duration = (ROUND_LENGTH * 2) * clevel;

    if((string)TO->query_spell_type() == "potion") {
      if(prof == -100) { // hack for potions. Cuz lib doesn't seem to call reverse spell anymore, and I'm lazy. N, 6/15.
        reverse_spell();
        return;
      }
      tell_object(caster,"%^CYAN%^As the potion warms your stomach, your body takes on a momentary translucent shimmer.%^RESET%^");
    }
    else
    {
        tell_room(place,"%^CYAN%^"+caster->QCN+"'s body takes on a momentary "
        "translucent shimmer!",caster);
        if(spell_type == "monk")
        {
            tell_object(caster, "%^BOLD%^%^CYAN%^Your manipulation allows you to "+
            "hide footsteps and your body takes on a momentary translucent shimmer!%^RESET%^");
        }
        else
        {
            tell_object(caster,"%^CYAN%^You call upon the wilds to hide your "
            "footsteps, and your body takes on a momentary translucent shimmer!%^RESET%^");
        }
    }

    caster->set_property("untrackable",1);
    addSpellToCaster();
    spell_successful();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    if(objectp(caster)) {
      if(reversed) {
        tell_object(caster,"%^CYAN%^You feel your body return to normal.%^RESET%^");
        caster->add_skill_bonus("stealth",5);
      }
      else caster->set_property("untrackable",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

void reverse_spell(){
    // adding in backfires for potions! Can't find where lib actually calls this anymore.
    tell_object(caster,"%^CYAN%^A queasy feeling runs through you, and you feel your body grow cumbersome.%^RESET%^");

    reversed = 1;
    caster->add_skill_bonus("stealth",-5);
    spell_successful();
    call_out("dest_effect",duration);
}
