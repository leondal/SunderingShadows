#include <std.h>
#include <daemons.h>
#include "./alliance.h"

inherit DAEMON;

int reaction_time;  // Reaction time for arriving guards
int deployed;

string *get_hall_rooms();

int alarm(string str) {
	string *files;
	string fpath;
	object room;
	int i;
	
	files = get_hall_rooms();
	for(i=0;i<sizeof(files);i++) {
		room = find_object_or_load(RDIR+files[i]);
		tell_room(room, str);
	}
	return 1;	
}

string *get_hall_rooms() {
	return get_dir(RDIR+"*.c");
}

int call_guards(object caller, object location) {
	int rtime;
	
        if(!caller->in_guild("Alliance Reborn") && !wizardp(caller)) return 0;
	rtime = reaction_time + random(2)+1;
	call_out("incoming", rtime, location);
	reaction_time += random(2)+1;
	return 1;
}

int incoming(object location) {
	tell_room(location, "%^BOLD%^You hear the sounds of clanking metal approaching rapidly!");
	call_out("arrive", random(5), location);
	return 1;
}

int arrive(object location) {
	int number;
	object *platoon, guard;
	tell_room(location, "%^BOLD%^Guards rush into the area, weapons at ready!");
	number = random(3)+2;
	while(number) {
		guard = new(MDIR+"guard");
		guard->move(location);
		number--;
	}
	return 1;
}
