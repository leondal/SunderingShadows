#include <std.h>

inherit DAEMON;

int help();

int cmd_ditch(string str)
{
    object targ;
    if (!str || !sizeof(TP->query_followers())) {
        return notify_fail("Ditch who?\n");
    }
    str = lower_case(str);
    str = TP->realNameVsProfile(str);
    targ = find_player(str);
    if (!targ) {
        targ = find_living(str);
    }
    if (!targ) {
        return notify_fail("No one by that name is online.\n");
    }
    if (member_array(targ,
                     TP->query_followers()) < 0) {
        if (!sizeof(TP->query_allowed())) {
            return notify_fail("No one by that name is following " +
                               "you.\n");
        }
    }
    if (targ->query_true_invis()) {
        return notify_fail("No one by that name is following " +
                           "you.\n");
    }
    write(targ->query_cap_name() + " will no longer follow you.");
    tell_object(targ, "You have been ditched by " +
                TP->query_cap_name() + ", and are no longer following " +
                TP->query_objective() + ".");
    TP->remove_follower(targ);
    TP->unallow_follower((string)targ->knownAs((string)TPQN));
    return 1;
}

int help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

ditch - ditch one of your followers

%^CYAN%^SYNOPSIS%^RESET%^

ditch %^ORANGE%^%^ULINE%^NAM%^RESET%^E

%^CYAN%^DESCRIPTION%^RESET%^

Allows you to ditch PC or NPC that is following you. A ditched player needs to be re-allowed to follow you again.

To see who is following you use %^ORANGE%^<followers>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

followers, follow, unfollow, party,
"
        );
    return 1;
}
