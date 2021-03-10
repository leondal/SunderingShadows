//changed pre-exit function to check for "drowmon" rather than just drow and 
//added to allow true_invis avatars through also  *Styx*  12/22/01

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
    set_short("%^BLUE%^Dark cavern tunnel%^RESET%^");
    set_long(
	"%^BLUE%^The tunnel leads away from the %^CYAN%^fog%^BLUE%^ "
	"found to the south and continues to press deeper into the "
	"mountain. You estimate you have reached a point where you are "
	"at least a half of a mile underground. You stop here as you have "
	"reached an intersection. There is also a "
	"%^WHITE%^skeleton%^BLUE%^ laying on the ground here. The cavern "
	"tunnel to the east is filled with a strange %^RED%^red%^BLUE%^ "
	"smoky fog.%^RESET%^"
    );
    set_listen("default",
	"Something whispers to you from within the fog to the east."
    );
    set_smell("default","Your senses tell you to flee this area.");
    set_items(([
  	"lichen":"%^MAGENTA%^The lichen is of a very unusual type and "
	"seems to provide the light source within the cavern tunnel.%^RESET%^",
	"fog":"%^RED%^The fog fills the eastern tunnel. As you look at it "
	"you hear a slight whisper emerge.%^RESET%^",
	"skeleton":"The skeleton lays outstreched on the cavern floor. It's "
	"left arm is laying in a manner that appears to be pointing to the "
   "north. It has a grin on its face and the skull stares to the east.",
	"writing":"%^BLUE%^The writing reads: %^RED%^Help...it "
	"futile..trapped...never leave city...only from poti..destroy "
	"the nodeus...only way...seek the healer...%^RESET%^",
	"walls":"There is %^RED%^bloody writing%^RESET%^ on the wall."
    ]));
    set_exits(([
	"south": RPATH "tun11",
	"east": RPATH "tun13",
	"north": RPATH "tun14"
    ]));
    add_pre_exit_function("east","block_func");
}
void reset() {
    ::reset();
    if(!present("drow fighter")) {
	write(
	    "%^BLUE%^A regiment of drow guards enter the room and take "
	    "their posts.%^RESET%^"
	);
	new( MPATH "drowf")->move(TO);
	new( MPATH "drowf")->move(TO);
	new( MPATH "drowf")->move(TO);
	new( MPATH "droww")->move(TO);
    }
}
int block_func() {
    if(!TP) return 0;
    if(wizardp(TP)) return 1;
    if( avatarp(TP) && TP->query_true_invis() ) return 1;
    if(!userp(TP)) return 1;
    if(present("drowmon")) {
	tell_object(TP,"The drow blocks your way!");
	return 0;
    }
    return 1;
}
