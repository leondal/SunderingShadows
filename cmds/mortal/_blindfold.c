#include <std.h>

inherit DAEMON;

int cmd_blindfold(string str)
{
    object who;

    if (!str) {
        return notify_fail("Blindfold whom??\n");
    }

    if (!(who = present(str, ETP)) || (avatarp(who) && !who->query_disguised())) {
        return notify_fail("That is not here.\n");
    }

    if (!TP->ok_to_kill(who)) {
        return notify_fail("Supernatural forces prevent you from doing that.\n");
    }
    if (!userp(who)) {
        return notify_fail("Blindfolding can only be done in RP situations.\n");
    }


    if (sizeof(TP->query_attackers())) {
        return notify_fail("You're too busy right now.\n");
    }

    if ((who != TP) && (!who->query_unconscious()) && (!who->query_bound())) {
        return 1 + write(who->query_cap_name() + " is gonna fight that ya know.\n");
    }

    if (who->query_blindfolded()) {
        return 1 + write(who->query_cap_name() + " is already blindfolded.\n");
    }

    if (who == TP) {
        who->set_blindfolded(4000);
        tell_room(ETP, "%^BOLD%^" + TPQCN + " takes a strip of cloth and blindfolds " + who->query_objective() + "self.", ({ TP }));
        tell_object(TP, "%^BOLD%^You take a strip of cloth and blindfold yourself.");
        return 1;
    } else {
        tell_room(ETP, "%^BOLD%^" + TPQCN + " takes a strip of cloth and blindfolds " + who->query_cap_name() + ".", ({ TP, who }));
        tell_object(TP, "%^BOLD%^You take a strip of cloth and blindfold " + who->query_cap_name() + ".");
        if (!who->query_unconscious()) {
            tell_object(who, "%^BOLD%^" + TPQCN + " takes a strip of cloth and blindfolds you.");
        }
        who->set_blindfolded((int)TP->query_stats("wisdom") * (int)TP->query_stats("strength") * 10);
        TP->set_paralyzed(5, "You are busy blindfolding " + who->query_cap_name());
        return 1;
    }
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

blindfold - deprive someone of sight

%^CYAN%^SYNOPSIS%^RESET%^

blindfold %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^SYNOPSIS%^RESET%^

This command will blindfold %^ORANGE%^%^ULINE%^TARGET%^RESET%^.

The %^ORANGE%^%^ULINE%^TARGET%^RESET%^ must be either unconcious or be bound.

Blinding will prevent them from seeing the room and objects in it.

To remove blindfold use %^ORANGE%^<unblindfold>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

unblindfold, bind, gag, ungag, struggle, drag, drop, strip, pkilling, rules, rope use

"
        );
}
