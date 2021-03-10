//quest_rooms.c
//rooms to be cloned for quests that are play specific.

#include <std.h>

inherit ROOM;

string player;

void create(){
	::create();
}

int clean_up(){return 1;}

set_player(string str){ player = str;}

string query_player(){return player;}
