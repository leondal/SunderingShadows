#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create()
{
	::create();
	set_property("light",2);
	set_terrain(GARDEN);
	set_travel(FOOT_PATH);
	set_short("A rose garden");
	set_long(
	"The path ends in a garden of beautiful roses. There is a little gray marble bench"+
	" for people to sit upon, with a trellis covered in rose vines stretching over it."+
	" There is a heart-shaped trellis at the far end of the garden, completely covered"+
	" in pink and red roses. Other roses of every color seem to stretch about the garden."+
	" There doesn't seem to be much attempt to control the roses, for the vines have"+
	" stretched out to mingle with the other colors. It is a beautiful effect, though,"+
	" each bush seems to have at least five different colors of flowers on it."
	);
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
	set_smell("default","The wonderful smell of roses surrounds you.");
	set_listen("default","You can hear birds chirping in the park.");
	set_items(([
	"grass" : "%^GREEN%^%^BOLD%^The grass beneath your feet is lush and green, it is"+
	" almost like a carpet it is so thick and well cared for.",
	({"bench","marble bench","gray bench","gray marble bench"}) : "There is a gray marble"+
	" bench just next to the path. It has a white trellis stretched over it in an arch"+
	" that is covered with %^YELLOW%^yellow%^RESET%^ and %^BOLD%^white%^RESET%^ roses.",
	"roses" : "The roses seem to intertwine with eachother, making each bush seems like"+
	" it is growing at least five different colors of flowers! You see red, pink, yellow,"+
	" white, purple, peach, orange, and a combination of all the colors to make so many"+
	" different shades. Some roses have a darker center, others are tipped with a"+
	" different color at the edges of their petals. Some flowers are large, others small,"+
	" there are even some baby-faced roses here. A few miniature roses are planted closer"+
	" to the path, they are kept well trimmed and do not spread out too far. They"+
	" alternate in colors around a large semi-circle, and look very beautiful.",
	"trellis" : "There is a large heart-shaped trellis at the far end of the garden. It"+
	" is covered in large %^BOLD%^%^MAGENTA%^pink%^RESET%^ and %^BOLD%^%^RED%^red%^RESET%^"+
	" roses and looks so beautiful.",
	]));
	set_exits(([
	"north" : MAINTOWN"park2",
	]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
