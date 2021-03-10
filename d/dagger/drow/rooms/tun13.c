#include "/d/dagger/drow/short.h"
#include <std.h>
inherit "/std/room";
void create() {
    ::create();
   set_terrain(NAT_TUNNEL);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^Fog filled room%^RESET%^");
    set_long(
	"%^RED%^This room is billowing with the red fog. You can barely "
	"make out your surroundings but can see it is about twenty feet "
	"in diameter and is bare of any details. Your mind is spinning "
	"from the constant bombardment of whispering coming to you in "
	"unintelligble languages.\n%^BLUE%^You think you are losing "
	"your sanity bit by bit.%^RESET%^"
    );
    set_listen("default","The whispers scream into your mind.");
    set_items(([
	"lichen":"%^MAGENTA%^The lichen is of a very unusual type and "
	"seems to provide the light source within the cavern tunnel.%^RESET%^",
	"fog":"%^RED%^The fog fills the room and makes your vision play "
	"tricks on you.%^RESET%^",
	"walls":"The walls are bare stone and obviously have been carved "
	"through the mountain. Glowing %^MAGENTA%^lichen%^RESET%^ grows on "
	"the walls here."
    ]));
    set_exits(([
	"west": RPATH "tun12"
    ]));
}
void reset() {
    ::reset();
    if(!present("mindflayer")) {
	write(
	    "%^BLUE%^A Mindflayer wanders slowly into the "
	    "cavern chamber.%^RESET%^"
	);
	new( MPATH "mflayer")->move(TO);
    }
    if(!present("drow")) {
	write(
	    "%^BLUE%^Drow guards enter the room and take up their "
	    "posts.%^RESET%^"
	);
	new( MPATH "drowg")->move(TO);
	new( MPATH "drowg")->move(TO);
    }
}
