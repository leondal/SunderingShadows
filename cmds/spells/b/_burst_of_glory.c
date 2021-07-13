#include <std.h>
#include <magic.h>

inherit SPELL;

object *tracker = ({});
int bonus;

void create()
{
    ::create();
    set_spell_name("burst of glory");
    set_spell_level(([ "paladin" : 4, "cleric" : 5, "inquisitor":5]));
    set_domains(({"good"}));
    set_bonus_type("sacred");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS burst of glory");
    set_damage_desc("+1 to attack, damage bonus, clevel to hp bonus on allies");
    set_description("Allies in the place of the time of casting become blessed. This spell won't stack with bless type spells.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^" + caster->QCN + "%^WHITE%^begins to cast a %^BOLD%^%^WHITE%^del%^RESET%^%^ORANGE%^i%^ORANGE%^c%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^t%^ORANGE%^e%^WHITE%^ prayer, %^BOLD%^%^WHITE%^war%^RESET%^%^ORANGE%^m %^WHITE%^lig%^ORANGE%^h%^BOLD%^%^WHITE%^t%^RESET%^%^WHITE%^ surrounds them.";
}

int spell_effect()
{
    int duration;
    object * allies, ally;

    duration = ROUND_LENGTH * (clevel * 6);

    //bonus = clevel / 22 + 1;
    bonus = 1;
    
    allies = ({});
    allies = ob_party(caster) + (caster->query_followers() - caster->query_attackers()) + ({ caster });
    allies = distinct_array(allies);
    allies = filter_array(allies, (: environment($1) == $2 :), place);

    tell_room(place, "%^RESET%^A %^BOLD%^%^WHITE%^burs%^RESET%^%^ORANGE%^t%^WHITE%^ of %^ORANGE%^w%^ORANGE%^a%^BOLD%^%^WHITE%^r%^RESET%^%^ORANGE%^m %^ORANGE%^l%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^g%^BOLD%^%^WHITE%^ht%^RESET%^%^WHITE%^ emanates into all directions from "+caster->QCN+".", caster);
 tell_object(caster,"%^RESET%^A %^BOLD%^%^WHITE%^bu%^RESET%^%^ORANGE%^r%^ORANGE%^s%^ORANGE%^t%^WHITE%^ of %^ORANGE%^l%^BOLD%^%^WHITE%^ight%^RESET%^%^WHITE%^ spreads in all directions from you, washing over your allies.");

    foreach(ally in allies)
    {
        if(!objectp(ally))
            continue;

        if(ally->query_property("sacred"))
        {
            tell_room(place,"%^RESET%^%^WHITE%^The %^BOLD%^%^WHITE%^l%^RESET%^%^ORANGE%^i%^BOLD%^%^WHITE%^ght%^RESET%^%^WHITE%^ washes over " + ally->QCN + "%^WHITE%^, but nothing happens.%^RESET%^");
            continue;
        }

        tell_object(ally,"%^WHITE%^As the %^ORANGE%^l%^ORANGE%^i%^ORANGE%^g%^ORANGE%^h%^BOLD%^%^WHITE%^t%^RESET%^%^WHITE%^ washes over you, you feel %^ORANGE%^s%^BOLD%^%^WHITE%^tro%^RESET%^%^ORANGE%^n%^BOLD%^%^WHITE%^g%^RESET%^%^ORANGE%^e%^BOLD%^%^WHITE%^r%^RESET%^%^WHITE%^ and invigorated.");
        ally->add_damage_bonus(bonus);
        ally->add_attack_bonus(bonus);
        ally->add_max_hp_bonus(clevel);
        ally->set_property("sacred", 1);
        tracker += ({ally});
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
    object ally;
    foreach(ally in tracker)
    {
        if (!objectp(ally)) {
            continue;
        }

        tell_object(ally, "%^WHITE%^You feel the %^BOLD%^%^WHITE%^b%^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^es%^RESET%^%^ORANGE%^s%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^n%^BOLD%^%^WHITE%^g%^RESET%^%^WHITE%^ bestowed upon you fade.");

        ally->add_damage_bonus(-bonus);
        ally->add_attack_bonus(-bonus);
        ally->add_max_hp_bonus(-clevel);
        ally->remove_property("sacred");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
