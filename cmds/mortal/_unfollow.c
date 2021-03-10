#include <std.h>

inherit DAEMON;

int help();

int cmd_unfollow(string str)
{
    string who;
    object targ;
    if (!str) {
        return notify_fail("Unfollow who?\n");
    }
    str = lower_case(str);
    who = (string)TP->realNameVsProfile(str);
    if (!who) {
        return notify_fail("You don't seem to know anyone by that name.\n");
    }
    targ = find_living(who);
    if (!objectp(targ)) {
        return notify_fail("You are not following " + capitalize(str) + ".\n");
    }
    if (!targ->query_followers()) {
        return notify_fail("You are not following " + capitalize(str) + ".\n");
    }
    if (member_array(TP, targ->query_followers()) < 0) {
        return notify_fail("You are not following " + capitalize(str) + ".\n");
    }
    tell_object(TP, "You are no longer following " + capitalize(str) + ".");
    tell_object(targ, TPQCN + " will no longer follow you.");
    targ->remove_follower(TP);
    who = targ->query_name();
    targ->unallow_follower((string)TP->knownAs(who));
    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

unfollow - stop following someone

%^CYAN%^SYNOPSIS%^RESET%^

unfollow %^ORANGE%^%^ULINE%^NAM%^RESET%^E

%^CYAN%^DESCRIPTION%^RESET%^

This will allow you to stop following %^ORANGE%^%^ULINE%^NAME%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

follow, party, ditch
"
        );
}
