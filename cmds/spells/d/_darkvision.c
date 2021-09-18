//removed mention of non-specialized mages ~Circe~ 8/2/19
#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

int modifier;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("darkvision");
    set_spell_level(([ "mage" : 2, "ranger" : 3, "monk" : 3, "assassin": 3, "magus": 3]));
    set_spell_sphere("alteration");
    set_monk_way("way of the shadow");
    set_syntax("cast CLASS darkvision");
    set_description("This spell will enhance the vision of the caster, allowing them better sight in areas of extreme "
"light or darkness.");
    set_verbal_comp();
    set_somatic_comp();
     // school specific mage spell
	set_helpful_spell(1);
}

string query_cast_string() {
    if(spell_type == "ranger")
    {
        tell_object(caster,"%^GREEN%^Closing your eyes, you focus upon your "
        "surroundings and attune your senses.%^RESET%^");
        tell_room(place,"%^GREEN%^"+caster->QCN+" closes "+caster->QP+" eyes and "
        "focusses intently.%^RESET%^",caster);
    }
    else if(spell_type == "monk")
    {
        tell_object(caster, "%^BOLD%^%^BLACK%^Focusing intently on your inner self you "+
        "attempt to heighten your senses.%^RESET%^");
        tell_room(place, caster->QCN+"%^BOLD%^%^BLACK%^ begins focusing intently!%^RESET%^", caster);
    }
    else
    {
        tell_object(caster,"%^ORANGE%^Passing a hand over your eyes, you draw on the weave to heighten your "
        "senses.%^RESET%^");
        tell_room(place,"%^ORANGE%^"+caster->QCN+" passes a hand over "+caster->QP+" eyes and focusses "
        "intently.%^RESET%^",caster);
    }
    return "display";
}

int preSpell() {
    if(caster->query_property("darkvision"))
    {
        tell_object(caster,"Your senses are already heightened.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    int duration;
    target = caster;
    if(member_array((string)target->query_race(),PLAYER_D->night_races()) != -1) modifier = -10;
    else modifier = 8;
    if(spell_type == "ranger")
    {
        tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+"'s eyes open again, alert and bright, and "+caster->QS+" looks around.",caster);
        tell_object(caster,"%^BOLD%^%^GREEN%^You open your eyes again, and find "
        "your vision has become crystal-clear.%^RESET%^");
    }
    else if(spell_type == "monk")
    {
        tell_object(caster, "%^BOLD%^%^CYAN%^Your vision blurs for a brief moment before "+
        "taking on a crystalline clarity!%^RESET%^");
        tell_room(place, caster->QCN+"%^BOLD%^%^CYAN%^'s eyes glaze over for a brief moment "+
        "before flashing back to normal!%^RESET%^", caster);
    }
    else
    {
        tell_room(place,"%^ORANGE%^A %^RED%^crimson glow%^ORANGE%^ becomes apparent around "+target->QCN+"'s "
        "irises.%^RESET%^",target);
        tell_object(caster,"%^ORANGE%^The world around you drains of color and snaps into crystalline clarity.%^RESET%^");
    }
    addSpellToCaster();
    spell_successful();
    target->add_sight_bonus(modifier);
    target->set_property("spelled",({TO}));
    target->set_property("darkvision",1);
}

void dest_effect()
{
    if(objectp(target))
    {
        if(spell_type == "ranger")
        {
            tell_object(target,"%^BOLD%^%^GREEN%^You blink, and realise your alert "
            "focus has faded, with your vision restored to normal.");
            tell_room(environment(target),"%^BOLD%^%^GREEN%^"+target->QCN+" blinks "
            "and loses "+target->QP+" alert poise.%^RESET%^",target);
        }
        else if(spell_type == "monk")
        {
            tell_object(target, "%^BOLD%^%^CYAN%^Your blink rapidly as your "+
            "vision suddenly returns to normal.%^RESET%^");
            tell_room(environment(target), target->QCN+" %^BOLD%^%^CYAN%^blinks "+
            "rapidly for a few brief moments.%^RESET%^", target);
        }
        else
        {
            tell_object(target,"%^ORANGE%^You blink, and the color drains back into your vision as it loses its clarity.");
            tell_room(environment(target),"%^ORANGE%^"+target->QCN+" blinks as the %^RED%^crimson glow %^ORANGE%^of "
            +target->QP+" eyes fades.%^RESET%^",target);
        }
        target->add_sight_bonus(-1*modifier);
        target->remove_property("darkvision");
    }
     ::dest_effect();
     if(objectp(TO)) TO->remove();

}
