//statues_d.c

#include <std.h>
#include <security.h>
#define SAVE_FILE "/daemon/save/statues"
inherit DAEMON;

mapping statues;

void SAVE();

void create(){
	::create();
	statues = ([]);
	seteuid(UID_DAEMONSAVE);
	restore_object(SAVE_FILE);
	seteuid(getuid());
	}

void add_statue(object room, string name){
	string file;
	
	file = base_name(room);
	if(!statues) statues = ([]);
	if(!statues[file]) statues[file] = ({});
	statues[file] += ({name});
	SAVE();
}

string *query_statues(object room){
	string file;
	
	file = base_name(room);
	if(!statues) statues = ([]);
	if(!statues[file]) statues[file] = ({});
	return statues[file];
}

void SAVE(){
	seteuid(UID_DAEMONSAVE);
	save_object(SAVE_FILE);
	seteuid(getuid());
	}
