#include <std.h>

inherit DAEMON;

int cmd_unblock(string str)
{
    int i;
    if (!str) {
        return notify_fail("Unblock what?\n");
    }
    if (member_array(str, ETP->query_exits()) == -1) {
        return notify_fail("No such exit.\n");
    }
    if (TP->query_bound()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if (member_array(str, keys(ETP->query_blockers())) < 0) {
        return notify_fail("You are not blocking " + str + ".\n");
    }
    if ((object)ETP->query_blocked(str) != TP) {
        return notify_fail("You are not blocking " + str + ".\n");
    } else {
        ETP->remove_blocker(str);
        tell_object(TP, "You stop blocking " + str + ".");
        TP->remove_property("posed");
        if (!TP->query_invis()) {
            tell_room(ETP, TPQCN + " stops blocking " + str + ".", TP);
        }
        return 1;
    }
    return 1;
}

void help()
{
    write(
"
%^CYAN%^NAME%^RESET%^

unblock - unblock exit

%^CYAN%^SYNOPSIS%^RESET%^

unblock %^ORANGE%^%^ULINE%^EXIT%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This will remove you blocking an exit

%^CYAN%^SEE ALSO%^RESET%^

block, sneak
"
        );
}
