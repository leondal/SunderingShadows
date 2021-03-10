#include <std.h>
#include <daemons.h>
#include "/d/tharis/barrow/short1.h"
inherit ROOM;
int FLAG,FLG;
void init() {
    ::init();
    add_action("enter_func","enter");
    add_action("no_func","throw");
    FLG = 0;
}
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_smell("default",
        "The smell of evil magic is here."
    );
    set_listen("default","You hear the chittering of spiders.");
 
    set_items(([
        "stone":"The whole chamber is constructed from stone slabs.",
        "torches":"The torches flicker and provide little light.",
        "walls":"The walls are made of stone and have a few flickering "
        "torches in them.",
        "ceiling":"The ceiling is made of stone.",
        "floor":"The floor is made of stone and a dark open pit is "
        "located in the center of the floor.",
        "pentagram":"A large blood coloured pentagram is located on the "
        "north wall.",
    ]));
    set_exits(([
    ]));
}
string lng_fun(string str) {
    if((int)TP->query_alignment() == 9) {
        str =
            "%^ORANGE%^The chamber you have entered is made from "
            "blackened stone. Several torches flicker an eerie light "
            "throughout the room. Facing you on the north wall "
	    "is a large %^RED%^blood "
            "red pentagram%^ORANGE%^ painted on the wall.\nIn the center "
            "of the floor is a large open pit.\n"
            ".%^ORANGE%^ ";
    } else {
        str =
            "%^BLUE%^The chamber is merely a "
            "%^ORANGE%^dirt%^BLUE%^ room. Several "
            "flickering %^WHITE%^torches%^BLUE%^ hang from the walls. "
            "The dirt floor and walls are bare. There appears "
            "to be no place to go from this small chamber.%^BLUE%^ ";
    }
    if(present("priest")) {
        str += "\n%^GREEN%^A priest of dark elven racial features "
	"stands chanting before you. A large sphere of energy "
	"surrounds the priest. ";
    }
    if(present("grazzt")) {
        str += "\n%^BOLD%^%^BLACK%^You stand within the long shadow cast "
        "by the evil presense of Grazzt."
               "%^RESET%^";
    }
    return str;
}
string shrt_fun(string str) {
    if((int)TP->query_alignment() == 9) {
        str =
            "%^ORANGE%^Room of the pentagram%^RESET%^";
    } else {
        str =
            "%^BLUE%^A cramped stone chamber%^RESET%^";
    }
    return str;
}

int enter_func(string str) {
    if(!str) {
        notify_fail("Enter what?\n");
        return 0;
    }
    if(str != "pentagram") {
        notify_fail("Enter what?\n");
        return 0;
    }
    write(
        "%^BOLD%^%^RED%^You step through the pentagram.%^RESET%^"
    );
    tell_room(TO,
        "%^BOLD%^%^RED%^"+TPQCN+" vanishes through the "
	"pentagram!%^RESET%^"
    );
/*    if(random(15) < 1) {
	write("%^BOLD%^%^RED%^SOMETHING GOES TERRIBLY WRONG!%^RESET%^");
        TP->move_player("/d/dagger/drow/rooms/city28");
        return 1;
    }*/
    TP->move_player( RPATH "bd10" );
    return 1;
}
 
void reset() {
    int x,i;
    string *inv;
    ::reset();
    FLG = 0;
    inv = all_living(this_object());
    inv = filter_array(inv, "is_non_immortal_player",FILTERS_D);
    i = sizeof(inv);
    if(i > 0) { FLG = 1; }
    if(FLG != 0) {
	write("%^RED%^You hear the hollow laughter of Grazzt!%^RESET%^");
    } else {
    if(present("priest")) {
        tell_room(TO,
            "%^BOLD%^%^RED%^A drow priest looks through the pentagram."
            "%^RESET%^"
        );
    } else {
        new( MPATH "priest1")->move(TO);
        tell_room(TO,
            "%^BOLD%^%^RED%^A Drow priest suddenly enters through "
	    "the pentagram "
            "painted on the wall."
            "%^RESET%^"
        );
    }
}
}
 
int no_func() {
    write("The Drow Priest grins at you and avoids your action!");
    return 1;
}
