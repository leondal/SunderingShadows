#include <std.h>
#include <magic.h>
inherit SPELL;

int lower;
object weap;

#define DISRUPTOR "/d/magic/obj/weap_effects/resounder"

void create()
{
    ::create();
    //AKA resounding blow, but will be useless in sg for just one blow
    set_spell_name("resounding weapon");
    set_spell_level(([ "inquisitor" : 5, "paladin" : 4 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS resounding weapon on WEAPON");
    set_damage_desc("divine");
    set_description("This spell makes a weapon vibrating impsossibly fast. Any creature struck with it will have a chance to recieve sonic damage. A successful save will negate the damage.");
    set_save("fort");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed(1);
}

void spell_effect()
{
    string poisonf;
    object targ;
    targ = present(arg,caster);
    if(!objectp(targ))
    {
        tell_object(caster, "Cant find "+arg+" in your inventory!");
        TO->remove();
        return;
    }
    if(!targ->is_weapon())
    {
        tell_object(caster, "That is not a weapon!");
        TO->remove();
        return;
    }

    if(targ->query_property("temp_hit_bonus"))
    {
        tell_object(caster, "This weapon is already engulfed with magic!");
        TO->remove();
        return;
    }

    if(objectp(targ))
    {
        mapping info = ([]);

        info["file"] = DISRUPTOR;
        info["func name"] = "disruptor_func";
        info["spell"] = TO;

        targ->set_property("temp_hit_bonus",info);

        weap = targ;

        tell_object(caster, "%^CYAN%^Your "+targ->query_name()+" begins vibrating %^CYAN%^as you move your hand along it.");
        tell_room(place, "%^CYAN%^"+targ->query_name()+"%^CYAN%^ begins vibrating as %^GREEN%^"+caster->QCN+" %^CYAN%^moves %^GREEN%^"+caster->QP+" %^CYAN%^hand along it.",({caster}));
        targ->set_property("added short",({ "%^RESET%^%^CYAN%^ %^BOLD%^{%^RESET%^%^CYAN%^vibrating%^BOLD%^}%^RESET%^" }));
//        call_out("dest_effect",ROUND_LENGTH*6*clevel);
        caster->set_property("spelled", ({TO}) );
        addSpellToCaster();
    }
}

void dest_effect()
{
    if(objectp(weap))
    {
        DISRUPTOR->remove_prop(weap);
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
