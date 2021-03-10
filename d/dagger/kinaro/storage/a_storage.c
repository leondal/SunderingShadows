#include "/d/shadow/mon/melnmarn.h"
inherit ROOM;

void create() {
    ::create();
   set_property("no teleport",1);
    set_properties((["light":0, "indoors":1]));
    set("short", "Kinaro armor store storage");
    set("long", "Only supplies and such here.\n");
    set_exits((["up" : "/d/dagger/kinaro/armor"]));
}

void reset() {

    ::reset();
    if(!present("buckler"))
	new("/d/dagger/kinaro/obj/armors/buckler")->move(this_object());
    if(!present("sbanded"))
	new("/d/dagger/kinaro/obj/armors/sbanded")->move(this_object());
    if(!present("sbronze"))
	new("/d/dagger/kinaro/obj/armors/sbronze")->move(this_object());
    if(!present("schain"))
	new("/d/dagger/kinaro/obj/armors/schain")->move(this_object());
    if(!present("sfullplate"))
	new("/d/dagger/kinaro/obj/armors/sfullplate")->move(this_object());
    if(!present("shield"))
	new("/d/dagger/kinaro/obj/armors/shield")->move(this_object());
    if(!present("sleather"))
	new("/d/dagger/kinaro/obj/armors/sleather")->move(this_object());
    if(!present("spadded"))
	new("/d/dagger/kinaro/obj/armors/spadded")->move(this_object());
    if(!present("sring"))
	new("/d/dagger/kinaro/obj/armors/sring")->move(this_object());
    if(!present("sscale"))
	new("/d/dagger/kinaro/obj/armors/sscale")->move(this_object());
    if(!present("sshield"))
	new("/d/dagger/kinaro/obj/armors/sshield")->move(this_object());

}

