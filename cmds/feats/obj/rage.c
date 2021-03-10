#include <std.h>
#include <magic.h>
#include <daemons.h>

#pragma strict_types, strong_types

inherit OBJECT;

string * JUDGEMENT_TYPES = ({
        "destruction",
            "healing",
            "justice",
            "piercing",
            "protection",
            "purity",
            "resiliency",
            "resistance",
//            "smiting"
});

object caster;
int duration;

void create()
{
    ::create();
    set_name("judgement_obj");
    set("id", ({ "judgement_obj" }) );
    set("short", "");
    set("long", "");

    set_property("no animate",1);
    set_weight(0);
}

void setup_rage(object mycaster)
{
    caster = mycaster;
}

void activate_rage()
{
    if(!objectp(caster))
    {
        TO->remove();
        return;
    }
    tell_object(caster,"%^RED%^The world takes on a tinge of red as you are overcome by an insatiable desire to see your enemies rendered into a bloody pulp.%^RESET%^");
    tell_room(ENV(caster),"%^RED%^"+caster->QCN+" growls fiercely as "+caster->QS+" transforms into a homicidal maniac.%^RESET%^",caster);

    call_out("check",ROUND_LENGTH);
}

void check()
{
    if(!objectp(caster))
    {
        TO->remove();
        return;
    }
    call_out("check",ROUND_LENGTH);
}
