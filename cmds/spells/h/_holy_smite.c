#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("holy smite");
    set_spell_level(([ "cleric" : 4, "inquisitor" : 4 ]));
    set_domains(({"good"}));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS holy smite");
    set_damage_desc("untyped on neutral and evil");
    set_description("You draw down holy power to smite your enemies, possibly blinding them. Only evil and neutral creatures are harmed by the spell, good creatures are unaffected.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(2);
    set_save("will");
}

string query_cast_string() {
    return "%^BOLD%^%^WHITE%^"+caster->QCN+" proclaims a divine prayer of smiting.";
}

void spell_effect(int prof){
    object *attackers;
    int i,admg;
    attackers = target_selector();

    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" raises hand and beam of power descends from heavens!%^RESET%^");
    if(!sizeof(attackers)){
        tell_object(caster,"%^BOLD%^%^ORANGE%^The area is washed in light but nothing else happens.%^RESET%^");
        dest_effect();
        return;
    }

    for(i=0;i<sizeof(attackers);i++)
    {
        int align = attackers[i]->query_alignment();
        if(!objectp(attackers[i]))
            continue;
        if(align == 1 || align == 4 || align == 7)
            continue;
        admg=sdamage;
        if(do_save(attackers[i]),-2)
        {
            admg/=2;
        }
        else
        {
            tell_object(attackers[i],"%^BOLD%^The light burns your eyes, blinding you!%^RESET%^");
            attackers[i]->set_temporary_blinded(3);
        }
        tell_object(attackers[i],"%^BOLD%^%^WHITE%^Your soul burns in the light!%^RESET%^");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg,"untyped");
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
