//      /bin/dev/_log.c
//      from the Nightmare Mudlib
//      tails a given log
//      created by Brian@TMI 920128

#include <std.h>
#include <dirs.h>

inherit DAEMON;

int cmd_logtail(string str) {
    if(!str) {
        notify_fail("Correct syntax: <logtail FILE>\n");
        return 0;
    }
    write(str+":\n");
    if(!tail("/log/"+str)) write("No such log file: "+str+"\n");
    return 1;
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

logtail - play last lines of logs

%^CYAN%^SYNTAX%^RESET%^

logtail %^ORANGE%^%^ULINE%^FILE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

plays any log by file name, displays only last lines

%^CYAN%^SEE ALSO%^RESET%^

avlog, plog, logmore
");
}
