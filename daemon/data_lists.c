// Stores lists that may be useful in campaign situations, such as
// player lists and etc.
// Thorn@ShadowGate
// 14 September 2000
// /daemon/data_lists.c

#include <std.h>
#include <security.h>

// DEBUG mode enabled on 1, 0 is off.  Make sure and set DEBUGGER
// to yourself if you are testing this.
#define DEBUG 1

#define SAVE_FILE "/daemon/save/data"

inherit DAEMON;

void SAVE();
void LOG(string msg);
int new_list(string id);

mapping data;

void create() {
    ::create();

  data = ([]);
  seteuid(UID_DAEMONSAVE);
  restore_object(SAVE_FILE);
  seteuid(getuid());
}

void SAVE() {
  seteuid(UID_DAEMONSAVE);
  save_object(SAVE_FILE);
  seteuid(getuid());
}

void LOG(string msg) {
  seteuid(UID_LOG);
  seteuid(getuid());
}

string *query_lists() {
	return keys(data);
}

mixed *query_list(string id) {
	return data[id];
}

int add_list(string id, mixed arg) {
	if(!data[id]) {
		if(!new_list(id)) return notify_fail("New list failed");
	}
	data[id] = data[id] + ({ arg });
	SAVE();
}

void set_list(string id, mixed *arg) {
	data[id] = arg;
	SAVE();
}

void delete_list(string id) {
	if(DEBUG) LOG("List "+id+" deleted.");
	map_delete(data, id);
	SAVE();
}

int new_list(string id) {
	if(!data) data = ([ ]);
	if(member_array(id, keys(data)) > -1) return 0;
	data[id] = ({ });
	if(DEBUG) LOG("List "+id+" created.");
	SAVE();
	return 1;
}
