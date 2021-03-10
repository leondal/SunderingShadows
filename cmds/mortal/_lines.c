#include <std.h>

inherit DAEMON;

int cmd_lines(string str)
{
    string* channels;
    int i;

    channels = distinct_array((string*)TP->query_channels());

    if (!str) {
        for (i = 0; i < sizeof(channels); i++) {
            if (TP->query_blocked(channels[i])) {
                message("info", "The %^RED%^" + channels[i] + "%^RESET%^ line is %^RED%^OFF%^RESET%^.", TP);
            }else {
                message("info", "The %^GREEN%^" + channels[i] + "%^RESET%^ line is %^GREEN%^ON%^RESET%^.", TP);
            }
        }
        return 1;
    }
    if (str == "on") {
        for (i = 0; i < sizeof(channels); i++) {
            if (TP->query_blocked(channels[i])) {
                TP->set_blocked(channels[i]);
            }
        }
        return 1;
    }
    if (str == "off") {
        for (i = 0; i < sizeof(channels); i++) {
            if (!TP->query_blocked(channels[i])) {
                TP->set_blocked(channels[i]);
            }
        }
        return 1;
    }
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

lines - toggle lines off or on

%^CYAN%^SYNOPSIS%^RESET%^

lines [on|off]

%^CYAN%^DESCRIPTION%^RESET%^

With no argument, it will list the status of your lines (channels).

With arguments on or off it will toggle all of your lines (channels) on or off.

To disable just one line use the line name without an argument, e.g. to disable ooc line just type %^ORANGE%^<ooc>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

line use, tell, mail, bboard

");
}
