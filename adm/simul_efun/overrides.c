#include <security.h>
#include <objects.h>
#include <commands.h>
#include <std.h>
#include <new_exp_table.h>

/**
 * @file
 * @brief Overrides driver/vm efuns. These mostly have been added to
 *        log and check for permissions.
 */


object find_player(string str)
{
    string whom;
    object* liv, who;
    int i;
    if (!stringp(str)) {
        return 0;
    }
    who = efun::find_player(str);
    if (!who) {
        liv = users();
        for (i = 0; i < sizeof(liv); i++) {
            if (((string)liv[i]->query_position() == "avatar" || wizardp(liv[i])) && liv[i]->query_disguised()) {
                if ((string)liv[i]->query_vis_name() == str) {
                    who = liv[i];
                }
            }
        }
    }
    return who;
}

void destruct(object destructee)
{
    string destee, dester;

    destee = geteuid(destructee);
    dester = geteuid(previous_object());
    if (environment(PO) == destructee) {
        return efun::destruct(destructee);
    }

    if (!destee || dester == destee || dester == UID_ROOT ||
        dester == UID_DESTRUCT ||
        master()->query_member_group(dester, "superuser") ||
        master()->query_member_group(dester, "assist") ||
        master()->query_member_group(dester, "over") ||
        master()->query_member_group(dester, "area")) {
        efun::destruct(destructee);
    }else if (owner_euid(destee) == dester) {
        efun::destruct(destructee);
    }else if (destee == "Magic") {
        efun::destruct(destructee);
    }else {
        write_file("dest.log", capitalize(dester) + " is not allowed to destruct " +
                   capitalize(destee) + "\n");
    }
}

varargs void shutdown(int code)
{
    if (geteuid(previous_object()) != UID_ROOT &&
        geteuid(previous_object()) != UID_SHUTDOWN) {
        return;
    }
    log_file("shutdowns", "Game shutdown by " +
             (this_player() ? capitalize(geteuid(this_player())) : "Root") +
             " at " + ctime(time()) + "\n");
    seteuid(UID_SHUTDOWN);
    catch(call_other("/daemon/nameserver_d", "send_shutdown"));
    seteuid(getuid());
    efun::shutdown(code);
}

varargs object snoop(object snooper, object snoopee)
{
    if (!snoopee) {
        return efun::snoop(snooper);
    }
    if (!wizardp(snooper)) {
        return 0;
    }
    if ((string)snooper->query_position() == "Admin") {
        return efun::snoop(snooper, snoopee);
    }
    seteuid(UID_ROOT);
    log_file("adm/snoop", snooper->query_name() + " attempted snoop of " + snoopee->query_name() + "\n");
    seteuid(getuid(TO));
    if ((int)master()->query_member_group(geteuid(snooper), "superuser") ||
        (int)master()->query_member_group(geteuid(snooper), "assist") ||
        (int)master()->query_member_group(geteuid(snooper), "over")) {
        if ((((int)master()->query_member_group(geteuid(snoopee), "superuser") == 1) ||
             ((int)master()->query_member_group(geteuid(snoopee), "assist") == 1)) &&
            (string)snooper->query_position() == "overseer") {
            tell_object(snoopee, capitalize((string)snooper->query_name()) +
                        " attempted to snoop you with Developer privileges!\n");
            seteuid(UID_ROOT);
            write_file("/log/adm/developers", "**Developer snoop attempted by " + capitalize(TPQN) + " on " +
                       capitalize((string)snoopee->query_name()) + " at " + ctime(time()) + "!**\n");
            seteuid(getuid());
            tell_object(snooper, "Developers may not snoop admins! Nice try, though.");
            tell_object(snooper, wrap("WARNING! Remember that misuse of Developer snoop is " +
                                      "grounds for instant demotion!"));
            return 0;
        }

        seteuid(UID_ROOT);
        if ((string)snooper->query_position() == "overseer") {
            tell_object(snooper, "Developer snoop enabled on " +
                        capitalize((string)snoopee->query_name()) + ".");
            tell_object(snooper, wrap("WARNING! Remember that misuse of Developer snoop is " +
                                      "grounds for instant demotion!"));
        }
        write_file("/log/adm/developers", "Developer snoop enabled by " + capitalize(TPQN) + " on " +
                   capitalize((string)snoopee->query_name()) + " at " + ctime(time()) + "\n");
        seteuid(getuid());


        if ((int)master()->query_member_group(geteuid(snoopee), "superuser")) {
            tell_object(snoopee, capitalize((string)snooper->query_name()) + " is now snooping you.\n");
        }
        return efun::snoop(snooper, snoopee);
    }
    return 0;
}

