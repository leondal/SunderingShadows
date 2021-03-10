#include <std.h>

/*
 *  Author and date unknown ??
 *  help() added 1/27/92   Brian@TMI
 */
inherit DAEMON;
string temp;

int
cmd_cd(string str) {
    if(!str) {
	str = user_path(geteuid(this_player()));
        str = str[0..strlen(str)-2];
	if (!str) str = "/doc";
        seteuid(geteuid(previous_object()));
	this_player()->set_path(str);
        seteuid(getuid());
	write( (string)this_player()->get_path() + ":");
	return 1;
    }
    str = resolv_path((string)this_player()->get_path(), str);
/*
    For some stupid reason this is not doing its job -Shadowwolf
    substr("//", "/", str);
NOTE: The substr simul_efun has been replaced by the replace_string efun
*/
if (sscanf(str,"//%s",temp) == 1) str = "/"+temp;
    if(!((int)master()->valid_read(str, previous_object()))) {
	notify_fail(str+": permission denied\n");
	return 0;
    }
    seteuid(geteuid(previous_object()));
    if(file_size(str) > -1) {
        write(str+": not a directory");
        seteuid(getuid());
        return 1;
    }
    if(file_size(str) == -1) {
        write(str+": no such file or directory");
        seteuid(getuid());
        return 1;
    }
    this_player()->set_path(str);
    seteuid(getuid());
    write( (string)this_player()->get_path() + ":");
    return 1;
}

int
help() {
  write("Command: cd\nSyntax: cd <directory>"
        "This command changes your current directory to the"
        " one you specify.  If directory begins with a / then"
        " the command will look from the root, otherwise it"
        " will look in the child directories of your current"
        "directory.  .. will back up to the parent of your "
        "current directory.  Thus cd ../obj will attempt to "
        "move to the directory obj which is a child of your "
        "current parent directory."
        "cd with no arguments will move you to your home dir-\n"+
        "ectory if you are a student, or the /doc directory if\n"+
        "not.\n");
  return 1;
}
