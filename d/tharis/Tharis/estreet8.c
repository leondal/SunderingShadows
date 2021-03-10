#include <std.h>

inherit ROOM;

void help_comes();

void init(){
	int i;
	
	::init();

	do_random_encounters(({"/d/tharis/monsters/ehater"}),30,3);
	
	if(present("elf hater") && !present("elven citizen") && !present("ruffian 2"))
		call_out("help_comes",15);
}

void create(){
	::create();
	set_terrain(CITY);
	set_travel(PAVED_ROAD);

	set_property("light",2);
	set_property("indoors",0);
	set("short","Main street through the elven quarter");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^Main street through the elven quarter%^RESET%^
As you walk through the elven quarter you continue to notice the 
fine lines of elven architecture. The street lacks people. The crowds
that are omnipresent in the main portion of Tharis cannot be found
here. Every now and then a group of people can be seen huddled.
Here and there you hear whispers directed toward you....
...%^YELLOW%^fear%^RESET%^...%^GREEN%^wonder%^RESET%^...but never %^BOLD%^%^RED%^hate%^RESET%^.
OLI
	);
	set_exits(([
		"west":"/d/tharis/Tharis/estreet7",
		"east":"/d/tharis/Tharis/estreet9"
	]));
	set_items(([]));
   set_smell("default","The sweet fragrances of nature are strangely present here in the city.");
	set_listen("default","Mumbles and whispers reach your ears.");
}

void help_comes() {
	int i,j;
	object ob,ob2;
	string es;
	if(!present("elf")){
		i = random(10);
		if(i < 2){
			i = random(4) + 1;
			for(j=1;j <= i;j++){
				ob = new("/d/tharis/monsters/elfsave");
				ob->move(TO);
				if(ob2 = present("elf hater"))
					ob->kill_ob(ob2,1);
			}
			if(i == 1) 
			tell_room(TO,"%^BOLD%^%^YELLOW%^An elf comes to help you.");
			else if(i > 1)
			tell_room(TO,"%^BOLD%^%^YELLOW%^"+i+" elves come to help you.");
		}			
	}
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/