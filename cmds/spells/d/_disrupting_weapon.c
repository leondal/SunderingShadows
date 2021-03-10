#include <std.h>
#include <magic.h>
inherit SPELL;

int lower;
object weap;

#define DISRUPTOR "/d/magic/obj/weap_effects/disruptor"

void create()
{
    ::create();
    set_spell_name("disrupting weapon");
    set_spell_level(([ "inquisitor" : 5, "cleric" : 5, "innate" : 5 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS disrupting weapon on WEAPON");
    set_damage_desc("divine");
    set_description("This spell makes a melee weapon deadly to undead. Any undead creature of level equal to or less than your caster level must succeed on a will save or be harmed greatly if struck in combat with this weapon. If the caster is undead, the effect is reversed and will harm living. A successful save will negate the damage.");
    set_save("will");
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

        tell_object(caster, "%^CYAN%^A layer of a%^BOLD%^rca%^RESET%^%^CYAN%^n%^BOLD%^e %^RESET%^%^CYAN%^f%^BOLD%^l%^RESET%^%^CYAN%^a%^BOLD%^me%^RESET%^%^CYAN%^s appears on %^WHITE%^"+targ->query_name()+" %^CYAN%^as you move your hand along it.");
        tell_room(place, "%^CYAN%^A layer of a%^BOLD%^rca%^RESET%^%^CYAN%^n%^BOLD%^e %^RESET%^%^CYAN%^f%^BOLD%^l%^RESET%^%^CYAN%^a%^BOLD%^me%^RESET%^%^CYAN%^s appears on %^WHITE%^"+targ->query_name()+" %^CYAN%^as %^GREEN%^"+caster->QCN+" %^CYAN%^moves %^GREEN%^"+caster->QP+" %^CYAN%^hand along it.",({caster}));
        targ->set_property("added short",({ "%^RESET%^%^CYAN%^ %^BOLD%^{%^RESET%^%^CYAN%^ablaze%^BOLD%^}%^RESET%^" }));
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
