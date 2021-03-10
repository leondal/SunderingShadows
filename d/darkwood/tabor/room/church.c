//updated by Circe 6/2/04 with color, etc
//#include "/d/shadow/room/shadow.h"
#include <std.h>
#include "../include/tabor.h"

inherit "/std/church";

void create() {
	::create();
	set_terrain(CITY);
	set_travel(DIRT_ROAD);
	set_name("Cathedral of St. Vala, Tabor");
	set_short("Cathedral of St. Vala, Tabor");
	set_long(
@TABOR
%^BOLD%^Cathedral of St. Vala, Tabor%^RESET%^
%^CYAN%^This cathedral is made of thick stone walls and a high vaulted 
ceiling reaching its apex in a %^ORANGE%^bell tower %^CYAN%^thirty feet overhead.  
The even masonry is broken only by colorful %^YELLOW%^s%^RESET%^%^ORANGE%^t%^BOLD%^%^RED%^a%^MAGENTA%^i%^CYAN%^n%^GREEN%^e%^BLUE%^d glass windows 
%^RESET%^%^CYAN%^depicting scenes of %^BOLD%^St. Vala %^RESET%^%^CYAN%^performing various duties about the 
land.  The windows are shaped like pointed domes, their tops reaching 
nearly to the base of the %^ORANGE%^bell tower%^CYAN%^.  The cathedral is a 
large square, with a long aisle carpeted in a %^MAGENTA%^wine-colored runner %^CYAN%^that 
leads between rows of %^ORANGE%^pews %^CYAN%^on either side.  The %^MAGENTA%^runner %^CYAN%^leads right to 
the foot of a large oblong %^ORANGE%^altar %^CYAN%^with a matching %^MAGENTA%^altar cloth%^CYAN%^.  In the 
center of the altar is a statue of %^BOLD%^St. Vala%^RESET%^%^CYAN%^, his head bowed in worship.%^RESET%^
TABOR
	);
	set_exits(([
		"west" : ROOMDIR+"vala2",
		"northwest" : ROOMDIR+"vala3",
	]));
	set_property("light", 2);
	set_property("indoors", 1);
	set_items(([
		"sign":"You should read it.",
		"chamber" : "People come here to pray for resurrection "
		"when they die.", 
            ({"windows","stained glass","stained glass windows"}) : "The "+
               "windows show St. Vala at various tasks, from tending the "+
               "sick and infirmed to helping rid what looks to be a "+
               "meadow of foul, invading beasts.  Strangely, no one "+
               "quite recalls exactly which deity St. Vala followed, "+
               "but in Tabor, all agree that he was an amazing man.  "+
               "The kings of Tabor have long claimed a direct descendence "+
               "from St. Vala, which they believe gives them the right "+
               "to rule.",
            ({"altar","altar cloth"}) : "The wooden altar has seen "+
               "many years.  It is well-tended and covered with a "+
               "wine colored altar cloth that protects its surface.",
            ({"statue","St. Vala","statue of St. Vala"}) : "The statue "+
               "on the altar depicts a human with long hair falling "+
               "about his shoulders.  His head is uncovered, and he "+
               "wears a suit of chainmail underneath a tabard.  The "+
               "tabard bears no symbol, however.  The saint's head "+
               "is bowed, and he has his eyes closed in prayer.",
            ({"runner","pews","rows of pews"}) : "Five rows of "+
               "pews march down the church on either side of a "+
               "long, wine-colored runner.  It seems that the church "+
               "is rarely full anymore, but it probably is for "+
               "special holidays or ceremonies.",
            ({"tower","bell","bell tower"}) : "A great iron bell "+
               "is housed overhead in the bell tower.  The bell "+
               "is rung every hour, giving those about a fair "+
               "idea of the time.  During holy days or important "+
               "ceremonies, the bell chimes a set number of times, "+
               "another way of communicating to the commoners what "+
               "is happening at the church."
	]) );
	set_listen("default", "It is very quiet.");
	set_smell("default","You smell the odor of a sweet incense.");
}

void reset(){
   ::reset();
   if(!present("Kenuric Offeriot")) find_object_or_load("/d/npc/kenuric")->move(TO);
}

