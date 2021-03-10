#include <std.h>
inherit ROOM;

void create(){
        :: create();
  set_property("no teleport",1);
        set_property("light", 2);
        set_property("indoors", 0);
        set_short("A temple");
        set_long(
@ISLAND
%^BLUE%^As you enter the temple you are filled with a sense of awe. What wondrous
things!  Drawings done in brilliant colours cover the walls, floor and
passage ways.  If a primitive tribe has done this, they all must have
spent several lifetimes as artists.  The paintings almost look as though
they could breathe, come to life and run.  The stone work also has been
done by a masters hands, as it shows no light through the rock, each stone
appears to be melded to the next to form impenetrable walls.  Urns of
bright fresh flowers rest upon stone tables and altars.  Vines with
bright green  foliage drape across the walls, held up by unseen hands.
A fire burns in copper vessels, however, no fuel appears to be used.
Truly, a wondrous, marvelous place.  Masks of beaten gold and copper line
the walls as if they were the wardens of this hidden temple.  They peer
down as if to ask, why are you here, why do you invade our place of peace,
our sanctuary.
ISLAND
	);
	set_smell("default", "You can smell the fires burning, a sweet jasmine odour.");
	set_listen("default", "All is quiet here, peaceful, the flickering of the flame snapping in a slight breeze is the only sound.");
	set_exits( ([
    "leave":"/d/shadow/virtual/sea/hmquest.dock"
	]) );
	set_items(([
		"drawings" : "Drawings of wild beasts, peoples of every kind, shape or form, and flowers cover the walls, floors and passageways.",
		"walls" : "The walls are made of gray stone, fitted together tightly to form an impenetrable barrier",
		"floor" : "The stones have been polished smooth to make a level and cool floor.",
		"paintings" : "Paintings of wild beasts, peoples of every kind, shape or form and flowers cover the walls, floors and passageways.",
		"stonework" : "The stonework has been crafted by a master, fitted together tightly.",
		"urns" : "Urns covered again with beautiful paintings stand upon stone tables and altars, filled with fresh flowers",
		"flowers" : "Hibiscus, roses, throttleweed, teardrops, lilies, and other glorious flowers fill the urns",
		"vines" : "Bold greens, and bright blue vines cover the walls like living draperies",
		"vessel" : "Beaten copper vessels, in the shape of oval dishes, have fire set within in them, but no fuel",
		"masks" : "Huge, three feet tall and two feet wide beaten copper and gold masks of human, animal and other forms of life, look down upon you."
	]) );
	add_post_exit_function("leave","go_out");
}

void reset(){
	::reset();
	if (!present("table"))
		new("/d/hm_quest/obj/table")->move(TO);
}

void go_out(){
	tell_object(TP,"%^BOLD%^%^GREEN%^You feel strange after being magically teleported here.");
	tell_object(TP,"%^BOLD%^You look around, slightly dazed.");
}
