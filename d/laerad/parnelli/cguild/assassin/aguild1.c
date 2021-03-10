//Assassins guild hall coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
//    object ob;
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(DIRT_ROAD);
    set_name("Assassins guild");
    set_short("Assassins guild");
    set_long(
	"You are in the local Assassins hang out.  The realms greatest "+
	"killers come here to inquire about new bounties or prospects.  "+
   "The room is very poorly lit and a bit cluttered, very easy to hide in.  "+
	"You can see a few shady characters whispering in the far corners "+
        "of the room."
    );
    set_property("indoors",1);
    set_property("light",2);
//    set_property("no teleport",1);  removing access restrictions from all guild halls
    set_listen("default","The room is deathly silent.");
    set_smell("default","The room smells strangely fresh and untainted.");
    set_items( ([
    ]) );
    set_exits( ([
    "up":"/d/laerad/parnelli/cguild/assassin/entrance",
	"south":"/d/laerad/parnelli/cguild/assassin/aguild2",
        "west":"/d/laerad/parnelli/cguild/assassin/bounty",
	"east":"/d/laerad/parnelli/cguild/assassin/aguild3"
    ]) );
/*  removing ooc boards that have outlived their usefulness  *Styx*  4/6/03
    ob= new(BBOARD);
    ob->set_name("board");
    ob->set_id( ({ "board","guild board" }) );
    ob->set_board_id("aguild1");
    ob->set_max_posts(30);
    ob->set_location("/d/laerad/parnelli/cguild/assassin/aguild1");
    ob->set_short("The Assassins board");
    ob->set_long("This is the Assassins board.  Post whatever Assassin-like things you wish.  ");
*/
}

int test_assassin(){
    if(TP->is_class("assassin") || TP->query("is_assassin") || avatarp(TP)) return 0;
    tell_object(TP, "You cannot do that here.");
    return 1;
}

void init(){
    ::init();
    add_action("test_assassin", "remove");
    add_action("test_assassin", "answer");
    add_action("test_assassin", "post");
    add_action("test_assassin", "edit");
}
