// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("aash_trail15");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("branches");
    set_travel("rutted track");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^D%^BOLD%^a%^RESET%^%^MAGENTA%^rk %^BOLD%^%^GREEN%^G%^RESET%^%^GREEN%^r%^CYAN%^o%^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^t%^CYAN%^o%^RESET%^ ");

    set_long("%^BOLD%^%^GREEN%^The trees in this %^RESET%^%^MAGENTA%^g%^BOLD%^r%^RESET%^%^MAGENTA%^o%^BOLD%^t%^RESET%^%^MAGENTA%^t%^BOLD%^o%^BOLD%^%^GREEN%^ are covered in a %^RESET%^%^CYAN%^p%^MAGENTA%^u%^CYAN%^l%"
	"^MAGENTA%^s%^CYAN%^a%^MAGENTA%^t%^CYAN%^i%^MAGENTA%^n%^CYAN%^g%^BOLD%^%^GREEN%^ fungus that seems to creep and crawl before your very eyes. The %^RESET%^%^CYAN%^mold%^BOLD%^%^GREEN%^ itself appears gr"
	"een, and the trees here smell of %^RESET%^%^ORANGE%^rot.%^BOLD%^%^WHITE%^ Skeletons%^GREEN%^ seem to be all thats left of the few animals that unwisely wandered into this place. In the middle of this "
	"pestilential grotto is a giant %^RESET%^%^MAGENTA%^w%^BOLD%^i%^RESET%^%^MAGENTA%^ll%^BOLD%^o%^RESET%^%^MAGENTA%^w t%^BOLD%^r%^RESET%^%^MAGENTA%^ee%^BOLD%^%^GREEN%^ that seems to almost be %^WHITE%^cre"
	"ating%^GREEN%^ the fungus rather than just feeding it.%^RESET%^"
	);

    set_smell("default","
It smells of fungus.");
    set_listen("default","You hear the pulsating fungus creeping over the trees, the ground everything!");

    set_search("skeletons"," The bleached bones have no secrets to reveal.");
    set_search("mold","Yuck there is nothing in the mold, are you crazy?!");
    set_search("rot","Yuck there is nothing in the mold, are you crazy?!");
    set_search("willow tree","The willow tree does not look like it would allow a search ... it seems almost hungry!");
    set_search("trees","You find little in the trees or underbrush. A quick search of the pine needles reveal little but the earth and roots.");
    set_search("skeleton"," The bleached bones have no secrets to reveal.");
    set_search("tree","The trees are just decayed wood covered in mold and fungus.");
    set_search("needles","You find little in the trees or underbrush. A quick search of the pine needles reveal little but the earth and roots.");
    set_search("path","A search of the path reveals that it seems no one has walked this way in a very long time. Somehow the creatures beyond have not been able to find this place.");
    set_search("animals","There are no animals around.");
    set_search("underbrush","You find little in the trees or underbrush. A quick search of the pine needles reveal little but the earth and roots.");
    
set_items(([ 
	"skeletons" : "There is nothing left on the bones except the random bit of fungus.",
	"fungus" : "The fungus seems to be moving under its own power!",
	"mold" : "The mold seems to be moving under its own power!",
	"trees" : "The trees here are all dead or dying. ",
	]));

    set_exits(([ 
		"out" : "/d/av_rooms/myrkul/aash_trail13",
	]));

}