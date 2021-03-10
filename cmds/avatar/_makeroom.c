// Command to allow avatars to create rooms for plots and such.  
// They are restricted to creating rooms in /d/av_rooms/<their name>/

#include <std.h>

inherit DAEMON;

int help(string str)
{
	write("This is the room generator for avatars to create rooms for plot related play.  "
		"These rooms are meant to be temporary in nature and will not have a permenant "
		"entrance from the mud as a whole.  The rooms are set to 'no teleport' to prevent "
		"players from remembering locations there and abusing unaccesable rooms where the "
		"avatars are not online.  DO NOT leave players unattended in the rooms.  We are "
		"making every effort possible to be sure that people don't get stuck there and cause "
		"problems, but it's best to avoid the potential for the problems to begin with.  "
		"The individual menu prompts contain the help files that "
		"you should need to understand the command.  If there are any problems or suggestions "
		"send a mail to Ares.");
	return 1;
}

int cmd_makeroom(string str)
{
	object obj;
	obj=new("/cmds/avatar/avatar_room_generator");
	obj->move(TP);
	obj->begin(TP,obj);
	return 1;
}

