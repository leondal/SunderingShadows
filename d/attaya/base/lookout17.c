
#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

#define MAX 3
int num, num2, i;
int flag;

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_property("no teleport", 1);
    set_short("Inside the walls of the Tower of the Black Dawn.");
    set_long(
      "This plain stone room is a storage area.  A few benches and shelves line the walls.  there isn't much here, though."
    );

    set_exits( ([
	"north" : "/d/attaya/base/lookout13",
      ]) );
    set_items(([
	"benches" : "Wooden benches are built into the north, south, and east walls.",
	"shelves" : "They contain various items of no real use to you.",
      ]));

}
void init(){
    ::init();
    if(flag) return;
    flag++;
    tell_room(ETP, "%^BOLD%^Hrm, looks like someone forgot somthing here.\n");
    num = random(MAX)+1;
    for(i=0;i<num;i++){
	num2 = random(10);
	switch (num2){
	case 0:
	    new("/d/shadow/obj/misc/schest")->move(TO);
	    break;
	case 1:
	    new("/d/shadow/obj/misc/lkchest")->move(TO);
	    break;
	case 2:
	    new("/d/tharis/obj/bpowder")->move(TO);
	    break;
	case 3:
	    new("/d/dagger/drow/obj/sphere")->move(TO);
	    break;
	case 4:
	    new("/d/dagger/drow/obj/cylinder")->move(TO);
	    break;
	case 5:
	    new("/d/deku/armours/hide")->move(TO);
	    break;
	case 6:
	    new("/d/antioch/armour/robes")->move(TO);
	    break;
	case 7:
	    new("/d/shadow/obj/misc/beacon")->move(TO);
	    break;
	case 8:
	    new("/d/dagger/road/obj/Mcoif")->move(TO);
	    break;
	case 9:
	    new("/d/attaya/mon/banisher")->move(TO);
	    break;

	}
    }
}

void reset(){
    ::reset();
    flag = 0;
}
