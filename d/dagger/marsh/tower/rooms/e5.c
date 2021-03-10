#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;
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
    add_action("no_func","tell");
}
void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no kill",1);
    set_property("no attack",1);
    set_property("no magic",1);
    set_property("no teleport",1);
    set_short("%^RED%^Within nothingness%^RESET%^");
    set_long(
	"%^BLUE%^You are floating within black nothingness. "
	"Around you float several %^MAGENTA%^glowing swirls%^BLUE%^ "
	"of meaningless colours. The only way out of here is to float "
	"back through the %^CYAN%^portal%^BLUE%^ you came through.\n%^BOLD%^%^RED%^"
	"There is an feeling of great lawfulness here.%^RESET%^"
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
        "colours":"The colours swirl about you.",
	"swirls":"The colours swirl about you.",
    ]));
    set_exits(([
        "portal": RPATH "e6",
    ]));
    set_pre_exit_functions(({"portal"}),({"exit_fun"}));
    new( OPATH "justice.c" )->move(TO);
}
 
int exit_fun() {
    write("%^BOLD%^%^BLUE%^You float your body back into the prime "
          "material plane.%^RESET%^"
    );
    say("%^BOLD%^%^BLUE%^"+TPQCN+" floats away.%^RESET%^"
    ,TP);
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
