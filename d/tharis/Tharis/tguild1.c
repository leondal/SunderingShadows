#include <std.h>
#include <daemons.h>
#include "/realms/grendel/grendel.h"

inherit ROOM;

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
    set_long(
@OLI
   %^BOLD%^%^YELLOW%^The thief's guild in Tharis%^RESET%^
This is a sparce room, holding only a desk. At this desk sits a
lovely elf. You look around and notice nothing much at all. A book
sits on the desk. You need to register to be allowed to use the facilities.
Registering here will cost 10,000 gold. However you can only register when
Nixie is here.
OLI
    );
    set_exits(([
	"south":"/d/tharis/Tharis/teashop",
	"store":"/d/tharis/Tharis/tstore"
      ]));

    set_smell("default","You smell only slight traces of really anything.");
   set_listen("default","Dead silence.");
/*
    ob= new(BBOARD);
    ob->set_name("board");
    ob->set_id( ({ "board", "guild board" }) );
    ob->set_board_id("tguild");
    ob->set_max_posts(30);
    ob->set_location("/d/tharis/Tharis/tguild1");
    ob->set("short", "Tharis's thieves' guild board");
   ob->set("long", "Post whatever thieving things you deem appropriate here.\n"
    );
taken out with the other boards in guilds.  Circe 6/26/04
*/
    set_pre_exit_functions(({"store"}),({"GoThroughDoor"}));
}

void init(){
    ::init();
    add_action("look","look");
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

    void reset(){
	::reset();

	if(!present("nixie"))
	    find_object_or_load("/d/tharis/monsters/nixie")->move(TO);
    }

    int GoThroughDoor(){
	registered = SAVE_D->query_array("tharis_members");
	if(member_array(TPQN, registered) != -1) return 1;

	write("%^BOLD%^%^RED%^Guild services are only available to guild members!");
	return 0;
    }