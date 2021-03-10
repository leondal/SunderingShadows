/*
// This is part of the TMI distribution mudlib.
// Please retain this header if you use this file.
// Written by Sulam (12-9-91)
// Help added by Brian (1/28/92)
*/

#include <std.h>
#include <objects.h>
#include <dirs.h>
#include <daemons.h>
#include <security.h>
#include <config.h>
#include <pwgen.h>

/**
 * @file
 */

inherit OB_USER;

int cmd_passwd(string str)
{

    if (TP->query_forced()) {
        log_file("player/passwd", "passwd: (forced): "+ctime(time())+" "+this_player()->query_name()+"\n");
        notify_fail("You must act of your own free will.\n");
        return 1;
    }

    adm_pass();

    return 1;
}

adm_pass()
{
    write("Changing password for " + TP->query_name());

    write("Current password:");
    input_to("adm_confirm_pass", 1);
}

adm_confirm_pass(string str)
{

    if (TP->query_password() != crypt(str, TP->query_password())) {
        write("Permission denied.");
        return 1;
    }

    write("New password:");
    input_to("adm_pw_entry", 1);
}

adm_pw_entry(string str)
{
    if(!str)
    {
        write("Empty password");
        TO->remove();
        return;
    }

    write("Retype new password:");
    input_to("adm_pw_verify", 1, str);
}

adm_pw_verify(string str, passwd)
{

    string salt, pass;

    if (str != passwd) {
        write("Sorry, passwords do not match.");
        return;
    }

    salt = PWGEN->random_salt(43);
    pass = crypt(passwd, "$6$" + salt);

    TP->set_password(pass);

    return;
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

passwd - change yor password

%^CYAN%^DESCRIPTION%^RESET%^

The command allows you to change your password. Do this at least once a year.

%^CYAN%^SEE ALSO%^RESET%^

setenv, chfn, who

"
        );
}
/* EOF */
