#include "/d/player.village/pvillage.h"

#define FILENAME "/d/player.village/data/nroad1"

inherit VAULT ;

int num_homes,increment;
string *longdesc,long_desc;
mapping door_status;
mapping door_locked;

void restoreit();
void saveit();
void add_long(string str);
void adjust_doors();
void remove_doornames(string str);
mixed *each(mapping map);

void create(){
  ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_long(" ");
    longdesc = allocate(11);
    door_status = (([]));
    door_locked = (([]));
    long_desc = " ";
    num_homes = 0;
}
void init(){
	if(longdesc[0] == 0){
            restoreit();
	    if(longdesc[0] == 0)
	       add_long("%^GREEN%^You are on the road in the Player Village. %^RESET%^");
	}
   ::init();
}
void restoreit(){
        restore_object(FILENAME,1);
	adjust_doors();
}

void add_long(string str){
    int x;
	long_desc = "";
	longdesc[num_homes] = str;
	num_homes++;
	x=0;	
	while(x < num_homes){
		long_desc += longdesc[x]+"\n";
		x++;
	}
	set_long(long_desc);
}

void set_doornames(string str){
	if(!str) return;
	door_status[str] = 0;
	door_locked[str] = 0;
	saveit();
}
mixed query_doornames(string str){
	if(!str) return door_status;
	return door_status[str];
}

void adjust_doors(){
	mixed *pair;
	increment = 0;
	while(( pair = each(door_status)) != ({})) {
		set_open(pair[0],pair[1]);
	}
	while(( pair = each(door_locked)) != ({})) {
		set_locked(pair[0],pair[1]);
	}
}
mixed *each(mapping map){
	mixed *thekeys,*thevalues;
	if(sizeof(map) < 1) return (({}));
	thekeys = keys(map);
	thevalues = values(map);
	increment++;
	return ({thekeys[increment-1],thevalues[increment-1]});
}
set_open(str,open){
	door_status[str] = open;
	saveit();
	return ::set_open(str,open);
}
set_locked(str,open){
	door_locked[str] = open;
	saveit();
	return ::set_locked(str,open);
}

void remove_doornames(string str){
        string dir;
        if(!str) return "";
        dir = doors[str]["direction"];
        map_delete(door_status,str);
        map_delete(door_locked,str);
        map_delete(doors,str);
        remove_pre_exit_function(dir);
}
