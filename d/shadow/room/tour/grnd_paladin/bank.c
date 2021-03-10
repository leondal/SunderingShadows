#include "/d/shadow/room/city/melnmarn.h"
#include <daemons.h>
#include <money.h>
#include <bank.h>

#define BANK_ID "praxis"

inherit VAULT;

void init() {
    ::init();
         add_action("read", "read");
    add_action("exchange","exchange");
}

void create() {
    ::create();
    set_property("magic hold", 50);
    set_property("no castle", 1);
    set_property("light", 1);
    set_property("indoors", 1);
     set("short", "A huge wagon in the DarkWood");
    set("long",
@MELNMARN
%^BOLD%^A huge wagon in the DarkWood.%^RESET%^
This is a large wagon with a large man on the back of it.  The
man seems to be taking money and exchanging it for other curriencies.
The is a crude sign painted on the side of the wagon.
MELNMARN
);

    set_items(
	(["bank" : "You are in its huge lobby. There is a counter in "
	    "front of you\nand and exit behind you.",
	  "customers" : "They are wandering about aimlessly.",
	  "sign" : "Reading it will give you a list of commands.",
	  "teller" : "The teller looks at you impatiently.",
	  "counter" : "A teller waits behind it for you to do something.",
	  "exit" : "It leads out into the street."]));
    set_exits(([
      "west":"/d/shadow/room/tour/death/hall1.c",
      ]));
    set_smell("default","The smell of money is in the air.");
    set_listen("default","The sounds of rustling coins fill your ears.");

}

int exchange(string str) {
    string from, to;
    float val;
    int amount;

    if(!str) {
        notify_fail("Correct syntax: <exchange # type for type>\n"+
                    "ex: <exchange 100 gold for copper>\n");
        return 0;
    }
    if(sscanf(str, "%d %s for %s", amount, from, to) !=3) {
	notify_fail("Correct syntax: <exchange # type for type\nex: "
		    "<exchange 100 gold for copper>\n");
	return 0;
     }
    if(amount < 1) {
	notify_fail("That would be a nifty trick indeed!\n");
        return 0;
    }
     if((int)this_player()->query_money(from) < amount) {
	notify_fail("You do not have that much of that currency.\n");
	return 0;
    }
    if(member_array(from, HARD_CURRENCIES) == -1)
        return notify_fail("The bank does not support "+from+".\n");
    val = amount/currency_rate(from);
    if(member_array(to, HARD_CURRENCIES) == -1)
      return notify_fail("The bank does not support "+to+".\n");
    this_player()->add_money(from, -(to_int(amount*0.00)+amount));
    amount = to_int(val * currency_rate(to));
    this_player()->add_money(to, amount);
    message("my_action", "You exchange your "+from+" coins for "+amount+" "+to,
      this_player());
    message("other_action", (string)this_player()->query_cap_name()+
      " exchanges some money.", this_object(), ({ this_player() }));
    return 1;
}


int read(string str) {
    if(str != "sign") return notify_fail("Read what?\n");
	write(
@MELNMARN
%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
%^BOLD%^%^GREEN%^      M\or's Money Exchange.
%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
%^BOLD%^%^CYAN%^Exchange <#> <type1> for <type2>%^BLACK%^ --- %^RESET%^%^CYAN%^Exchanges currencies.
%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
MELNMARN
    );
    return 1;
}

