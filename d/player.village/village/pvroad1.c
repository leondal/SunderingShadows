#include "/d/player.village/pvillage.h"
inherit ROOM;

void create(){
  ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Player Village Road");
    set_long(
		"This is the Player Village Road. \n"
	     	"It is the only road to and from the player village.\n"
	     	"South is the village. You are in a lightly wooded forest.\n"
		"%^CYAN%^There is a sign here.%^RESET%^");
    set_exits(([
	"north" : VILLAGE+"pvroad2",
	"south" : VILLAGE+"nroad5",
    ]));
   set_smell("default","You smell fresh air and the odor of wildflowers.");
   set_listen("default","You can hear birds singing.");
}
void init(){
	::init();
	add_action("read_it","read");

}
int read_it(string str){
	if(!str) return 0;
	if(str != "sign") return 0;

	write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-");
	write("%^BOLD%^%^GREEN%^     Player Village ");
	write("%^BOLD%^%^WHITE%^    ----------------\n");
	write("%^BOLD%^%^CYAN%^  The main office ->");
	write("%^YELLOW%^  Go:   s,e,e,e,e,n");
	write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-");
	
	return 1;
}
