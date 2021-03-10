/*    /cmds/mortal/_version.c
 *    from Nightmare Mudlib 3.2
 *    gives version info about the mud and up time
 *    written by Descartes of Borg 940130
 *    Changed by Melnmarn@Shadowgate
 */

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_version(string str) {
    int x;
    string tz,tmp;

    tz = sprintf("%s", ctime(time()-uptime()));
	
  	tmp = sprintf("%%^YELLOW%%^%40s\n",mud_name());
	tmp += "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
	tmp += "%^BOLD%^%^CYAN%^Driver %^BLACK%^---- %^RESET%^%^GREEN%^"+version();
	tmp += "\n%^BOLD%^%^CYAN%^Mudlib %^BLACK%^---- %^RESET%^%^GREEN%^"+mudlib();
	tmp += "\n%^BOLD%^%^CYAN%^Version %^BLACK%^--- %^RESET%^%^GREEN%^"+mudlib_version();
	tmp += "\n%^BOLD%^%^CYAN%^Up Since %^BLACK%^-- %^RESET%^%^GREEN%^"+tz;
	tmp += "\n%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
	write(tmp);
    return 1;
}

void help() {
    write(
        "
%^CYAN%^NAME%^RESET%^

version - display mud version

%^CYAN%^SEE ALSO%^RESET%^

uptime, who, finger, chfn, setenv

");
}
