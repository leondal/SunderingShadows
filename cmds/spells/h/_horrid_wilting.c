#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("horrid wilting");
    set_spell_level(([ "mage" : 8, "oracle" : 8, "cleric" : 8 ]));
    set_domains(({"destruction"}));
    set_spell_sphere("necromancy");
    set_mystery(({"reaper","bones"}));
    set_syntax("cast CLASS horrid wilting");
    set_damage_desc("negative energy on living, nothing on undead");
    set_description("This spell sends a wave of necrotic energy at everyone living in sight, evaporating water and life from them.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    set_save("fort");
    set_components(([
      "mage" : ([ "drop of blood" : 1 ]),
    ]));
}

string query_cast_string() {
    return "%^BLUE%^"+caster->QCN+" spells an incantation in eldritch tongue.";
}

void spell_effect(int prof){
    object *attackers;
    int i, admg;
    attackers = target_selector();

    tell_room(place, "%^BLUE%^"+caster->QCN+" raises hand and releases wave of cold energy!%^RESET%^");
    if(!sizeof(attackers)){
        tell_object(caster, "%^BOLD%^%^BLUE%^The area is washed in death energy but nothing else happens.%^RESET%^");
        dest_effect();
        return;
    }

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i]))
            continue;
        if(attackers[i]->is_undead())
            continue;
        admg=sdamage;
        if(do_save(attackers[i]))
        {
            admg/=2;
        }
        tell_object(attackers[i], "%^BLUE%^Your flesh is withered with fell power!%^RESET%^");
        damage_targ(attackers[i], attackers[i]->return_target_limb(), admg, "negative energy");
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
