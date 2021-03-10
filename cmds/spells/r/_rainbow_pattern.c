#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int bonus;

object * victims=({});;

void create()
{
    ::create();
    set_spell_name("rainbow pattern");
    set_spell_level((["mage":4,"oracle":4,"bard":4]));
    set_mystery("heavens");
    set_spell_sphere("illusion");
    set_damage_desc("clevel / 8 to perception");
    set_syntax("cast CLASS rainbow pattern on TARGET");
    set_description("This spell creates a hypnotic pattern in the air, causing every enemy to be fascinated and distracting them from reacting properly. Strong willed may shrug off that pattern.");
    set_save("will");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    mental_spell(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^Hypnotic %^BOLD%^%^RED%^s%^RESET%^%^ORANGE%^p%^BOLD%^i%^GREEN%^r%^CYAN%^a%^BLUE%^l%^MAGENTA%^s%^RESET%^spring into being around "+caster->QCN+".%^RESET%^";
}

void spell_effect(int prof)
{
    object * foes,foe;
    int duration = clevel/12+1;

    tell_object(caster,"%^BOLD%^%^WHITE%^You wave your hand and send hypnotic patterns to dance in front of your enemies.");
    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" waves "+caster->QP+" hand and sends hypnotic pattern to dance in front of "+caster->QP+"enemies",caster);

    foes = target_selector();
    bonus = clevel/8+1;

    foreach(foe in foes)
    {
        if(!objectp(foe))
            continue;
        if(foe->query_property("fascinated"))
            continue;
        if(do_save(foe,0) || mind_immunity_damage(foe))
        {
            tell_object(foe,"%^BOLD%^%^WHITE%^%^You manage to avert your gaze of the hypnotic pattern.");
        }
        else
        {
            tell_object(foe,"%^BOLD%^%^WHITE%^You can not shrug of distracting patterns.");
            tell_room(place,"%^BOLD%^%^WHITE%^"+foe->QCN+" seems to be fascinated by the pattern.",foe);
            foe->set_property("fascinated",1);
            victims+=({foe});

            foe->add_skill_bonus("perception",-bonus);

        }
    }
    if(sizeof(victims)){
        spell_duration = duration * ROUND_LENGTH;
        set_end_time();
        call_out("dest_effect",spell_duration);
    }
}

void dest_effect()
{
    object foe;
    ::dest_effect();
    foreach(foe in victims)
    {
        if(objectp(foe))
        {
            tell_object(foe,"%^BOLD%^%^WHITE%^Fascinating patterns fade away");
            tell_room(ENV(foe),"%^BOLD%^%^WHITE%^Patterns were dancing in front of "+foe->QCN+"'s eyes fade away.",foe);
            foe->remove_property("fascinated");
            foe->add_skill_bonus("perception",bonus);
        }
    }
    if(objectp(TO))
        TO->remove();
}
