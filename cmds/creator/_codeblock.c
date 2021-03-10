//      codeblock.c
//      created by Descartes of Borg 31 October 1992


#include <std.h>

inherit DAEMON;

#define CHANNELS "bin/daemon/channels"

int cmd_codeblock() {
    this_player()->set_blocked("all");
    if(this_player()->query_blocked("all")) write("Codeblock on.\n");
    else write("Codeblock off.\n");
    return 1;
}

void help() {
    write("Syntax: <codeblock>\n\n"+
        "Toggles between blocking and not blocking all remote communications.\n");
}
