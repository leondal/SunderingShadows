//    /std/vendor_pstore
//    special vendor for player-owned store clerks
//    created by Styx @ ShadowGate 12/2002
//    use in conjunction with /std/pstore for owner functions


/* key features & info. to set in create():

1)  set_shop("filename") in create - filename = room that inherits /std/room_pstore
2)  #define MAX_ITEMS # - preferably 10 or less unless it's mail
3)  max of 2 items per person allowed in normal drop storage (see __Repair);
4)  leave_letter and pickup_letter can be overloaded for special effects if desired
5)  Please save the clerk mobs in /d/player_houses/shopclerks/ as playername_clerk for ease of finding and maintaining them all if we add features that need something set, etc.
*/

/* ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?
   Add a function to allow owners to maintain a list of people they won't deal with
   Put in base functionality to store (& make pardonable & cleanable) attackers?
   Static int __SellAll(); -> should this comment out of /std/vendor ?? not used????
*/

#include <std.h>
#include <money.h>
#include <daemons.h>

#define MAX_ITEMS 50   // in case it's not set on the clerk, will this override?

inherit "/std/vendor";

int query_shop();
void set_drop_deposit(int x);
void leave_letter(object cust, int step);
void pickup_letter(object cust);
void pickup_actions(object cust, object *what, int step);
void del_letter(object cust, object *what);

//**  int check_allowed(object ob);
//**  string types(object ob);

string shop;
int delivering;

void init() {
    ::init();
// wonder if this will actually work....
    if(base_name(ETO) == query_shop()) {
       add_action("__Buy", "buy");
       add_action("__Show", "show");
       add_action("__List", "list");
       add_action("__Leave", "leave");
       add_action("__Help", "help");
       add_action("__Pickup", "pickup");
    }
}

void heart_beat()
{
    ::heart_beat();
}

void create() {
    ::create();
}

void set_shop(string str) {
   shop = str;
}

int query_shop() {
   return shop;
}

void notify_messages(object ob)
{
    tell_object(ob, "\n%^BOLD%^%^RED%^A message from " + TOQCN + " suddenly enters your mind:");
    tell_object(ob, "It seems we have a message left for you.\nPay " +ETO->query_short()+"%^RESET%^ a visit to pickup the letter.\n");
    return;
}

int notify_players()
{
    object * users = users();
    object user;
    object * inv, i;
    object * what;

    if (!objectp(ETO)) {
        return;
    }
    inv = all_inventory(find_object_or_load(ETO->query_drop_storage()));

    users = filter_array(users, (:$1->query_property("notified_about_mess") < time():));

    foreach(user in users)
    {
        if (!interactive(user)) {
            continue;
        }
        if (user->query_invis() || user->query_hidden()) {
            continue;
        }

        what = ({});
        foreach(i in inv)
        {
            if (i->id("paper") && i->query_property("pstore_cust") == user->query_name()) {
                what += ({ i });
            }
        }

        if (sizeof(what)) {
            notify_messages(user);
            user->set_property("notified_about_mess", time() + 60 * 60);
        }
    }
    return 1;
}

int at_shop() {
   if(base_name(ETO) != query_shop()) {
	tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^Sorry, I need to be at the shop to do business.");
	return 0;
   }
   return 1;
}

string query_items_allowed() {
   if(base_name(ETO) != query_shop())
      return 0;
   return ETO->query_items_allowed();
}

int check_allowed(object ob) {
   if(base_name(ETO) != query_shop())
      return 0;
   return ETO->check_allowed(ob);
}

// These need to over-ride the std/vendor inherit
void inventory() {
    return 0;    // don't want to over-ride the normal inventory function here
}

int __Sell(string str) {
   tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^Sorry, I do not purchase items.");
    return 1;
}

int __Value(string str) {
   tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^Sorry, I am not qualified or allowed to appraise items.");
   return 1;
}

protected int __SellAll() {
   tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^Sorry, I do not purchase items.");
   return 1;
}

