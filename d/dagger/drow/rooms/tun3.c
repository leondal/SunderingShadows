#include <std.h>
inherit ROOM;
int FLAG;
void create() {
    ::create();
   set_terrain(NAT_TUNNEL);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^Dark cavern tunnel%^RESET%^");
    set_long("%^BLUE%^The tunnel opens into an intersection here and has "
	"the same exotic %^MAGENTA%^lichen%^BLUE%^ as before. A "
	"%^RED%^bloody%^BLUE%^ scene greets you here as a slaying has "
	"occurred in this intersection earlier. "
	"The corpse of a human slain in battle lays on the ground before "
	"you. The positioning of the dead body seems to indicate that it "
	"was slashed by sword and dagger as it attempted to crawl in "
	"desperation from its slayers. A look of tormented horror fills "
	"the corpse's eyes and the coloration of its skin tends to make "
	"you think it had not seen the sunlight for months.%^RESET%^"
    );
    FLAG = 0;
    set_smell("default","It reeks of blood and evil.");
    set_items(([
	"lichen":"%^MAGENTA%^The lichen is of a very unusual type and seems "
	"to provide the light source within the cavern tunnel.%^RESET%^",
	"corpse":"The corpse is fresh and is that of a human. The body has "
	"been slashed to death by sword and dagger. Even as he died, it is "
	"apparent that he continued to attempt to crawl away from his "
	"attackers.",
	"eyes":"Even in death the corpse's eyes are filled with horror.",
	"skin":"The skin on the corpse is extremely pale, but not from death, "
	"from lack of sunlight.",
	"walls":"The walls are bare stone and obviously have been carved "
	"through the mountain. Glowing %^MAGENTA%^lichen%^RESET%^ grows "
	"on the walls here."
    ]));
    set_exits(([
	"northwest":"/d/dagger/drow/rooms/tun9",
	"east":"/d/dagger/drow/rooms/tun5",
	"south":"/d/dagger/drow/rooms/tun2",
	"north":"/d/dagger/drow/rooms/tun4"
    ]));
}

int search (string str) {
    if(str != "corpse") {
        notify_fail ("Search what?");
	return 0;
    }
    if(FLAG == 0) {
        FLAG = 1;
	message("my_action",
	    "%^BLUE%^You search the corpse and find some odd gems!%^RESET%^",TP);
	message("other_action",
	    "%^BLUE%^"+TPQCN+" searches the corpse and finds some odd gems!%^RESET%^"
	,environment(TP),TP);
// 	new("/d/dagger/drow/obj/blcloak")->move(TO);
// Put the cloaks on the hunters (1/10 chance) so they have to fight at least
// and fixed a couple of typos.   Styx 7/15/01
    new("/d/dagger/drow/obj/drow_gem")->move(TO);
    new("/d/dagger/drow/obj/drow_gem")->move(TO);
	return 1;
    } else {
	tell_object(TP,"There is nothing left of value on the corpse.");
	return 1;
    }
}

void reset() {
    ::reset();
    if(!present("drow hunter")) {
	new("/d/dagger/drow/mon/drowh")->move(TO);
	new("/d/dagger/drow/mon/drowh")->move(TO);
	write("%^BLUE%^Two drow enter and examine a corpse.%^RESET%^");
        FLAG = 0;
    }
}

void init()
{
   ::init();
   add_action("search","search");
   if(present("drow hunter 2")) present("drow hunter 2")->force_me("block east");
   if(present("drow hunter")) present("drow hunter")->force_me("block east");
}

