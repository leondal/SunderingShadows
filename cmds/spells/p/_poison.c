#include <priest.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

#define POISONS ({ "wyvern_poison", "shadow_essence", "purple_worm_poison", "large_scorpion_venom", "giant_wasp_poison", "deathblade" })
#define PDIR "/d/common/obj/poisons/base/"

object wpn;

void create()
{
    ::create();
    set_spell_name("poison");
    set_spell_level(([ "cleric" : 4, "druid" : 3, "paladin" : 4, "assassin" : 1, "inquisitor" : 3, "ranger":3]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS poison on TARGET|WEAPON");
    set_description("With this spell you create a natural poison and either envenom your target with it, or apply it to a weapon in your possession.

%^BOLD%^%^RED%^See also:%^RESET%^ poison *player commands");
    set_save("fort");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed(1);
}

void spell_effect()
{
    string poisonf;
    object targ;

    if (!objectp(place)) {
        return;
    }

    poisonf = PDIR+POISONS[random(sizeof(POISONS))];

    targ = present(arg,place);

    if(objectp(targ) &&
       !living(targ))
    {
        tell_object(caster, "That is not a living being!");
        TO->remove();
        return;
    }

    if(objectp(targ))
    {
        tell_object(caster,"%^GREEN%^You extend your hand and %^BOLD%^thorn%^RESET%^%^GREEN%^ flies out of it straight into %^BOLD%^"+targ->QCN+"%^RESET%^%^GREEN%^!");
        tell_room(place,"%^GREEN%^"+caster->QCN+" extends "+caster->QP+" hand and %^BOLD%^thorn%^RESET%^%^GREEN%^ flies out of it straight into %^BOLD%^"+targ->QCN+"%^RESET%^%^GREEN%^!",({caster}));
        POISON_D->ApplyPoison(targ,poisonf,caster,"injury");
        spell_kill(targ,caster);
        dest_effect();
        return;
    }
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
    if(objectp(targ))
    {
        string pname;
        object poisono;

        poisono=new(poisonf);
        if(!objectp(poisono))
        {
            tell_object(caster, "Poisoning failed because of reasons!");
            TO->remove();
            return;
        }
        wpn = targ;

        pname = poisono->query_poison_name();
        wpn->set("PoisonDoses", clevel/5);
        wpn->set("PoisonType", pname);
        wpn->set("whoImmune", caster->query_name());
        if(wpn->query_property("temp_oiled")){
            wpn->remove_property("temp_oiled");
        }
        wpn->set_property("temp_oiled","damage bonus acid 5");
        tell_object(caster, "%^RESET%^%^GREEN%^A layer of %^BOLD%^%^GREEN%^p%^BLACK%^ois%^GREEN%^o%^GREEN%^n%^BLACK%^o%^GREEN%^u%^BLACK%^s %^BLACK%^ve%^GREEN%^n%^BLACK%^o%^GREEN%^m%^RESET%^%^GREEN%^ appears on%^RESET%^ "+wpn->query_name()+" %^RESET%^%^GREEN%^as you move your hand along it.%^RESET%^");
        tell_room(place, "%^RESET%^%^GREEN%^A layer of %^BOLD%^%^GREEN%^p%^BLACK%^ois%^GREEN%^o%^GREEN%^n%^BLACK%^o%^GREEN%^u%^BLACK%^s %^BLACK%^ve%^GREEN%^n%^BLACK%^o%^GREEN%^m%^RESET%^%^GREEN%^ appears on%^RESET%^ "+wpn->query_name()+" %^RESET%^%^GREEN%^as "+caster->QCN+" moves "+caster->QP+" hand along it.%^RESET%^",({caster}));
        dest_effect();
        return;
    }
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
