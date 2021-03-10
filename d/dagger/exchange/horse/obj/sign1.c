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
	"betting parlor.\n\n%^YELLOW%^ - 'list horses'%^RESET%^%^ORANGE%^ to see "+
	"all the horses on the circuit. This includes just the basic information "+
	"on horses, the name, the owners name and the record the horse "+
	"has so far this searson.\n %^YELLOW%^- 'research #'%^RESET%^%^ORANGE%^ to look at the "+
	"details of a single horse (use the horse's number). This shows much more detailed "+
	"information on a horse including an idea how powerful the horse is and what "+
	"types of circumstances are unusual for them. It also shows how much they "+
	"have won so far this season.\n %^YELLOW%^- 'view "+
	"race'%^RESET%^%^ORANGE%^ will check to see if there is a race on the "+
	"books and show you the details of that race. This will only have information "+
	"if Clarise has been informed of a race about to happen\n %^YELLOW%^- "+
	"'bet <amount> on <#>'%^RESET%^%^ORANGE%^ "+
	"to place a bet on that horse. Remember to use the horse's number when placing "+
	"the bet and %^RESET%^%^BOLD%^ensure that that horse is running%^RESET%^%^ORANGE%^. "+
	"All bets are final.\n %^YELLOW%^ "+
	"- 'claim stub'%^RESET%^%^ORANGE%^ after the race to check if you have a "+
	"winning bet. Remember though a betting stub is only good until the next "+
	"race is being arranged so remember to cash in as soon as "+
	"you can.\n\n %^RED%^%^BOLD%^Good Luck!\n%^RESET%^");
    set_weight(1000);
    set_value(5000);
    set_property("no animate",1);
}
