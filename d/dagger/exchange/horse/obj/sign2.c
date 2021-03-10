//Loki 2011

#include <std.h>
#include "../horse.h"
inherit OBJECT;

void create(){
    ::create();
    set_name("painted sign");
    set_id(({"sign","painted sign"}));
    set_short("%^GREEN%^painted sign%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLACK%^This sign stands near the door "+
	"and reminds betters of the different things that can be done in the "+
	"owner's lounge.\n\n%^YELLOW%^ - 'buy horse'%^RESET%^%^ORANGE%^ to buy "+
	"a horse for the circuit. Currently you may own only "+
	"one horse. A horse costs 500,000 gold.\n%^YELLOW%^ - 'disown horse'%^RESET%^%^ORANGE%^ to get "+
	"rid of the horse you own.\n %^YELLOW%^- 'train horse'%^RESET%^%^ORANGE%^ "+
	"to arrange "+
	"with your trainer what kind of training your horse should be in, and "+
	"how much to invest in that training. A stronger horse will require more "+
	"gold invested at a time to grow, and each time you train it takes some "+
	"time for your horse and trainer to be ready for more. \n%^YELLOW%^ "+
	"- 'reinvest'%^RESET%^%^ORANGE%^ to take some of your winnings and reinvest "+
	"them into your horse at 100% value.\n%^YELLOW%^ - 'withdraw'%^RESET%^%^ORANGE%^ "+
	"to get paid some of the gold your horse has won. You will only receive %50 of "+
	"what you request back as the house takes the rest.\n%^YELLOW%^ - 'research "+
	"<topic>'%^RESET%^%^ORANGE%^ will let you learn more about what "+
	"and why you should train on your horse.\n\n%^CYAN%^%^BOLD%^You can also give "+
	"Baffert any special items that you think might help out your "+
	"horse or jockey in their races.\n\n%^RED%^%^BOLD%^Good Luck!\n%^RESET%^");
    set_weight(1000);
    set_value(5000);
    set_property("no animate",1);
}
