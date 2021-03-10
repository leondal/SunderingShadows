#include <std.h>

inherit DAEMON;

int cmd_gag(string str)
{
    object who;

    if (!str) {
        return notify_fail("Gag whom??\n");
    }

    if (!(who = present(str, ETP)) || (avatarp(who) && !who->query_disguised())) {
        return notify_fail("That is not here.\n");
    }

    if (!TP->ok_to_kill(who)) {
        return notify_fail("Supernatural forces prevent you from doing that.\n");
    }
    if (!userp(who)) {
        return notify_fail("Gagging can only be done in RP situations.\n");
    }


    if (sizeof(TP->query_attackers())) {
        return notify_fail("You're too busy right now.\n");
    }

    if ((who != TP) && (!who->query_unconscious()) && (!who->query_bound())) {
        return 1 + write(who->query_cap_name() + " is gonna fight that ya know.\n");
    }

    if (who->query_gagged()) {
        return 1 + write(who->query_cap_name() + " is already gagged.\n");
    }
    if (who == TP) {
        tell_room(ETP, "%^BOLD%^" + TPQCN + " takes a strip of cloth and gags " + who->query_objective() + "self.", ({ TP }));
        tell_object(TP, "%^BOLD%^You take a strip of cloth and gag yourself.");

        who->set_gagged(4000);
    } else {
        tell_room(ETP, "%^BOLD%^" + TPQCN + " takes a strip of cloth and gags " + who->query_cap_name() + ".", ({ TP, who }));
        tell_object(TP, "%^BOLD%^You take a strip of cloth and gag " + who->query_cap_name() + ".");
        if (!who->query_unconscious()) {
            tell_object(who, "%^BOLD%^" + TPQCN + " takes a strip of cloth and gags you.");
        }

        who->set_gagged((int)TP->query_stats("wisdom") * (int)TP->query_stats("strength") * 10);
        TP->set_paralyzed(5, "You are busy gagging " + who->query_cap_name());
        return 1;
    }
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

gag - gag someone

%^CYAN%^SYNOPSIS%^RESET%^

gag %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Gag the %^ORANGE%^%^ULINE%^TARGET%^RESET%^. This will prevent them from doing a ny speech oriented actions. The %^ORANGE%^%^ULINE%^TARGET%^RESET%^ must be unconcious or bound.

%^CYAN%^SEE ALSO%^RESET%^

struggle, ungag, bind, unbind, blindfold, unblindfold, stip, hit, pkilling, rules
"
        );
}
