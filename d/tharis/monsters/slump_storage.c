#include <std.h>
#include <daemons.h>

inherit "/std/obj/fence_store_high";

void create(){
    ::create();
    set_property("no teleport",1);
    set_properties((["light":2,"indoors":1]));
    set("short","thief storage");
    set("long","If you're here you shouldn't be.");
}

void reset(){
    object ob;
    ::reset();
    if(!present("smokebomb")) {
        ob = new("/d/tharis/obj/smokebomb");
        ob->move(TO);
        ob->set_origin("tharis");
    }
}

