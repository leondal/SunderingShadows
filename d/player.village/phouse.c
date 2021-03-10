//   An inheritable house object for the player village homes. 
//   handles changable descriptions, long and short, doors, removing
//   and installing. an equipment chest, that holds items indefinately.
//   and has user created decorative items.
//
//	
//	Written by Melnmarn@ShadowGate 11/20/94
//



#include "/d/player.village/pvillage.h"
inherit VAULT;

void restoreit();                 
void restore_chest(string str);
void saveit(string str);
void adjust_doors();
void add_the_items();
void set_itemlist(string str);
void set_dooritem(string str1, string str2);
string remove_doornames(string str);
mixed *each(mapping map);

string filename,chest;
mapping itemlist,door_status,door_locked;
int increment;

void create(){
	::create();
	set_exits(([]));
	set_items(([]));
	door_status = (([]));
	door_locked = (([]));
	itemlist = (([]));
}
void saveit(string filename){ 
	string tmp;
      	if(!filename){
		sscanf(file_name(),"/%*s/%*s/%*s/%s",tmp);
		filename = HOMES+tmp;
      	}
	save_object(filename,1);
}
void restoreit(){
    string tmp;
      	if(!filename){
		sscanf(file_name(),"/%*s/%*s/%*s/%s",tmp);
		filename = HOMES+tmp;
      	}
	restore_object(filename,1);
	adjust_doors();
	add_the_items();
	restore_chest(chest);
}
void set_doornames(string str){
	if(!str) return;
	door_status[str] = 0;door_locked[str] = 0;
	saveit(filename);
}
string remove_doornames(string str){
	string dir;
	if(!str) return "";
	dir = doors[str]["direction"];
	map_delete(door_status,str);
	map_delete(door_locked,str);
	map_delete(doors,str);
	remove_pre_exit_function(dir);
	remove_item(dir);
	return dir;
}
mixed query_doornames(string str){
	if(!str) return door_status;
	return door_status[str];
}
mixed *each(mapping map){
	mixed *thekeys,*thevalues;
	if(sizeof(map) < 1) return (({}));
	thekeys = keys(map);
	thevalues = values(map);
	increment++;
	return ({thekeys[increment-1],thevalues[increment-1]});
}

void adjust_doors(){
	mixed *pair;	
	while(( pair = each(door_status)) != ({})) {
		set_open(pair[0],pair[1]);
	}
	while(( pair = each(door_locked)) != ({})) {
		set_locked(pair[0],pair[1]);
	}
}
set_open(str,open){
	door_status[str] = open;
	saveit(filename);
	return ::set_open(str,open);
}
set_locked(str,open){
	door_locked[str] = open;
	saveit(filename);
	return ::set_locked(str,open);
}
void set_itemlist(string str){
	itemlist[str] = 1;
	saveit(filename);
}
void remove_an_item(string str){
	map_delete(itemlist,str);
	saveit(filename);
}
void add_the_items(){
	mixed *pair;	
	object obj;
	while(( pair = each(itemlist)) != ({})) {
		if(present(pair[0],this_object())) continue;
		obj = new(MAIN+"item");
		obj->restoreit(OBJ+pair[0],pair[1]);		
		obj->move(this_object());
	}
}
void set_dooritem(string str1,string str2){
	set_items(([str1 : "The "+str2+" door is "+str1,]));
	saveit(filename);
}
void set_chest(string str){ chest = str; }
string query_chest(){ return chest; }
void restore_chest(string str){
	object obj;
	if(!chest) return;
	if(strlen(chest) < 1) return;
	if(present("chest",TO)) return;
	obj = new(MAIN+"chest");
	obj->move(TO);
	obj->set_player(chest);
}
