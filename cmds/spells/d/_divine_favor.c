#include <priest.h>
#include <daemons.h>
inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("divine favor");
    set_spell_level(([ "paladin" : 3, "inquisitor" : 1, "cleric" : 1]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS divine favor");
    set_bonus_type("luck");
    set_damage_desc("clevel / 24 + 1 to damage and attack bonus");
    set_description("Calling upon the strength of their patron, a holy warrior can gain a bonus to their attack and damage rolls.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
    /*
    if(caster->query_property("blessed")){
     tell_object(caster,"%^ORANGE%^Your caster has already received guidance.");
        return 0;
    }
    if(caster->query_property("blighted")){
     tell_object(caster,"%^ORANGE%^Your caster has already received guidance.");
        return 0;
    }
    */
    return 1;
}

string query_cast_string()
{
    return "%^CYAN%^" + caster->QCN + " clenches " + caster->QP + " fists and raises " + caster->QP + " eyes to the heavens.";
}

void spell_effect(int prof)
{
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^%^CYAN%^Heat floods through your body as the power of your god infuses you!");
        tell_room(place, "%^BOLD%^%^CYAN%^" + caster->QCN + "'s body seems to take on a faint radiance!", caster);
    }
    bonus = clevel / 24 + 1;
    caster->add_damage_bonus(bonus);
    caster->add_attack_bonus(bonus);
    //caster->set_property("blessed", 1);
    spell_successful();
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 5;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if (objectp(caster)) {
        tell_object(caster, "%^BOLD%^%^CYAN%^The blazing inspiration of your deity fades from you.%^RESET%^");
        caster->add_damage_bonus(-bonus);
        caster->add_attack_bonus(-bonus);
        //caster->remove_property("blessed");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