int __Buy(string str) {
    object ob, storage;
    int cost, x;
    string cointype;
    string *not_allowed;
    if(!at_shop())
	return 1;

    not_allowed = ({ "bound", "disabled" });
    if(disabled(TP, not_allowed))
	return 1;

    if(member_array("letters", ETO->query_allowed()) != -1)
	return 1;
    if (!str) {
        write("Try 'buy <item> [#]'!");
        return 1;
    }

    if (!should_interact(TP)) {
        force_me("glare "+TPQN);
        force_me("say Leave scum, we don't deal with those with your reputation.");
        return 1;
    }
    if (!TP->is_player() && member_array(TP->query_race(),RACE_D->query_races())== -1) {
        force_me("say We don't serve your kind around here.");
        return 1;
    }
    storage = find_object_or_load(ETO->query_storage());
    if (!(ob = present(str, storage)) && !(ob = parse_objects(storage)) ) {
        write("I don't have any "+str+"s to sell you!");
        return 1;
    }
    cost = (int)ob->query_property("pstore_value");
    cointype = "gold";
    cost = adjust_cost(cost);
//    if ((int)TP->query_money(cointype) < cost) {
//        convert_money(cointype,cost);
    tell_room(ETO, TPQCN+" seems to be trying to buy something.", TP);
    if(!TP->query_funds(cointype, cost)) {
//        if ((int)TP->query_money(cointype) < cost) {
        tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^You don't have enough money!");
        tell_room(ETO,"%^MAGENTA%^"+TOQCN+" says:  %^RESET%^You need "+cost+" "+cointype+".");
            return 1;
//    }
    }

    if (ob->is_plate()) {
        if ((int)TP->query_level() < 7) {
            write("The shop refuses by orders of the King to sell that item to someone as inexperienced as yourself!");
            return 1;
        } else {
            ob->check_plate(TP,ob);
            write("The armor is fitted to your body size and shape.");
        }
    }
    write("Here is your "+str+" for "+cost+" gold!");
    message("other_action", query_cap_name()+" hands "+TPQCN+" "+(string)ob->query_short()+".", ETO, ({ TP,TO}));
    message("other_action", query_cap_name()+" hands you "+(string)ob->query_short()+".", TP);
    TP->add_money(ob->query_cointype(), -cost);
    storage->set_property("funds", cost*2/3);
    ob->remove_property("pstore_value");
    ob->remove_property("pstore_cust");
    if (ob->move(TP)) {
        message("my_action", "You drop it as fast as you get it!", TP);
        message("other_action", TPQCN+" drops "+(string)ob->query_short()+".", ETO,({ TP}));
        ob->move(ETO);
    }
    return 1;
}

