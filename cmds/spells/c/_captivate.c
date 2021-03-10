#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    //This is enthrall from srds, but simpler. Warlocks stole the name for enthrall, so naming it captivate.
    set_spell_name("captivate");
    set_spell_level(([ "bard" : 2, "cleric": 2 ]));
    set_domains("charm");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS captivate");
    set_damage_desc("stops combat");
    set_description("With this spell, the caster uses her enchanted speech to captivate and pacify everyone present. This spell may even work on the strong of will.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
}

string query_cast_string() {
    tell_room(place,"%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ chants sonorously in captivating tones.",caster);
    tell_object(caster,"%^CYAN%^You chant sonorously in captivating tones.");
    return "display";
}

void spell_effect(int prof)
{
    object *foes, foe;
    int x;

    tell_object(caster,"%^CYAN%^You sing a song of peace, calming everyone present.");
    tell_room(place,"%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ sings a song of peace, calming everyone.",caster);

    foes = all_living(place) - ({caster});

    caster->cease_all_attacks();
    foreach(foe in foes)
    {
        x=0;
        if(do_save(foe,-8))
        {
            tell_object(foe,"%^CYAN%^You shrug off the song.");
            tell_room(place,"%^CYAN%^"+foe->QCN+" remains unaffected by the song.",foe);
            continue;
        }
        tell_object(foe,"%^BOLD%^%^CYAN%^You feel calm, momentarily pacified. ");
        tell_room(place,"%^BOLD%^%^CYAN%^"+foe->QCN+" looks more calm and pacified.",foe);
        foe->cease_all_attacks();
    }

    spell_successful();
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
