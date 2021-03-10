// /d/dagger/Daggerdale/shops/vethor_guild.c

#include <std.h>
#include <daemons.h>

inherit ROOM;

string *registered;

void create(){
	object ob;
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	registered = SAVE_D->query_array("vethor_members");
	set_property("light", 2);
        set_property("indoors",1);
        set_property("no teleport",1);
	set_short("Daggerdale guild entrance");
	set_long(
@STYX
This small dimly lit room is made for functionality rather than looks.  The walls are bare as is the stone floor.  A pretty young woman sits behind a small desk with several quill pens and a few papers scattered about.  There is also a message board on one wall.
STYX
);
	set_smell("default", "You smell ink and oiled leather.");
	set_listen("default", "All you hear is a slight rustling of papers as the"+
" woman adjusts them on her desk.");
	set_items(([
	]));

	set_exits(([
		"out" : "/d/dagger/Daggerdale/shops/vethor_trophy",
		"healer" : "/d/dagger/Daggerdale/shops/vethor_healer",
		"store" : "/d/dagger/Daggerdale/shops/vethor_store",
	]));
	set_pre_exit_functions( ({"healer", "store"}), ({"GoThroughDoor", "GoThroughDoor"}) );
	ob= new(BBOARD);
	ob->set_name("board");
	ob->set_id( ({ "board", "guild board" }) );
	ob->set_board_id("ddguild");
	ob->set_max_posts(30);
	ob->set_location("/d/dagger/Daggerdale/shops/vethor_guild");
	ob->set("short", "Dagger thieves' guild board");
	ob->set("long", "Post whatever thieving and guild-related things you deem "
	"appropriate here.\n"
    );
}

void init() {
	::init();
}

void reset() {
	::reset();
	if(!present("selena"))
	new("/d/dagger/Daggerdale/shops/npcs/selena")->move(TO);
}

int add_member(string str){
	registered = SAVE_D->query_array("vethor_members");
	if(member_array(str,registered) == -1){
		SAVE_D->set_value("vethor_members", str);
		return 1;
	}
	else return 0;
}

void remove_member(string str){
	registered = SAVE_D->query_array("vethor_members");
	if(member_array(str, registered) != -1){
		SAVE_D->remove_name_from_array("vethor_members", str);
	}
}

// Using GoThroughDoor for function name so thief sneak won't work to bypass it.

int GoThroughDoor() {
	registered = SAVE_D->query_array("vethor_members");
//	if (avatarp(TP)) 
//		return 1;
//	if (!avatarp(TP)) {
	if(member_array(TPQN, registered) != -1) {
//	   write("%^BOLD%^%^BLUE%^Testing - you should get in");
	   return 1;
	}
	else {
   write("%^BOLD%^%^BLUE%^Only members are allowed to use the guild services!");
	return 0;
	}
}

