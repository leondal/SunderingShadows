#include <spell.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

int benchmark,tally,bonus;

#define DELAY 10800

void create()
{
    ::create();
    set_spell_name("eclipse");
    set_spell_level(([ "mage" : 9, "oracle" : 8, "cleric" : 9 ]));
    set_domains("moon");
    set_mystery("lunar");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS eclipse");

    set_description("With this powerful ritual, a caster moves Tyrannos in front of the sun, temporarily turning day into night. The heavenly body will stay in the sky for a long while, but eventually it will return back to its orbit.");
    set_helpful_spell(1);
    evil_spell(1);
    set_components(([
                        "mage" : ([ "large diamond" : 13]),
                        ]));
}

string query_cast_string()
{
    return "%^BOLD%^%^BLACK%^"+caster->QCN+" raises "+caster->QP+" hands to the %^WHITE%^sky%^BLACK%^, loudly proclaiming the ritual.%^RESET%^";
}

int preSpell()
{
    if(ENV(caster)->query_property("indoors"))
    {
        tell_object(caster, "%^BOLD%^%^BLACK%^Cover what sun? You're inside!%^RESET%^");
        return 0;
    }
    if(!caster->query_time_delay("eclipse_caused", DELAY))
    {
        tell_object(caster, "%^BOLD%^%^BLACK%^Tyrannos won't move yet.%^RESET%^");
        return 0;
    }
    if((int)ASTRONOMY_D->query_eclipse())
    {
        tell_object(caster, "%^BOLD%^%^BLACK%^There is already an ongoing %^WHITE%^eclipse%^BLACK%^!%^RESET%^");
        return 0;
    }
    if((string)EVENTS_D->query_time_of_day() == "night")
    {
        tell_object(caster, "%^BOLD%^%^BLACK%^Cover what sun? It is already dark!%^RESET%^");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    /* if(!random(19)&&!present("mark999",caster)) */
    /* { */
    /*     object mark; */
    /*     mark = new("/d/common/assassins/obj/mark"); */
    /*     mark->move(caster); */
    /* } */
    caster->set_time_delay("eclipse_caused");
    tell_object(caster,"%^BOLD%^%^WHITE%^As power rushes through you and you throw your hands toward the sky, you notice Tyrannos starts to move to stand in front of the sun!%^RESET%^");
    tell_room(place,"%^BOLD%^%^WHITE%^As "+caster->QCN+"'s chanting grows louder, up in the sky you see Tyrannos moving!",caster);
    message("info","%^BOLD%^%^BLACK%^You see the moon Tyrannos moving in front of the sun up in the sky!%^BOLD%^%^BLACK%^\n",filter_array(users(),(:!(environment($1)->query_property("indoors")):)));
    call_out("step_two",ROUND_LENGTH);
}

void step_two()
{
    message("info","\n%^BOLD%^%^BLACK%^Darkness descends as Tyrannos blots out the %^YELLOW%^s%^RESET%^%^ORANGE%^u%^YELLOW%^n%^BOLD%^%^BLACK%^!\n",filter_array(users(),(:!(environment($1)->query_property("indoors")):)));
    ASTRONOMY_D->set_eclipse();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
