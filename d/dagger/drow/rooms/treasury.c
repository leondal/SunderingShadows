#include <std.h>
#include <security.h>
#include "/d/dagger/drow/short.h"
inherit ROOM;
int y = 90376;
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^Drow treasury%^RESET%^");
    set_long(
	"%^BLUE%^This place of business is known as the treasury of the "
	"Drow Regime. It is used to collect treasures that drowish "
	"raiding parties bring back from missions of plunder. Then the "
	"gold is turned over to Grazzt in return for more devices, "
	"weaponry, traps and protection. \n%^RED%^The current project is: "
	"%^WHITE%^Gate towers and portcullis for the city's entrance.\n"
        "%^YELLOW%^Gold still needed: "+y+"%^RESET%^"
    );
    set_listen("default",
	"You hear gold clinking."
    );
    set_smell("default",
	"The smell of money fills the air."
    );
    set_items(([
    ]));
    set_exits(([
    	"south": RPATH "city16"
    ]));
}
void init() {
    ::init();
    add_action("donate_amount","donate");
}
int donate_amount(string str) {
    string type;
    int x;
    if(!str) {
	notify_fail("Donate what?\n");
	return 0;
    }
    if(sscanf(str,"%d %s", x, type ) !=2) {
	notify_fail("Donate <amount> gold>\n");
        return 0;
    }
    if(type != "gold") {
	notify_fail("Only gold please!\n");
	return 0;
    }
    if(x <= 0) {
        notify_fail("Too little!\n");
        return 0;
    }
    if((int)TP->query_money("gold") < x ) {
	notify_fail("You do not have that much money!\n");
        return 0;
    }
    if (!present("mykrysh")) {
	notify_fail("The treasurer is not in right now!\n");
	return 0;
    }
    message("my_action",
	"You give the treasurer a "+x+" gold donation.\n"
	"Treasurer says: Thank you. I will deliver this as soon as possible."
    ,TP);
    message("other_action",
	""+TPQCN+" gives some gold to the treasurer."
    ,environment(TP),TP);
    TP->use_funds("gold",x);
    y=y-x;
    seteuid(UID_RESTORE);
    write_file("/d/dagger/drow/logs/donations",
        ""+capitalize(TP->query_true_name())+" donated "+x+" gold to help the drow at "
	+ctime(time())+"\n");
    set_long(
	"%^BLUE%^This place of business is known as the treasury of the "
	"Drow Regime. It is used to collect treasures that drowish "
	"raiding parties bring back from missions of plunder. Then the "
	"gold is turned over to Grazzt in return for more devices, "
	"weaponry, traps and protection. \n%^RED%^The current project is: "
	"%^WHITE%^Gate towers and portcullis for the city's entrance.\n"
        "%^YELLOW%^Gold still needed: "+y+"%^RESET%^"
    );
    return 1;
}
void reset() {
    ::reset();
    if(!present("mykrysh")) {
        write("%^RED%^The treasurer enters the room and grins "
	"evilly.%^RESET%^");
	new( MPATH "mykrysh")->move(TO);
    }
}
