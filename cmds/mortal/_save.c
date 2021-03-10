//	/bin/user/_save.c
//	from the Nightmare mudlib
//	command to save the player
//	written by Descartes of Borg

#include <std.h>

inherit DAEMON;

int cmd_save(string str)
{
    string file;
    if (this_player()->query_disable()) {
        write("Wait a minute.");
        return 1;
    }
//    this_player()->set_disable();
    TP->setAdminBlock(1);
    if (objectp(ETP)) {
        if (clonep(ETP)) {
            file = "/daemon/virtual_room_d.c"->register_virtual_room(ETP, TP->query("my_virtual_room"), TP->query("my_virtual_base"));
            if (!TP->query("my_virtual_room") != file) {
                TP->delete("my_virtual_room");
                TP->delete("my_virtual_base");
                TP->set("my_virtual_room", file);
                TP->set("my_virtual_base", base_name(ETP));
            }
        }else {
            TP->set_primary_start(file_name(environment(this_player())));
        }
    }else {
        TP->set_primary_start("/d/darkwood/room/road18");
    }
    "/daemon/yuck_d"->save_inventory(this_player());
    this_player()->save_player((string)this_player()->query_name());

    write(capitalize(TPQN) + " is now saved.");
    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

save - save yourself

%^CYAN%^DESCRIPTION%^RESET%^

This command saves the present status of your character to disk. This is important as it is this file that will be used to set your character back up if the mud should crash. Your character is automatically saved if you %^ORANGE%^<quit>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

inventory, score
"
        );
}
