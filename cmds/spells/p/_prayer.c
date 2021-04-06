#include <std.h>
#include <magic.h>

inherit SPELL;

object *ally_tracker = ({});
object *enemy_tracker = ({});
int bonus;

void create()
{
    ::create();
    set_spell_name("prayer");
    set_spell_level(([ "cleric" : 3, "inquisitor" : 3, "paladin":3 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS prayer");
    set_bonus_type("luck");
    set_damage_desc("+2 to attack, damage bonus, positive to allies, negative to enemies");
    set_description("Allies in the place of the time of casting become blessed, enemies become cursed. This spell is short duration.");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^" + caster->QCN + " wavers unevenly as " +caster->QCN+" %^ORANGE%^c%^BOLD%^%^WHITE%^h%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^n%^RESET%^%^ORANGE%^t%^WHITE%^s sonorously.";
}

int spell_effect()
{
    int duration;
    object * allies, ally, enemy;

    duration = ROUND_LENGTH * (clevel / 12 + 1);

    //bonus = clevel / 16 + 1;
    bonus = 2;
    
    allies = ({});
    allies = ob_party(caster) + (caster->query_followers() - caster->query_attackers()) + ({ caster });
    allies = distinct_array(allies);
    allies = filter_array(allies, (: environment($1) == $2 :), place);

    tell_room(place, "%^WHITE%^Soft %^BOLD%^%^WHITE%^r%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^d%^RESET%^%^ORANGE%^i%^ORANGE%^a%^ORANGE%^n%^BOLD%^%^WHITE%^c%^RESET%^%^ORANGE%^e%^WHITE%^ emanates into all directions from " + caster->QCN, caster);
    tell_object(caster,"%^WHITE%^You feel %^BOLD%^%^WHITE%^s%^RESET%^%^ORANGE%^o%^ORANGE%^f%^BOLD%^%^WHITE%^t %^WHITE%^radi%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^nce%^RESET%^%^WHITE%^ emanating out from you and washing over everyone in the area.");

    foreach(ally in allies)
    {
        if(!objectp(ally))
            continue;
        
        if(ally->query_property("luck"))
            continue;

        tell_object(ally,"%^WHITE%^You feel you grow stronger as %^ORANGE%^t%^BOLD%^%^WHITE%^h%^RESET%^%^ORANGE%^e %^WHITE%^r%^ORANGE%^a%^BOLD%^%^WHITE%^d%^RESET%^%^ORANGE%^i%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^n%^BOLD%^%^WHITE%^ce%^RESET%^%^WHITE%^ touches you.");
        ally->add_damage_bonus(bonus);
        ally->add_attack_bonus(bonus);
        ally_tracker += ({ally});
    }

    foreach(enemy in caster->query_attackers())
    {
        if(!objectp(ally))
            continue;

        tell_object(enemy,"%^WHITE%^You feel compelled not to fight as the %^ORANGE%^r%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^d%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^nce%^RESET%^%^WHITE%^ emanating from " + caster->QCN + " washes over you.");
        enemy->add_damage_bonus(-bonus);
        enemy->add_attack_bonus(-bonus);
        enemy_tracker += ({enemy});
    }

    caster->set_property("spelled",({TO}));
    spell_successful();
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    return;
}

void dest_effect()
{
    object ally, enemy;
    if(objectp(caster))
    {
        tell_object(caster,"%^WHITE%^You notice effects of your %^BOLD%^%^WHITE%^pra%^RESET%^%^ORANGE%^y%^BOLD%^%^WHITE%^er%^RESET%^%^WHITE%^ fade.");
    }
    foreach(ally in ally_tracker)
    {
        if (!objectp(ally)) {
            continue;
        }
        ally->add_damage_bonus(-bonus);
        ally->add_attack_bonus(-bonus);
    }

    foreach(enemy in enemy_tracker)
    {
        if (!objectp(enemy)) {
            continue;
        }
        enemy->add_damage_bonus(bonus);
        enemy->add_attack_bonus(bonus);
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
