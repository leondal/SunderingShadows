// inheritable for player owned stores & repair shops by *Styx* 12/2002
// the room handles the owner-specific functions
// it needs a clerk that inherits /std/vendor_pstore for the non-owner functions
// uses recognized names up to a point, but has limitations

/* key features & info. to set in create() of player store:

1)  set_storage("filename");  & set_drop_storage("filename");
    > be sure the storage room files include: 
  	a)  remove_property("no teleport") and THEN
	b)  set_property("no teleport")
      		(need to remove first because otherwise it increments each time
		restoring from the last setting)
	c)  set_no_clean(1);    to keep objects from getting zapped by clean_up
	d)  set_storage(1); and
	e)  restore_room(); at the end of the create function
2)  If accepts items for repair or pickup by another, must have
	set_drop_deposit(int) (will be in gold)
3)  set_owners( ({ "name", "name" }) )
4)  set_items_allowed( ({ "armor", "clothing", etc. }) ) 
     >> valid types are armor, clothing, jewelry, material, weapon, letters
     >> added type "letters" for Stefano's idea of an IC mail drop & pickup 2/22/03
	restrict it according to the nwps of the owner/use of the shop for most cases
5)  #define MAX_ITEMS #
	preferably 10 or less, it will count each storage room separately
*/
// added so avatars can perform all owner commands *Styx* 9/30/06, last chg. 7/24/05

#include <std.h>
#include <daemons.h>
#include <money.h>

inherit VAULT;

#define MAX_ITEMS 20

void set_owners(string *str);
void set_storage(string str);
void set_drop_storage(string str);

string StoreRoom;
string DropStoreRoom;
string *owners, *allowed;
int deposit;

int check_allowed(object ob);
// string types(object ob);

void create() {
    ::create();
}
void init() {
    ::init();
    add_action("__Deposit", "deposit");
    add_action("__Price", "price");
    add_action("__Check", "check");
    add_action("__Retrieve", "retrieve");
//    add_action("__Show", "show");
    add_action("__Help", "help");
}


int clean_up() {  return 1; }  // should we let it clean up???? *Styx* 1/19/03

void set_owners(string *str) {
   if(!owners)  owners = ({});
   owners = str;
}

void query_owners() {
   if(!owners)  owners = ({});
   return owners;
}

void set_drop_storage(string str) {
    DropStoreRoom = str;
}

string query_drop_storage() { 
    if(!DropStoreRoom)
	return "none set";
    return DropStoreRoom; 
}

void set_storage(string str) {
   StoreRoom = str;
}

string query_storage() { 
    if(!StoreRoom)
	return "none set";
    return StoreRoom;  
}

void set_drop_deposit(int x) {
   deposit = x;
}

int query_deposit() {
   if(!deposit)
	return 200;
   return deposit;
}

void set_items_allowed(string types) { 
// valid types are armor, clothing, jewelry, material, weapon
// added letters 2/22/03 *Styx*
    allowed = types; 
}

string query_allowed() {
   if(!allowed)  allowed = ({});
   return allowed;
//   if (!TO->query("items_allowed"))
//      TO->set_items_allowed("all");  make this none if not set?
}

int check_allowed(object ob) {
    string type;
    type = (string)ob->query_type();
    if(!allowed)   return 0;
    if(ob->is_weapon() && member_array("weapon", allowed) != -1)  
	return 1;
    if(ob->is_armor()) {
	if(member_array("armor", allowed) != -1 && type != "clothing" && type != "ring") 
   	   return 1;
	if(member_array("clothing", allowed) != -1 && type == "clothing")				   return 1;
	if(member_array("jewelry", allowed) != -1 && (type == "ring" || type == "bracer"))	   return 1;
    }
    if(ob->is_material() && member_array("material", allowed) != -1)  
	return 1;
    if((string)ob->query_name() == "paper" && member_array("letters", allowed) != -1)  
	return 1;
    return 0;
}

int check_deposit() {
    int deposit;
    deposit = query_deposit();
    if(member_array(TPQN, owners) != -1 || avatarp(TP)) {
	write("The deposit required for others to leave items is currently "+deposit+" gold.");
	return 1;
    }
    return deposit;
}

