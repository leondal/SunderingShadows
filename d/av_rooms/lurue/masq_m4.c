// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_name("masq_m4");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Land of %^WHITE%^Mist%^MAGENTA%^ and %^BOLD%^%^CYAN%^Dreams%^RESET%^");

    set_long("%^RESET%^%^MAGENTA%^Recessed into the wall, this balcony stretches all the way around the top of the ballroom in a horseshoe type shape.  Each end near the stage and the back half where the %^ORANGE%^"
	"stairs %^MAGENTA%^lead to.  Comfortable %^WHITE%^couches%^MAGENTA%^, plush and welcoming are arranged around the balcony, interspersed between are small %^BOLD%^%^BLACK%^intimate tables %^RESET%^%^MAG"
	"ENTA%^with upholstered chairs.  Beside the staircase a bar has been set up, providing food and drink to guests.   The walls are hung with %^BOLD%^%^BLACK%^dark drapes %^RESET%^%^MAGENTA%^that stand in"
	" contrast to the bright %^BOLD%^%^WHITE%^whites %^RESET%^%^MAGENTA%^and %^ORANGE%^golds %^MAGENTA%^of the ballroom but cause the balcony to feel intimate and private.%^RESET%^"
	);

    set_smell("default","
A faint, rich scent of flowers and earth lingers here.");
    set_listen("default","You can hear the pleasant sounds of laughter and conversation.");

    
set_items(([ 
	({ "drapes", "dark drapes", "drape" }) : "%^BOLD%^%^BLACK%^Recessed as the balcony is, the drapes give it an even darker feeling, close and intimate.  A stark contrast to the brightness of the ballroom and the rest of the manor.  Thick velvet, the curtains draw in the sound and muffle conversations, making this a nice quiet spot to rest after the whirlwind of dancing and performing.%^RESET%^",
	({ "tables", "chairs", "table", "chair", "couches", "couch" }) : "%^BOLD%^%^WHITE%^Set around in small groups or individually, small couches have been arranged to give comfortable sitting places for watching the ballroom and the stage.  Interspersed between those couches are little iron tables with upholstered chairs that offer even more intimate settings for those not as interested in watching the goings on.%^RESET%^",
	({ "stair", "stairs" }) : "%^RESET%^%^MAGENTA%^A sweeping curve of stairs rises up to the back of the ballroom, leading up to a large horseshoe shaped balcony that is recessed back into the wall, leaving the ballroom itself open with high ceilings.%^RESET%^",
	"bar" : "%^BOLD%^%^WHITE%^Beside the stairs a bar has been set up.  The dark marble of the counter blending well with the dark drapes that line the balcony.  Faintly illuminated with soft fairy light, there are no stools at the bar as it appears to simply be a place of service and not a dining spot.%^RESET%^",
	]));

    set_exits(([ 
		"ballroom" : "/d/av_rooms/lurue/masq_m2",
	]));

}

void reset(){
   ::reset();
   if(!present("stage")) new("/d/av_rooms/lurue/masq/stage2")->move(TO);
   if(!present("ghostly waiter")) new("/d/avatars/nienne/party/attendant")->move(TO);
}

void init(){
::init();
add_action("read","read");
}

int read(string str){
object obj;
int i;
string *names;
obj = present("ghostly waiter");
if(str == "menu") {
say(""+TPQCN+" reads over the menu.");
message("Ninfo","You pick up a menu from the bar's countertop and read over:\n"+
"%^GREEN%^===================================================================\n",TP);
message("Ninfo"," %^RESET%^%^MAGENTA%^Dragonblood%^RESET%^ \t\t "+
" "+(int)obj->get_price("dragonblood")+" silver pieces\n",TP);
message("Ninfo"," %^RESET%^%^MAGENTA%^Tortured Toddy%^RESET%^ \t "+
" "+(int)obj->get_price("tortured toddy")+" silver pieces\n",TP);
message("Ninfo"," %^RESET%^%^MAGENTA%^Witch Brew%^RESET%^ \t\t "+
" "+(int)obj->get_price("witch brew")+" silver pieces\n",TP);
message("Ninfo"," %^RESET%^%^MAGENTA%^Spiced Mist%^RESET%^ \t\t "+
" "+(int)obj->get_price("spiced mist")+" silver pieces\n",TP);
message("Ninfo","%^GREEN%^===================================================================\n",TP);
message("Ninfo"," %^RESET%^%^MAGENTA%^Pumpkin Seed Brittle%^RESET%^ \t  "+
" "+(int)obj->get_price("pumpkin seed brittle")+" silver pieces\n",TP);
message("Ninfo"," %^RESET%^%^MAGENTA%^Yummy Mummy%^RESET%^ \t\t "+
" "+(int)obj->get_price("yummy mummy")+" silver pieces\n",TP);
message("Ninfo"," %^RESET%^%^MAGENTA%^Spider Bites%^RESET%^ \t\t "+
" "+(int)obj->get_price("spider bites")+" silver pieces\n",TP);
message("Ninfo","%^GREEN%^===================================================================\n",TP);
return 1;
}
}