
#include <std.h>
#include <security.h>
#include <dirs.h>
#define BOAT_DIR "/d/save/boats/saakrune/"

inherit DAEMON;


int wizuserp(object ob) {
  if (objectp(ob) && wizardp(ob))
    return 1;
  else
    return 0;
}

void help()
{
    write(
"
%^CYAN%^NAME%^RESET%^

suicide - prevent further logins on the character

%^CYAN%^DESCRIPTION%^RESET%^

This command moves your character file into suicide directory. After a while, it will be deleted.

Restoration of deleted accounts is not possible without aid of an admin.

%^CYAN%^SEE ALSO%^RESET%^

kill, quit, account
"
        );
}

int cmd_suicide(string str)
{
    string name, * oldfiles;
    int j;

    if (str) {
        return help();
    }

    if (TP->query_ghost()) {
        tell_object(TP, "You cannot commit suicide being a ghost.");
        return 1;
    }
    if ((TP->query_property("last_death") < time() + 3600) &&
        TP->query_property("last_death")) {
        tell_object(TP, "You cannot commit suicide so soon after death. Reflect upon what went wrong and if you're sure, try again in an hour.");
        return 1;
    }
    if (TP && TP->query_forced()) {
        seteuid(UID_ROOT);
        write_file("log/ILLEGAL", "suicide " + ctime(time()) + " " + "Forcer: " + getuid(this_player(2)) + " " + TPQN + " (forced)\n");
        return notify_fail("Someone tried to force you to suicide!\n");
    }
    if (wizardp(TP)) {
        message("my_action", "Wizards can not do this.", TP);
        return 1;
    }
    if (avatarp(TP) && !TP->query("is_valid_npc")) {
        tell_object(TP, "You cannot commit suicide with an avatar.");
        return 1;
    }
    if (!TP || !userp(TP) || TP != this_player(1) || TP != previous_object()) {
        write_file("/log/ILLEGAL", "suicide " + ctime(time()) + " " + geteuid(previous_object()) + "\n");
        return notify_fail("I dont think so!\n");
    }
    name = TPQN;
    if (name == "guest") {
        return notify_fail("You cannot suicide Guest.\n");
    }
    if (TP->query("no suicide")) {
        return notify_fail("You are not allowed to suicide.\n");
    }
    message("info", "%^BOLD%^%^WHITE%^This action will disconnect your character from your account, and you will no longer able to log into it. After a while, it might even get deleted. You won't be able to restore your charecter without staff help, that's for sure.", TP);
    message("info", "%^BOLD%^%^RED%^If you are sure you want to do this, then enter your password now.", TP);
    input_to("really_suicide", 1);
    return 1;
}

nomask private int really_suicide(string typed_password)
{
    string real_password, name;
    string* oldfiles, * files;
    int j, x;

    if (!typed_password) {
        message("info", "Suicide cancelled.", TP);
        return 0;
    }
    real_password = TP->query_password();
    if (real_password != crypt(typed_password, real_password)) {
        message("info", "Incorrect Password.  Suicide canceled.\n",
                TP);
        return 0;
    }
    name = TP->query_true_name();
    TP->save_player(name);
    log_file("player/suicide", name + " (level " + TP->query_level() + ") at " + ctime(time()) + " " + " from " + TP->query_ip() + " \n");
    seteuid(UID_USERSAVE);
    if (file_exists(DIR_USERS + "/" + name[0..0] + "/" + name + ".o")) {
        rename(DIR_USERS + "/" + name[0..0] + "/" + name + ".o", DIR_USERS + "/suicide/" + name + ".o");
    }
    if (file_exists(DIR_ACCOUNTS + "/" + name + ".o")) {
        rename(DIR_ACCOUNTS + "/" + name + ".o", DIR_USERS + "/suicide/" + name + ".account.o");
    }
    if (file_size(DIR_POSTAL + "/" + name[0..0] + "/" + name + ".o") > -1) {
        rm(DIR_POSTAL + "/" + name[0..0] + "/" + name + ".o");
    }
    if (file_exists(BOAT_DIR + name + "boat.c")) {
        rm(BOAT_DIR + name + "boat.c");
    }
    oldfiles = get_dir("/inv/" + name + "/");
    for (x = 0; x < sizeof(oldfiles); x++) {
        j = rm("/inv/" + name + "/" + oldfiles[x]);
    }
    rmdir("/inv/" + name);
    if (TP->is_class("mage") || TP->is_class("bard")) {
        files = TP->wild_card("/d/magic/spellbook/backup_books/" + name + "_*.backup.o");
        for (x = 0; x < sizeof(files); x++) {
            if (file_exists(files[x])) {
                rm(files[x]);
            }
        }
        files = TP->wild_card("/d/magic/spellbook/save_books/" + name + "_*.backup.o");
        for (x = 0; x < sizeof(files); x++) {
            if (file_exists(files[x])) {
                rm(files[x]);
            }
        }
        if (file_exists("/d/magic/spellbook/" + name + ".comp.o")) {
            rm("/d/magic/spellbook/" + name + ".comp.o");
        }
    }
    if (TP->query("advance place")) {
        "daemon/room_d"->remove_room(TP->query("advance place"));
    }
    message("my_action", "You leave this reality, and the bunnies, piglets and unicorns lead you off to the happy little afterlife for lost characters.", TP);
    message("other_action", TPQCN + " just committed suicide!!!", environment(TP), ({ TP }));
    TP->move("/d/shadowgate/void");
    rm("/d/save/background/" + TP->query_true_name());
    rm("/d/save/background/" + TP->query_true_name() + ".htm");
    "/daemon/save_d"->remove_name(name);
    "/daemon/guilds_d.c"->delete_player(name);
    if (TP->query_base_character_level() > 15) {
        "/daemon/multi_d"->add_name(name, 2);
    }
    message("notify", "%^YELLOW%^<< " + TP->query_name() + " has committed suicide! >>\n", filter_array(users(), "wizuserp", TO));
    "/cmds/avatar/_note.c"->cmd_note("ckpt " + TP->query_name() + " committed suicide!\n");
    TP->remove();
    return 1;
}
