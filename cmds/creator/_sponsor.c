//	/bin/dev/_sponsor.c
//	from the Nightmare mudlib
//	a command to allow mentors to sponsor new wizards
//	created by Descartes of Borg 31 january 1993

#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_sponsor(string str) {
    string file;
    string *lines;
    int i;
    object who;

    if(!str) {
	notify_fail("Sponsor whom?\n");
	return 0;
    }
    who = find_living(str);
    if(!who) {
	notify_fail("No "+capitalize(str)+" on the mud.\n");
	return 0;
    }
    if((string)who->query_position() != "new immortal") {
	notify_fail(capitalize(str)+" is still a mortal!\n");
	return 0;
    }
    if(!archp(this_player()) && (string)this_player()->query_position() != "mentor") {
	notify_fail("You are not allowed to sponsor anyone!\n");
	return 0;
    }
    who->set_level(1);
    seteuid(UID_ADVANCE);
    who->set_position("immortal");
    seteuid(UID_ARCHSAVE);
    write_file("/adm/etc/sponsor", str+" ("+(string)this_player()->query_name()+
	":"+ctime(time())+")\n");
    seteuid(getuid());
    message("info", sprintf("You are now a full immortal!\nYour home "
      "directory is %s.", user_path(str)), who);
    message("info", sprintf("%s is now a full immortal!", capitalize(str)),
      users(), ({ who }));
    seteuid(UID_CRESAVE);
    mkdir("/realms/"+lower_case(str));
    write_file(user_path(str)+"workroom.c", read_file("/std/obj/workroom.c"));
    seteuid(getuid());
    return 1;
}

void help() {
    write("Syntax: <sponsor [player]>\n\n"+
	"Mentors and above may use this command to sponsor new immortals\n"+
	"from level 20 immortality to level 21, and it makes the directory\n"+
	"as well.\n");
}
