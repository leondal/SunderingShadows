#include <std.h>
#include <spell.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("overwhelming presence");
    set_spell_level(([ "cleric" : 9, "bard" : 6, "mage" : 9, "inquisitor" : 6, "oracle" : 9, "psion" : 9 ]));
    set_spell_sphere("enchantment_charm");
    set_mystery("dragon");
    set_discipline("telepath");
    set_domains("vigilance");
    set_syntax("cast CLASS overwhelming presence");
    set_damage_desc("trips attackers, 1d6 to wisdom");
    set_description("Your presence inspires incredible awe in your enemies. Those who fail to overcome it, will fall to their knees and prostrate themselves before you. Their mental abilities will suffer for a long while.");
    mental_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
}

string query_cast_string() {
    return "%^YELLOW%^"+caster->QCN+" proclaims an inspiring spell.";
}

void spell_effect(int prof){
    object *attackers, targ;
    int i, die;
    attackers = caster->query_attackers();
    attackers = target_filter(attackers);

    die=clevel/4;
    die=die<4?4:die;

    tell_room(place,"%^YELLOW%^"+caster->QCN+" basks in the light of divinity!%^RESET%^");
    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i]))
            continue;
        targ = attackers[i];
        if(!(do_save(targ,0)&&mind_immunity_damage(targ)))
        {
            targ->set_tripped(roll_dice(1,die),"%^BOLD%^You're prostrating in awe of "+caster->QCN+"'s divinity!%^RESET%^",die);
            tell_room(ENV(targ),"%^YELLOW%^"+targ->QCN+" prostrates itself before "+caster->QCN+"!");
            if(!targ->query_property("overwhelming_presence"))
            {
                targ->set_property("overwhelming_presence",1);
                targ->add_stat_bonus("wisdom",-roll_dice(1,6));
            }
        }
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