int exec(object to_obj, object from_obj)
{
    string prev;
    prev = base_name(previous_object());
    if (prev == OB_LOGIN || geteuid(previous_object()) == UID_EXEC) {
        return efun::exec(to_obj, from_obj);
    }
}

object query_snoop(object snoopee)
{
    if (geteuid(previous_object()) != UID_SNOOP &&
        base_name(previous_object()) != OB_USER) {
        return 0;
    }
    return efun::query_snoop(snoopee);
}

object query_snooping(object ob)
{
    if (geteuid(previous_object()) != UID_ROOT) {
        return 0;
    }
    return efun::query_snooping(ob);
}

void write(string str)
{
    if (this_player()) {
        message("my_action", str, this_player());
    }else {
        efun::write(str);
    }
}

string query_ip_name(object ob)
{
    string whom;
    if (sscanf(geteuid(previous_object()), "%sobj", whom) > 0) {
        if (member_group(whom, "superuser")) {
            return efun::query_ip_name();
        }
        return "";
    }
    return efun::query_ip_name();
}

int living(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query("not living")) {
        return 0;
    }
    return efun::living(ob);
}

int exp_for_level(int x)
{
    int lev;
    if (!intp(x) || x < 1 || x > 100) {
        return -1;
    }
    lev = (x - 1);
    return (EXP_NEEDED[x] - EXP_NEEDED[lev]);
}

int total_exp_for_level(int x)
{
    if (!intp(x) || x < 0 || x > 100) {
        return -1;                              //beyond the table.
    }
    return EXP_NEEDED[x];
}

mixed first_letter(string str)
{
    if (!stringp(str) || !strlen(str)) {
        return str;
    }
    return explode(str, "")[0];
}

int is_real_user(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (base_name(ob) == OB_USER && !ob->query_quietness()) {
        return 1;
    }
    return 0;
}

/**
 * Returns list of players and non-quiet imms
 */
object* real_users()
{
    object* usrs = ({});
    usrs = filter_array(users(), "is_real_user", TO);
    return usrs;
}

/**
 * Hijacked because there is a function in contrib with the same name.
 */
string english_number(mixed x)
{
    string* split, * len;
    int size, ct, flag;
    if (!intp(x) && !floatp(x)) {
        return x + "";
    }
    if (strlen(x + "") <= 3) {
        return x + "";
    }
    if (x < 0) {
        x = absolute_value(x);
        flag = 1;
    }
    split = explode(x + "", ".");
    if (!sizeof(split)) {
        return x + "";
    }
    len = explode(split[0], "");
    size = sizeof(len);
    size--;
    ct = 0;
    while (size >= 0) {
        if (ct == 3) {
            len[size] = len[size] + ",";
            ct = 0;
        }
        ct++;
        size--;
        continue;
    }
    if (flag) {
        len[0] = "-" + len[0];
    }
    if (sizeof(split) > 1) {
        return implode(len, "") + "." + implode(split[1..(sizeof(split) - 1)], "");
    }
    return implode(len, "");
}

int wizardp(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    return efun::wizardp(ob);
}

int userp(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    return efun::userp(ob);
}