int __Pickup(string str) {
    object ob, storage, *inv, what;
    int cost, x;
    string cointype;
    string *not_allowed;
    if(!at_shop())
	return 1;

    not_allowed = ({ "bound", "disabled" });
    if(disabled(TP, not_allowed))
	return 1;

    if (!str) {
        TP->command("help shop");
	return 1;
    }

    if (!should_interact(TP)) {
        force_me("glare "+TPQN);
        force_me("say Leave scum, we don't deal with those with your reputation.");
        return 1;
    }
    if (!TP->is_player() && member_array(TP->query_race(),RACE_D->query_races())== -1) {
        force_me("say We don't deal with your kind around here.");
        return 1;
    }
    if(member_array("letters", ETO->query_allowed()) != -1) {
        if(str != "letter" && str != "letters")
	    return notify_fail("Try <pickup letter>\n");
 	pickup_letter(TP);
	return 1;
    }

    storage = find_object_or_load(ETO->query_drop_storage());
    inv = all_inventory(storage);
    for(x=0; x<sizeof(inv); x++) {
    	if(!inv[x]->query_property("pstore_value")) continue;
	if(inv[x]->id(str) && inv[x]->query_property("pstore_cust") == TPQN) {
	   what = inv[x];
// I'm not sure how to make it quit checking at this point or deal with choosing a second one but they should be picking up everything ready anyway.  *Styx*  1/25/03
        }
    }
    if(!what) {
	tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^We don't seem to have a "+str+" ready for you.");
	return 1;
    }
    cost = (int)what->query_property("pstore_value");
    cointype = "gold";
    cost = adjust_cost(cost);
//    if ((int)TP->query_money(cointype) < cost) {
//        convert_money(cointype,cost);
    tell_room(ETO, TPQCN+" seems to be trying to deal with the clerk.", TP);
    if (!TP->query_funds(cointype, cost)) {
        tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^You don't have enough money!");
        tell_room(ETO,"%^MAGENTA%^"+TOQCN+" says:  %^RESET%^You need "+cost+" "+cointype+" to pick up your "+str+".");
            return 1;
//        }
    }
    write("Here is your "+str+", all repaired for a mere "+cost+" gold!");
    tell_room(ETO, TOQCN+" hands "+TPQCN+" "+(string)what->query_short()+".", TP);
    tell_object(TP, TOQCN+" hands you "+(string)what->query_short()+".");
    TP->use_funds(cointype, cost);
    storage->set_property("funds", cost*2/3);
    what->remove_property("pstore_value");
    what->remove_property("pstore_cust");
    if (what->move(TP)) {
        tell_object(TP, "You drop it as fast as you get it!");
        tell_room(ETO, TPQCN+" drops "+(string)what->query_short()+".", TP);
        what->move(ETO);
    }
    return 1;
}

