#include <std.h>
#include <daemons.h>

inherit DAEMON;

#define SYNTAX "newsadm <command> <arg>\n"

int cmd_newsadm(string str) {
    string cmd, arg;

    if (!archp(this_player(1))) return 0;
    if (!str) return notify_fail(SYNTAX);
    cmd = str;
    sscanf(cmd, "%s %s", cmd, arg);
    switch (cmd) {
    case "add":
        if (!arg) return notify_fail(SYNTAX);
        NEWSSERVER->add_group(arg);
        break;
    case "rmgroup":
    if (!arg) return notify_fail(SYNTAX);
    NEWSSERVER->remove_group(arg);
    break;
    case "list":
        write(implode(NEWSSERVER->get_groups(), ", "));
        break;
    default:
        write("Invalid command.");
    }
    return 1;
}
