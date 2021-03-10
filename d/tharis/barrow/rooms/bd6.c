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
 	"You hear the hoot of an owl."
    );
    set_smell("default",
	"There is a distasteful odour in the air."
    );
    set_items(([
	"mound":"The large mound is of the barrow type used to "
	"house the dead bodies of long lost warriors.",
	"large mound":"The large mound is of the barrow type used to "
	"house the dead bodies of long lost warriors.",
        ({"hole","stonebrick hole","large stonebrick hole"}):
	"%^BOLD%^%^BLUE%^The hole into the large mound is dark and musty. "
	"You swear you hear voices in your mind as you gaze upon it.",
	"grass":"All the brush grass is dead and withered as though it was "
	"slowly strangled.%^RESET%^",
	"trees":"The dead trees creak in the blowing wind and probably are "
	"responsible for the eerie moaning sounds you hear.%^RESET%^",
    ]));
    set_exits(([
	"west": RPATH "bd5",
	"southwest": RPATH "bd10",
	"south": RPATH "bd7"
    ]));
    set_pre_exit_functions(({"southwest"}),({"exit_fun"}));
    set_pre_exit_functions(({"south"}),({"exit_fun"}));
    set_pre_exit_functions(({"west"}),({"exit_fun"}));
}
void init() {
    ::init();
    add_action("enter_hole","enter");
}
string lng_fun(string str) {
    if(random(10) > 0) {
	str = 
            "%^BLUE%^You stand within an %^WHITE%^ancient "
	    "burial field%^BLUE%^ northeast of a large burial mound. "
	    "To your "
	    "southwest is the top of the large burial mound. "
	    "In the side of the burial mound "
	    "is a large stonebrick hole. All around you dead and "
	    "withered %^ORANGE%^trees%^BLUE%^ stand creaking in "
	    "the wind. There is much brush "
	    "grass here, but it is dead as well.%^RESET%^";
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
	str = "%^BLUE%^Barrow Downs.%^RESET%^";
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
    write("%^BOLD%^%^BLUE%^A low wail is heard as you move through the "
	  "barrow downs.%^RESET%^"
    );
    tell_room(TO,"%^BOLD%^%^BLUE%^A low wail is heard as "+TPQCN+" gets a glazed "
	"and strange look on his face as "+TPSX+" wanders off.%^RESET%^"
    ,TP);
    return 1;
}	
int enter_hole(string str) {
    if(!str) {
	notify_fail("Enter what?\n");
	return 0;
    }
    if(str != "hole") {
	notify_fail("Enter what?\n");
	return 0;
    } else {
	write("%^BOLD%^%^BLUE%^You clamber down into the cold and dark "
	"hole.%^RESET%^"); 
	tell_room(TO,"%^BOLD%^%^BLUE%^"+TPQCN+" clambers down into the cold and dark "
       "hole.%^RESET%^",TP);
        TP->move_player( RPATH "mound4.c" );
	return 1;
    }
}    

void reset(){
  int r;
  ::reset();
  if(!present("chest")){
    r = random(2);
    if(r==0) new("/d/hm_quest/chests/chest7")->move(TO);
    else new("/d/hm_quest/chests/chest12")->move(TO);
  }
}
