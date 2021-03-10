#include <std.h>
#include <magic.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("shadowform");
    set_spell_level(([ "paladin" : 4, "bard" : 4, "psion" : 4, "mage" : 4, "magus" : 4 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS shadowform");
    set_damage_desc("a chance to reduce damage to 1/5 for clevel / 5 rounds");
    set_save("will");
    set_description("You replace own body with mystic shadow material drawn from the Shadow Plane, rendering the own physical form only quasi-real. Whenever a foe tries to directly attack you of the spell (for instance, with a weapon or a targeted spell), that foe must attempt a Will save to disbelieve. If successful, the opponent can attack you normally and is unaffected by shadowform for 1 round. If the foe fails, you take only one-fifth the normal amount of damage from the foe's successful attack.");
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell()
{
    target = caster;
    if (target->query_property("shadowform")) {
        tell_object(caster, "You are already under the influence of similar effect");
        return 0;
    }
    return 1;
}

spell_effect()
{
    target = caster;

    spell_successful();

    tell_room(place, "%^BLUE%^" + caster->QCN + " with a swift chant turns into shadow.%^RESET%^", ({ caster }));
    tell_object(caster, "%^BLUE%^You turn into shadow.%^RESET%^");

    target->set_property("spelled", ({ TO }));
    target->set_property("shadowform", clevel);
    target->set_property("added short", ({ "%^RESET%^%^BLUE%^ (a shadow)%^RESET%^" }));
    addSpellToCaster();
    spell_duration = (clevel / 5 + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if (objectp(target)) {
        target->remove_property_value("spelled", ({ TO }));
        tell_object(target, "%^BLUE%^You feel yourself again as shadowform disappears.%^RESET%^");
        target->remove_property_value("added short", ({ "%^RESET%^%^BLUE%^ (a shadow)%^RESET%^" }));
        target->remove_property("shadowform");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
