#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>

inherit SPELL;
int indoors;
object *newfoes;

void create() {
    ::create();
    set_spell_name("reverse gravity");
    set_spell_level(([ "mage" : 7, "druid" : 8 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS reverse gravity");
    set_damage_desc("untyped");
    set_description("This spell reverses gravity in an area, causing all unattached objects and creatures within that area to fall upward and reach the top of the area in 1 round. If some solid object (such as a ceiling) is encountered in this fall, falling objects and creatures strike it in the same manner as they would during a normal downward fall, getting damaged. If an object or creature reaches the top of the area without striking anything, it remains there, until the spell ends, as if it was under normal gravity. At the end of the spell duration, affected objects and creatures fall downward. Ouch!");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    set_save("reflex");
    set_components(([
      "mage" : ([ "white feather" : 1 ]),
    ]));
}

string query_cast_string() {
    return "%^WHITE%^"+caster->QCN+" places a feather into the air, and it stays floating.";
}

void spell_effect(int prof){
    object foe, *foes;
    int i;
    int duration;

    duration = clevel/12;
    duration=roll_dice(1,duration);
    duration=duration<2?2:duration;

    foes = target_selector();

    tell_room(place,"%^BOLD%^%^WHITE%^Suddenly, everyone starts to float up!%^RESET%^");

    indoors=(int)place->query_property("indoors");

    newfoes=foes;

    foreach(foe in foes)
    {
        if(do_save(foe))
        {
            tell_object(foe,"%^RESET%^%^WHITE%^%^BOLD%^You manage to grab something and hold to the ground!%^RESET%^");
            tell_room(place,"%^RESET%^%^WHITE%^%^BOLD%^"+foe->QCN+"%^BOLD%^%^WHITE%^ manages to hold to the ground!%^RESET%^",({foe}));
            newfoes-=({foe});
            continue;
        }
        if((int)foe->query_property("flying"))
        {
            tell_object(foe,"%^RESET%^%^WHITE%^%^BOLD%^You are levitating and remain unaffected by reversed gravity!%^RESET%^");
            tell_room(place,"%^RESET%^%^WHITE%^%^BOLD%^"+foe->QCN+"%^BOLD%^%^WHITE%^ is flying and remains unaffected by reversed gravity!%^RESET%^",({foe}));
            newfoes-=({foe});
            continue;
        }
        tell_object(foe,"%^BOLD%^%^WHITE%^You start to float uncontrollably!");
        tell_room(place,"%^RESET%^"+foe->QCN+" starts to float uncontrollably!",({foe}));
    }

    if(indoors)
        foreach(foe in newfoes)
        {
            define_base_damage(0);
            tell_object(foe,"%^RESET%^%^WHITE%^You smash into the ceiling!%^RESET%^");
            tell_room(place,"%^RESET%^"+foe->QCN+" smashes into the ceiling!%^RESET%^");
            newfoes->set_tripped(duration,"%^BOLD%^You are floating uncontrollably in the air!%^RESET%^",4);
            damage_targ(foe,"torso",sdamage,"untyped");
        }
    else
        newfoes->set_tripped(duration,"%^BOLD%^You are floating uncontrollably in the air!%^RESET%^",4);

    spell_duration = (duration - 1) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
}

void dest_effect()
{
    object foe;
    foreach(foe in newfoes)
    {
        if(!objectp(foe))
            continue;
        if(!present(foe,place))
            continue;
        define_base_damage(0);
        tell_object(foe,"%^BOLD%^%^WHITE%^You fall rapidly andsmash into the floor!%^RESET%^");
        tell_room(place,"%^BOLD%^%^WHITE%^"+foe->QCN+" stops falls rapidly and smashes into the floor!%^RESET%^");
        damage_targ(foe,"torso",sdamage,"untyped");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