int __Price(string str) {
    object ob;
    string what;
    int value;
    if(TP->query_unconscious())
	return notify_fail("Not in your current state!\n");
    if(TP->query_bound() || TP->query_paralyzed()){
	TP->send_paralyzed_message("info",TP);
	return 1;
    }

    if(member_array(TPQN, owners) == -1 && !avatarp(TP))
	return notify_fail("You're not an owner here and not allowed.\n");
    if(!str || sscanf(str,"%s at %d",what, value) != 2) 
	return notify_fail("Try 'price <item> at <value>'.\n");
    if(value < 1)
	return notify_fail("No, you can NOT make it negative!");
    if(!(ob = present(what, TP))) {
        write("You don't have a "+what+"!");
        return 1;
    }
    if(!allowed)
	return notify_fail("Your shop doesn't seem to be able to deal in anything.\n");
    if(check_allowed(ob) == 0)
	return notify_fail("Your shop doesn't handle those kinds of items.\n");
// If we don't remove the property, it adds to the last set value
    ob->remove_property("pstore_value");
    ob->set_property("pstore_value", value);
    write("You set the value of "+what+" at "+value+" for your store.");
    return 1;
}

int __Deposit(string str) {
    object ob, storage;
    string what, who, name;
    if(TP->query_unconscious())
	return notify_fail("Not in your current state!\n");
    if(TP->query_bound() || TP->query_paralyzed()){
	TP->send_paralyzed_message("info",TP);
	return 1;
    }

    if(member_array(TPQN, owners) == -1 && !avatarp(TP))
	return notify_fail("You're not an owner here and not allowed.\n");
    if(!str || sscanf(str,"%s for %s",what, who) != 2) 
	return notify_fail("Try 'deposit <item> for <who|sale>'.\n");
    if(!(ob = present(what, TP))) {
        write("You don't have a "+what+"!");
        return 1;
    }
    if(!allowed)
	return notify_fail("Your shop doesn't seem to be able to deal in anything.\n");
    if(check_allowed(ob) == 0)
	return notify_fail("Your shop doesn't handle those kinds of items.\n");
    if(!ob->query_property("pstore_value")) 
	return notify_fail("You need to set a price on it first.\n");
    if(who == "sale") {
        storage = find_object_or_load(query_storage());
	if (sizeof(all_inventory(storage)) >= MAX_ITEMS)
           return notify_fail("Sorry, we haven't sold what is there already.\n");
	write("You put the "+what+" out for sale in your shop.");
        tell_room(TO, TPQCN+" puts "+what+" out for sale in the shop.", TP);
	  if(ob->query_item_owner_prop("sale_clear")) ob->clear_item_owners(); //remove soulbind in shop code
        ob->remove_property("pstore_cust");
    }
//    if(who != "sale" && who = "owner") {
    if(who != "sale") {
        storage = find_object_or_load(query_drop_storage());
	if (sizeof(all_inventory(storage)) >= MAX_ITEMS)
           return notify_fail("Sorry, we have too much in deposited storage already.\n");
	if(ob->query_property("pstore_cust")) {
	   if(who == "owner") {
	      who = ob->query_property("pstore_cust");
	      if(!who)
		return notify_fail("You can't leave it for the owner if you don't have one on record.\n");
//	   } else {
//	      who = ob->query_property("pstore_cust");
	   if(TP->isKnown(lower_case(who)))
	       who = (string)TP->knownAs(who);
           } else {
	   ob->remove_property("pstore_cust");
	   }
	}
 	if(!ob->query_property("pstore_cust")) {
	   name = TP->realName(who); 
	   if(name != "")  
	      ob->set_property("pstore_cust", name);
	   else ob->set_property("pstore_cust", who);
	}
	write("You store the "+what+" for "+capitalize(who)+" to pick up.");
	tell_room(TO,TPQCN+" puts "+what+" into storage.", TP);
    }
    ob->move(storage);
    return 1;
}

int __Retrieve(string str) {
    object ob, storage;
    string what, where;
    if(TP->query_unconscious())
	return notify_fail("Not in your current state!\n");
    if(TP->query_bound() || TP->query_paralyzed()) {
	TP->send_paralyzed_message("info",TP);
	return 1;
    }

    if(member_array(TPQN, owners) == -1 && !avatarp(TP))
	return notify_fail("You're not an owner here and not allowed.\n");
    if(!str || sscanf(str,"%s from %s",what, where) != 2) 
	return notify_fail("Try 'retrieve [item] from [inventory|drops]'.\n");
    if(where != "inventory" && where != "drops")
	return notify_fail("Try 'retrieve [item] from [inventory|drops]'.\n");
    if(where == "inventory") {
        if(query_storage() == "none set") 
	   return notify_fail("You don't have a storage room for inventory.\n");
	storage = find_object_or_load(query_storage());
    }
    if(where == "drops") {
        if(query_drop_storage() == "none set") 
	   return notify_fail("You don't have a storage room for customers to leave items.\n");
	storage = find_object_or_load(query_drop_storage());
    }
    if (!(ob = present(what, storage)) && !(ob = parse_objects(storage)) ) 
        return notify_fail("There is no "+what+" in your storage room.\n");
    write("You retrieve "+ob->query_short()+" from your storage room.");
    tell_room(TO, TPQCN+" retrieves "+ob->query_short()+" from the storage room.", TP);
    if(ob->move(TP)) {
        write("You drop it as fast as you get it!");
        tell_room(TO, TPQCN+" drops "+ob->query_short()+".", TP);
        ob->move(ETP);
    }
//    ob->remove_property("pstore_drop");  using pstore_cust & want to leave it
    return 1;
}

