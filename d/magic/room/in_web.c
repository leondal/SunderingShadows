#include "std.h";
inherit "/std/room";

void create(){
    ::create();
    set_property("indoors", 1);
    set_property("light", 1);
     set_property("no teleport",1);
    set_smell("default", "All you smell is newly spun spider webs.");
    set_listen("default", "You can't hear anything.");
    set("short", "In a mass of web");
    set("long",
	"You are caught in a mass of sticky web.  The only way out "+
	"seems to be to tear through the web.\n");
    set_items( ([ ({"web", "webs", "spider web", "spider webs",
	"cobweb", "cobwebs"}):  "The web seems to be at least a "+
	"few feet thick."]) );
}