int __Show(string str) {
    object ob;
    string *not_allowed;
    string storage, what, whom;
    if(!at_shop())
	return 1;
    not_allowed = ({ "bound", "disabled" });
    if(disabled(TP, not_allowed))
	return 1;

    if (!str) {
        write("Try 'show <item id>'.");
        return 1;
    }
    if(str == "letter" || str == "letters")
	return notify_fail("It's going to look like a letter silly.\n");
    if(sscanf(str, "%s to %s",what, whom) == 2)
	return 0;   // to allow normal show command to work
    if( (string)ETO->query_storage() == "none set")
	   return notify_fail("There is no storage room with items to show you.\n");
    storage = find_object_or_load(ETO->query_storage());
    if (!(ob = present(str, storage)) && !(ob = parse_objects(storage))) {
        write("%^MAGENTA%^"+TOQCN+" says: %^RESET%^I don't have a "+str+" to show you.");
        return 1;
    }
    tell_object(TP,TOQCN+" shows you "+(string)ob->query_short()+".");
    tell_room(ETO, TOQCN+" shows "+TPQCN+" "+(string)ob->query_short()+".", TP);
    message("info", (string)ob->query_long(), TP);
    if(ob->is_weapon()) {
	   if(ob->is_lrweapon()) {
	        tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says: %^RESET%^To use this as a ranged weapon, you'll have to visit the archery range and train in the use of "+ob->query_lr_prof_type()+".");
        }
	    else {
            tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says: %^RESET%^To use this well, you'll need to be trained in the use of "+ob->query_prof_type()+".");
        }
    }
    if(ob->is_armor()) {
       tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says: %^RESET%^This particular item is classed as "+ob->query_type()+".");
    }
    if(ob->query_property("pstore_value")) {
        tell_room(ETO,"%^MAGENTA%^"+TOQCN+" says:  %^RESET%^This item "+
        "will cost you "+adjust_cost((int)ob->query_property("pstore_value"))+
        " gold coins.%^RESET%^");
    }
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

    if(!str || sscanf(str, "for %s",what) != 1)
	return notify_fail("Try 'list for sale' or 'list for pickup'.\n");
    if(what != "sale" && what != "pickup")
	return notify_fail("Try 'list for sale' or 'list for pickup'.\n");
    if(what == "sale")
	storage = find_object_or_load(ETO->query_storage());
    if(what == "pickup")
	storage = find_object_or_load(ETO->query_drop_storage());
    inv = all_inventory(storage);
    if (!sizeof(inv)) {
	tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^Sorry, I have nothing on hand today.");
        return 1;
    }
    inv = sort_array(inv,"sort_items",TO);
    tell_room(ETO,TPQCN+" looks around carefully, checking out the inventory.", TP);
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
//	if(TP->isKnown(lower_case(who)))    don't think I need this for here...
//	   who = (string)TP->knownAs(who);
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

int __Leave(string str) {
    object ob, storage, *inv;
    string response;
    int cost, count, x, letter;
    string cointype, whom, name;
    string *not_allowed;
    if(!at_shop())
	return 1;

    not_allowed = ({ "bound", "disabled" });
    if(disabled(TP, not_allowed))
	return 1;
    if (!str) {
        TP->command("help shop");
	return 1;
    }

    if (!should_interact(TP)) {
        force_me("glare "+TPQN);
        force_me("say Leave scum, we don't deal with those with your reputation.");
        return 1;
    }
    if (!TP->is_player() && member_array(TP->query_race(),RACE_D->query_races())== -1) {
        force_me("say We don't serve your kind around here.");
        return 1;
    }
    response = "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^";
// if they mention a letter or paper at all do this stuff
    if(strsrch(str, "letter") != -1 || strsrch(str, "paper") != -1) {         if(sscanf(str,"letter for %s", whom) != 1)
	  return notify_fail("Try <leave letter for [name]>.\n");
       if(!ob = present("paper", TP)) {
          tell_room(ETO, response+"You don't seem to have a letter to leave.");
          return 1;
       }
       if(delivering) {
	  tell_room(ETO, response+"You'll have to wait until we've finished with the last one.");
          return 1;
       }
/*  let them leave a letter for someone they have only heard of since it's all IC and they
might have IC reasons to try to contact someone they have only heard of
       if(name == "")
	   return notify_fail("You must give a name you know someone as.\n");
*/
        name = TP->realName(whom);
	if(name == "")   name = whom;
        ob->remove_property("pstore_mailto");
	ob->set_property("pstore_mailto", whom);
        ob->remove_property("pstore_cust");
	ob->set_property("pstore_cust", name);
        letter = 1;
    }

    if(!letter) {
       if (!(ob = present(str, TP))) {
          tell_room(ETO, response+"You don't seem to have any "+str+" to leave.");
          return 1;
       }
       if (check_allowed(ob) == 0) {
          tell_room(ETO, response+"Sorry, we don't handle that type item.");
          return 1;
       }
    }
    cost = ETO->query_deposit();
    cointype = "gold";
    cost = adjust_cost(cost);
    if(!TP->query_funds(cointype, cost)) {
	tell_room(ETO, TPQCN+" seems to be discussing price with the clerk.", TP);
        tell_room(ETO, response+"You don't have enough money for the deposit!");
        tell_room(ETO, response+"I'm sorry, but the fee for leaving that is "+cost+
		" "+cointype+".");
        return 1;
    }
    storage = find_object_or_load(ETO->query_drop_storage());
    inv = all_inventory(storage);
// removing this as old players have left vast stockpiles behind, making these non-functional. N, 4/12
/*    if (sizeof(inv) >= MAX_ITEMS) {
        tell_room(ETO, response+"Sorry, we already have too much that has been left and not picked up!");
        return 1;
    } */
// don't want to let people abuse it as personal storage
    for (x=0, count = 0; x<sizeof(inv); x++) {
        if(living(inv[x]))  continue;
	if(inv[x]->query_property("pstore_cust") == TPQN)
	   count++;
    }
    if(!letter) {
      if(count > 1) {
	tell_room(ETO, TOQCN+" checks a list and responds to "+TPQCN+".", TP);
	tell_room(ETO, response+"I'm sorry, but you already have too many items here that haven't been picked up.");
	return 1;
      }
      if (ob->query_worn()) {
        tell_room(ETO, response+"Please remove your "+str+" so you can leave it.");
        return 1;
      }
      if (ob->query_wielded()) {
        tell_room(ETO, response+"Please unwield your "+str+" so you can leave it.");
        return 1;
      }
    }
    if(letter) {
	delivering = 1;
        write("You hand the clerk the letter for "+capitalize(whom)+".");
	leave_letter(TP, 0);
	ob->add_id("letter");
    }  else {
	tell_room(ETO, TOQCN+" takes the "+(string)ob->query_short()+" and locks it away.");
	tell_room(ETO, response+"Check back in a few days to see if it's ready.");
	ob->remove_property("pstore_cust");
	ob->set_property("pstore_cust", TPQN);
    }
    TP->use_funds("gold", cost);
    storage->set_property("funds", cost*2/3);
    ob->move(storage);
    return 1;
}

void leave_letter(object cust, int step) {
   write("The clerk puts your money and the letter away carefully.");
   tell_room(ETO, cust->query_cap_name()+" hands the clerk a letter who then puts it into storage.", cust);
   delivering = 0;
}

void pickup_letter(object cust) {
   int x;
   object *inv, *what;
   what = ({});
   inv = all_inventory(find_object_or_load(ETO->query_drop_storage()));
   for(x=0; x<sizeof(inv); x++) {
      if(inv[x]->id("paper") && inv[x]->query_property("pstore_cust") == cust->query_name()) {
	 what += ({ inv[x] });
      }
   }
   if(!sizeof(what)) {
      tell_room(ETO, "%^MAGENTA%^"+TOQCN+" checks the log book and then says:  %^RESET%^We don't seem to have any letters for you.");
      return 1;
   }
   pickup_actions(cust, what, 0);
   return 1;
}

void pickup_actions(object cust, object *what, int step) {
    int num = sizeof(what);
    if(num == 1) {
      tell_room(ETO, TOQCN+" hands "+cust->query_cap_name()+" a folded piece of paper.", cust);
      tell_object(cust, TOQCN+" hands you a folded piece of paper.");
    } else {
      tell_room(ETO, TOQCN+" hands "+cust->query_cap_name()+" %^BOLD%^"+num+"%^RESET%^ pieces of paper.", cust);
      tell_object(cust, TOQCN+" hands you %^BOLD%^"+num+"%^RESET%^ pieces of paper.");
    }
    del_letter(cust, what);
}

void del_letter(object cust, object *what) {
   int x;
   for(x=0; x<sizeof(what); x++) {
      what[x]->remove_property("pstore_cust");
      if(what[x]->move(cust)) {
         tell_object(cust, "You drop it as fast as you get it!");
         tell_room(ETO, cust->query_cap_name()+" drops a letter.", cust);
         what[x]->move(ETO);
      }
   }
   delivering = 0;
}

int __Help(string str) {
   if (!str) return 0;
   if(base_name(ETO) != query_shop())
      return 0;
   if (strcmp("shop",str) != 0) return 0;
   if(member_array("letters", ETO->query_allowed()) != -1) {
      write(
"
Commands available are:

 %^ORANGE%^<leave letter for %^ORANGE%^%^ULINE%^NAME%^RESET%^>%^RESET%^     leave paper (the letter) for %^ORANGE%^%^ULINE%^NAME%^RESET%^ to pick up
 %^ORANGE%^<pickup letter>%^RESET%^	     pick up a letter left for you

Note: You will only be able to pick up letters left for your real name OR by people who have you recognized and leave it for you as the name they recognized you by.
"
      );

   } else {
      write(
@STYX
Commands available are:

  <list for sale>	list items for sale
  <list for pickup>	see if you have something to pick up & the price
  <leave [item]>	leave an item for repair (requires paying a deposit)
  <show [item]>		to get a better look at an item for sale
  <buy [item]>		buy an item for sale
  <pickup [item]>	pick up item that has been repaired or left for you
STYX
     );
   }
    return 1;
}

reset ()
{
    ::reset();
}
