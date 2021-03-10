#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_dsync(string str)
{
    string src,
        dest;
    if (!str) {
        HELP_D->help("dsync");
        return 1;
    }
    if (!sscanf(str, "%s %s", src, dest)) {
        HELP_D->help("dsync");
        return 1;
    }
    if (!stat(src)) {
        write("Unable to find " + src);
        return 1;
    }
    if (this_player()->query_forced()) {
        write("Someone has tried forcing you to dsync " + str);
        return 1;
    }
    src = resolv_path(TP->get_path(), src);
    dest = resolv_path(TP->get_path(), dest);
    seteuid(geteuid(previous_object()));
    sync_dir(src, dest);
    return 1;
}

int copy_file(string src, string dest)
{
    if (!master()->valid_read(src, TP, "cp")) {
        notify_fail(src + ": Permission denied.\n");
        return 0;
    }
    if (!master()->valid_write(dest, TP, "cp")) {
        notify_fail(dest + ": Permission denied.\n");
        return 0;
    }
    if (!cp(src, dest)) {
        write("%^RED%^failed to copy: %^GREEN%^" + src + "%^RESET%^");
        return 0;
    } else {
        write("%^GREEN%^'" + src + "'%^RESET%^ -> %^GREEN%^'" + dest + "'%^RESET%^");
        return 1;;
    }
}

int sync_file(mixed fstat, string src, string dest)
{
    mixed fss, fds;

    if (fstat[1] == -2) { //directory
        sync_dir(src + "/" + fstat[0], dest + "/" + fstat[0]);
        return 1;
    }
    if (sizeof(fds = stat(dest + "/" + fstat[0], -1))) {
        if (fds[1] < fstat[2]) {
            copy_file(src + "/" + fstat[0], dest + "/" + fstat[0]);
            return 1;
        }
    } else {
        copy_file(src + "/" + fstat[0], dest + "/" + fstat[0]);
        return 1;
    }
    return 0;
}

int sync_dir(string src, string dest)
{
    string tmp;

    if (!stat(dest + "/")) {
        if (!mkdir(dest)) {
            write("%^RED%^unable to create: %^BLUE%^" + dest + "%^RESET%^");
            return 0;
        }
        sync_dir(src, dest);
    } else {
        write("%^BLUE%^'" + src + "'%^RESET%^ -> %^BLUE%^'" + dest + "'%^RESET%^");
        map_array(get_dir(src + "/", -1), (: sync_file($1, $2, $3) :), src, dest);
    }
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

dsync - synchronize directories

%^CYAN%^SYNTAX%^RESET%^

dsync %^ORANGE%^%^ULINE%^SOURCE%^RESET%^ %^ORANGE%^%^ULINE%^DESTINATION%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command synchronizes two directories, checking timestamp of file creation of each file withing and copying over files if in %^ORANGE%^%^ULINE%^SOURCE%^RESET%^ they are newer than in %^ORANGE%^%^ULINE%^DESTINATION%^RESET%^. The command preserves files in destination directory. If destination directory does not exist it will be created.

Note that new files will be created with current timestamp. Which means, if you sync directory in reversed direction you will overwrite all files.

Warning: Copying large number of files is dangerous because of collisions, limit use of this command to your areas only and don't forget to sync from area youre editing prior to editing, in case someone changes a file there.

The command will continue upon failing to copy a file or create a directory.

%^CYAN%^EXAMPLES%^RESET%^

%^ORANGE%^<dsync /d/shadow /realms/bob/myshadow>%^RESET%^

    Will create /realms/bob/myshadow if it does not exist and copy contents of /d/shadow there.

%^CYAN%^SEE ALSO%^RESET%^

cp, rm, rmdir, diff
");
}
