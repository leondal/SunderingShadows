// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ginger1");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("hut");
    set_travel("ledge");
    set_climate("temperate");

    set_short("%^ORANGE%^A Gingerbread Cottage%^RESET%^");

    set_long("%^RESET%^You have entered the main room of a small, extraordinary cottage built primarily of %^ORANGE%^gingerbread%^RESET%^.  The floorboards, walls and major furnishings are all made from the same %^"
	"ORANGE%^brown%^RESET%^, cookie-like stuff that sparkles every so slightly with dark sugar %^ORANGE%^cr%^YELLOW%^y%^RESET%^%^ORANGE%^stals.  %^RESET%^Looking beyond the major features, one notices that"
	" the door frames look remarkably like %^BOLD%^c%^RED%^a%^WHITE%^n%^RED%^d%^WHITE%^y c%^RED%^a%^WHITE%^n%^RED%^e%^WHITE%^s%^RESET%^.  The main room appears to serve dual duty as both a sitting parlor a"
	"nd, further back, kitchen.  Twin couches made of something quite possibly %^MAGENTA%^purple gumdrop%^RESET%^ flank a long %^YELLOW%^toffee %^RESET%^%^ORANGE%^coffee%^RESET%^ table.  A fine example of "
	"a %^BOLD%^%^MAGENTA%^cotton candy%^RESET%^ fire roars in the %^ORANGE%^chocolate-brick%^RESET%^ hearth.  Across the room, %^ORANGE%^butterscotch%^RESET%^ kitchenware sputter away in the cluttered kitc"
	"hen area.  A stout door opposite the hearth also boasts a %^BOLD%^%^WHITE%^c%^RED%^a%^WHITE%^n%^RED%^d%^WHITE%^y%^RESET%^ frame, and likely leads to even more nonsense.%^RESET%^"
	);

    set_smell("default","
%^ORANGE%^Mmm, smells like cookies!");
    set_listen("default","%^GREEN%^You hear something cooking in the back.");

    
set_items(([ 
	"table" : "%^ORANGE%^The long, low coffee table is made from caramel colored toffee.  There are some empty marshmallow mugs on the table, as well as a few gold coins.  To your dismay, the candy coins are made of chocolate, evidenced by the peeling gold foil.",
	"couch" : "%^MAGENTA%^The couches have a solid frame made from...something, but the cushions are in fact slightly gelatinous.  They look very comfortable.",
	"fire" : "%^BOLD%^%^MAGENTA%^The fire is obviously fake, and gives off no warmth.  It would be silly if cotton candy fires were warm...it would melt the chocolate.",
	]));

    set_exits(([ 
		"east" : "/d/av_rooms/tiamat/ginger2",
	]));

    set_door("main door","/d/shadow/room/forest/road1","out");
    set_open("main door",0);
    set_string("main door","knock","knocks on the");
    set_string("main door","open","You open the door.");
    set_string("main door","close","You close the door.");
    set_door_description("main door","The door is made of gingerbread!");
    set_door("side door","/d/av_rooms/tiamat/ginger2","east","candy key","candy lock");
    add_lock("side door","candy key","candy lock","A lock made from hard candy.  Very hard candy.");
    set_locked("side door",1,"candy lock");
    lock_difficulty("side door",-500,"candy lock");
    set_open("side door",0);
    set_string("side door","knock","knock on the");
    set_string("side door","open","You open the side door.");
    set_string("side door","close","You close the side door.");
    set_door_description("side door","A gingerbread door, including a hard candy lock.");
}