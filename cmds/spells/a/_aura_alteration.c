#include <priest.h>

inherit SPELL;

#define ALIGNS ({"lawful good","neutral good","chaotic good","lawful neutral","true neutral","chaotic neutral","lawful evil","neutral evil","chaotic evil"})

void create() 
{
    ::create();
    set_spell_name("aura alteration");
    set_spell_level(([ "psywarrior" : 3, "psion" : 6 ]));
    set_spell_sphere("telepathy");
    mental_spell();
    set_syntax("cast CLASS aura alteration on <alignment>");
    set_description("By making use of this power, a psion can hide his inner thoughts from others, effectively masking "
        "his alignment.  There are, naturally, ways to bypass this power's protection, but it will offer the psion some peace of "
        "mind should he need it.\n\nThe choices for alignment are lawful good, neutral good, chaotic good, lawful neutral, true "
        "neutral, chaotic neutral, lawful evil, neutral evil, or chaotic evil.  Please make sure you do not capitalize any part "
        "of your choice.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_silent_casting(1);
    set_helpful_spell(1);
}


int preSpell()
{
    if((int)caster->query_property("hidden alignment"))
    {
        tell_object(caster,"You are already have an alignment "+
            "altering affect.");
        return 0;
    }
    return 1;
}


void spell_effect(int prof) 
{
    int newal;

    if(!arg) 
    {
        tell_object(caster,"That is not a valid alignment choice!");
        tell_object(caster,"Your choices are: lawful good, neutral "+
            "good, chaotic good, lawful neutral, true neutral, "+
            "chaotic neutral, lawful evil, neutral evil, or "+
            "chaotic evil.  Please make sure you do not capitalize "+
            "any part of your choice.");
        dest_effect();
        return;
    }
    
    arg = lower_case(arg);
    
    if(member_array(arg,ALIGNS) == -1)
    {
        tell_object(caster,"That is not a valid alignment choice!");
        tell_object(caster,"Your choices are: lawful good, neutral "+
            "good, chaotic good, lawful neutral, true neutral, "+
            "chaotic neutral, lawful evil, neutral evil, or "+
            "chaotic evil.  Please make sure you do not capitalize "+
            "any part of your choice.");
        dest_effect();
        return;
    }
    
    switch(arg)
    {
    case "lawful good":      newal = 1;  break;
    case "neutral good":     newal = 4;  break;
    case "chaotic good":     newal = 7;  break;
    case "lawful neutral":   newal = 2;  break;
    case "true neutral":     newal = 5;  break;
    case "chaotic neutral":  newal = 8;  break;
    case "lawful evil":      newal = 3;  break;
    case "neutral evil":     newal = 6;  break;
    case "chaotic evil":     newal = 9;  break;
    }
    
    tell_object(caster,"%^CYAN%^You turn your thoughts inward, "+
        "hiding those you wish not to reveal.");
    tell_object(caster,"%^BOLD%^%^CYAN%^Your alignment will "+
        "been seen as "+arg+" for a time.");
    caster->set_property("hidden alignment",newal);
    spell_successful();
    addSpellToCaster();
}


void dest_effect()
{  
    if(objectp(caster))
    {
        tell_object(caster,"%^BOLD%^You feel strangely exposed as the power "
            "protecting your alignment fades away.%^RESET%^");
        caster->remove_property("hidden alignment");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
