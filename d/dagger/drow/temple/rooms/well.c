#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit ROOM;
void init() {
    ::init();
    add_action("dive_func","dive");
    add_action("say_func","say");
    add_action("say_func","yell");
    add_action("say_func","shout");
    add_action("no_func","cast");
    add_action("no_func","drop");
    add_action("no_func","offer");
    add_action("no_func","give");
    add_action("no_func","put");
    add_action("no_func","throw");
    add_action("no_func","drink");
}
void create() {
    ::create();
   set_terrain(BARREN);
   set_travel(FRESH_BLAZE);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no kill",1);
    set_property("no attack",1);
    set_property("no magic",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^Within nothingness%^RESET%^");
    set_long(
	"%^BLUE%^You are floating within black nothingness. "
	"Around you float several %^MAGENTA%^glowing spheres"
	"%^BLUE%^. The %^MAGENTA%^spheres%^BLUE%^ "
	"colours are %^RED%^red%^BLUE%^, "
	"%^BOLD%^%^BLUE%^blue%^RESET%^%^BLUE%^, "
	"%^YELLOW%^yellow%^RESET%^%^BLUE%^ and "
	"%^GREEN%^green%^BLUE%^."
    );    
    set_smell("default",
        "There is no smell here."
    );
    set_listen("default",
	"There is no sound here."
    );	
    set_items(([
        "blackness":"You are floating in the blackness.",
        "nothingness":"You are floating in the nothingness.",
        "space":"You are floating in infinite space.",
        "sphere":"There are spheres of light floating within the "
	"void dimension.",
        "spheres":"There are spheres of light floating within the "
	"void dimension.",
        "red sphere":"%^RED%^The red sphere floats behind you.%^RESET%^",
	"blue sphere":"%^BLUE%^The blue sphere floats in front of "
	"you.%^RESET%^",
	"yellow sphere":"%^YELLOW%^The yellow sphere floats beneath you."
	"%^RESET%^",
	"green sphere":"%^GREEN%^The green sphere floats to the right "
	"of you.%^RESET%^"
    ]));
    set_exits(([
        "red":"/d/tharis/road/road8",
	"blue":"/d/dagger/drow/rooms/city1",
	"green":"/d/laerad/wasteland/waste1",
	"yellow":"/d/darkwood/room/road18"
    ]));
    set_pre_exit_functions(({"red"}),({"exit_fun"}));
    set_pre_exit_functions(({"blue"}),({"exit_fun"}));
    set_pre_exit_functions(({"yellow"}),({"exit_fun"}));
    set_pre_exit_functions(({"green"}),({"exit_fun"}));
}
 
int exit_fun() {
    write("%^BOLD%^%^BLUE%^You float your body back into the prime "
          "material plane.%^RESET%^"
    );
    say("%^BOLD%^%^BLUE%^"+TPQCN+" floats away.%^RESET%^"
    ,TP);
    return 1;
}
int dive_func(string str) {
    if(!str) {
        notify_fail("Dive what?\n");
        return 0;
    }
    if(str != "well") {
        notify_fail("Dive what?\n");
        return 0;
    }
    write(
        "%^BOLD%^%^RED%^Your body is %^BLUE%^ripped%^RED%^ into a "
	"million pieces as you attempt to dive into "
	"a sub-space from "
	"within a sub-space.%^RESET%^"
    );
    say(
        "%^BOLD%^%^RED%^"+TPQCN+" EXPLODES!!!"
        "%^RESET%^"
    );
    TP->do_damage("torso",850);
    return 1;
}
int say_func(string str) {
    write("There is no sound in a void.");
    return 1;
}
int no_func(string str) {
    write("That action cannot be performed here!");
    return 1;
}
