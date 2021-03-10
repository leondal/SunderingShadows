#include <std.h>

inherit DAEMON;

int cmd_unblindfold(string str)
{
    int delay;
    object who;

    if (TP->query_bound()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }


    if (!str) {
        return notify_fail("Unblindfold whom?\n");
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

    if (!who->query_blindfolded()) {
        return notify_fail("That person is not blindfolded.\n");
    }
    if (who == TP) {
        tell_room(ETP, "%^BOLD%^" + TPQCN + " starts to take off " + who->query_possessive() + " blindfold.", ({ TP }));
        tell_object(TP, "%^BOLD%^You start to remove your blindfold.");
    } else {
        tell_room(ETP, "%^BOLD%^" + TPQCN + " starts to unblindfold " + who->query_cap_name() + ".", ({ TP, who }));
        tell_object(TP, "%^BOLD%^You start to unblindfold " + who->query_cap_name() + ".");
        if (!who->query_unconscious()) {
            tell_object(who, "%^BOLD%^" + TPQCN + " starts to unblindfold you.");
        }
    }
    delay = (20 - ((int)TP->query_skill("rope use") / 2));
    call_out("unblindfold", delay, who, TP);
//  call_out("unblindfold",(25 - (int)TP->query_stats("dexterity"))*2, who, TP);

    return 1;
}

void unblindfold(object who, object tp)
{
    if (environment(who) != environment(tp)) {
        tell_object(tp, "You are no longer in the room with " + who->query_cap_name());
        return;
    }

    if (sizeof(tp->query_attackers())) {
        tell_object(tp, "%^BOLD%^You can not unblindfold " + who->query_cap_name() + " while fighting.");
        return;
    }
    tell_room(environment(tp), "%^BOLD%^" + tp->query_cap_name() + " unblindfolds " + who->query_cap_name() + ".", ({ tp, who }));
    if (who == tp) {
        tell_object(tp, "You unblindfold yourself.");
    } else {
        tell_object(tp, "%^BOLD%^You unblindfold " + who->query_cap_name() + ".");
        if (!who->query_unconscious()) {
            tell_object(who, "%^BOLD%^" + tp->query_cap_name() + " unblindfolds you.");
        }
    }
    who->set_blindfolded(0);
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

unblindfold - remove a blindfold

%^CYAN%^SYNOPSIS%^RESET%^

unblindfold %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This will remove blindfold from %^ORANGE%^%^ULINE%^TARGET%^RESET%^. Unblindfolding does take some time.

%^CYAN%^SEE ALSO%^RESET%^

blindfold, gag, ungag, bind, unbind, pkilling, rules
"
        );
}
