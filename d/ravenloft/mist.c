// Coded by Bane
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("mist");
    set_short("A thick Mist");
    set_long(
	"You have wandered into a thick mist.  The area around you is dull "+
	"and lifeless, visibility is only about 10 feet.  For some "+
	"reason you can't see the ground or anything above you.  It "+
	"almost appears as if you are trapped in some misty bubble."
    );
    set_smell("default","The mist smells of decaying flesh.");
    set_listen("default","Only the howling of the wind can be heard.");
    set_property("indoors",1);
    set_property("light",2);
    set_exits( ([
	"out":"/d/shadowgate/adv_main"
    ]) );
    set_heart_beat(1);
}
void heart_beat(){
    int i;
    i = random(100);
    switch(i){
	case 1..90:
	    break;
	case 91..93:
	    tell_room(TO,"%^MAGENTA%^A strange voice says%^RESET%^: Enter the mist...");
	    break;
	case 94..95:
	    tell_room(TO,"%^CYAN%^Someone whispers to you%^RESET%^: Step into the mist and your wildest dreams will come true...");
	    break;
	case 96:
	    tell_room(TO,"The mist seems to beckon you forth.");
	    break;
	case 97:
	    tell_room(TO,"A pair of red eyes jumps into and out of view within the mist.");
	    break;
	case 98:
	    tell_room(TO,"%^MAGENTA%^A low, deep voice says%^RESET%^: Come forth, enter the mist...");
	    break;
	case 99:
	    tell_room(TO,"%^MAGENTA%^A cackling voice screams%^RESET%^: The mist commands you forward!  Do so now or live in eternal damnation!");
	    break;
    }
}
