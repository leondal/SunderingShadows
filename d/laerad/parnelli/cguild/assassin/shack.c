//Assassins guild hall coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
   set_terrain(HUT);
   set_travel(FOOT_PATH);
    set_name("Abandoned shack");
    set_short("Abandoned shack");
    set_long(
	"This is a dirty old abandoned tin shack.  The walls are covered "+
	"in rust and some dark maroon substance.  The wood floor is cracked "+
	"and rotting.  There are still a few old tools hanging from the walls, "+
	"such as a spade, shovel, rake and others."
    );
    set_property("indoors",1);
    set_property("light",2);
//    set_property("no teleport", 1);  removing safe haven from guild halls *Styx*  4/6/03
    set_listen("default","The creaking of the floor is the only audible sound.");
    set_smell("default","The room smells dirty and weakly of blood.");
    set_items( ([
	({"floor"}):"The floor is very old and rotten.  You notice a few of the "+
	    "floor boards are a bit loose.",
	({"substance"}):"It looks like dried blood.",
	({"walls"}):"The walls are very rusty and covered in old tools."
    ]) );
    set_exits( ([
    "north" : "/d/laerad/parnelli/asgard/as42",
    ]) );
    set_pre_exit_functions( ({"down"}),({"go_down"}) );
}
void init(){
    ::init();
    add_action("search","search");
    add_action("peer","peer");
    add_action("sneak","sneak");
}
int peer(){
    write("It's too dark for that.");
    return 1;
}
int search(string str){
    write("You find a trapdoor in the corner of the room!");
    write("You lift it up revealing a secret passage leading down.");
    add_exit("/d/laerad/parnelli/cguild/assassin/entrance","down");
    return 1;
}
int go_down(){
    write("You jump down into the darkness.");
    if(!TP->query_invis()) tell_room(ETO,TPQCN+" appears to disappear into the ground.",TP);
    return 1;
}
void reset(){
    ::reset();
    remove_exit("down");
}
int sneak(string str){
    if(str == "down" && member_array("down",query_exits()) != -1){
        write("This will get you killed down there.");
        return 1;
    }
    return 0;
}
