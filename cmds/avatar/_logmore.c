//      /bin/dev/_log.c
//      from the Nightmare Mudlib
//      tails a given log
//      created by Brian@TMI 920128

#include <std.h>
#include <dirs.h>

inherit DAEMON;

int cmd_logmore(string str) {
    if(!str) {
        notify_fail("Correct syntax: <logmore FILE>\n");
        return 0;
    }
    write(str+":\n");
    TP->more("/log/"+str);
    return 1;
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

logmore - play logs

%^CYAN%^SYNTAX%^RESET%^

logmore %^ORANGE%^%^ULINE%^FILE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

plays any log by file name

%^CYAN%^SEE ALSO%^RESET%^

avlog, plog, logtail
");
}
