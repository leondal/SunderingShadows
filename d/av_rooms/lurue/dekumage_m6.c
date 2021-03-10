// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";
int mysearch;

void create()
{
    ::create();
    set_name("dekumage_m6");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("decayed floor");
    set_climate("tropical");

    set_short("%^BOLD%^%^WHITE%^An old manor house%^RESET%^");

    set_long("%^RESET%^A large %^ORANGE%^wooden table %^RESET%^occupies the center of this room.  It's thick beams still displaying the delicate %^RED%^carvings %^RESET%^that once made this table incredibly beautif"
	"ul and valuable.  Further lining the room are %^CYAN%^glass trophy cases%^RESET%^, now caked in dirt and grime and missing whatever valuables they once held.  On the floor, a thick pile rug lays, as d"
	"irty and ruined as the rest of the house, and reeking of %^GREEN%^mildew%^RESET%^."
	);

    set_smell("default","The air smells of ruin and mold.");
    set_listen("default","The boards under your feet groan with your weight.");

    set_search("cases",(:TO,"search_fun":));
    set_search("case",(:TO,"search_fun":));
    
set_items(([ 
	({ "case", "cases" }) : "%^RESET%^%^CYAN%^They look like they've been emptied, but you never know, you might get lucky and find something interesting.%^RESET%^",
	({ "rug", "mildew" }) : "%^RESET%^%^GREEN%^The carpet is thick and plush, though time has decayed it and mildew has begun to grow across the once delicate forestry design.%^RESET%^",
	({ "carvings", "table" }) : "%^RESET%^%^ORANGE%^This table was created from thick timbers of ironwood, shaped and carved into intricate designs along the edge and left solid and polished across the top for a smooth dining surface.%^RESET%^",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/lurue/dekumage_m2",
		"east" : "/d/av_rooms/lurue/dekumage_m7",
	]));

    set_door("entry door","/d/av_rooms/lurue/dekumage_m1","west","manor_key","entry lock");
    add_lock("entry door","manor_key","entry lock","The lock is made of iron and looks to be in fairly good repair.");
    set_locked("entry door",1,"entry lock");
    lock_difficulty("entry door",-30,"entry lock");
    set_open("entry door",0);
    set_string("entry door","knock","pounds on the");
    set_string("entry door","open","You put your weight against the heavy wooden door and shove it open.");
    set_string("entry door","close","With a heave, you close the heavy wooden door.");
    set_door_description("entry door","%^RESET%^%^ORANGE%^This large wooden door is covered in fancy scrollwork and inset with delightful panels of amethyst glass.  Unfortunately, time and weather have swollen the wood to the point that the door is nearly wedged into the door jam.  Though, you do notice evidence of it having been opened recently. %^RESET%^");
   mysearch = 0;
}

int search_fun(string str) {
   object myob;
   if(!str) return 0;
   if(str != "cases" && str != "case") return 0;
   if(mysearch) {
     tell_object(TP,"It looks like someone has already searched there.");
     return 1;
   }
   tell_object(TP,"%^RESET%^%^ORANGE%^You open up all the cabinets hoping to find something interesting, and after completely covering yourself in dust during your search you come up with something that was clearly forgotten.%^RESET%^");
   tell_room(TO,"%^RESET%^%^ORANGE%^"+TP->QCN+" searches around and seems to find something.%^RESET%^",TP);
   myob = new("/d/common/obj/special/sp_randwpn");
   myob->move(TO);
   myob->remove_property("enchantment");
   myob->set_property("enchantment",random(2)+1);
   mysearch = 1;
   return 1;
}

void reset() {
   ::reset();
   mysearch = 0;
}