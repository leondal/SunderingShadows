//hut  - Essyllis - May - 2014


#include <std.h>
#include "../lgnoll.h"
#define RANDSTUFF "/d/common/daemon/randstuff_d"

inherit CROOM;
int tablex;

void create() {

    set_repop(70);
    ::create();
    set_terrain(STONE_BUILDING);
	tablex=0;
    set_travel(PAVED_ROAD);
	set_property("indoor",1);
    set_property("light",2);
    set_name("hut");
    set_short("BloodFangs Hut.");
    set_long("%^GREEN%^This hut is indeed much larger and in must better state than the rest of the "+
	"%^BOLD%^%^BLACK%^huts%^RESET%^%^GREEN%^. %^BOLD%^%^RED%^B%^RESET%^%^RED%^lood%^BOLD%^F%^RESET%^%^RED%^ang "+
	"%^GREEN%^is obviously an important member of this %^ORANGE%^gn%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^ll p%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^ck%^GREEN%^. "+
	"Even though the %^BOLD%^%^BLACK%^hut %^RESET%^%^GREEN%^is in better shape it is by no means what a civilized "+
	"person would call livable. A %^ORANGE%^large bed %^GREEN%^in by the eastern wall has been assembled with roughly "+
	"cut wooden boards. A %^ORANGE%^large table %^GREEN%^in the middle of the room is in perfect condition and very well "+
	"crafted. Besides the opening you just entered from, there is just one large window in the back of the hut.%^RESET%^\n");
    set_smell("default","%^ORANGE%^There is a foul stench of rotting flesh, but not from in here.%^RESET%^");
    set_listen("default","%^BOLD%^%^BLACK%^You hear a constant buzzing from somewhere close by. Sounds like thousands of insects.%^RESET%^");
	set_exits((["out":ROOMS"23"]));
    set_items
    (([	
        ({"floor", "ground"}) : "%^MAGENTA%^The ground is hard-stamped soil. Only under the window in the far end of the hut there is a %^RED%^red taint%^MAGENTA%^ to the soil.",
        ({"wall", "walls"}) : "%^RESET%^%^ORANGE%^The walls in here are made from various sorts of wooden planks. Crude but it makes a home.",
        ({"bed"}) : "%^GREEN%^This bed seem to have been made from the same planks of wood as the walls. Very crude but they seem sturdy enough. Dried grass is used for a mattress and furs from various creatures, skinned with horrible craftsmanship, for blankets.",	
                ({"table"}) : "%^ORANGE%^The table is remarkably well-crafted and telling from the design, obviously of asgardian origin. Various items lay shattered on the table",
		({"window"}) : "The window is at the far end of the hut. As you get closer you can hear the buzzing of insects getting stronger. So does the smell. Are you sure you want to glance out the window?",
    ]));
	
	set_search("bed","%^MAGENTA%^Nothing here, except the foul stench of wet gnoll.");
	set_search("table",(:TO,"tablez":));
	set_search("window","%^GREEN%^Well, it's a window. You could take a glance out of the window?");
	
	
}	




string tablez(){
	if(tablex){
		write("%^ORANGE%^Only garbage here. If there were anything useful, it is elsewhere now.");
	return 1;}
	write("%^ORANGE%^Looks like there could be some items worth something, you could try to rummage through them.");
	return 1;}

void init(){
		::init();
	add_action("glance","glance");	
	add_action("rummage","rummage");
	add_action("jump","jump");
}	
		
int rummage(string str){
	if(!str){notify_fail("What do you want to search?"); return 0;}
	if(str != "table"){notify_fail("You find nothing."); return 0;}
	if(tablex){notify_fail("%^ORANGE%^Only garbage here. If there were anything useful, it is elsewhere now"); return 0;}
	tablex=1;
	tell_object(TP,"%^MAGENTA%^%^ORANGE%^Looks like BloodFang collected spoils from his last 'dinner' on this table.");
	tell_room(ETP,TP->QCN+" %^MAGENTA%^rummages through the items on the table.",TP);
	RANDSTUFF->find_stuff(TO,"highscroll");
	RANDSTUFF->find_stuff(TO,"midscroll");
	RANDSTUFF->find_stuff(TO,"coins");
	if(random(1000) < 333) {new(OBJ"worg_tooth")->move(TO);}
	return 1;
}

void reset(){
   ::reset();
   tablex=0;
   switch(random(5)){
      case 0..2:  tell_room(TO,"%^BOLD%^%^BLACK%^You hear a %^ORANGE%^li%^RED%^o%^ORANGE%^n's "+
	  "%^RED%^roar %^BLACK%^followed by the death-cry of a %^RESET%^%^ORANGE%^gnoll.");
               break;
      case 3..4:  tell_room(TO,"%^ORANGE%^A %^CYAN%^gust of wind blows %^ORANGE%^through the "+
	  "camp, lifting the %^BOLD%^%^BLACK%^stink %^RESET%^%^ORANGE%^of %^MAGENTA%^death %^ORANGE%^and "+
	  "%^MAGENTA%^decay %^ORANGE%^for a precious few seconds.");
               break;
      case 5:  tell_room(TO,"%^BOLD%^%^BLACK%^A %^RED%^horrible death cry %^BLACK%^of another of the "+
	  "gnolls' victims can he heard from somewhere in the camp.");
               break;
         }
}


int glance(string str){
		if(!str){notify_fail("glance out of what?"); return 0;}
                if(str != "out of window" && str != "out window" && str != "out the window" && str != "out of the window"){notify_fail("You glance at "+str+" for a moment."); return 0;}
		tell_object(TP,"%^RED%^You can see out of the window and are almost pushed back by the rancid smell. It looks to be a backyard of sorts except there is blood splattered everywhere! You could jump out of the window if you really wanted.");
		tell_room(ETP,TP->QCN+" covers "+TP->QP+" nose as "+TP->QS+" glances out the window",TP);
		return 1;
}

int jump(string str){
	if(!str){notify_fail("You jump around a little"); return 0;}
	if(str != "out of window"){notify_fail("What do you want to jump out of?"); return 0;}
	if(str == "bed"){
	tell_object(TP,"You jump up and down in the crude gnoll bed ... not as fun as you had hoped.");
	tell_room(ETP,TP->QCN+" jumps up and down in the crude gnoll bed for some reason?",TP);
	return 1;}	
	tell_object(TP,"You hold your breath as you jump out the window.");
	tell_room(ETP,TP->QCN+" jumps out of the window in the back of the hut.",TP);
	TP->move(ROOMS"backyard");
	TP->describe_current_room(1);
	
	return 1;
}

	
