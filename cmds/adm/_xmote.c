/*    /cmds/adm/_xmote.c
 *    from the Nightmare Mudlib 3.2
 *    a promote/demote style command for use with the Nightmare system
 *    created by Descartes of Borg 940124
 */

#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_xmote(string str)
{
    string pos, nom;
    object ob;
    int lev, ulvl;

    if (!archp(previous_object())) {
        return 0;
    }
    if (!str) {
        return notify_fail("Usage: <xmote [player] ([level]) ([position])>\n");
    }
    if (sscanf(str, "%s %s", nom, str) != 2) {
        return notify_fail("Usage: <xmote [player] ([level]) ([position])>\n");
    }
    if (!(ob = find_player(nom = lower_case(nom)))) {
        return notify_fail(sprintf("Cannot find %s anywhere.\n", capitalize(nom)));
    }
    if (sscanf(str, "%d %s", lev, pos) != 2) {
        if (!sscanf(str, "%d", lev)) {
            seteuid(UID_LOG);
            log_file("xmote", sprintf("%s went to position %s thanks to "
                                      "%s on %s.\n", nom, str, (string)previous_object()->query_name(),
                                      ctime(time())));

            seteuid(UID_ADVANCE);
            ob->set_position(str);
            ob->save_player();
            seteuid(getuid());
            message("info", sprintf("%s is now position %s", capitalize(nom),
                                    str), this_player());
            message("info", sprintf("You have been xmoted to %s", str), ob);
            return 1;
        }
        if (!archp(TP)) {
            seteuid(UID_LOG);
            log_file("xmote", sprintf("%s attempted to raise %s to level %d  %s.\n",
                                      (string)this_player()->query_name(), nom, lev, ctime(time())));
            return 0;
        }
        if (((string)this_player()->query_position() != "Admin" && (ob->query_level() > lev))) {
            return 0;
        }
        seteuid(UID_LOG);
        log_file("xmote", sprintf("%s went to level %d thanks to %s on %s.\n",
                                  nom, lev, (string)previous_object()->query_name(), ctime(time())));
        seteuid(getuid());
        ob->set_level(lev);
        message("info", sprintf("%s is now level %d.", capitalize(nom), lev),
                this_player());
        message("info", sprintf("You have been xmoted to level %d.\n", lev), ob);
        return 1;
    }
    if (!archp(TP)) {
        seteuid(UID_LOG);
        log_file("xmote", sprintf("%s attempted to raise %s to level %d and position %s  %s.\n",
                                  (string)previous_object()->query_name(), nom, lev, pos, ctime(time())));
        return 0;
    }
    if (((string)this_player()->query_position() != "Admin" && (ob->query_level() >
                                                                lev))) {
        return 0;
    }
    seteuid(UID_LOG);
    log_file("xmote", sprintf("%s went to position %s and level %d thanks to "
                              "%s on %s.\n", nom, pos, lev, (string)previous_object()->query_name(),
                              ctime(time())));
    seteuid(getuid());
    seteuid(UID_ADVANCE);
    ob->set_position(pos);
    seteuid(getuid());
    ob->set_level(lev);
    message("info", sprintf("%s is now level %d and position %s.\n",
                            capitalize(nom), lev, pos), this_player());
    message("info", sprintf("You are now level %d %s.\n", lev, pos), ob);
    return 1;
}

void help()
{
    message("help", "Syntax: <xmote [player] ([level]) ([position])>\n\n"
            "Changes the level, position, or both of a player.", this_player());
}
