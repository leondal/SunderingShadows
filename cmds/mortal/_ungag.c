#include <std.h>

inherit DAEMON;

int cmd_ungag(string str)
{
    int delay;
    object who;

    if (TP->query_bound()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }


    if (!str) {
        return notify_fail("Ungag whom?\n");
    }

    if (sizeof(TP->query_attackers())) {
        return notify_fail("You're too busy right now.\n");
    }

    if (!objectp(present(str, ETP))) {
        return notify_fail("That is not here.\n");
    }

    if (!(who = present(str, ETP)) || (avatarp(who) && !who->query_disguised())) {
        return notify_fail("That is not here.\n");
    }

    if (!TP->ok_to_kill(who)) {
        return notify_fail("Supernatural forces prevent you from doing that.\n");
    }

    if (!who->query_gagged()) {
        return notify_fail("That person is not gagged.\n");
    }

    tell_room(ETP, "%^BOLD%^" + TPQCN + " starts to ungag " + who->query_cap_name() + ".", ({ TP, who }));
    if (who == TP) {
        tell_object(TP, "You start to ungag yourself.");
    } else {
        tell_object(TP, "%^BOLD%^You start to ungag " + who->query_cap_name() + ".");
        if (!who->query_unconscious()) {
            tell_object(who, "%^BOLD%^" + TPQCN + " starts to ungag you.");
        }
    }
    delay = (20 - ((int)TP->query_skill("rope use") / 2));
    call_out("ungag", delay, who, TP);
//  call_out("ungag",(25 - (int)TP->query_stats("dexterity"))*2, who, TP);

    return 1;
}

void ungag(object who, object tp)
{
    if (environment(who) != environment(tp)) {
        tell_object(tp, "You are no longer in the room with " + who->query_cap_name());
        return;
    }

    if (sizeof(tp->query_attackers())) {
        tell_object(tp, "%^BOLD%^You can not ungag " + who->query_cap_name() + " while fighting.");
        return;
    }
    tell_room(environment(tp), "%^BOLD%^" + tp->query_cap_name() + " ungags " + who->query_cap_name() + ".", ({ tp, who }));
    if (who == tp) {
        tell_object(tp, "You ungag yourself.");
    } else {
        tell_object(tp, "%^BOLD%^You ungag " + who->query_cap_name() + ".");
        if (!who->query_unconscious()) {
            tell_object(who, "%^BOLD%^" + tp->query_cap_name() + " ungags you.");
        }
    }
    who->set_gagged(0);
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

ungag - ungag someone

%^CYAN%^SYNOPSIS%^RESET%^

ungag %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This will free a gagged %^ORANGE%^%^ULINE%^TARGET%^RESET%^ allowing them to speak. Anyone can ungag a gagged %^ORANGE%^%^ULINE%^TARGET%^RESET%^. Ungagging a %^ORANGE%^%^ULINE%^TARGET%^RESET%^ does take some time. To ungag yourself you must not be bound.

%^CYAN%^SEE ALSO%^RESET%^

gag, bind, unbind, blindfold, unblindfold, stip, pkilling, rules
"
        );
}
