//      /cmds/law/_trash.c
//      from the Nightmare Mudlib
//      from Descartes of Borg 02 august 1993
// 	revised by Pator@ShadowGate
#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_trash(string str) {
    string *files;
    string tmp, str1, str2;
    object ob;
    int i;

    if(!member_group(geteuid(this_player()), "law_c")) return 0;
    if(!str) {
        notify_fail("Correct syntax: <trash [file]>\n");
        return 0;
    }
    if((ob=previous_object())->query_forced()) {
        write("Someone attempted to force you to trash "+str+".");
        return 1;
    }
    seteuid(UID_ROOT);
    tmp = resolv_path((string)ob->get_path(), str);
      files = ({ tmp });
    if(!(i=sizeof(files))) {
        message("system", "File "+tmp+" does not exist.", this_player());
        return 1;
    }
    while(i--) {
        switch(file_size(files[i])) {
            case -1: message("system", "File "+files[i]+" does not exist.",
			     this_player()); break;
            case -2: message("system", files[i]+" is a directory.", 
			     this_player()); break;
            default: 
		if ( sscanf(files[i], "/realms/%s/%s", str1, str2) != 2 )
			{ return 0; }
		     tmp = "/rummage/cleanup/"+str2+time();
		     write_file(tmp , read_file(files[i]));
		     seteuid(UID_ROOT);
	message("system", rm(files[i]) ? files[i]+": Ok." :
			     files[i]+": Permission denied.", this_player());
      write_file("/log/adm/trash",getuid(TP)+" trashed "+tmp+
                 " at "+ctime(time())+"\n");
	seteuid(getuid());
	      break;
        }
    }
    return 1;
}

void help() {
    message("help", "Syntax: <trash [file]>\n\n"
	    "The command deletes the file named.  Once deleted, the file "
	    "cannot be recovered.", this_player());
}
