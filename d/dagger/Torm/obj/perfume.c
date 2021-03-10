#include <std.h>
inherit OBJECT;
//inherit ROOM;

int count;

void create()
{
	::create();
	set_name("bottle of perfume");
   set_id(({"perfume","bottle of perfume","citrus perfume"}));
   set_short("%^RESET%^%^ORANGE%^A bottle of citrus perfume%^RESET%^");
	set_long(
   "%^BOLD%^This is a small crystal bottle that holds the amber liquid of"+
   " an exotic citrus perfume. You can't quite place what fruit it imitates,"+
   " but it is quite captivating."
	);
   set_value(100);
	set_weight(1);
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
      write("%^ORANGE%^You spray a bit of citrus perfume on.");
      tell_room(ETP,"%^ORANGE%^"+TPQCN+" sprays on some citrus perfume.",TP);
			long = TP->query_long();
      TP->set("long","%^RESET%^%^ORANGE%^"+capitalize(nominative(TP))+" is wearing"+
      " an exotic citrus fragarance.");
			return 1;
		}
		else {
			write("The bottle is empty.");
			set_long("%^BOLD%^This small crystal bottle used to contain"+
      " citrus perfume, but now it is empty.");
			set_short("An empty bottle of perfume");
			set_value(0);
			return 1;
		}
	}
}
