#include <std.h>
#include "../../valley.h"
inherit ROOM;

int found = 0;

void create()
{
	::create();
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
	set_property("outdoors",3);
	set_property("light",2);
   set_short("%^BOLD%^%^MAGENTA%^Meadows%^RESET%^");
	set_long(
	"%^GREEN%^You are in a peaceful meadow. The %^BOLD%^grass%^RESET%^%^GREEN%^ is"+
	" shorter here and numerous %^MAGENTA%^w%^BOLD%^i%^RED%^l%^YELLOW%^d%^RESET%^%^ORANGE%^f%^BOLD%^"+
        "%^WHITE%^l%^RESET%^%^ORANGE%^o%^YELLOW%^w%^RED%^e%^MAGENTA%^r%^RESET%^%^MAGENTA%^"+
        "s%^RESET%^%^GREEN%^ are growing"+
	" along the ground. They come in all different"+
	" varieties and are flourishing here in the meadow."+
	" You see some %^RESET%^field mice%^GREEN%^ scatter"+
	" away from you, trying to find a hiding place."+
	" The meadow has a %^CYAN%^tranquil%^GREEN%^ feeling and you think"+
	" you could spend hours relaxing here.\n"
	);
	set("night long",
	"%^GREEN%^You're standing in the middle of a meadow. The"+
	" %^BOLD%^%^GREEN%^grass%^RESET%^%^GREEN%^ is shorter here and there are numerous"+
	" %^MAGENTA%^w%^BOLD%^i%^RED%^l%^YELLOW%^d%^RESET%^%^ORANGE%^f%^BOLD%^"+
        "%^WHITE%^l%^RESET%^%^ORANGE%^o%^YELLOW%^w%^RED%^e%^MAGENTA%^r%^RESET%^%^MAGENTA%^"+
        "s%^RESET%^%^GREEN%^ growing all over the place. There"+
	" are all sorts of varieties here, they seem to"+
	" flourish in this place. You can still hear some"+
	" %^RED%^field mice%^GREEN%^ scampering about, trying to find"+
	" their dinner. Even though it is %^BLUE%^night%^GREEN%^, this"+
	" place is no less peaceful. You'd feel quite"+
	" safe spending the night here.\n"
	);
	set_smell("default",
	"The scent of wildflowers is over powering here."
	);
	set_listen("default",
	"You hear the scampering of field mice."
	);
	set_items( ([
	"mice" : "%^BOLD%^Cute little field mice are running from you.",
	"wildflowers" : "%^MAGENTA%^There are many flowers of all"+
	" different types growing here. It would be easy to"+
	"%^BOLD%^pick%^RESET%^%^MAGENTA%^ a boquet of them.",
	"grass" : "%^GREEN%^%^BOLD%^This is lush green grass that looks like"+
	" it has been cut short.",
	]) );
}

void init()
{
	::init();
	add_action("pick", "pick");
}

int pick(string str)
{
	if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if(!str) {
	write("Pick what?");
	return 1;
	}
	if(str != "flowers" && str != "wildflowers") {
	write("You do not see that here.");
	return 1;
	}
	if(found) {
	write("All the wildflowers have been picked.");
	return 1;
	}
	else {
	write("%^MAGENTA%^You pick a beautiful boquet of"+
	" wildflowers.");
	say("%^MAGENTA%^"+TP->query_cap_name()+" picks a"+
	" beautiful boquet of wildflowers.");
	new(OBJ+"boquet")->move(this_object());
	found = 1;
	return 1;
	}
}
