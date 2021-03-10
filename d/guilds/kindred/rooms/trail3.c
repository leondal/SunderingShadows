#include <std.h>
inherit ROOM;

void create()
{
	::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
	set_property("indoors",0);
	set_property("light",2);
	set_short("%^BOLD%^%^GREEN%^The Garden");
	set_long(
	"This is the entrance to the gathering place of those known as The Kindred."+
	" This little clearing within a pine grove hidden in a section of Tharis"+
	" Forest has been affectionately termed %^BOLD%^The Garden%^RESET%^. Directly in front of"+
	" you is a large tree. It is so old that its name has been forgotten and"+
	" there are only a few left throughout the realms. It is a magical tree,"+
	" some say, its base grows hollow for people to live inside. It cannot"+
	" exist for long without someone around to help take care of it. An open"+
	" section in the trunk of the tree serves as a doorway."
	);
	set_smell("default","The scent of pine floats in the air.");
	set_listen("default","The wind rustles through the trees.");
	set_items(([
	"tree" : "This large tree is so old that its name has been forgotten and"+
	" there are only a few left throughout the realms. Some say that the tree"+
	" is magical, at one point they were hunted to near extinction because"+
	" people were so avid to have things made out of their wood. Now the few"+
	" trees that have survived are hidden from the world. Their relationship"+
	" with people is symbiotic, their trunk grows tall and hollow, providing"+
	" a safe shelter for people to live inside. They need people to help take"+
	" care of them, however, or they will eventually die. Some myths say that"+
	" the trees grow lonely without someone around and die of sorrow. An open"+
	" section in the trunk of the tree serves as a doorway.",
	"pine grove" : "The pine grove surrounds this clearing, keeping it safe.",
	]));
	set_exits(([
	"west" : "/d/guilds/kindred/rooms/stones",
	"south" : "/d/guilds/kindred/rooms/trail2",
	"east" : "/d/guilds/kindred/rooms/atree",
	"north" : "/d/guilds/kindred/rooms/tree",
	]));
}
