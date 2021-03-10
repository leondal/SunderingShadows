#include <std.h>
#include "/d/tharis/barrow/short1.h"
inherit ROOM;

void create() {
    ::create();
   set_terrain(CEMETERY);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("outdoors",1);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_listen("default",
 	"You hear a low, distant howl."
    );
    set_smell("default",
	"There is a distasteful odour in the air."
    );
    set_items(([
	"mound":"The mound in the distance is of the barrow type used to "
	"house the dead bodies of long lost warriors.",
	"grass":"All the brush grass is dead and withered as though it was "
	"slowly strangled.",
	"trees":"%^ORANGE%^The dead trees creak in the blowing wind "
	"and probably are "
	"responsible for the eerie moaning sounds you hear.%^RESET%^",
    ]));
    set_exits(([
//     "south" : "/d/tharis/road/wroad25",
	"north": RPATH "bd9",
      "east" : RPATH"bpath1"
    ]));
    set_pre_exit_functions(({"north"}),({"exit_fun"}));
}
string lng_fun(string str) {
    if(random(10) > 0) {
	str = 
            "%^BLUE%^You have entered into an %^WHITE%^ancient "
	    "burial field%^BLUE%^. You quickly question your sanity for "
	    "coming here. This looks to be a truly evil place. "
	    "All around you dead and withered %^ORANGE%^"
	    "trees%^BLUE%^ stand creaking in the wind. There is much brush "
	    "grass here, but it is dead as well. Ahead of you to the north "
	    "stands a large mound.  To the east is a narrow path that "+
          "winds through the scrubland.%^RESET%^";
    } else {
	str = 
	    "%^BOLD%^%^BLUE%^You are suddenly seized be a sharp pain "
	    "inside your head. Your vision becomes pitch black and you "
	    "fall to the ground screaming in pain. Your body begins to "
	    "writhe in agony and you taste dirt in your mouth.\n\n"
	    "%^RED%^A Voice tells you: "
	    "%^RESET%^Welcome "+TPQCN+". You have entered "
	    "my domain now and i wanted you to know i am aware of your "
	    "presence. I can control your body and mind as i wish...but "
	    "soon i will control your soul!\n\n%^BOLD%^%^BLUE%^"
	    "Suddenly, as fast as it came, the pain vanishes and you slowly "
	    "regain control of your body and mind. You have difficulty "
	    "remembering where you were and where you were going prior to "
	    "the strange possession.%^RESET%^";
    }
    return str;
}
string shrt_fun(string str) {
    if(random(10) > 0) {
	str = 
            "%^BLUE%^Barrow Downs' Entrance%^RESET%^";
    } else {
	str = 
	    "%^BOLD%^%^BLUE%^You are suddenly seized be a sharp pain "
	    "inside your head. Your vision becomes pitch black and you "
	    "fall to the ground screaming in pain. Your body begins to "
	    "writhe in agony and you taste dirt in your mouth.\n"
	    "%^RED%^A Voice tells you: "
	    "%^RESET%^Welcome "+TPQCN+". You have entered "
	    "my domain now and i wanted you to know i am aware of your "
	    "presence. I can control your body and mind as i wish...but "
	    "soon i will control your soul!\n\n%^BOLD%^%^BLUE%^"
	    "Suddenly, as fast as it came, the pain vanishes and you slowly "
	    "regain control of your body and mind. You have difficulty "
	    "remembering where you were and where you were going prior to "
	    "the strange possession.%^RESET%^";
    }
    return str;	
}

int exit_fun() {
    if(TP->query_true_invis()) return 1;
    write("%^BOLD%^%^RED%^A slow chill runs down your spine as you enter "
	  "into the barrow downs.%^RESET%^"
    );
    tell_room(TO,"%^BOLD%^%^RED%^"+TPQCN+" slowly walks north into the barrow "
	"downs. You hear a low cackle from off in the distance.%^RESET%^"
    ,TP);
    return 1;
}	
