#include <std.h>
#include <daemons.h>

inherit DAEMON;

int disruptor_func(object obj)
{
    object targ, tp, etp;
    object pspell;
    mapping winfo;

    if(!objectp(obj))
        return 0;
    if(!objectp(environment(obj)) ||
       !living(environment(obj)))
        return 0;

    tp = environment(obj);
    etp = environment(tp);

    if(!objectp(etp))
        return 0;

    winfo = obj->query_property("temp_hit_bonus");

    pspell = winfo["spell"];

    if(!objectp(pspell))
    {
        remove_prop(obj);
        return 0;
    }

    targ = tp->query_current_attacker();

    if(!objectp(targ))
        return 0;

    if(targ->query_level() < pspell->query_clevel() - 5)
        if(tp->is_undead() ^ targ->is_undead())
            if(!random(3))
                if(!(pspell->do_save(targ,6)))
                {
                    tell_object(tp,"%^CYAN%^The fire on your weapon burns "+targ->QCN+"%^CYAN%^ as you strike "+targ->QO+"%^CYAN%^.%^RESET%^");
                    tell_object(targ,"%^CYAN%^The fire on "+tp->QCN+"%^CYAN%^'s "+obj->query_name()+"%^CYAN%^ burns as it strikes you!%^RESET%^");
                    tell_room(etp,"%^CYAN%^The fire on "+tp->QCN+"%^CYAN%^'s "+obj->query_name()+"%^CYAN%^ burns "+targ->QCN+"%^CYAN%^ as it strikes "+targ->QO+"%^CYAN%^.%^RESET%^",({tp,targ}));
                    targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(1, 12), "fire");
                    //targ->do_damage(targ->return_target_limb(), roll_dice(1,12));
                }

    return 1;

}

void remove_prop(object obj)
{
    obj->remove_property_value("added short",({ "%^RESET%^%^CYAN%^ %^BOLD%^{%^RESET%^%^CYAN%^ablaze%^BOLD%^}%^RESET%^" }));
    obj->remove_property("temp_hit_bonus");
    if(userp(environment(obj)))
    {
        tell_object(environment(obj),"%^CYAN%^Arcane flames disappear from "+obj->query_name()+".");
    }
}
