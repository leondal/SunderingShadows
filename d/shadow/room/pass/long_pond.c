//Written by Longman.
//Please ask for permission before copying this file to your area!
//The number of ponds needs to be regulated.

#include <std.h>
#include <objects.h>

inherit "std/pier";

void init() {
  ::init();
  add_action("take", "take");
}

void create() {
    ::create();
    set_light(2);
    set_short("%^BOLD%^%^BLUE%^A small fishing hole%^RESET%^");
    set_long("%^BOLD%^%^BLUE%^A small fishing hole%^RESET%^\n%^RESET%^%^CYAN%^Set back from the main road is this small, "+ 
	"%^GREEN%^serene%^CYAN%^ pond. The calm surface of the "+ 
	"%^BOLD%^%^BLUE%^water%^RESET%^%^CYAN%^ reflects the "+ 
	"tall %^BOLD%^%^GREEN%^trees%^RESET%^%^CYAN%^ that rise up all "+ 
	"around you. Lush %^BOLD%^%^GREEN%^bushes%^RESET%^%^CYAN%^ nestled around large stones adds to the lovely landscape. Some %^BOLD%^%^BLACK%^rocks%^RESET%^%^CYAN%^ and "+ 
	"%^ORANGE%^logs%^RESET%^%^CYAN%^ have been placed around "+ 
	"the pond as makeshift seats, and a nearby "+
	"%^BOLD%^%^BLACK%^f%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^re%^RED%^p%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^ "+ 
	"can be used to cook your catch. A %^ORANGE%^trough%^RESET%^%^CYAN%^ sits off to one "+
	"side, filled with free fishing poles for those who forgot to bring their own.\n");
set_smell("default","The air is fresh and smells of trees.");
set_listen("default","Birds sing cheerfully high up in the braches.");
    set_exits(([
    "west":"/d/shadow/room/pass/pass4",
     "northeast":"/d/shadow/room/pass/road1",
    ] ));
    set_items(([
"pond" : "The pond is just the right size. It is filled with shiny fish, darting about beneath the calm surface.",
       "fish" : "They swim about, oblivious to anything else.",
	   "trough" : "The wooden trough seems to have an endless supply of fishing poles. Perhaps you could take one.",
	   "firepit" : "This is a simple ring of blackened stones placed around piles of ashes. Perhaps you could <gather> some wood and <start> a fire?",
	   "trees" : "Standing tall, the trees envelop the small clearing, creating a hideaway from the hectic world.",
	   "bushes" : "The bushes are thick enough to nearly obscure the big pile of stones.",
	   "stones" : "They are quite large, and pitted with cracks and crevices.",
	   ({"logs","rocks","seats"}) : "Looks like a nice place to sit and relax for awhile.",
    ] ));
//	set_search("crevices","One of the crevices looks particularly wide and deep, perhaps enough so to enter it?");
set_max_fishing(4);
set_chance(17);
set_max_catch(6);
set_fish( ([ "Issaquah Trout": 3, "Big Kahuna": 10 ]) );
}

int take(string str) {
	object ob;
    if(!stringp(str)) { return 0; }
    if(str == "fishing pole" || str == "pole")
	{
ob = new("/d/shadow/obj/misc/fishing_pole.c");
ob->move(TP);
write("You select a nice fishing pole from the trough.");
say(this_player()->query_cap_name()+" selects a nice fishing pole from the trough.", this_player());
return 1;
}
}
