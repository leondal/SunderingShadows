#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("infernal healing");
    set_spell_level(([ "mage" : 1, "cleric" : 1, "warlock": 1, "magus" : 1 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS infernal healing [on TARGET]");
    set_damage_desc("fast healing 1");
    set_description("You anoint a wounded creature with devil's blood or unholy water, giving it fast healing 1.

%^BOLD%^%^RED%^See also:%^RESET%^ status effects");
    evil_spell(1);
	set_helpful_spell(1);
    set_feats_required(([ "warlock" : "infernal practitioner"]));
}

string query_casting_string()
{
    return "%^BOLD%^%^RED%^"+caster->QCN+" %^BOLD%^%^RED%^spells an %^RED%^i%^BLACK%^n%^RED%^f%^BLACK%^ernal %^BLACK%^inc%^RED%^a%^BLACK%^nt%^RED%^a%^RED%^t%^BLACK%^ion.%^RESET%^
";
}

int preSpell()
{
    if(!target)
        target = caster;
    if(target->query_property("fast_healing_spell"))
    {
        tell_object(caster,"%^BOLD%^%^BLACK%^You feel your spell repelled...");
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

    tell_room(place, "%^BOLD%^%^RED%^" + target->QCN + "%^BOLD%^%^RED%^'s veins burn %^BLACK%^infernal %^BLACK%^re%^RED%^d%^RED%^ through the skin.%^RESET%^", caster);
    {
        int duration = clevel * ROUND_LENGTH * 12;
        tell_object(target, "%^BOLD%^%^RED%^You feel your blood %^BLACK%^bur%^RED%^n%^BLACK%^i%^RED%^n%^BLACK%^g %^RED%^a%^BLACK%^w%^RED%^a%^RED%^y%^RED%^ your wounds.%^RESET%^
");
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
        tell_object(target, "%^BOLD%^%^RED%^Your blood cools down.%^RESET%^");
        target->remove_property_value("spelled", ({ TO }));
        target->set_property("fast healing", -1);
        target->remove_property("fast_healing_spell");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
