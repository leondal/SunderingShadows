//Adjusted by ~Circe~ to give an attack bonus based on
//level as well.  5/25/08 rebalancing domains
// armor of darkness
#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

int armor_bonus,modifier,attk_bonus;


void create()
{
    ::create();
    set_author("ares");
    set_spell_name("armor of darkness");
    set_spell_level(([ "cleric" : 4]));
    set_spell_sphere("divination");
    set_bonus_type(({"deflection"}));
    set_syntax("cast CLASS armor of darkness");
    set_description("This spell will surround the caster in a dark haze making it harder for enemies to see the caster to hit them.  It also improves the caster's vision to allow them to better see through the darkness themselves.");
    set_verbal_comp();
    set_helpful_spell(1);
}


string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^BLACK%^Cupping your hands to your mouth,"+
        " you begin to whisper a prayer.");
    tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" cups "+caster->QP+" "+
        "hands to "+caster->QP+" mouth, as "+caster->QS+" begins to "+
        "whisper a prayer.",caster);
    return "display";
}


int preSpell()
{
    /*
    if(caster->query_property("darkness armor") || caster->query_property("light nimbus"))
    {
        tell_object(caster,"%^BLUE%^You are already protected by armor of darkness.");
        return 0;
    }
    */
    return 1;
}


void spell_effect(int prof)
{
    int duration;

    armor_bonus = 3;
    //attk_bonus = clevel/10;

    duration = (ROUND_LENGTH * 20) * clevel;

    if(member_array((string)caster->query_race(),PLAYER_D->night_races()) != -1)
    {
        modifier = -3;
    }
    else { modifier = 2; }

    tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+"'s eyes flash "+
        "%^RED%^red%^BOLD%^%^BLACK%^ as "+caster->QS+" is engulfed "
        "in an eerie darkness!");
    tell_object(caster,"%^BOLD%^%^BLACK%^You can feel the protective"+
        " darkness seep around you as your vision begins to intensify.");

    addSpellToCaster();
    caster->add_ac_bonus(armor_bonus);
    spell_successful();
    caster->add_sight_bonus(modifier);
    caster->add_attack_bonus(attk_bonus);
    caster->set_property("spelled",({TO}));
    //caster->set_property("darkness armor",1);
    caster->set_property("added short",({"%^BOLD%^%^BLACK%^ (seeped in darkness)%^RESET%^"}));
}


void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,"%^BOLD%^%^BLACK%^You blink your eyes as the darkness fades "
            "away, leaving you vulnerable once again.");
        tell_room(environment(caster),"%^BOLD%^%^BLACK%^The %^RED%^red%^BLACK%^ glow"+
            " slowly fades from "+caster->QCN+"'s eyes.");
        caster->add_ac_bonus(-1*armor_bonus);
        caster->add_sight_bonus(-1*modifier);
        caster->add_attack_bonus(-1*attk_bonus);
        //caster->remove_property("darkness armor");
        caster->remove_property("added short",({"%^BOLD%^%^BLACK%^ (seeped in darkness)%^RESET%^"}));
    }

    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
