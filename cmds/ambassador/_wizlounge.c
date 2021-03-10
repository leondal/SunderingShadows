//Coded by Bane@Shadowgate for use by Immortals//
//to teleport them to the main wizard lounge.//
#include <std.h>
#include <move.h>
inherit DAEMON;
int cmd_wizlounge(string str){
    object ob, place;
    ob = "/d/laerad/wizlounge.c";
    if(!wizardp(TP)) return 1;
    if((int)TP->move(ob) == MOVE_OK){
	tell_object(TP,"You levitate up to the Immortal lounge.");
	TP->describe_current_room(1);
	return 1;
    }
}
