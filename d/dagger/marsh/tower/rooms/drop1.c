#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;
void init() {
    ::init();
    add_action("jump_fun","jump");
    add_action("climb_fun","climb");
    add_action("fly_fun","fly");
}
void create() {
    ::create();
   set_travel(FRESH_BLAZE);
    set_property("light",3);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_listen("default",
        "The wind blows hard against your face, and a faint whispering coupled with a hollow moaning rises up from below."
    );
    set_smell("default",
        "There is a very foul and evil smell to this new land before you."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
   "material and seems to glow in its blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
	"moon":"%^MAGENTA%^The two purple moons are very eerie to gaze upon and light the area with an "
	"incandescent glow.%^RESET%^",
 	"land":"You would have to enter the %^BLUE%^Shadowland%^RESET%^ to examine "
	"it closer.",
	"moons":"%^MAGENTA%^The two purple moons are very eerie to gaze upon and light the area with an "
	"incandescent glow.%^RESET%^",
	"shadows":"%^BLUE%^The shadows fill the land below and dance and stir in the wind.",
	"wall":"The outer tower wall looks climbable if you had some climbing tools.",
    ]));
    set_exits(([

    ]));
}
string lng_fun(string str) {
    if(TP->query_property("falling") != 0) {
        str =  "%^BOLD%^%^RED%^You are falling very fast through the air!\n"
	"%^RESET%^%^BLUE%^The %^WHITE%^sky%^BLUE%^ is "
	"%^CYAN%^grey%^BLUE%^ and filled with a swirling combination of %^WHITE%^mist and smoke%^BLUE%^. "
	"Two %^MAGENTA%^purple hazy moons%^BLUE%^ provide an incandescent shimmering light "
	"to view your surroundings by. The %^MAGENTA%^moons%^BLUE%^ are not the moons of your world. "
	"The %^GREEN%^land%^BLUE%^ below you in hard to make out clearly, as it is enveloped in %^BOLD%^%^BLUE%^shadows"
	"%^RESET%^%^BLUE%^. Of the %^BOLD%^%^BLUE%^shadows%^RESET%^%^BLUE%^; some are moving, some are still, some solid "
	"in substance and some are virtually transparent. The ground below you is atleast a forty foot "
	"clear drop.%^RESET%^";
	return str;
    }
    if(TP->query_property("demongate flying") != 0) {
	str =  "%^BOLD%^%^RED%^You are flying slowly through the air.\n"
	"%^RESET%^%^BLUE%^The %^WHITE%^sky%^BLUE%^ is "
	"%^CYAN%^grey%^BLUE%^ and filled with a swirling combination of %^WHITE%^mist and smoke%^BLUE%^. "
	"Two %^MAGENTA%^purple hazy moons%^BLUE%^ provide an incandescent shimmering light "
	"to view your surroundings by. The %^MAGENTA%^moons%^BLUE%^ are not the moons of your world. "
   "The %^GREEN%^land%^BLUE%^ below you is hard to make out clearly, as it is enveloped in %^BOLD%^%^BLUE%^shadows"
	"%^RESET%^%^BLUE%^. Of the %^BOLD%^%^BLUE%^shadows%^RESET%^%^BLUE%^; some are moving, some are still, some solid "
	"in substance and some are virtually transparent. The ground below you is atleast a forty foot "
	"clear drop.%^RESET%^";
	return str;
    } else {
	str =  "%^BOLD%^%^RED%^You are climbing on the tower's outer wall.\n"
	"%^RESET%^%^BLUE%^The %^WHITE%^sky%^BLUE%^ is "
	"%^CYAN%^grey%^BLUE%^ and filled with a swirling combination of %^WHITE%^mist and smoke%^BLUE%^. "
	"Two %^MAGENTA%^purple hazy moons%^BLUE%^ provide an incandescent shimmering light "
	"to view your surroundings by. The %^MAGENTA%^moons%^BLUE%^ are not the moons of your world. "
   "The %^GREEN%^land%^BLUE%^ below you is hard to make out clearly, as it is enveloped in %^BOLD%^%^BLUE%^shadows"
	"%^RESET%^%^BLUE%^. Of the %^BOLD%^%^BLUE%^shadows%^RESET%^%^BLUE%^; some are moving, some are still, some solid "
	"in substance and some are virtually transparent. The ground below you is atleast a forty foot "
	"clear drop.%^RESET%^";
	return str;
    }
}
string shrt_fun(string str) {
   if(TP->query_property("falling") != 0) {
	str = "%^BOLD%^%^RED%^Falling through the air%^RESET%^";
	return str;
    }
    if(TP->query_property("demongate flying") != 0) {
	str =  "%^BOLD%^%^RED%^Flying beside the tower wall%^RESET%^";
	return str;
    } else {
	str =  "%^BOLD%^%^RED%^Climbing on the tower's outer wall%^RESET%^";
	return str;
    }
}
int fly_fun(string str) {
    if(!str) {
	notify_fail("Fly where?\n");
	return 0;
    }
    if(str != "down" && str != "up") {
	notify_fail("Fly where?\n");
	return 0;
    }
    if(TP->query_property("demongate flying") == 0) {
	notify_fail("You can't fly...your not a bird are you???\n");
	return 0;
    }
    if(str == "down") {
        write(
	    "%^CYAN%^You slowly fly down the side of the tower.%^RESET%^"
        );
        say(
	    "%^CYAN%^"+TPQCN+" slowly flys down the side of the tower.%^RESET%^"
        ,TP);
        TP->move_player( RPATH "drop2.c","flying in the air");
        return 1;
    } else {
        write(
	    "%^CYAN%^You slowly fly up the side of the tower.%^RESET%^"
        );
        say(
	    "%^CYAN%^"+TPQCN+" slowly flys up the side of the tower.%^RESET%^"
        ,TP);
        TP->move_player( RPATH "c9.c","flying in the air");
        return 1;
    }
}
int climb_fun(string str) {
    int success;
    if(!str) {
	notify_fail("Climb where?\n");
	return 0;
    }
    if(str != "down" && str != "up") {
	notify_fail("Climb where?\n");
	return 0;
    }
    if(!present("climbing tools",TP)) {
	notify_fail("You have nothing to climb with!\n");
	return 0;
    }
    if(str == "down") {
        write(
	    "%^CYAN%^You slowly begin to climb further down the side of the tower.%^RESET%^"
        );
        say(
	    "%^CYAN%^"+TPQCN+" utilizes some climbing tools and continues to "
	    "climb down the side of the tower.%^RESET%^"
        ,TP);
    } else {
        write(
	    "%^CYAN%^You slowly begin to climb further up the side of the tower.%^RESET%^"
        );
        say(
	    "%^CYAN%^"+TPQCN+" utilizes some climbing tools and continues to "
	    "climb up the side of the tower.%^RESET%^"
        ,TP);
    }
if(TP->is_class("thief")) {
        success = random(100);
    } else {
 	success = random(10);
    }
    if(success < 1) {
	write("You make a mistake climbing and begin fall...");
	say(""+TPQCN+" makes a mistake climbing and begins to fall...",TP);
	TP->set_property("falling",1);
	TP->move_player( RPATH "drop2.c","falling through the air");
        TP->move_player( RPATH "drop3.c","falling through the air");
	TP->move_player( RPATH "drop4.c","falling through the air");
        write("You hit the cold hard ground with a dull thud!");
        TP->move_player( RPATH "s1.c","falling through the air");
	TP->do_damage("torso",random(40)+40);
	TP->remove_property("falling");
        return 1;
    } else {
        if(str == "down") {
	    write("You succeed in climbing ten feet or so down the tower's outer wall.");
	    TP->move_player( RPATH "drop2.c","climbing down the tower wall");
	    return 1;
        } else {
	    write("You succeed in climbing ten feet or so up the tower's outer wall.");
	    TP->move_player( RPATH "c9.c","climbing up the tower wall");
	    return 1;
        }
    }
}
int jump_fun(string str) {
    if(TP->query_property("demongate flying") != 0) return 0;
    if(!str) {
	notify_fail("Jump where?\n");
	return 0;
    }
    if(str != "down") {
	notify_fail("Jump where?\n");
	return 0;
    }
    write(
	"%^CYAN%^You jump off the side of the tower's outer wall!%^RESET%^"
    );
    say(
	"%^CYAN%^"+TPQCN+" jumps off the side of the tower's outer wall!%^RESET%^"
    ,TP);
    write("You fall...");
    say(""+TPQCN+" falls...",TP);
    TP->set_property("falling",1);
    TP->move_player( RPATH "drop2.c","falling through the air");
    TP->move_player( RPATH "drop3.c","falling through the air");
    TP->move_player( RPATH "drop4.c","falling through the air");
    write("You hit the cold hard ground with a dull thud!");
    TP->move_player( RPATH "s1.c","falling through the air");
    TP->do_damage("torso",random(40)+40);
    TP->remove_property("falling");
    return 1;
}
  
