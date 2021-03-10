/* Offshoot of avatarmail for handling law complaints *Styx*  7/2003
   "/cmds/mortal/_lawmail.c" inherits this file so the code could be put here for security purposes
*/

#include <std.h>
#define LOCATION "/adm/save/lawboardroom"

inherit DAEMON;

object getBoard()
{
    object ob;
    ob = present("Law_Mail board", find_object_or_load(LOCATION));
    if (!objectp(ob)) {
        LOCATION->reset();
    }
    return ob;
}

int cmd_lawmail(string str)
{
    object board;
    board = getBoard();
    if (!str) {
        return notify_fail(
            "Please specify a brief title for your message, preferably something "
            "like 'name's attack on me' or 'abuse of this or that'.  The correct "
            "syntax is <lawmail [title of message]>.  You will then get a "
            "screen to enter your message.\n"
            );
    }

    if (strlen(str) > 72) {
        return notify_fail("Please be more brief on the title, less than 72 characters.\n  You can elaborate in the editor.\n");
    }

    tell_object(TP, "You are now in edit to post a message to the "
                "immortals who handle law complaints.  Please supply all "
                "relevant facts and names of witnesses or logs if brief, "
                "but do not spam with an excess of information.  We will "
                "mail or catch you on to ask for more information if needed.  "
                "Please do not whine.\n"
                "The title is set to:  %^BOLD%^%^YELLOW%^" + str);
    board->post_message(str);
    return 1;
}

int help(){
    write(
"
%^CYAN%^NAME%^RESET%^

lawmail - complain about rule violations or disputes

%^CYAN%^SYNTAX%^RESET%^

lawmail %^ORANGE%^%^ULINE%^TITLE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This is a way to communicate to law group of the staff. You should do this when you see rule violations by players or staff members.

This method of communication is not for resolving pk disputes.

%^CYAN%^SEE ALSO%^RESET%^

pkmail, avatarmail, game
"
        );
}
