#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("celestial healing");
    set_spell_level(([ "mage" : 1, "cleric" : 1, "magus" : 1 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS celestial healing [on TARGET]");
    set_damage_desc("fast healing 1");
    set_description("You anoint a wounded creature with celestial energy, giving it fast healing 1.

%^BOLD%^%^RED%^See also:%^RESET%^ status effects");
	set_helpful_spell(1);
}

string query_casting_string()
{
    return "%^BOLD%^%^CYAN%^"+caster->QCN+" %^BOLD%^%^YELLOW%^spells an %^CYAN%^c%^YELLOW%^e%^CYAN%^l%^YELLOW%^estial %^CYAN%^inc%^YELLOW%^a%^CYAN%^nt%^YELLOW%^a%^CYAN%^t%^YELLOW%^ion.%^RESET%^";
}

int preSpell()
{
    if(!target)
        target = caster;
    if(target->query_property("fast_healing_spell"))
    {
        tell_object(caster,"%^BOLD%^%^YELLOW%^You feel your spell repelled...");
        return 0;
    }
    return 1;
}

void spell_effect()
{
    if (!target) {
        target = caster;
    }

    if (!objectp(target)) {
        TO->remove();
        return;
    }
    if (!objectp(caster)) {
        TO->remove();
        return;
    }

    tell_room(place, "%^BOLD%^%^CYAN%^" + target->QCN + "'s veins glow %^YELLOW%^with celestial energy through the skin.%^RESET%^", caster);
    {
        int duration = clevel * ROUND_LENGTH * 12;
        tell_object(target, "%^BOLD%^%^CYAN%^You feel your blood %^YELLOW%^glow%^CYAN%^ with celestial energy, healing your wounds.%^RESET%^");
        target->set_property("spelled", ({ TO }));
        target->set_property("fast healing", 1);
        target->set_property("fast_healing_spell", 1);
        spell_successful();
        addSpellToCaster();
        spell_duration = duration;
        set_end_time();
        call_out("dest_effect",spell_duration);
    }
}

void dest_effect()
{
    if (objectp(target)) {
        tell_object(target, "%^BOLD%^%^YELLOW%^Your blood cools down.%^RESET%^");
        target->remove_property_value("spelled", ({ TO }));
        target->set_property("fast healing", -1);
        target->remove_property("fast_healing_spell");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
