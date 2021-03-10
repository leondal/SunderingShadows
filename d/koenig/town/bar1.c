#include <std.h>

inherit ROOM;

string time;

void init() {
    ::init();
    add_action("read", "read");
}
void create() {
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
  set_short("%^BOLD%^%^RED%^Bloody Mary's Bar%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This building, though it has seen better days, is very much a bar. "+ 
"The %^ORANGE%^tables%^CYAN%^ are laid out in a rather random fashion and %^ORANGE%^chairs%^CYAN%^ are strewn about. There is a %^BOLD%^restaurant%^RESET%^%^CYAN%^ "+ 
"of sorts located to the east that looks like a rather interesting place to eat. All in all, it's "+ 
"not a pretty scene, but this is a place to be as social as you dare, and of course, to drink. There is a %^RESET%^menu%^CYAN%^ "+ 
"over the bar. %^BOLD%^%^MAGENTA%^Enjoy%^RESET%^%^CYAN%^!%^RESET%^\n");
    set_smell("default","You smell the odor of alcohol and food.");
    set_listen("default","You hear low mumbled conversation.");
    set_items(([
       "bar" : "Bloody Mary's Bar",
          "sign" : "The menu is posted there.",
          "menu" : "Maybe you should <read> the menu instead.",
		  "tables" : "The shoddy furniture sits where it was placed, without any real care given to order.",
		  "chairs" : "The shoddy furniture sits where it was placed, without any real care given to order.",
		  ]));
    set_exits( ([
       "out":"/d/koenig/town/room1",
        "restaurant":"/d/koenig/town/rest1"
]) );
}

void reset() {
  	::reset();
    	time = "daemon/events_d"->query_time_of_day();
    	if(time == "dawn" || time == "day"){
  		if(!present("barkeep"))new("/d/koenig/town/mon/mystra.c")->move(TO);
  		if(!present("drunk"))new("/d/koenig/town/mon/drunk.c")->move(TO);
	}else {
  	if(!present("scarlet"))new("/d/koenig/town/mon/scarlet.c")->move(TO);
  	if(!present("hyena"))new("/d/koenig/town/mon/hyena.c")->move(TO);
  	if(!present("barkeep"))new("/d/koenig/town/mon/mystra2.c")->move(TO);
  	}
}

int read(string str)
{
    object ob = present("barkeep");
    int i;
    if(str == "menu")
    {
        if(!ob)
        {
            write("The barkeeper is not here at the moment.");
            return 1;
        }
        say(""+TPQCN+" reads over the menu.");
        write(
"%^RED%^-<<-<>->>- %^BOLD%^%^RED%^Bloody Mary's Bar %^RESET%^%^RED%^-<<-<>->>-%^WHITE%^

   %^BOLD%^%^RED%^Bloody Mary Special   %^BOLD%^%^WHITE%^25 %^RESET%^Silver
   %^BOLD%^%^RED%^Red Wine              %^BOLD%^%^WHITE%^15 %^RESET%^Silver
   %^BOLD%^%^RED%^Bottle of Beer        %^BOLD%^%^WHITE%^10 %^RESET%^Silver
   %^BOLD%^%^RED%^Shot of Tequila       %^BOLD%^%^WHITE%^15 %^RESET%^Silver
   %^BOLD%^%^RED%^Glass of Pale Ale     %^BOLD%^%^WHITE%^10 %^RESET%^Silver

%^RED%^-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-%^WHITE%^");
        return 1;
    }
    return 0;
}