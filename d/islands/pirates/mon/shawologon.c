#include <std.h>
#include "../piratedefs.h"
inherit "/std/vendor_pstore";

void create() {
   ::create();
   set_nwp("escape",10,500);
   set_name("Shawologon");
   set_id(({"shawologon","arms smuggler","smuggler","dealer"}));
   set_short("Shawologon, arms smuggler and dealer");
   set("aggressive",0);
   set_level(10);
   set_long("Shawologon stands by the far wall, partly cloaked in the flickering shadows.  The short "
"halfling has a rough appearance and a piercing gaze, and numerous scars cover his hands and arms.  He "
"watches you carefully, his gaze never leaving you the entire time you are here.");
   set_gender("male");
   set_alignment(9);
   set_race("halfling");
   add_money("gold", random(200));
   set_body_type("human");
   set_hd(10,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_exp(1);
   set_shop(COVE"smuggler");
}

// Function rewrites for this owner.

int __Sell(string str) {
   tell_room(ETO, "%^MAGENTA%^"+TOQCN+" smirks and says: %^RESET%^Thanks but no thanks, I've got me own "
"suppliers.");
    return 1;
}

int __Value(string str) {
   tell_room(ETO, "%^MAGENTA%^"+TOQCN+" waves you away with his hand, saying: %^RESET%^Nah, not interested.");
   return 1;
}

protected int __SellAll() {
   tell_room(ETO, "%^MAGENTA%^"+TOQCN+" smirks and says: %^RESET%^Thanks but no thanks, I've got me own "
"suppliers.");
   return 1;
}

int __Pickup(string str) {
   tell_room(ETO, "%^MAGENTA%^"+TOQCN+" laughs and says: %^RESET%^You think I'm running a convenience here?");
   return 1;
}

int __Leave(string str) {
   tell_room(ETO, "%^MAGENTA%^"+TOQCN+" laughs and says: %^RESET%^Do I look like a messenger service to "
"you?");
   return 1;
}

int __List(string str) {
    object *inv, storage;
    string *tmp, *not_allowed, short, who, what, type;
    int i, x, cost;

    if(!at_shop())
	return 1;
    not_allowed = ({ "bound", "disabled" });
    if(disabled(TP, not_allowed))
	return 1;

    if(member_array("letters", ETO->query_allowed()) != -1)
	return 0;

    storage = find_object_or_load(ETO->query_storage());
    inv = all_inventory(storage);
    if (!sizeof(inv)) {
	tell_room(ETO, "%^MAGENTA%^"+TOQCN+" shrugs and says: %^RESET%^Ain't got no stock today.  Come back "
"tomorrow.");
        return 1;
    }
    inv = sort_array(inv,"sort_items",TO);
    tell_room(ETO,TPQCN+" looks around carefully, checking out the stock.", TP);
    write("%^YELLOW%^ Description				       Price	 Type");
    write("%^BOLD%^%^BLUE%^"
	"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    for (x=0, tmp = ({}); x<sizeof(inv); x++) {
        if(living(inv[x]))  continue;
	short = inv[x]->query_short();
        if(strlen(short) > 44)
	   //short = short[0..43] + "~ ";
           short = arrange_string(short,43);
	if(what == "pickup") {
           who = inv[x]->query_property("pstore_cust");
	   if(!avatarp(TP) && (string)TPQN != who)  continue;
	   if(!inv[x]->query_property("pstore_value"))  continue;
        }
	cost = inv[x]->query_property("pstore_value");
	cost = adjust_cost(cost);
	type = types(inv[x]);
	if(avatarp(TP))   type = inv[x]->query_property("pstore_cust");
        tmp +=({ sprintf("%%^BOLD%%^%%^GREEN%%^%-45s %%^YELLOW%%^%5d %%^WHITE%%^%-5s %-20s",
	   short,cost,"gold", type )
	});
    }
    if(tmp == ({}))
	tmp += ({"%^BOLD%^Nothing marked for you at this time.\n"});
    tmp += ({"%^BOLD%^%^BLUE%^"
	"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="});
    TP->more(tmp);
    return 1;
}

int __Help(string str) {
   if (!str) return 0;
   if(base_name(ETO) != query_shop())
      return 0;
   if (strcmp("shop",str) != 0) return 0;
   write("
Commands available are:

  <list>		see what items are available to buy
  <show [item]>		to get a better look at an item for sale
  <buy [item]>		buy an item for sale
     ");
    return 1;
}
