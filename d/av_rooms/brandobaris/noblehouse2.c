// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("noblehouse2");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^a large office%^RESET%^");

    set_long("%^BOLD%^This is a %^ORANGE%^grand%^WHITE%^, second-story office. Nearly twenty five feet long by twenty across, it is decorated with a number of expensive-looking furnishings. Most notable, a large an"
	"d imposing %^RESET%^%^ORANGE%^desk%^BOLD%^%^WHITE%^, wrought of %^BLACK%^p%^WHITE%^o%^BLACK%^l%^RESET%^i%^BOLD%^s%^BLACK%^h%^WHITE%^e%^BLACK%^d d%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^rk oak%^WHITE%^, d"
	"ominates much of the room, set directly across from the office door. A %^CYAN%^large plush chair %^WHITE%^sits behind it. To either side of the room are a number of small tables, and sofas, presumably"
	" for guests or more informal meetings, while much of the back wall is arrayed with numerous %^RESET%^%^ORANGE%^b%^BOLD%^%^BLACK%^oo%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^sh%^RESET%^%^ORANGE%^e%^BOLD%^%^"
	"BLACK%^lv%^RESET%^%^ORANGE%^es%^BOLD%^%^WHITE%^. A %^RESET%^%^MAGENTA%^p%^RED%^l%^MAGENTA%^u%^RED%^s%^MAGENTA%^h%^BOLD%^%^WHITE%^, %^RESET%^%^MAGENTA%^pl%^RED%^u%^MAGENTA%^m-c%^RED%^o%^MAGENTA%^l%^BOL"
	"D%^o%^RESET%^%^MAGENTA%^r%^RED%^e%^MAGENTA%^d r%^BOLD%^u%^RESET%^%^MAGENTA%^g %^BOLD%^%^WHITE%^covers much of the gleaming hardwood %^RESET%^%^ORANGE%^floor%^BOLD%^%^WHITE%^, and the large, wide %^CYA"
	"N%^window %^WHITE%^set into the east wall allows for an unimpeded view of the house's exterior.%^RESET%^"
	);

    set_smell("default","
The clean air here mingles with the scent of old texts.");
    set_listen("default","This room seems to be well insulated - you can hear only your own sounds.");

    
set_items(([ 
	({ "desk", "chair" }) : "%^BOLD%^%^BLACK%^This massive %^RESET%^%^ORANGE%^desk %^BOLD%^%^BLACK%^is nearly ten feet across, and wrought of d%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^rk o%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^k, %^RESET%^%^ORANGE%^stained %^BOLD%^%^BLACK%^and p%^RESET%^o%^BOLD%^lish%^RESET%^e%^BOLD%^%^BLACK%^d to a %^WHITE%^mirror sheen%^BLACK%^. Its surface is kept almost entirely bare, save for a %^WHITE%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^r i%^RESET%^n%^BOLD%^k%^RESET%^w%^BOLD%^e%^RESET%^l%^BOLD%^l %^BLACK%^and a small %^RESET%^stationary kit%^BOLD%^%^BLACK%^. Numerous %^RESET%^%^RED%^drawers %^BOLD%^%^BLACK%^both large and small are set into the backside of the desk, and most of them look to be locked. A large, %^BLUE%^p%^CYAN%^l%^BLUE%^u%^CYAN%^s%^BLUE%^h c%^CYAN%^h%^BLUE%^a%^CYAN%^i%^BLUE%^r %^BLACK%^sits behind it, almost a throne unto itself.%^RESET%^",
	({ "tables", "sofas", "furniture" }) : "%^ORANGE%^Not quite so impressive as the desk set in the middle of the room, these secondary pieces of furniture still look quite comfortable, and several low %^WHITE%^tables %^ORANGE%^are placed near the sofas for entertaining guests.%^WHITE%^",
	({ "bookshelves", "shelves" }) : "%^BOLD%^The entirety of the back wall is arrayed with large %^RESET%^%^ORANGE%^bookshelves%^BOLD%^%^WHITE%^, each of them filled almost to bursting with %^RESET%^%^ORANGE%^books %^BOLD%^%^WHITE%^and %^BLACK%^tomes %^WHITE%^of many different subjects, though certain topics look to be more common than others.%^RESET%^",
	({ "rug", "floor" }) : "%^MAGENTA%^The %^ORANGE%^g%^WHITE%^l%^BOLD%^e%^RESET%^%^ORANGE%^a%^BOLD%^m%^WHITE%^i%^RESET%^n%^ORANGE%^g hardwood floor %^MAGENTA%^looks to be made from many long, %^ORANGE%^oaken planks%^MAGENTA%^, and is covered almost in its entirety by a %^BOLD%^plush %^RESET%^%^MAGENTA%^pl%^BOLD%^u%^RESET%^%^MAGENTA%^m-c%^BOLD%^o%^RESET%^%^MAGENTA%^l%^BOLD%^o%^RESET%^%^MAGENTA%^r%^BOLD%^e%^RESET%^%^MAGENTA%^d rug, lined at the edges with a %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^r e%^RESET%^m%^BOLD%^b%^RESET%^r%^BOLD%^o%^RESET%^i%^BOLD%^d%^RESET%^e%^BOLD%^r%^RESET%^y%^MAGENTA%^.%^WHITE%^",
	]));

    set_exits(([ 
		"foyer" : "/d/av_rooms/brandobaris/noblehouse1",
	]));

    set_door("office doors","/d/av_rooms/brandobaris/noblehouse1","foyer");
    set_string("office doors","knock","knock");
    set_string("office doors","open","%^ORANGE%^The doors swing open to reveal a large and %^BOLD%^inviting %^RESET%^%^ORANGE%^foyer.%^WHITE%^");
    set_string("office doors","close","%^ORANGE%^The doors swing shut, closing with a quiet %^BOLD%^%^BLACK%^thud%^RESET%^%^ORANGE%^.%^WHITE%^");
    set_door_description("office doors","%^ORANGE%^These large double doors are made from polished d%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^rk w%^BOLD%^%^BLACK%^oo%^RESET%^%^ORANGE%^d, and each door bears an o%^BOLD%^r%^WHITE%^n%^ORANGE%^a%^WHITE%^t%^RESET%^%^ORANGE%^e handle of %^BOLD%^gold%^RESET%^%^ORANGE%^.%^WHITE%^");
}