#include <std.h>

inherit ROOM;

void help_comes();

void init(){
	int i;
	
	::init();

	do_random_encounters(({"/d/tharis/monsters/ehater"}),30,5);
	
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
From this portion of the street you see to the east the east gate. You
feel slightly safer here. Thinking that the ruffians might not attack
you with city guards only a block away. The problems of the elven quarter
are evident around you. But the ornate building and the finely curved 
architecture cannot be hidden by burn marks and garbage.
OLI
	);
	set_exits(([
		"west":"/d/tharis/Tharis/estreet8",
		"east":"/d/tharis/Tharis/estreet10"
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