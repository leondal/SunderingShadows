//Mechanics by Bane, Atmosphere by Vis
#include <std.h>
inherit ROOM;
void create(){
    ::create();
set_name("%^BLUE%^Sparring Chamber of the %^RED%^%^BOLD%^Iron Fist.");
 set_short("Sparring Chamber");
    set_long(
"%^CYAN%^%^BOLD%^The Sparring Chamber of the %^RED%^Iron Fist%^RESET%^.\n"
"%^BLUE%^This domed chamber is where members of the %^RED%^Iron Fist%^BLUE%^ test each other's skills, and are judged for advancement by their leaders. The floor, like the curved walls, is made of a white marble, but it has been mottled and stained with the dark brown of long dried blood."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_property("arena",1);
set_light(2);
set_property("deathmove","/d/shadow/guilds/fist/guildheal.c");
set_listen("default","You hear the ghostly whispering of long dead warriors of the %^RED%^Iron Fist.");
set_smell("default","You smell the odor of the old blood that has long since dried into the fine brown patina on the floor.");
    set_exits( ([
  "west":"/d/shadow/guilds/fist/guild4.c",
  "north":"/d/shadow/guilds/fist/guild6.c"
    ]) );
}

void init(){
	::init();
	add_action("no_vials","drink");
	add_action("no_vials","quaff");
}

int no_vials(string str){
  if(!str || (str!="potion" && str!="vial" &&  str!="blue" && str!="kit"))
    return 0;
  else{
    tell_object(TP,"%^BOLD%^What? You want to use those in the middle of an arena fight? What a wimp!");
    tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" just tried to drink a healing potion. What a wimp!",TP);
    return 1;
  }
}
