#include <std.h>
#include <objects.h>
#include <dirs.h>
#include <daemons.h>
#include <security.h>
#include <config.h>

inherit OB_USER;

#define LETTERS "-.0123456789abcdefghijklmnopqrstuvwxyz"

void create()
{
    seteuid(getuid());
}

int cmd_passchange(string str)
{
    object ob;
    string who, pos, name;
    int lev;
    if (!member_group(TPQN, "superuser")) {
        return 0;
    }
    if (!str) {
        help();
        return 1;
    }
    name = str;
    pos = "/adm/daemon/pwgen"->random_string(14, LETTERS);
    who = sprintf("%s/%s/%s", "/adm/save/users", name[0..0], name);
    ob = find_player(name);
    restore_object(who);
    if (ob) {
        write("The player must be offline, log them out first.");
    } else {
        write(sprintf("You have changed %s's password to %s", name, pos));
        seteuid(UID_ROOT);
        set_password(crypt(pos, 0));
        seteuid(getuid());
        seteuid(UID_USERSAVE);
        save_object(who);
    }
    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

passchange - change passwords

%^CYAN%^SYNTAX%^RESET%^

passchange %^ORANGE%^%^ULINE%^NAME%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command changes password of a %^ORANGE%^%^ULINE%^NAME%^RESET%^ to random one.

%^CYAN%^SEE ALSO%^RESET%^

passwd, who
"
        );
}
