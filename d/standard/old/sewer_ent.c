#include <std.h>

inherit VAULT;

void create() {
    ::create();
    set("short", "The Praxis sewers");
    set("long",
      "You are underneath the town of Praxis inside their "
      "small sewer system.  There is a manhole to the surface above "
      "you.");
    set_smell("default", "The sewers stink of humanoid waste.");
    set_door("manhole","/d/standard/yard","up",0);
    set_exits( 
	      (["north" : "/d/under/entry",
		"east" : "/d/standard/sewer",
		"up" : "/d/standard/yard"]) );
    set_property("light", 0);
    set_property("indoors", 1);
    set_items(
        ([ "manhole" : "It is a hole that leads to the surface."]) );
}

void reset() {
  ::reset();
    if(!present("sword")) 
      new("/d/standard/obj/weapon/sword")->move(this_object());
}

