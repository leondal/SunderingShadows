#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;
#define PLACE1 "/d/dagger/marsh/tower/rooms/s19";
int FLAG;
void init() {
    ::init();
    add_action("summon_fun","summon");
}
void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no teleport",1);
set_short("%^BLUE%^The Shadowland");
    set_long("%^CYAN%^"
	"The strange %^GREEN%^land%^CYAN%^ before you is extremely hard "
	"to see clearly due to the swirling %^MAGENTA%^mist%^CYAN%^ "
	"and numerous "
	"%^BLUE%^shadowy shapes%^CYAN%^ which surround you. Things "
	"seem to come into focus then "
	"fade away again. Moving %^BLUE%^shadows%^CYAN%^ "
	"roam and wander, swaying wildly in the "
	"howling %^ORANGE%^wind%^CYAN%^ in all directions. The %^ORANGE%^wind%^CYAN%^ "
	"never remains constant, it rises in tempo and shifts in "
	"direction with every heartbeat. The %^WHITE%^sky%^CYAN%^ is grey and filled with a "
	"%^MAGENTA%^smoky mist%^CYAN%^. %^BLUE%^Shadowy shapes%^CYAN%^ "
	"fly overhead in random "
	"erratic patterns. The two %^BOLD%^%^MAGENTA%^purple moons "
	"%^RESET%^%^CYAN%^fill the land with a faint eerie incandescent %^YELLOW%^light"
	"%^RESET%^%^CYAN%^.%^RESET%^\n"
	"%^BOLD%^%^RED%^There is a blood covered altar set into the muddy earth here.%^RESET%^"
    );
    set_listen("default",
        "The wind blows hard against your face, and a faint whispering coupled with a hollow moaning fills the mist."
    );
    set_smell("default",
        "There is a very foul and evil smell to this new land around you."
    );
    set_items(([
	"moon":"%^MAGENTA%^The two purple moons are very eerie to gaze upon and light the area with an "
	"incandescent glow.%^RESET%^",
 	"land":"You would have to enter the %^BLUE%^Shadowland%^RESET%^ to examine "
	"it closer.",
	"moons":"%^MAGENTA%^The two purple moons are very eerie to gaze upon and light the area with an "
	"incandescent glow.%^RESET%^",
	"shadows":"%^BLUE%^The shadows fill the land below and dance and stir in the wind.",
	"shapes":"%^CYAN%^The shapes move around you occasionally and are hard to make out. Every now and "
	"then a shadowy shape flies overhead.",
	"altar":"You recognize this blood covered altar as a device of summoning.",
    ]));
    set_exits(([
	"northeast": RPATH "s3",
    ]));
    set_pre_exit_functions(({"southwest"}),({"exita_fun"}));
    set_pre_exit_functions(({"west"}),({"exita_fun"}));
    set_pre_exit_functions(({"northeast"}),({"exita_fun"}));
}
int exita_fun() {
    write(
        "%^BLUE%^You slowly wander through the mist and walk among the shadows."	
    );
    say(
 	"%^BLUE%^"+TPQCN+" slowly wanders through the mist and walks among the shadows."
    ,TP);
    return 1;
}
int summon_fun(string str) {
    object stone;
    object ob1;
    if(!str) {
	notify_fail("Summon what?\n");
	return 0;
    }
    if(str != "beast") {
	notify_fail("Summon what?\n");
        return 0;
    }
    if(FLAG == 1) {
	notify_fail("Nothing happens!\n");
	return 0;
    }
    if(stone = present("stone_of_render",TP)) {
       write("%^BOLD%^%^RED%^"
	   "You hold the charcoal stone aloft and chant the words of summoning!%^RESET%^"
       );
       say("%^BOLD%^%^RED%^"
	   +TPQCN+" holds a charcoal stone aloft and chants some evil words!%^RESET%^"    
       ,TP);
       FLAG = 1;
       stone->remove();
       message("render", 
	   "%^RESET%^%^BLUE%^Dark storm clouds gather above and the wind begins to howl across the land!\n"
	   "%^YELLOW%^Lightning scorches across the sky and the air is charged with an evil energy!\n"
	   "%^RESET%^"
       ,users());
       find_object_or_load(RPATH "s19");
       ob1 = PLACE1;
       new( MPATH "render.c")->move(ob1);
       return 1;
    } else {
	notify_fail("Summon what?\n");
	return 0;
    }
}    
void reset() {
    ::reset();
    FLAG = 0;
}
