//changed pre-exit function to check for "drowmon" rather than just drow and 
//added to allow true_invis avatars through also  *Styx*  12/22/01

#include "/d/dagger/drow/short.h"
#include <std.h>
inherit "/std/room";
void create() {
    ::create();
   set_terrain(NAT_TUNNEL);
   set_travel(LEDGE);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^At the top of a cavern rift%^RESET%^");
    set_long("%^BLUE%^Now you have come to the top of a cavern rift. "
	"Cobble stepping stairs lead down the side of the rift from "
	"here to a plateau one hundred feet below. Looking out from the "
	"rift the scene of magnificant proportions unfolds. The cavern "
	"has widened into a huge underground hollowed out pocket. At the "
	"bottom of the rift, in this massive cavern chamber, lies a "
	"%^BOLD%^%^BLUE%^deep blue lake%^RESET%^%^BLUE%^. Found in the "
	"center of this lake is a very large %^RED%^island%^BLUE%^. "
	"Covering the %^RED%^island%^BLUE%^ is a %^CYAN%^city%^BLUE%^. "
	"Cobblestone paths wind through the city, and quite a few buildings "
	"scatter the %^RED%^island%^BLUE%^ as well. All the buildings are "
	"constructed of giant %^MAGENTA%^marble slabs%^BLUE%^. However, "
	"your attention is drawn most to the giant "
	"%^BOLD%^%^WHITE%^temple%^RESET%^%^BLUE%^ constructed "
	"completely of %^BOLD%^%^WHITE%^black polished stone%^RESET%^%^BLUE%^ "
	"located in the center of the city. It looms far above the other buildings "
	"on the island and you feel very uneasy as you gaze at it."
    );
    set_listen("default","You hear far away chanting.");
    set_smell("default","Your senses tell you that you are being watched by "
	"someone or something from within the temple."
    );
    set_items(([
        "lichen":"%^MAGENTA%^The lichen is of a very unusual type and seems to "
	"provide the light source within the cavern tunnel.%^RESET%^",
	"lake":"%^BLUE%^The lake lies far below you in the cavern chamber "
	"and appears quite cold and menacing.",
	"city":"The city stretches across the island. You can see movement "
	"within the city.",
	"temple":"%^BOLD%^%^BLUE%^The temple is forboding looking and you get "
	"the feeling that it watches you. It towers higher than any other "
	"building in the city.%^RESET%^",
	"island":"The island lies in the lake and you notice a bridge from the "
	"stairs below leading to it.",
	"bridge":"There is a bridge leading from the bottom of the stairs "
	"before you to the island.",
	"stairs":"The cobblestone staircase leads down the side of the rift "
	"in the cavern to the foot of the bridge.",
	"walls":"The walls are bare stone and obviously have been carved "
	"through the mountain. Glowing %^MAGENTA%^lichen%^RESET%^ grows "
	"on the walls here."
    ]));
    set_exits(([
	"south": RPATH "tun12",
        "down": RPATH "bridge1"
    ]));
    add_pre_exit_function("down","block");
}
void reset() {
    ::reset();
    if(!present("drowmon")) {
	write(
	"%^BLUE%^A troop of drow enter and take up their posts.%^RESET%^"
	);
	new( MPATH "droww")->move(TO);
	new( MPATH "drowg")->move(TO);
	new( MPATH "drowg")->move(TO);
    }
}
int block() {
    if(!TP) return 0;
    if(wizardp(TP)) return 1;
    if( avatarp(TP) && TP->query_true_invis() ) return 1;
    if(!userp(TP)) return 1;
    if(present("drowmon")) {
        tell_object(TP,"The drow blocks your way!");
        return 0;
    }
    write("%^BOLD%^%^BLUE%^You take a deep breath and clamber down the stairs into the city.%^RESET%^");
    return 1;
}
