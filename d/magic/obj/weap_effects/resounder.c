#include <std.h>
#include <daemons.h>

inherit DAEMON;

int resounder_func(object obj)
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

    if(!random(4))
        if(!(pspell->do_save(targ,6)))
        {
            tell_object(tp,"%^CYAN%^The vibrations of your"+obj->query_name()+" %^CYAN%^ resound with "+targ->QCN+"%^CYAN%^.%^RESET%^");
            tell_object(targ,"%^CYAN%^The virbations of "+tp->QCN+"%^CYAN%^'s "+obj->query_name()+"%^CYAN%^ resound with your flesh!%^RESET%^");
            tell_room(etp,"%^CYAN%^The virbations of  "+tp->QCN+"%^CYAN%^'s "+obj->query_name()+"%^CYAN%^ resound with "+targ->QCN+".%^RESET%^",({tp,targ}));
            targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(1, 8), "sonic");
            //targ->do_damage(targ->return_target_limb(), roll_dice(1,8));
        }

    return 1;

}

void remove_prop(object obj)
{
    obj->remove_property_value("added short",({ "%^RESET%^%^CYAN%^ %^BOLD%^{%^RESET%^%^CYAN%^vibrating%^BOLD%^}%^RESET%^" }));
    obj->remove_property("temp_hit_bonus");
    if(userp(environment(obj)))
    {
        tell_object(environment(obj),"%^CYAN%^The "+obj->query_name()+" stops vibrations.");
    }
}
