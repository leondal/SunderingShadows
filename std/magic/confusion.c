/**
 * @file
 * @brief common confusion functions
 */

#include <std.h>
#include <daemons.h>

void confuse(object caster, object targ)
{
    int i;
    switch(random(100))
    {
    case 0..10:
        targ->force_me("kill "+caster->query_name()+"");
        tell_object(targ,"%^BOLD%^%^RED%^Outraged, you attack "+caster->QCN+"!");
        tell_object(caster,"%^BOLD%^%^RED%^Outraged "+targ->QCN+" attacks you!");
        tell_room(environment(targ),"%^BOLD%^"+targ->QCN+" attacks "+caster->QCN+" in a violent rage!",({targ,caster}));
        break;
    case 11..20:
        break;
    case 21..50:
        if(!present(caster,environment(targ)))
            TO->dest_effect();
        tell_object(targ,"%^YELLOW%^A strange thought enters your mind, but you cannot grasp it!");
        tell_room(environment(targ),"%^YELLOW%^"+targ->QCN+" stares at a point in space, babbling incoherently!",targ);
        targ->set_paralyzed(7,"You are trying to recall that thought!");
        break;
    case 51..70:
        if(!present(caster,environment(targ))) TO->dest_effect();
        tell_object(targ,"%^BOLD%^%^CYAN%^A sudden, overwhelming sense of fear comes over you!%^RESET%^");
        tell_room(environment(targ),"%^BOLD%^%^CYAN%^"+targ->QCN+" runs away in confusion!%^RESET%^",targ);
        targ->run_away();
        break;
    default:
    {
        object *targs;
        object chosen;

        if(!present(caster,environment(targ)))
            TO->dest_effect();

        targs = all_living(environment(targ));
        filter_array(targs, "is_non_immortal", FILTERS_D);
        targs -= ({targ});
        i = random(sizeof(targs));
        chosen = targs[i];

        tell_object(targ,"%^BOLD%^%^RED%^In a blind rage, you attack the thing closest to you!");
        tell_object(chosen,"%^BOLD%^%^RED%^"+targ->QCN+" suddenly turns and swings wildly at you!");
        tell_room(environment(targ),"%^BOLD%^%^RED%^"+targ->QCN+" suddenly turns and swings wildly, "+"attacking "+chosen->QCN+"!",({targ, chosen}));

        targ->force_me("kill "+chosen->query_name()+"");
    }
    break;
    }
}
