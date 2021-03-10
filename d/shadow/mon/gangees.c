#include "./melnmarn.h"

inherit "/std/vendor.c";

int build;

void create() {
    ::create();
   set_name("gangees");
   set_id( ({ "gangees","human" }) );
   set_short("A Human");
   set_level(19);
   set("long", "He sells things. Like tobacco.\n");
   set_gender("male");
   set("race", "human");
   set_body_type("human");
   set_class("mage");
   set_alignment(5);
   set_mp(300);
   set_hd(19,1);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_exp(20);
   set_items_allowed("tobacco");
   set_storage_room(ROOMDIR+"tb_storage.c");
   build = 0;
   set_event("7:15","say go_home");
   set_event("7:16","fun go_home");
}

void reset(){
	object ob;
	ob = ROOMDIR+"tb_storage";
	ob->reset();
	return 1;
}
void go_home(mixed str){
	build = 1;
    command("say ok...");
}
void start_heart(){
	set_heart_beat(1);
}
void heart_beat(){
	if(!build) return;
	build ++;
	if(build == 5){
		command("say hello there!");
	}


}
