//out exit updated for new Seneca ~Circe~ 1/12/09
//still needs updating
#include "/d/attaya/seneca/short.h"

#define SAVE_ROOM "/d/save/thief_seneca"

inherit ROOM;

string *registered;

void create(){
//    object ob;
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    registered = ({});
    seteuid(geteuid());
    restore_object(SAVE_ROOM);
    set_properties((["light":2,"indoors":1]));
    set_name("This is within the Seneca Thief's Guild.");
    set("short","%^BLUE%^%^BOLD%^This is within the Seneca Thief's Guild.%^RESET%^");
    set("long",
      "%^BOLD%^%^BLUE%^This is within the Seneca Thief's Guild.%^RESET%^\n You have entered the main room of the guild. To the north is a store which will sell you thievish stuff. It will cost you 20,000 gold to become a member of the guild.\n   %^BOLD%^%^BLUE%^Welcome and enjoy!%^RESET%^"
    );
    set_exits(([
        "north" : THIEF "thief10",
//        "out" : THIEF "thief1",
        "out" : "/d/attaya/newseneca/rooms/bar_storage"
      ]));

    set_smell("default","It smells of leather and Nellie's perfume.");
    set_listen("default","You can hear the mumbling of thieves");

/*  removing ooc boards & others that have outlived their usefulness  *Styx*  4/6/03
    ob= new(BBOARD);
    ob->set_name("board");
    ob->set_id( ({ "board", "guild board","thief guild board" }) );
    ob->set_board_id("tboard");
    ob->set_max_posts(25);
    ob->set_location(THIEF "2thief9.c");
    ob->set("short", "The board of Thievish Things");
    ob->set("long", "Post information of particular interest to other thieves here...or what you want.\n"
    );
*/

    set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
    save_object(SAVE_ROOM);
}

void init(){
    ::init();

    add_action("look","look");

}

int look(string str){
    int i;
    if(!str || str != "book") return 0;

    tell_room(TO,""+TPQCN+" looks over the book.",TP);
    write("This book contains all the names of the members of the Seneca Thieves's guild!");
    write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    for(i = 0;i<sizeof(registered);i++)
	write("%^BOLD%^%^RED%^              "+capitalize(registered[i]));
	  return 1;
      }

	int add_member(string str){
	if(member_array(str,registered) == -1){
	    registered += ({str});
	    save_object(SAVE_ROOM);
	    return 1;
	}
	else return 0;
    }

    void remove_member(string str){
	if(member_array(str, registered) != -1){
	    registered -= ({str});
	    save_object(SAVE_ROOM);
	}
    }

    void reset(){
	::reset();

	if(!present("nellie"))
	    new(THIEF "nellie.c")->move(TO);
    }

    int GoThroughDoor(){
	if(member_array(TPQN, registered) != -1) return 1;

	write("%^BOLD%^%^RED%^Guild services are only available to guild members!");
	return 0;
    }
