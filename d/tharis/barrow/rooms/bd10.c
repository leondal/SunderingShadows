#include <std.h>
#include "/d/tharis/barrow/short1.h"
inherit ROOM;
void create() {
    ::create();
   set_terrain(CEMETERY);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("outdoors",1);
    set_long( (:TO,"lng_fun" :) );
    set_short( (:TO, "shrt_fun" :) );
    set_listen("default",
 	"You hear a low, distant howl."
    );
    set_smell("default",
	"There is a distasteful odour in the air."
    );
    set_items(([
	"mound":"The mound is of the barrow type used to "
	"house the dead bodies of long lost warriors. You swear you can"
	" feel the dead awake beneath your feet.",
	"grass":"All the brush grass is dead and withered as though it was "
	"slowly strangled.%^RESET%^",
	"trees":"The dead trees creak in the blowing wind and probably are "
	"responsible for the eerie moaning sounds you hear.%^RESET%^",
        "fog":"%^BOLD%^%^CYAN%^The fog drifts around the burial mound."
	"%^RESET%^",
	"presense":"You can only feel the presense, not see it."
    ]));
    set_exits(([
	"south": RPATH "bd9",
        "west": RPATH "bd3",
	"east": RPATH "bd7",
	"north": RPATH "bd5",
        "northwest": RPATH "bd4",
	"northeast": RPATH "bd6",
	"southwest": RPATH "bd2",
	"southeast": RPATH "bd8",
        "down": RPATH "inner1"
    ]));
    set_pre_exit_functions(({"south"}),({"exit_fun"}));
    set_pre_exit_functions(({"east"}),({"exit_fun"}));
    set_pre_exit_functions(({"west"}),({"exit_fun"}));
    set_pre_exit_functions(({"north"}),({"exit_fun"}));
    set_pre_exit_functions(({"southwest"}),({"exita_fun"}));
    set_pre_exit_functions(({"southeast"}),({"exita_fun"}));
    set_pre_exit_functions(({"northwest"}),({"exita_fun"}));
    set_pre_exit_functions(({"northeast"}),({"exita_fun"}));
    set_pre_exit_functions(({"down"}),({"exitd_fun"}));

}
string lng_fun(string str) {
    if(random(10) > 0) {
	str =
            "%^BLUE%^You stand at the top of the large burial mound in the "
	    "%^WHITE%^ancient "
	    "burial field%^BLUE%^ known as the Barrow Downs. From here you "
	    "can view the surrounding grounds located around the mound. "
	    "It is difficult to clearly make out your surroundings as "
	    "much of the view from here is clouded in a strange fog. "
	    "However, one thing you are sure of is that some strange "
	    "presense is watching you. Furthermore, the ground beneath your "
	    "feet feels as though it is moving, as if some unearthly being "
	    "is awakening.%^RESET%^";	
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
	str = "%^BLUE%^Barrow Downs, Top of the Burial Mound.%^RESET%^";
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
int exit_fun() {
    if(TP->query_true_invis()) return 1;
    write("%^BOLD%^%^BLUE%^You clamber slowly down off the mound."
	  "%^RESET%^"
    );
    tell_room(TO,"%^BOLD%^%^BLUE%^"+TPQCN+" clambers down off the mound and "
	"into the surrounding fog.%^RESET%^"
    ,TP);
    return 1;
}	
int exita_fun() {
    if(TP->query_true_invis()) return 1;
    write("%^BOLD%^%^BLUE%^You feel a strange presense leave your mind "
	  "as you clamber down from the top of the mound."
	  "%^RESET%^"
    );
    tell_room(TO,"%^BOLD%^%^BLUE%^"+TPQCN+" chuckles and clambers down off the "
	"mound and into the surrounding fog.%^RESET%^"
    ,TP);
    return 1;
}	
int exitd_fun() {
    if(TP->query_true_invis()) return 1;
    write("%^BOLD%^%^BLUE%^You shudder and climb down into the burial "
	  "mound.%^RESET%^\n%^BOLD%^%^RED%^"
	  "A Voice tells you: %^RESET%^"
	  "Yes! Come closer "+TPQCN+"...and your soul I will own!!!"
    );
    tell_room(TO,"%^BOLD%^%^BLUE%^"+TPQCN+" slips through a hole and into the mound!"
        "%^RESET%^"
    ,TP);
    return 1;
}	

