#include <std.h>
#include <daemons.h>
#include "/realms/grendel/grendel.h"
#include "../tharis.h"
inherit "/std/bounty.c";

string *registered;

void create(){
    object ob;
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
    registered = SAVE_D->query_array("tharis_members");
    set_properties((["light":2,"indoors":1]));
    set_property("no teleport",1);

    set("short","The thief's guild in Tharis");
    set_long("%^ORANGE%^This small room serves as the main room for the thief guild in Tharis. While the city "
"has been rebuilt and repaired at several points in history, this room is obviously in its original state, and "
"has survived over many decades where most other establishments have fallen or changed. Several comfortable "
"%^RED%^couches %^ORANGE%^are arranged for members to sit, discuss, and negotiate. The walls are covered in "
"%^GREEN%^rich, soft fabric %^ORANGE%^that seems to muffle any sound. Even though several conversations go on "
"around you, it is surprisingly %^CYAN%^quiet %^ORANGE%^here. A large desk sits against the north wall where "
"people can 'register' for membership in the guild.\n%^BOLD%^There is a board here, accompanied by a small sign.\n%^RESET%^");
    set_exits(([
        "north" : ROOMS"thief_tailor",
        "store" : ROOMS"tstore",
        "down" : ROOMS"tunnel13",
      ]));
    set_items(([
        ({"sign","board"}) : "%^RESET%^%^ORANGE%^The board is a list of bounties, and the sign details its use. You can read either for more details.%^RESET%^",
        ]));
    set_smell("default","The room has the dusky, stale smell common to long-term enclosed places.");
    set_listen("default","It's surprisingly quiet here.");
    set_pre_exit_functions(({"store"}),({"GoThroughDoor"}));
}

void init(){
    ::init();
    add_action("look","look");
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}

void reset(){
	::reset();
	if(!present("nixie")) find_object_or_load(MOBS"nixie")->move(TO);
}

int look(string str){
    int i;
string stuff;
stuff = "";
    if(!str || str != "book") return 0;

    tell_room(TO,""+TPQCN+" looks over the book.",TP);
    write("This book contains all the names of the members of the Tharis Thieves's guild!");
    write("After flipping through a couple pages of names they all start blending together.");
    return 1;
    write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    registered = SAVE_D->query_array("tharis_members");
sort(registered);
    for(i = 0;i<sizeof(registered);i++)
stuff += "%^BOLD%^%^RED%^              "+capitalize(registered[i])+"\n";
this_player()->more(explode(stuff, "\n"));
    return 1;
}

int add_member(string str){
	registered = SAVE_D->query_array("tharis_members");
	if(member_array(str,registered) == -1){
	    SAVE_D->set_value("tharis_members", str);
	    return 1;
	}
	else return 0;
}

void remove_member(string str){
	registered = SAVE_D->query_array("tharis_members");
	if(member_array(str, registered) != -1){
	    SAVE_D->remove_name_from_array("tharis_members", str);
	}
}

int GoThroughDoor(){
	registered = SAVE_D->query_array("tharis_members");
	if(member_array(TPQN, registered) != -1) return 1;

	write("%^BOLD%^%^RED%^Guild services are only available to guild members!");
	return 0;
}
