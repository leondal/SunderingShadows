//cuberoom.c

#include <std.h>

inherit ROOM;

int flag;

void player_damage();
void move_here(object ob);

void create(){
	::create();
	
	set_property("light",-10);
	set_property("indoors",1);
	set_property("no teleport",1);
	set_property("no attack",1);
	set("short","Inside the cube");
	set("long","In side the cube");
	set_exits(([]));
	set_items(([]));
	set_smell("default","You wish your nose would close to lock out the rancid fumes.");
	set_listen("default","Muffled sounds reach your ears but nothing more");
	flag = 0;

}

void clean_up(){ return; }


void player_damage(){
	object *inven;
	int i,j;
	inven = all_inventory(TO);
	i = sizeof(inven);
			for(j = 0; j < i;j++){
				if(interactive(inven[j])){
					tell_object(inven[j],"%^BOLD%^%^GREEN%^You feel the cubes acids eating at you!\n");
					inven[j]->add_hp(-(random(6)+2));
					tell_object(inven[j],"%^RESET%^Hp: "+inven[j]->query_hp()+"    Mp: "+inven[j]->query_mp()+"\n");
				}
			}
	call_out("player_damage",10);

}

void move_here(object ob){
	ob->move(TO);
	}

void init(){
	::init();
	if(!flag){
		call_out("player_damage",10);
		flag = 1;
	}
}
