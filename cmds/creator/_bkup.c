//      bkup (remove file and go into edit w/ same file name)
//      Thorn@Shadowgate
//      2/8/95
//      Creator commands
//      _bkup.c

#include <std.h>

inherit DAEMON;


int cmd_bkup(string str) {
        string temp;
        seteuid(getuid(previous_object()));
        if(!wizardp(previous_object())) return 0;
        if(!str) {
                notify_fail("bkup: What file?\n");
                return 0;
        }
        temp = read_file(str);
        write_file(str+".bk", temp);
        write("Backed up: "+str);
}

void help() {
    write("Syntax: bkup <filename>\n\n"+
        "This command makes a file backup.\n");
}