int __Check(string str) {
    string *inv, *tmp, short, who, name;
    object storage;
    int num, x;
    if(TP->query_unconscious())
	return notify_fail("Not in your current state!\n");
    if(TP->query_bound() || TP->query_paralyzed()) {
	TP->send_paralyzed_message("info",TP);
	return 1;
    }

    if(member_array(TPQN, owners) == -1 && !avatarp(TP))
	return notify_fail("You're not an owner here and not allowed.\n");
    if(str == "deposit") {
	check_deposit();
	return 1;
    }
    if(!str || (str != "inventory" && str != "drops" && str != "funds")) 
	return notify_fail("Try <check inventory>, <check drops>, or <check funds>.\n");
    if(str == "funds") {
	write("You flip to the back of the clerk's log book.");
	if(query_storage() != "none set")
	   write("You find the clerk has logged %^YELLOW%^"+find_object_or_load(query_storage())->query_property("funds")+" gold %^RESET%^after expenses for sales thus far.");
	if(query_drop_storage() != "none set")
	   write("You find a tally in the log of%^YELLOW%^ "+find_object_or_load(query_drop_storage())->query_property("funds")+" gold %^RESET%^left from deposits or fees.");
	tell_room(TO, TPQCN+" flips to the back of the clerk's log book.", TP);
	return 1;
    }
    if(str == "inventory") {
        if(query_storage() == "none set") 
	   return notify_fail("You don't have a storage room for inventory.\n");
	storage = find_object_or_load(query_storage());
    }
    if(str == "drops") {
        if(query_drop_storage() == "none set") 
	   return notify_fail("You don't have a storage room for customers to leave items.\n");
	storage = find_object_or_load(query_drop_storage());
    }
    inv = all_inventory(storage);
    num = sizeof(inv);
    if(!num)  {
	write("That store room is empty!");
	return 1;
    }
//    inv = sort_array(inv,"sort_items",TO);
    if(!avatarp(TP))
       tell_room(TO,TPQCN+" looks around carefully, checking on things.", TP);

    write("%^YELLOW%^ Description				       Price	 Customer");
    write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    for (x=0, tmp = ({}); x<num; x++) {
        if(living(inv[x]))  continue;
	short = inv[x]->query_short();
        if(strlen(short) > 44)
//	   short = short[0..43] + "~ ";
           short = arrange_string(short,43);
// the above apparently works better with color codes, from the fix to vendor_pstore *Styx* 6/13/05
        who = inv[x]->query_property("pstore_cust");
        if(!who)  who = "general sale";
	if(TP->isKnown(lower_case(who)))
	   who = (string)TP->knownAs(who);
        tmp +=({ sprintf("%%^BOLD%%^%%^GREEN%%^%-45s %%^YELLOW%%^%5d %%^WHITE%%^%-5s %-20s",
	   short,inv[x]->query_property("pstore_value"),"gold", capitalize(who) ) 
	});
    }
    tmp += ({"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="});
    TP->more(tmp);
    return 1;
}

int __Help(string str) {
   if(member_array(TPQN, owners) != -1 || avatarp(TP)) {
      if(!str || (str != "store" && str != "shop")) {
	 write("You probably want <help store> for owner commands or maybe "
		"<help shop> for customer commands.\n");
	 return 1;
      }
      if(str == "store")
      write(
@STYX
As a store owner, you can do the following:
	price [item] at [amount]    (in gold - must do before deposit into storage)
	deposit [item] for sale
	deposit [item] for owner    
	   (for the same person that left it with the clerk to pick up after repair)
	deposit [item] for [name]   (for [name] to pick up after repair)
	check [inventory | drops]   (see items in stock or left for repair or pickup)
	check deposit		    (check the deposit required for items being left)
	check funds		    (check the balance of funds collected)
					note, there are expenses too...	
	retrieve [item] from [inventory|drops]  (get item from storage rooms)
STYX
         );
      return 1;
   }
   return 0;
}
