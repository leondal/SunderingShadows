#include <std.h>
#include <daemons.h>

inherit SPELL;

string potential_diseases = ({"blinding sickness", "cackle fever", "filth fever", "mindfire", "red ache", "shakes", "slimy doom"});

void create() {
    ::create();
    set_spell_name("epidemic");
    set_spell_level(([ "cleric":6, "druid":6, "mage":7]));
    set_spell_sphere("necromancy");
    set_damage_desc("Random disease");
    set_syntax("cast CLASS epidemic");
    set_description("This spell functions exactly like contagion, but affects everyone in the area. Unlike contagion, this spell starts combat.");

    set_verbal_comp();
    set_somatic_comp();

    set_save("fort");
    evil_spell(1);
    splash_spell(3);
}

string query_cast_string()
{
    return "%^BOLD%^%^BLACK%^"+caster->QCN+" spreads arms around them, chanting in deep, dark tone.";
}

void spell_effect()
{
    object disease;
    object * diseases;
    string * targ_infections, dname;
    string dfile;

    object * attackers;

    tell_object(caster,"%^BOLD%^%^BLACK%^You connect your hands, clapping loudly, as waves of fell powers spread with the sound.");
    tell_room(place, "%^BOLD%^%^BLACK%^" + caster->QCN + " connects " + caster->QP + " hands with a loud clap, sickening waves of power spread with the sound.");

    attackers = target_selector();

    if (!sizeof(attackers)) {
        tell_object(caster,"%^BOLD%^Your spell fails to infect anyone.");
    }

    foreach(target in attackers) {

        targ_infections = filter_array(all_inventory(target), (: $1->is_disease() :))->query_name();
        diseases = potential_diseases - targ_infections;

        if (!sizeof(diseases)) {
            continue;
        }

        dfile = "/std/diseases/diseases/" + replace_string(diseases[random(sizeof(diseases))], " ", "_") + ".c";

        if (!file_exists(dfile)) {
            continue;
        }

        disease = dfile->infect(target, clevel);
        if (objectp(disease)) {
            disease->advance_disease();
            spell_kill(target, caster);
        }
    }

    spell_successful();
    return;

}
