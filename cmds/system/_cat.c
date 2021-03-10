/*    /cmds/system/_cat.c
 *    from Nightmare Mudlib 3.2
 *    command to display file contents
 *    created by Descartes of Borg 940124
 */

#include <std.h>

inherit DAEMON;

int cmd_cat(string str) {
    string tmp;

    if(!str) return notify_fail("Usage: <cat [file]>\n");
    str = resolv_path((string)this_player()->get_path(), str);
    seteuid(geteuid(previous_object()));
    if(!(tmp = read_file(str))) return notify_fail("File not found.\n");
    seteuid(getuid());
    message("system", tmp, this_player());    
    return 1;
}

int help() {
    message("help", "Syntax: <cat [file]>\n\n"
      "Displays the contents of the file mentioned all ate once.",
      this_player());
}
