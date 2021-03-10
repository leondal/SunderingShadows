#include <std.h>
#include <security.h>
#include <bank.h>
#include <dirs.h>

inherit DAEMON;

string admins;

int cmd_arrest(string str) {
    string who, reason;
    object ob;

    if(!archp(previous_object())) return 0;
    if(!str || sscanf(str, "%s %s", who, reason) != 2) {
	notify_fail("Syntax: <arrest [player] [reason]>\n");
	return 0;
    }
    str = lower_case(who);
    if(member_group(str, "superuser")) {
        notify_fail("Shyeah...NOT.\n");
        return 0;
    }
    ob = find_player(str);
    if(!ob && !user_exists(str)) {
	notify_fail("No such player: "+capitalize(str)+".\n");
	return 0;
    }
    if(ob) ob->remove();
    if(ob) {
        seteuid(UID_DESTRUCT);
        destruct(ob);
        seteuid(getuid());
    }
    seteuid(UID_USERSAVE);
    rename(DIR_USERS+"/"+str[0..0]+"/"+str+".o", DIR_USERS+"/arrest/"+str+".o");
    if(file_size(ACCOUNTS_DIR+str+".o") > -1) rm(ACCOUNTS_DIR+str+".o");
    write(capitalize(str)+" is arrested for "+mud_name()+".\n");
    seteuid(UID_LOG);
    log_file("arrest", (string)this_player()->query_name()+" arrested "+
	str+": "+ctime(time())+"\n");
    log_file("arrest", "      Reason: "+reason+"\n");
    seteuid(getuid());
    return 1;
}

void help() {
    message("help", "Syntax: <arrest [player] [reason]>\n\n"
      "Arrests a player causing trouble so that they cannot login until "
      "law has had a chance to review the case.  Only law may move a player "
      "back into the game or remove them permanently from the game.\n\n"
      "See also: rid", this_player()
    );
}
