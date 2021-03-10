#include <std.h>
#include "../antioch.h"
inherit OBJECT;
//inherit ROOM;

int count;

void create()
{
	::create();
	set_name("bottle of perfume");
	set_id(({"perfume","bottle of perfume","lilac perfume"}));
	set_short("%^BOLD%^%^MAGENTA%^A bottle of lilac perfume%^RESET%^");
	set_long(
	"%^BOLD%^This is a small crystal bottle of lilac perfume. You"+
	" can see the lavender colored liquid in side and a wonderful"+
	" fragarance comes from the bottle."
	);
	set_value(20);
	set_weight(1);
	set_cointype("electrum");
}

void init()
{
	::init();
	add_action("wear_me","wear");
}

int wear_me(string str)
{
	string long;
	if(strsrch(str,"perfume")==-1) return 0;
	else {
		if(count!=5) {
			count+=1;
			write("%^BOLD%^You dab on some lilac perfume.");
			tell_room(environment(TP),"%^BOLD%^"+TP->query_cap_name()+""+
			" puts on some lilac perfume.",TP);
			long = TP->query_long();
			TP->set("long","%^BOLD%^%^MAGENTA%^"+capitalize(nominative(TP))+" is wearing a"+
			" lovely lilac fragrance.");
			return 1;
		}
		else {
			write("The bottle is empty.");
			set_long("%^BOLD%^This small crystal bottle used to contain"+
			" lilac perfume, but now it is empty.");
			set_short("An empty bottle of perfume");
			set_value(0);
			return 1;
		}
	}
}
