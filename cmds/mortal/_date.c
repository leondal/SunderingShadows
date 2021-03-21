//	/bin/user/_date.c
//	from the Nightmare mudlib
//	gives the time for any time zone
//	created by Descartes of Borg 14 december 1992

#include <daemons.h>
#include <std.h>

inherit DAEMON;

int cmd_date(string str)
{
    int borg;

    if (!str) {
        str = (string)this_player()->getenv("TZONE");
    }
    borg = (int)TIME_D->query_tzone(str);
    write("%^BOLD%^%^RED%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    if (!str) {
        write("%^BOLD%^%^CYAN%^Current mud time: %^YELLOW%^" + ctime(borg));
    }else {
        write("%^BOLD%^%^CYAN%^Current time " + str + ": %^YELLOW%^" + ctime(borg));
    }
    write("%^BOLD%^%^BLUE%^Current Sundering Shadows time: %^GREEN%^" + hour(time()) + ":" + (minutes(time()) > 9?minutes(time()):"0" + minutes(time())) + " " + day(time()) + ", " + date(time()) + " " + month(time()) + ", " + year(time()) + " SG");
    write("%^BOLD%^%^RED%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

date - show current date

%^CYAN%^DESCRIPTION%^RESET%^

This command gives you the time both on-server and in-mud.

Alternatively, you can just %^ORANGE%^<look sky>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

help, set, weather, look

"

        );
/* write( */
/* @ZONES */
/* Available time zones are: */
/*    PST   Pacific Standard Time    +0 */
/*    MST   Mountain Standard Time   +1 */
/*    CST   Central Standard Time    +2 */
/*    EST   Eastern Standard Time    +3 */
/*    AST   Atlantic Standard Time   +4 */
/*    BST   British Summer Time      +7 */
/*    GMT   Greenwich Mean Time      +8 */
/*    CET   Central European Time    +9 */
/*    MT    Moscow Time              +11 */
/*    AWT   Australian Western Time  +15 */
/*    AET   Australian Eastern Time  +17 */
/*    NZT   New Zealand Standard Time +18 */
/* ZONES */
/* ); */
}
