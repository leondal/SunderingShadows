#include <spell.h>
#include <clock.h>
#include <magic.h>
inherit SPELL;

int abonus;
int rbonus; //Should make evasion useful, but not above that
int nodeathflag = 0; //To make spell useful on targets already warded against death
int duration;

void create() {
    ::create();
    set_spell_name("dark foresight");
    set_spell_level(([ "warlock" : 4 ]));
    set_spell_sphere("divination");
    set_bonus_type("insight");
    set_syntax("cast CLASS dark foresight");
    set_damage_desc("clvel/16 to armor bonus, clevel/12 to reflex save");
    set_description("The warlock uses this invocation to utilize the forbidden and arcane knowledge, granted by their patron, to see the very fabric of existence. The causality of the universe becomes plain to them and they have the ability to see what the future holds.");
    set_verbal_comp();
    set_somatic_comp();
    set_feats_required(([ "warlock" : "tome of ancient secrets" ]));
    set_property("keywords", ({ "defensive", "personal", "targeted"}));
    set_helpful_spell(1);
}

int preSpell()
{
    /*
    if(caster->query_property("foresighted"))
    {
        tell_object(caster,"%^BOLD%^%^BLACK%^You feel your spell repelled...");
        return 0;
    }
    */
    return 1;
}

void spell_effect(int prof)
{

    duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 7;
    abonus = 1 + (clevel / 16);
    rbonus = 1 + (clevel / 12);

    /*
    if (caster->query_property("foresighted"))
    {
        tell_object(caster,"%^CYAN%^The spell is repelled by its own magic.%^RESET%^\n");
        TO->remove();
    }
    */

    spell_successful();

    tell_object(caster,"%^CYAN%^You feel the fabric of reality itself.\n");
    tell_room(place,"%^CYAN%^"+caster->QCN+" opens and closes their eyes, looking distanced from the surroundings.\n", caster );

    caster->add_ac_bonus(abonus);
    caster->add_saving_bonus("reflex",rbonus);
    caster->set_property("spelled", ({TO}) );
    //caster->set_property("foresighted",1);
    addSpellToCaster();
    call_out("test", 10);
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void test()
{
    if (!objectp(caster))
    {
        remove();
        dest_effect();
        return;
    }

    call_out("test", 10);
    return 0;
}

void dest_effect()
{
    if (find_call_out("test") != -1) remove_call_out("test");

    if(objectp(caster))
    {
        caster->add_ac_bonus(- abonus);
            caster->add_saving_bonus("reflex",- rbonus);
        caster->remove_property_value("spelled", ({TO}) );
        tell_object(caster, "%^MAGENTA%^BOLD%^The fabric of reality no longer is present in your mind.");
        //caster->remove_property("foresighted");
    }

    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

string query_cast_string() { return "%^BOLD%^%^BLACK%^" + caster->QCN + " puts their hands together where e%^RESET%^%^GREEN%^l%^BOLD%^d%^RESET%^r%^BOLD%^i%^BLACK%^tch e%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^r%^BOLD%^g%^BLACK%^y f%^RESET%^%^GREEN%^o%^BOLD%^r%^RESET%^m%^BOLD%^s%^BLACK%^."; }
