#include <std.h>
#include <daemons.h>
#include <dirs.h>
#include <magic.h>
inherit DAEMON;

int cmd_heal(string str)
{
    string targ_id;
    int mount, mod, success, prof, paratime, delay, diff, healed, toheal;
    int x, combat_ok = 0;
    object targ, *weapons,class_ob;

    if (TP->query_bound() || TP->query_paralyzed())
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if(!str)
    {
        return help();
    }
    if(TP->query_disable())
    {
        write("%^YELLOW%^You are still busy healing other wounds.%^RESET%^");
        return 1;
    }
    if(targ = present(str,ETP))
    {
        if(targ->query_true_invis() || (targ->query_invis() && !TP->detecting_invis() && targ != TP) )
        {
            notify_fail("You don't see that target here now do you?\n");
            return 0;
        }
    }

    if(!objectp(targ))
    {
        tell_object(TP, "You don't see that target here.");
        return 1;
    }

    if(sizeof(TP->query_attackers()) && TP->is_class("monk"))
    {
        class_ob = find_object_or_load(DIR_CLASSES+"/monk.c");
        if(class_ob->monk_check(TP, "heal", targ)) { combat_ok = 1; }
    }
    if((object)TP->query_attackers() != ({}) && !combat_ok)
    {
        return notify_fail("Get real, not while fighting!\n\n");
    }

    if(combat_ok && TP == targ)
    {
        if((int)TP->query_hp() >= (int)TP->query_max_hp())
        {
            tell_object(TP, "%^BOLD%^%^CYAN%^You are not wounded and have no reason to focus "+
            "your mind on making your body whole.%^RESET%^");
            return 1;
        }
        tell_object(TP, "%^BOLD%^%^CYAN%^You focus your mind, drawing on energy deep inside "+
        "yourself as you attempt to make your body whole again!%^RESET%^");
        if(objectp(ETP))
        {
            tell_room(ETP, TPQCN+"%^BOLD%^%^CYAN%^ begins focusing intently and you "+
            "watch in awe as some of "+TP->QP+" wounds mend on their own!%^RESET%^", TP);
        }
        TP->add_hp((int)TP->query_guild_level("monk") * 12);
        TP->remove_property("wholeness of body");
        TP->set_property("wholeness of body", (time() + 20));//was  90 + random(90)));
        TP->spend_ki(3);
        return 1;
    }

    if(targ->query_hp() >= targ->query_max_hp() )
    {
        return notify_fail("That target doesn't need healing.\n");
    }

    prof = TP->query_skill("healing");

    targ_id = targ->query_cap_name();

//    diff = targ->query_level(); //difficulty should not depend on the target's overall level
    diff = 15; //changing to a static difficulty
//    if(!diff) diff = 10;//this is no longer needed with static difficulty

    if(!interactive(targ)) { notify_fail("Another bug fixed :)\n"); }

    if(TP->query_blind())     prof = 0;

    paratime = 3; // setting a default timer for use, but increasing effectiveness with skill. N, 8/13

    if(!TP->query_time_delay("healing",paratime) && !combat_ok)
    {
        return notify_fail("You need more time to study the wounds and prepare before you try again.\n");
    }

// this works for both except animals need a check for type?
    prof += roll_dice(1,20);
    if(prof >= diff) success = 1;

    TP->set_disable(paratime,targ);
    call_out("notify_done",paratime*ROUND_LENGTH);
    TP->set_time_delay("healing");

    if(TP == targ)
    {
        write("%^BOLD%^%^CYAN%^You slowly start tending to your wounds...%^RESET%^");
        tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" begins to tend to "+TPQP+" wounds.%^RESET%^", TP);
    }
    else
    {
        write("%^BOLD%^%^CYAN%^You start tending to "+targ_id+"'s wounds.%^RESET%^");
        tell_object(targ,"%^BOLD%^%^CYAN%^"+TPQCN+" begins to tend to your wounds.%^RESET%^");
        tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" begins to tend to "+targ_id+"'s wounds.%^RESET%^", ({TP, targ}) );
    }

    // changed this to a variable for success, defined above as before if NWPs don't kick in
    if(!success)
    {
        write("%^BOLD%^Your attempt begins to falter!%^RESET%^");
        if(TP != targ)
        tell_room(ETP,"%^GREEN%^%^BOLD%^You see a worried expression cross "+TPQCN+"'s face.",TP);
    }
    else
    {
        write("%^BOLD%^%^YELLOW%^The wounds slowly heal!%^RESET%^");
        if(TP != targ)
        {
            tell_room(ETP,"%^BOLD%^%^YELLOW%^The wounds slowly heal!%^RESET%^",TP);
        }

        healed = prof - diff; // to give percentage of max hp healed
//        if(healed > 20) healed = 20; // no greater than 20% of max hp healed in a single use
// taking this out. Player healing is self-limited at about 50% of max.

        toheal = (int)targ->query_max_hp();
        healed = (toheal * healed)/100;
        toheal -= (int)targ->query_hp();
        if(healed > toheal) healed = toheal;

        targ->add_hp(healed);
    }

    return 1;
}

void notify_done()
{
    if(objectp(TP))
        tell_object(TP,"%^CYAN%^%^BOLD%^You finish tending to wounds.%^RESET%^");
}

void help()
{
   write(
"
%^CYAN%^NAME%^RESET%^

name - heal something

%^CYAN%^SYNOPSIS%^RESET%^

heal %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This will allow a player to tend to some of %^ORANGE%^%^ULINE%^TARGET%^RESET%^s wounds. The amount of healing and success depends on healing skill. Heal can't be used in combat and the process takes some time, during which you won't be able to move.

%^CYAN%^MONKS%^RESET%^

Monks of The Way of The Fist can use %^ORANGE%^<heal>%^RESET%^ in combat, and power of their heal won't depend on healing skill. Instead, it will be based on their monk levels and will always amount to monk levels multiplied by 8.

%^CYAN%^SEE ALSO%^RESET%^

healing, heal *spells, *player commands
"
   );
   return 1;
}
