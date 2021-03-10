// Work began on this file by Darkone on 2/20/93
#include <std.h>
inherit DAEMON;

int cmd_dirupdate(string str)
{
    string file, tmp, * dir;
    object ob;
    int i;

    if (!str) {
        file = resolv_path((string)this_player()->get_path(), str);
    } else {
        file = str;
    }


    if (file_size(file) != -2) {
        write(file + " is not a directory.\n");
        return 1;
    }

    if (!regexp(file, "^(/d/|/realms/|/cmds/)")) {
        write("dirupdate win't work outside of /d/, /cmds/ and /realms/ because of reasons.");
        return 1;
    }

    dir = get_dir(file + "/*.c");
    for (i = 0; i < sizeof(dir); i++) {
        if (!catch(ob = find_object_or_load(file + "/" + dir[i]))) {
            write("Updating..." + file + "/" + dir[i]);
            catch(ob->remove());
        }else {
            write("Failed to update " + file + "/" + dir[i]);
        }
    }
    write("Update done.\n");
    return 1;
}

int help()
{
    write(
"Syntax: dirupdate < directory >
Effect: updates all objects in < directory >
See also: update, dir
"
          );
    return 1;
}
