#include <priest.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

#define POISONS ({ "wyvern_poison", "shadow_essence", "deathblade" })
#define PDIR "/d/common/obj/poisons/base/"

object wpn;

void create()
{
    ::create();
    set_spell_name("phantasmal poison");
    set_spell_level(([ "mage" : 4, ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS phantasmal poison on WEAPON");
    set_description("You create a phantasm of an oily green phantasmal poison on the target weapon.");
    set_arg_needed(1);
}

void spell_effect()
{
    string poisonf;
    object targ;

    poisonf = PDIR+POISONS[random(sizeof(POISONS))];

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
        tell_object(caster, "%^RESET%^%^CYAN%^A layer of %^BOLD%^%^CYAN%^p%^BLACK%^ois%^CYAN%^o%^CYAN%^n%^BLACK%^o%^CYAN%^u%^BLACK%^s %^BLACK%^ve%^CYAN%^n%^BLACK%^o%^CYAN%^m%^RESET%^%^CYAN%^ appears on%^RESET%^ "+wpn->query_short()+" %^RESET%^%^CYAN%^as you move your hand along it.%^RESET%^");
        tell_room(place, "%^RESET%^%^CYAN%^A layer of %^BOLD%^%^CYAN%^p%^BLACK%^ois%^CYAN%^o%^CYAN%^n%^BLACK%^o%^CYAN%^u%^BLACK%^s %^BLACK%^ve%^CYAN%^n%^BLACK%^o%^CYAN%^m%^RESET%^%^CYAN%^ appears on%^RESET%^ "+wpn->query_short()+" %^RESET%^%^CYAN%^as "+caster->QCN+" moves "+caster->QP+" hand along it.%^RESET%^",({caster}));
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
