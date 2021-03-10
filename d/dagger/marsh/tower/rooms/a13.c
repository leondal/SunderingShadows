#include <std.h>
#include <move.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;
int FLAG,CHECK,CHECK1;
int xyz;
void init() {
    ::init();
    add_action("open_fun","open");
    add_action("push_fun","push");	
    add_action("search_fun","search");
}
void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
      "The medium sized chamber before you is made of the same %^BOLD%^"
      "blood-red%^RESET%^%^RED%^ stone as seen in other parts of the tower. "
      "The stone is very faded in colour here and has small %^RESET%^"
      "white veins%^RED%^ coursing through it. Old rusted torch brackets hang broken "
      "from the walls. Pressed against the north wall, a large %^ORANGE%^"
      "wooden coffin%^RED%^ can be seen. Attached to the sides of the "
      "%^ORANGE%^coffin%^RED%^, "
      "numerous sinewy %^CYAN%^web-like strands%^RED%^ lead from within the interior of "
      "the %^ORANGE%^coffin%^RED%^ into the floor and walls of the chamber. A murky red "
      "substance is slowly being drawn through the %^CYAN%^strands%^RED%^"
      " into the %^ORANGE%^coffin%^RED%^. Two passageways lead to the southwest and the "
      "southeast."
      "%^RESET%^" 
    );
    set_short("%^RED%^Burial Chamber%^RESET%^");
    set_listen("default",
      "A low moan can be heard from within the coffin."
    );
    set_smell("default",
      "Your body begins to emit the smell of your inner fear."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
	"brackets":"%^ORANGE%^The brackets hang broken from the walls.%^RESET%^",
	"coffin":"%^ORANGE%^You sense an inner force present within the coffin.%^RESET%^",
	"strands":"%^BOLD%^%^RED%^The strands seem to deliver the inner life-force "
	"of the stones used to build this hellish place to the insides of the coffin.",
	"substance":"%^BOLD%^%^RED%^You could swear the substance was blood.%^RESET%^",
      ]));
    set_exits(([
	"southwest": RPATH "a10",
	"southeast": RPATH "a12",
	"south": RPATH "a11",
      ]));

    set_pre_exit_functions(({"southwest"}),({"exita_fun"}));
    set_pre_exit_functions(({"southeast"}),({"exita_fun"}));
    set_pre_exit_functions(({"south"}),({"exitb_fun"}));
    set_pre_exit_functions(({"north"}),({"exita_fun"}));
}
int exita_fun() {
    if(present("vampyre")) {
	write("The vampyre blocks your way!");
	return 0;
    }
    write("%^BLUE%^You push your way through the hanging strands and "
      "head into the darkness.%^RESET%^"
    );
    return 1;
}
int exitb_fun() {
    if(present("vampyre")) {
	write(
	  "%^BOLD%^%^RED%^Vampyre shouts: Run in fear, "+TPQCN+" you maggot child!%^RESET%^"
	);
	say(
	  "%^BOLD%^%^RED%^Vampyre tells you: %^RESET%^You would be wise to "
	  "flee as "+TPQCN+" the maggot child just did!"
	  ,TP);
	return 1;
    }
    return 1;
}
void reset() {
    object ob, room;
    ::reset();
    ob = find_living("my_vampyre");
    if(objectp(ob)) room = environment(ob);
    if(!room){
	FLAG = 0;
	CHECK = 0;
    }
}
int open_fun(string str) {
    if(!str) {
	notify_fail("Open what?\n");
	return 0;
    }
    if(str != "coffin") {
	notify_fail("Open what?\n");
	return 0;
    }
    if(FLAG != 0) {
	notify_fail("The coffin is open already!\n");
	return 0;
    }
    write(
      "%^GREEN%^You slowly open the coffin.\n"
      "%^BOLD%^%^RED%^A vampyre leaps from the coffin with a burning rage in it's eyes!\n"
      "%^MAGENTA%^Vampyre says:%^RESET%^ For disturbing my eternal sleep, you shall DIE!%^RESET%^"
    );
    say(
      "%^GREEN%^"+TPQCN+" slowly opens the coffin.\n"
      "%^BOLD%^%^RED%^A vampyre leaps from the coffin with a burning rage in it's eyes!\n"
      "%^MAGENTA%^Vampyre says:%^RESET%^ For disturbing my eternal sleep, you shall DIE!%^RESET%^"
      ,TP);
    new( MPATH "vampyre.c" )->move(TO);
    present("vampyre")->force_me("kill "+TP->query_name());
    FLAG = 1;
    return 1;
}
int push_fun(string str) {
    if(!str) {
	notify_fail("Push what?\n");
	return 0;
    }
    if(str != "coffin") {
	notify_fail("Push what?\n");
	return 0;
    }
    if(CHECK != 0) {
	notify_fail("The coffin is already been pushed aside!\n");
	return 0;
    }
    if(FLAG == 0) {
	write("The coffin is too heavy to push!");
	return 1;
    } else {
	write("%^CYAN%^You push the coffin aside revealing a small passage "
	  "leading north!");
	say("%^CYAN%^"+TPQCN+" pushes the coffin aside revealing a small "
	  "passage leading north!",TP);
	TO->add_exit( RPATH "stair1" , "north" );
	CHECK = 1;
	return 1;
    }
}
int search_fun(string str) {
    if(!str) {
	notify_fail("Search what?\n");
	return 0;
    }
    if(str != "coffin") {
	notify_fail("Search what?\n");
	return 0;
    }
    if(CHECK1 != 0) {
	write("You find nothing odd.");
	return 1;
    }
    if(FLAG == 0) {
	write("The coffin is closed.");
	return 1;
    } else {
	write("%^CYAN%^You search the coffin and find a few trinkets!");
	say("%^CYAN%^"+TPQCN+" searches the coffin!",TP);
	xyz = new(OPATH "note2.c")->move(TP);
	if( (xyz == MOVE_NO_ROOM) || (xyz == MOVE_NOT_ALLOWED) ){
	    tell_room(ETP, "%^CYAN%^The note is too heavy, and falls to the ground!");
	    new(OPATH "note2.c")->move(ETP);
	}
	xyz = new(OPATH "bracelet.c")->move(TP);
	if( (xyz == MOVE_NO_ROOM) || (xyz == MOVE_NOT_ALLOWED) ){
	    tell_room(ETP, "%^CYAN%^The bracelet is too heavy, and falls to the ground!");
	    new(OPATH "bracelet.c")->move(ETP);
	}
	xyz = new(OPATH "tooth.c")->move(TP);
	if( (xyz == MOVE_NO_ROOM) || (xyz == MOVE_NOT_ALLOWED) ){
	    tell_room(ETP, "%^CYAN%^The fang is too heavy, and falls to the ground!");
	    new(OPATH "tooth.c")->move(ETP);
	}
	xyz = new(OPATH "ring.c")->move(TP);
	if( (xyz == MOVE_NO_ROOM) || (xyz == MOVE_NOT_ALLOWED) ){
	    tell_room(ETP, "%^CYAN%^The ring is too heavy, and falls to the ground!");
	    new(OPATH "ring.c")->move(ETP);
	}
	new( OPATH "ruby.c" )->move(TP);		
	CHECK1 = 1;
	return 1;
    }
}
