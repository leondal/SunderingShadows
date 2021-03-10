#include <std.h>
#include "monsters.h"
//inherit "/realms/obsidian/closed/vault.c";
inherit VAULT ;

int alphabetical_sort(string alpha,string beta)
{  return strcmp(alpha,beta); }
void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_property("no teleport",1);
	set_short("The spawning room");
	set_long(
	"This room is essentially just a large gray void. From the center of the"+
	" void avatars can call forth certain monsters to do their bidding. There"+
        " is a list floating in mid air of what monsters can currently be called"+
        " forth <read list>. You can <request [monstername]> a monster "+
        "from the list, but please do not"+
	" leave them here, destroy the ones you do not use. You may also <clear>"+
	" the room if there are too many monsters here."
	);
	set_smell("default","The room has a sulfuric smell to it.");
	set_listen("default","The void swirls soundlessly around you.");
	set_items(([
	"list" : "Read the list to see what monsters you can request.",
	]));
	set_exits(([
        "arena" : "/realms/obsidian/rooms/arena1",
//        "locked" : "/realms/obsidian/rooms/lock",
        "adventure" : "/d/shadow/room/city/adventure",
	"northeast" : "/d/dagger/avalounge",
	]));
        set_door("door","/d/dagger/avalounge","northeast",0);
        set_open("door",0);
        set_string("door","knock","kick");
        set_door("grate","/realms/obsidian/rooms/arena1","arena",0);
        set_open("grate",0);
        set_string("grate","open","You lift the grate.");
        set_string("grate","knock","bang");
      //  set_door("black portal","/d/shadow/room/city/adventure","adventure",0);
      //  set_open("black portal",0); this room not there anymore
      //  set_string("black portal","open","You tap open the mysterious portal.");
        //set_invis_door("black portal",1);
}

void init()
{
	::init();
	add_action("read","read");
	add_action("request","request");
	add_action("clear","clear");
}

void read(string str)
{
	int i;
	string *tmp = ({});
     if(str != "list")   return 0;
	tmp = keys(MONSTERS);
     tmp=sort_array(tmp,"alphabetical_sort",TO)
;

	for(i=0;i<sizeof(tmp);i++) {
		write(tmp[i]);
	}
	return 1;
}

void request(string str)
{
        object mon;
	if(member_array(str, keys(MONSTERS)) == -1) {
		write("That monster isn't on the list.");
		return 1;
	} 
        new(mon = MONSTERS[str])->move(TO);
        write(mon->query_short()+" appears.");
	return 1;
}

void clear(string str)
{
	int n, j;
	object *inven;

	inven = all_living(TO);
	j = sizeof(inven);

	for(n=0;n<j;n++) {
		if(!objectp(inven[n])) continue;
		if(avatarp(inven[n])) continue;
		inven[n]->die();
	}
	return 1;
}
