#include <std.h>
#include <daemons.h>
inherit DAEMON;

int cmd_nickname(string str)
{
    mapping nicknames;
    mixed* nicks;
    int i;
    string nn, rn;
    object act_ob;

    act_ob = this_player();
    if (str == "reset") {
        write("Resetting nicknames...");
        act_ob->empty_nicknames();
        write("Done.\n");
        return 1;
    }
    nicknames = (mapping)act_ob->query_nicknames();

    if (!str) {
        nicks = keys(nicknames);
        if (!sizeof(nicks)) {
            write("No nicknames defined.\n");
            return 1;
        }
        nicks = sort_array(nicks, "alphabetical_sort", FILTERS_D);
        for (i = 0; i < sizeof(nicks); i++) {
            write(sprintf("%%^YELLOW%%^%-15s %%^RESET%%^%%^CYAN%%^%s", nicks[i], nicknames[nicks[i]]));
        }
        return 1;
    }
    if (sscanf(str, "%s %s", nn, rn) == 2) {
        if (nicknames[nn]) {
            write("Nickname " + nn + " changed from " + nicknames[nn] + ".\n");
        }else {
            write("Nickname " + nn + " added.\n");
        }
        act_ob->set_nicknames(nn, rn);
        return 1;
    }else {
        if (member_array(str, keys(nicknames)) == -1) {
            write("No such nickname: " + str);
            return 1;
        }
        write(sprintf("%-15s %s\n", str, nicknames[str]));
        return 1;
    }
    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

nickname - manage nicknames

%^CYAN%^SYNOPSIS%^RESET%^

nickname %^ORANGE%^%^ULINE%^NICKNAME%^RESET%^ %^ORANGE%^%^ULINE%^SUBSTITUTE%^RESET%^
nickname [reset|%^ORANGE%^%^ULINE%^NICKNAME%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

This command allows you to define nicknames for various things. When a %^ORANGE%^%^ULINE%^NICKNAME%^RESET%^ is defined each time you enter it into the mud it will be replaced with %^ORANGE%^%^ULINE%^SUBSTITUTE%^RESET%^. For example, if you used %^ORANGE%^<nickname bob alice>%^RESET%^ each time you do %^ORANGE%^<look bob>%^RESET%^ the game will interpret it as if you typed %^ORANGE%^<look alice>%^RESET%^. If you type %^ORANGE%^<kill bob>%^RESET%^ then the game will interpret it as if you typed %^ORANGE%^<kill alice>%^RESET%^.

To list currently defined nicks type %^ORANGE%^<nickname>%^RESET%^ without arguments.

To remove a nickname type %^ORANGE%^<unnickname %^ORANGE%^%^ULINE%^NICKNAME%^RESET%^%^ORANGE%^>%^RESET%^.

To remove all nicknames type %^ORANGE%^<nickname reset>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

alias, set, look, glance, score
");
}
