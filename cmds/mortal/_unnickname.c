#include <std.h>

int cmd_unnickname(string arg)
{
    mapping nicknames = TP->query_nicknames();
    string s, nickname;

    if (!arg) {
        notify_fail("usage: unnickname NICKNAME\n");
        return 1;
    }

    if (!sizeof(nicknames)) {
        notify_fail("You don't have any nicknames defined!");
        return 1;
    }

    foreach(s in keys(nicknames)) {
        if (nicknames[s] == arg) {
            nickname = s;
            break;
        }
    }

    if (!nickname) {
        notify_fail("No such nickname defined.\n");
        return 0;
    }

    TP->remove_nickname(nickname);
    write("Nickname removed: " + nickname + " (" + arg + ") " "\n");
    return 1;
}

void help()
{
    write(
"
%^CYAN%^NAME%^RESET%^

unnickname - remove a nickname

%^CYAN%^SYNOPSIS%^RESET%^

unnickname %^ORANGE%^%^ULINE%^NICKNAME%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This will remove %^ORANGE%^%^ULINE%^NICKNAME%^RESET%^ from list of used nick names.

Alternatively, type %^ORANGE%^<nickname %^ORANGE%^%^ULINE%^NICKNAME%^RESET%^%^ORANGE%^>%^RESET%^ providing no more arguments.

%^CYAN%^SEE ALSO%^RESET%^

nickname, alias, unalias, history, last, colors
"
        );
}
