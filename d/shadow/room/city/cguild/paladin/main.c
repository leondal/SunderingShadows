#include <std.h>
#define RPATH "/d/shadow/room/city/cguild/paladin/"+

inherit ROOM;

void init() {
    ::init();
    add_action("sit_func","sit");
//    add_action("test_ranger", "remove");
//    add_action("test_ranger", "answer");
//    add_action("test_ranger", "post");
//    add_action("test_ranger", "edit");
}
void create() {
    object ob;
    ::create();
    set_property("light",2);
//    set_property("no teleport", 1);
    set_property("indoors",1);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_smell("default",
	"A rather serious smell fills the room."
    );
    set_listen("default","It is silent from interruption here.");

    set_items(([
	"table":"There is a large stone meeting table here.",
	"chair":"There are many chairs around the large stone table.",
	"chairs":"There are many chairs around the large stone table."
    ]));
    set_exits(([
        "south": RPATH "sanctum"
    ]));
/*   ob=new(BBOARD);
    ob->set_name("board");
    ob->set_id(({"board","paladin"}));
    ob->set_board_id("paladin");
    ob->set_max_posts(30);
    ob->set_location( RPATH "main.c" );
    ob->set_short("%^CYAN%^Paladin Board%^RESET%^");
    ob->set_long(
	"This is the board for information, comments and suggestions "
	"about the Paladin's guild. "
    );
*/
}
string lng_fun(string str) {
    str =
	"%^CYAN%^You have entered the main meeting chamber "
	"within the Paladin Keep "
	"which is used by the paladins to hold meetings of discussion "
	"and to leave information for one another. "
	"This chamber, like the others is quite bare in a regal way. "
	"The only decoration is a large, round %^RESET%^stone "
	"table%^CYAN%^ surrounded by %^RESET%^stone chairs%^CYAN%^."
        "%^CYAN%^ ";
    if(present("grazzt")) {
	str += "\n%^BOLD%^%^BLACK%^You stand within the long shadow cast "
	"by the evil presense of Grazzt."
	       "%^RESET%^";
    }
    return str;
}
string shrt_fun(string str) {
    str =
        "%^CYAN%^The Chamber of Meeting%^RESET%^";
    return str;
}
int sit_func(string str) {
    if(!str) {
	notify_fail("Sit where?\n");
	return 0;
    }
    if(str != "chair") {
	notify_fail("Sit where?\n");
        return 0;
    }
    write(
	"%^CYAN%^You seat yourself upon one of the stone chairs.%^RESET%^"
    );
    say(
        "%^CYAN%^"+TPQCN+" takes a place at the table."
        "%^RESET%^"
    ,TP);
    return 1;
}
/*
int test_ranger(){
    if(avatarp(TP)) return 0;
    if(TP->is_class("paladin")) return 0;
    tell_object(TP, "Only paladins may do that here.");
    return 1;
}
*/