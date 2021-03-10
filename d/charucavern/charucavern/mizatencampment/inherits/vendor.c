//      /std/shop.c
//      a standard object that sells things in shops
//      created by Melnmarn @ ShadowGate

//	This file has been changed by Melnmarn@ShadowGate
//	Do *NOT* alter this file without permission from
//	Melnmarn or Aragorn @ Shadowgate!
//  moved adjust_cost() to /std/npc so avail. for special vendors such as comp_vend
/*  changed to have vendors seem more interactive, esp. to indicate to room that someone is interracting with the vendor   *Styx*  Jan. 03
    added to have vendor tell what skill is needed on show command *Styx*  2/13/03
    also added to deny buying if no coin type is set (solve kit problem)
*/
//changed it so that you cannot buy, sell or get an appraisal from an unconscious vendor *tsera* 4/2/04
/*
Changed by Circe 3/19/05
This change should make it so we can set a maximum level on
the vendor that will control the value and/or power of items
that can be sold in the shop.  Essentially, vendors will have
a property set_mymaxvalue() that will be a number 1-40.
This will make it so that anything above a certain value
(defined below) or a certain enchantment will still be sold,
but won't go into the shop's storage area to be re-sold to the
public.  The set_mymaxvalue() should be basically the level
of the players who should frequent the area.
*/

//Minor change 6/14/05 by ~Circe~ to allow showing by size.
//Made selling items populate the random search treasure -Ares

#include <std.h>
#include <money.h>
#include <daemons.h>
#include <objects.h>

#define MAX_ITEMS 75
#define VALUES ({50,100,150,200,250,300,400,500,600,700,800,900,1000,1150,1300,1500,1700,1900,2100,2300,2500,2700,2900,3100,3300,3600,3900,4200,4500,4800,5100,5400,5700,6000,6300,6600,6900,7200,7500,7800})

inherit "/std/npc";

mapping __Eco, __Values;
int query_mymaxvalue();
int mymaxvalue;
int convert_money(string cointype,int amount);
int is_fence;
mixed sort_items(object one, object two);
int check_allowed(object ob);
string types(object ob);
string *factionofficials = ({});
string myfaction;

void init() {
    ::init();
    add_action("__Buy", "buy");
    add_action("__Sell", "sell");
    add_action("__Show", "show");
    add_action("__List", "list");
    add_action("__Value", "value");
    add_action("__Help", "help");
    add_action("inventory", "inventory");

    add_action("__Repair","repair"); // adding functionality to vendors to repair items for people -Ares
    add_action("__Resize","resize"); // throwing HM command in here so imms don't have to - N
}

void set_is_fence(int x) {
    is_fence = x;
}

void heart_beat() {
    ::heart_beat();
}

void create() {
    ::create();
    __Eco = ([ "storage object" : 0, "storage file" : 0]);
    __Values = ([]);
    //   set_db("vendor");
}


void set_mymaxvalue(int x){
   mymaxvalue = x;
}

int query_mymaxvalue(){
   return mymaxvalue;
}

int __Buy(string str) {
    object ob;
    string tmp;
    int cost, x,lvl;
    string cointype, *not_allowed, response;

    if (!str) {
        write("Try 'buy <item> [#]'!");
        return 1;
    }
    not_allowed = ({ "bound", "disabled", "unconscious" });
    if(disabled(TP, not_allowed))
	return 1;
    if(disabled(TO, not_allowed)){
      write("Do you really expect someone who cannot move to sell you something?");
	return 1;
    }
    response = "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^";
    if (!should_interact(TP)) {
        force_me("glare "+TPQN);
        force_me("say Leave my shop, scum, I will not serve you.");
        return 1;
    }
    if (!TP->is_player() && member_array(TP->query_race(),RACE_D->query_races())== -1) {
        force_me("say We don't serve your kind around here.");
        return 1;
    }
    if (!__Eco["storage object"]) {
        __Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
    }
    if (!(ob = present(str, __Eco["storage object"])) && !(ob = parse_objects(__Eco["storage object"]))) {
	tell_room(ETO, TPQCN+" asks the shopkeeper about an item.", TP);
        tell_room(ETO, response+"I don't have any "+str+"s to sell you!");
        return 1;
    }
     cost = (int)ob->query_value();

    if (ob->query_property("enchanted"))
        cost = cost * query_property("enchantment");
    cost = adjust_cost(cost);
    cointype = (string)ob->query_cointype();
    if ((int)this_player()->query_money(cointype) < cost) {
        convert_money(cointype,cost);
        if ((int)this_player()->query_money(cointype) < cost) {
            tell_room(ETO, response+TPQCN+", you don't have enough money for that!", TP);
	    tell_object(TP, response+"You don't have enough money.");
            tell_room(ETO, response+"You need "+cost+" "+ob->query_cointype()+".");
            return 1;
        }
    }
    if (ob->is_plate()) {
        if ((int)TP->query_level() < 7) {
	    tell_room(ETO, TPQCN+" seems to be trying to buy a suit of full plate.", TP);
            tell_room(ETO, response+"It took far too much time to make such plate to sell it to someone as inexperienced as yourself!");
            return 1;
        } else {
            ob->check_plate(TP,ob);
            write("The armor is fitted to your body size and shape.");
	    tell_room(ETO, "The clerk fits the armor to "+TPQCN+"'s height and weight.", TP);
        }
    }
    if(ob->is_factionitem()){
       myfaction = ob->query_factionitem();
       factionofficials = "/daemon/save_area_lists_d.c"->query_jailer_names(myfaction);
       if(member_array(TPQN,factionofficials) == -1){
          tell_room(ETO, response+"I'm sorry.  I can only sell that to officials of "+myfaction+".");
          return 1;
       }else{
          ob->check_factionitem(TP,ob);
          tell_room(ETO,response+"Here you are...fitted just for you!");
       }
    }
//added the above faction stuff to allow for faction-specific
//items.  ~Circe~ 11/24/07
/*Below stuff about levelrestrict is set up to allow restriction of items to certain levels ~Circe~ 1/19/08*/
    if(ob->query_property("levelrestrict")){
       lvl = ob->query_property("levelrestrict");
       if((int)TP->query_lowest_level() < lvl){
          tell_object(ETO,response+"I'm sorry.  You are not "+
             "experienced enough to buy that yet.");
          return 1;
       }
    }
    tell_room(ETO, response+"Here is your "+str+" for "+cost+" "+ob->query_cointype()+"!");
    tell_room(ETO, TOQCN+" hands "+TPQCN+" "+(string)ob->query_short()+".", TP);
    tell_object(TP, TOQCN+" hands you "+(string)ob->query_short()+".");
    TP->add_money(ob->query_cointype(), -cost);
    if (ob->move(TP)) {
        tell_object(TP, "You drop it as fast as you get it!");
        tell_room(ETO, TPQCN+" drops "+(string)ob->query_short()+".", TP);
        ob->move(ETO);
    }
    return 1;
}

//maxvalue stuff added by Circe 3/19/05
int __Sell(string str) {
    object ob;
    string tmp, response;
    int value, mymax, maxenchant, myenchant;

    if (!str) {
        write("Try 'sell <object>'!");
        return 1;
    }
    if(disabled(TP, ({"disabled", "unconscious"})) )
	return 1;
    if(disabled(TO, ({"disabled", "unconscious", "bound"})) ){
      write("Do you really expect a person who cannot move to buy something?");
	return 1;
    }
    if (!should_interact(TP)) {
        force_me("glare "+TPQN);
        force_me("say Leave my shop, scum, I will not serve you.");
        return 1;
    }
    if (!TP->is_player() && member_array(TP->query_race(),RACE_D->query_races())== -1) {
        force_me("say We don't serve your kind around here.");
        return 1;
    }
    response = "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^";
    tell_room(ETO, TPQCN+" seems to be discussing something with the vendor.", TP);
    if (!__Eco["storage object"])
        __Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
    if (sizeof(all_inventory(__Eco["storage object"])) >= MAX_ITEMS) {
        tell_room(ETO, response+"Sorry, I can't get rid of what I have now!");
        return 1;
    }
    if (!(ob = present(str, TP))) {
        tell_room(ETO, response+"You don't have any "+str+" to sell!");
        return 1;
    }
    if (check_allowed(ob) == 0) {
        tell_room(ETO, response+"Sorry, I don't deal in "+str+"s!");
        return 1;
    }
    if (ob->query_property("no_profit")||ob->query_property("plot_item")||ob->query_property("soulbound")) {
      tell_room(ETO, response+"Sorry, I can't buy that "+ob->query_short()+"!");
      return 1;
    }
    if (!(value = (int)ob->query_value())) {
        tell_room(ETO, response+"That "+str+" is worthless.");
        return 1;
    }
    if (!ob->query_cointype()) {
        tell_room(ETO, response+"I wouldn't know how much to give you for that "+str+".");
        return 1;
    }
    if (ob->query_worn()) {
        tell_room(ETO, response+"Please remove that before selling it.");
        return 1;
    }
    if (ob->query_wielded()) {
        tell_room(ETO, response+"Please unwield that before selling it.");
        return 1;
    }
    //Added by Saide to support the new soulbound/ownered
    //item code - 3/21/2007
    if(ob->query_item_owner_prop("sale_clear"))
    {
        ob->clear_item_owners();
    }
	//this mymax check is here so it will bypass this code if the vendor has no max set
	//This starts the maxvalue code.  Circe 3/19/05
	if(mymax = TO->query_mymaxvalue())
	{
      	if(myenchant = ob->query_property("enchantment"))
		{
			switch(mymax)
			{
             		case 1..8:  maxenchant = 0;
                         	break;
             		case 9..16:  maxenchant = 1;
                          	break;
             		case 17..22: maxenchant = 2;
                          	break;
             		case 23..28: maxenchant = 3;
                          	break;
             		case 29..35: maxenchant = 4;
                         	break;
             		default: maxenchant = 5;
                          	break;
          		}
       	}
       	mymax = VALUES[mymax];
       	if((value > mymax) || (myenchant > maxenchant))
		{
          		value = value - (value/3);
          		value = adjust_cost(value,1);
          		TP->add_money(ob->query_cointype(), value);
          		if(myenchant > 0)
			{
             		force_me("say Whoa, well, let's see...I think I might know "+
                		"someone with a heavy purse who's interested in something "
				"like this.  Let's just put that away...");
          		}
			else
			{
             		force_me("say Well, now, this might be a little "+
				"much to just keep lying around.");
			}
          		force_me("emote puts the "+ob->query_short()+" away in a safe place.");
          		tell_room(ETO, TPQCN+" sells "+(string)ob->query_short()+".",TP);
          		tell_object(TP, "You sell "+(string)ob->query_short()+
			" for "+value + " " +ob->query_cointype()+".");
          		"/daemon/search_d.c"->add_object(ob);// added to populate the search table -Ares
          		ob->remove();
          		return 1;
       	}
    	}
    	//this ends the maxvalue code

    	value = value - (value/3);

    	value = adjust_cost(value,1);
    	TP->add_money(ob->query_cointype(), value);
    	tell_room(ETO, TPQCN+" sells "+(string)ob->query_short()+".",TP);
   	tell_object(TP, "You sell "+(string)ob->query_short()+
	" for "+value + " " +ob->query_cointype()+".");
    	if (ob->query_destroy())
	{
		"/daemon/search_d.c"->add_object(ob);
		ob->remove();
	}
    	else
	{
//                 "/daemon/search_d.c"->add_object(ob);// added to populate the search table -Ares
// was glitching & spamming the bug log, commenting out til it can be fixed. N, 4/14.
        	ob->move(__Eco["storage object"]);
        	return 1;
    	}
    	if (ob) destruct(ob);
    	return 1;
}

int __Show(string str) {
    object ob;
    string what, whom, cost;
    if (!str) {
        write("Try 'show <object>'.");
        return 1;
    }
    if(disabled(TP, ({"disabled", "unconscious"})) )
	return 1;
    if(disabled(TO, ({"disabled", "unconscious", "bound"})) ){
      write("Get real.");
	return 1;
    }
    if(sscanf(str, "%s to %s",what, whom) == 2)
	return 0;   // to allow normal "show something to someone" to work *Styx* 4/14/03

    tell_room(ETO, TPQCN+" asks the vendor to see a "+str+".", TP);
    if (!__Eco["storage object"])
        __Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
    if (!(ob = present(str, __Eco["storage object"])) &&
        !(ob = parse_objects(__Eco["storage object"]))) {
        tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^I don't have a "+str+" to show you.");
        return 1;
    }
    tell_object(TP,TOQCN+" shows you "+(string)ob->query_short()+".");
    tell_room(ETO, TOQCN+" shows "+TPQCN+" "+(string)ob->query_short()+".", TP);
    message("info", (string)ob->query_long(), TP);
// added to have vendor tell them the skillneeded per requests *Styx*  2/13/03
    if(ob->is_weapon())
    {
	    if(ob->is_lrweapon())
        {
            if(TP->query("new_class_type"))
            {
	            tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says: %^RESET%^To use this as a ranged weapon, you'll have to visit the archery range and train in the use of "+ob->query_weapon_prof()+" weapon proficiency.");
            }
            else
            {
                tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says: %^RESET%^To use this as a ranged weapon, you'll have to visit the archery range and train in the use of "+ob->query_lr_prof_type()+".");
            }
        }
	    else
        {
            if(TP->query("new_class_type"))
            {
                tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says: %^RESET%^To use this well, you'll need to be trained in the use of "+ob->query_weapon_prof()+" weapon proficiency.");
            }
            else
            {
                tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says: %^RESET%^To use this well, you'll need to be trained in the use of "+ob->query_prof_type()+".");
            }
        }
    }
    if(ob->is_armor())
    {
       if(TP->query("new_class_type"))
       {
//added the check for a prof to stop bug reports when certain items were shown ~Circe~ 1/3/13
           if(!ob->query_armor_prof()){
              tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says: %^RESET%^This particular piece of armor is classed as "+ob->query_type()+".");
           }else{
           tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says: %^RESET%^To use this piece of armor you must be trained in "+ob->query_armor_prof()+" armor proficiency.");
           }
       }
/*This was not working as intended because there was no check. I moved it to above ~Circe~ 1/3/13
       else
       {
           tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says: %^RESET%^This particular piece of armor is classed as "+ob->query_type()+".");
       }
*/
    }
    if(is_fence == 1) {
        //Uses the adjust_cost() override in fence.c - Saide
        cost = adjust_cost(ob) + "%^BOLD%^%^WHITE%^ credits";
    }
    else {
        cost = adjust_cost((int)ob->query_value()) + " "+ob->query_cointype() + " coins";
    }
    tell_room(ETO,"%^MAGENTA%^"+TOQCN+" says:  %^RESET%^This item "+
    "will cost you "+cost+"%^RESET%^.");
    return 1;
}

int __List(string str) {
    object *inv;
    string *tmp;
    int i, x, j;
    if(disabled(TP, ({"disabled", "unconscious"})) )
	return 1;
    tell_room(ETO, TPQCN+" looks over the shop's inventory and price list.", TP);
    while (!__Eco["storage object"]) {
        __Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
    }
    i = sizeof(inv = filter_array(all_inventory(__Eco["storage object"]), "filter_list", TO, str));
    if (!i) {
//__Eco["storage object"]->reset();
        i = sizeof(inv = filter_array(all_inventory(__Eco["storage object"]),"filter_list", TO, str));
        if (!i) {
            tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^I have nothing on hand.");
            return 1;
        }
    }
    inv = sort_array(inv,"sort_items",TO);
    write("%^YELLOW%^ Description			  Cost			 Type");
    write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    for (x=0, tmp = ({}); x<i; x++) {
	//stolen from ares token vendor to fix line wrap + color problem.
	    j =strlen("/daemon/filters_d.c"->filter_colors(inv[x]->query_short()));
        j = 39 - j;
        if (inv[x]->is_armour() || inv[x]->is_weapon()) {
            tmp +=({sprintf("%%^BOLD%%^%%^GREEN%%^%-30s %%^YELLOW%%^%4d %%^WHITE%%^%-20s %-5s",
                   inv[x]->query_short()+""+arrange_string(" ",j)
				   ,adjust_cost((int)inv[x]->query_value()),inv[x]->query_cointype(), types(inv[x]))});
        } else {
            tmp +=({sprintf("%%^BOLD%%^%%^GREEN%%^%-30s %%^YELLOW%%^%4d %%^WHITE%%^%s",
                    inv[x]->query_short()+""+arrange_string(" ",j)
					,adjust_cost((int)inv[x]->query_value()),inv[x]->query_cointype())});
        }
        if (( ( x%17 ) == 0 ) && ( x > 15 ) ) {
            tmp += ({"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="});
            if (x == 17) tmp += ({" "});
            tmp += ({"%^YELLOW%^ Description			  Cost			 Type"});
            tmp += ({"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="});
        }
    }
    tmp += ({"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="});
    TP->more(tmp);
    return 1;
}

int __Value(string str) {
    object ob;
    string tmp, cn, response;
    int value;

    if (!str) {
        write("Try 'value <object>'.");
        return 1;
    }
    if(disabled(TP, ({"disabled", "unconscious"})) )
	return 1;
    if(disabled(TO, ({"unconscious", "disabled"})) ){
      write("Do you really expect an unconscious person to give you an appraisal?");
	return 1;
    }
    if (!should_interact(TP)) {
        force_me("glare "+TPQN);
        force_me("say Leave my shop, scum, I will not serve you.");
        return 1;
    }
    tell_room(ETO, TPQCN+" asks for an appraisal.", TP);
    response = "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^";
    if (!(ob = present(str, TP))) {
        tell_room(ETO, response+"You don't have a "+str+"!");
        return 1;
    }
    if (check_allowed(ob) == 0) {
        tell_room(ETO, response+"Sorry, I don't deal in "+str+"s!");
        return 1;
    }
//    message("other_action", TPQCN+" asks for an appraisal.", ETO, ({TO,TP}));
    if (ob->query_property("no_profit")||ob->query_property("plot_item")) {
      tell_room(ETO, response+"Sorry, I can't buy that "+ob->query_short()+"!")	;
      return 1;
    }

    if (!(value = (int)ob->query_value())) {
        tell_room(ETO, response+"That "+str+" is worthless!");
        return 1;
    }
    value = value - (value/3);
    value = adjust_cost(value,1);
    tell_room(ETO, response+TPQCN+", I will offer you "+value+" "+ob->query_cointype()+" for it.", TP);
    tell_object(TP, response+"I will offer you "+value+" "+ob->query_cointype()+" for it.");
    return 1;
}

int filter_list(object ob, string str) {
    if (!objectp(ob) || !stringp(ob->query_name()) || !stringp(ob->query_short()) || ((string)ob->query_name() == "") || ((string)ob->query_short() == ""))
        return 0;
    if (!str || str == "") return 1;
    switch (str) {
    case "weapon":
    case "weapons": return(int)ob->is_weapon();
    case "armor":
    case "armour":
    case "armors":
    case "armours": return(int)ob->is_armour();
    case "bag":
    case "bags": return(int)ob->is_bag();
    case "other": return(!((int)ob->is_weapon()) && !((int)ob->is_armour()));
    case "size small": return((int)ob->query_size() == 1);
    case "size normal":
    case "size medium": return((int)ob->query_size() == 2);
    case "size large": return((int)ob->query_size() == 3);
    case "size giant": return((int)ob->query_size() == 4);
    case "size universal": return((int)ob->query_size() == 0);
    default: return((string)ob->query_type() == str || ob->id(str));
    }
    return 0;
}

protected int __SellAll() {
    object *inv;
    int i, value;
    int cp,sp,ep,gp,pp;
    string tmp;

    cp=0;sp=0;ep=0;gp=0;pp=0;

    if(disabled(TP, ({"disabled", "unconscious"})) )
	    return 1;

    if (!(i = sizeof(inv = all_inventory(TP)))) {
        write("You don't have anything to sell!");
        return 1;
    }
    while (i--) {
        if (check_allowed(inv[i]) == 0) {
            write("Sorry, I don't deal in those things!");
            continue;
        }
	if (inv[i]->query_property("no_profit")||inv[i]->query_property("plot_item")) {
           write("Sorry, I cannot buy that "+inv[i]->query_short()+"!");
	  continue;
	}

        if (!(value = (int)inv[i]->query("value"))) {
            write((string)inv[i]->query_short()+" is worthless.");
            continue;
        }
        value = value - (value / 5);
        switch ((string)inv[i]->query_cointype()) {
        case "platinum":pp += value;break;
        case "gold"    :gp += value;break;
        case "electrum":ep += value;break;
        case "silver"  :sp += value;break;
        case "copper"  :cp += value;break;
        }
        TP->add_money(inv[i]->query_cointype(), value);
        message("my_action", "You sell "+(string)inv[i]->query_short()+" for "+value+" "+inv[i]->query_cointype()+".",TP);
        message("other_action", TPQCN+" sells "+(string)inv[i]->query_short()+".", ETO, ({ TP}));
        if (inv[i]->query_destroy()) inv[i]->remove();
        else inv[i]->move(__Eco["storage object"]);
    }
    write("\nWell, let's see here. That comes to:\n");
    if ( pp > 0) write(" Total Platinum :"+pp+" pp");
    if ( gp > 0) write(" Total Gold     :"+gp+" gp");
    if ( ep > 0) write(" Total Electrum :"+ep+" ep");
    if ( sp > 0) write(" Total Silver   :"+sp+" sp");
    if ( cp > 0) write(" Total Copper   :"+cp+" cp");
    write("\nThank you for your business!");
    return 1;
}

mixed sort_items(object one,object two) {
    return strcmp(one->query_short(),two->query_short());
}

void set_storage_room(string str) {
    __Eco["storage object"] =find_object_or_load(__Eco["storage file"] = str);
    __Eco["storage object"]->set_property("no teleport",1);
}

object query_storage_room() {return __Eco["storage object"];}

void set_items_allowed( string str) {
    set("items_allowed",str);

    if (str == "armor") {
        set_nwp("armorsmithing",10);
    }
    if (str == "weapon") {
        set_nwp("weaponsmithing",10);
    }
    if (str == "clothing") {
        set_nwp("tailoring",10);
    }
    if (!(TO->query_property("generic db")))  return;
    if (str == "all" || str == "weapon") {
// removing the generic databases from being automatically added
// too spammy now that we have specific ones set or these manually added
// in the most needed places  *Styx*  12/7/02
//        set_db("weapons");
    }
    if (str == "all" || str == "armor") {
//        set_db("armors");
//        set_random_act_db("armorsrandom");
    }
    if (str == "all" || str == "misc") {
//        set_db("miscvendors");
    }
}

string query_items_allowed() {
    if (!this_object()->query("items_allowed"))
        this_object()->set_items_allowed("all");
    return this_object()->query("items_allowed");
}

int check_allowed(object ob) {
    if (strcmp("all",(string)this_object()->query_items_allowed()) == 0)
        return 1;
    if (strcmp("clothing",(string)this_object()->query_items_allowed()) == 0) {
        if ((string)ob->query_type() == "ring" || (string)ob->query_type() == "clothing") return 1;
        else return 0;
    }
    if (strcmp("misc",(string)this_object()->query_items_allowed()) == 0) {
        if (ob->is_weapon()) return 0;
        if (ob->is_armour()) return 0;
// changing to allow misc shops to buy potions & tobacco *Styx* 1/6/06
//        if (member_array("potion",ob->query_id(),0) != -1) return 0;
        if (member_array("pet",ob->query_id(),0) != -1) return 0;
        if (member_array("food",ob->query_id(),0) != -1) return 0;
        if (member_array("drink",ob->query_id(),0) != -1) return 0;
//        if (member_array("tobacco",ob->query_id(),0) != -1) return 0;
        return 1;
    }
    if (strcmp("armor",(string)this_object()->query_items_allowed()) == 0) {
        if (ob->is_armour()) return 1;
        else return 0;
    }
    if (strcmp("weapon",(string)this_object()->query_items_allowed()) == 0) {
        if (ob->is_weapon()) return 1;
        else return 0;
    }
    if((string)this_object()->query_items_allowed() == "material"){ return ob->is_material();}
    if (member_array((string)this_object()->query_items_allowed(),ob->query_id(),0) == -1)
        return 0;
    return 1;
}

void __Help(string str) {
    if (!str) return;
    if (strcmp("shop",str) != 0) return;
    this_player()->more("/std/shop.help");
    return 1;
}

void inventory() {
    object *inv;
    int i, value;
    string tmp;

    if(disabled(TP, ({"disabled", "unconscious"})) )
	    return 1;

    if (!(i = sizeof(inv = all_inventory(TP)))) {
        write("You don't have anything!");
        return 1;
    }
    write("%^CYAN%^The shop clerk looks over your inventory.");
    while (i--) {
        tmp = "";
         if ((check_allowed(inv[i]) == 0)||(!(value = (int)inv[i]->query_value()))) {
            if ((string)inv[i]->query_short() == "") continue;
            tmp += arrange_string((string)inv[i]->query_short(),46);
            tmp += "0    -----";
            write(tmp);
            continue;
        }
        value = value - (value / 3);
     value = adjust_cost(value,1);
        tmp += arrange_string((string)inv[i]->query_short(),46);
        tmp += arrange_string(value,6);
        tmp += (string)inv[i]->query_cointype();
        write(tmp);
    }
    return 1;
}

string types(object ob) {
    string type;
    string ret;
    if (ob->is_lrweapon() || ob->is_weapon())
    {
        //type = (string)ob->get_weapon_prof();
        type = (string)ob->query_weapon_prof();
    }
    else if(ob->is_armour())
    {
        if((string)ob->query_type() == "clothing") { type = "clothing"; }
        else { type = (string)ob->query_armor_prof(); }
    }
    else
    {
        type = (string)ob->query_type();
    }
    /*
    switch (type)
    {
    case "slashing":
    case "piercing":
        ret = "thief";
        break;
    case "bludgeoning":
        ret = "cleric";
        break;
    case "piercing":
    case "bludgeoning":
        ret = "mage";
        break;
    default:
        if (ob->is_weapon())
            ret = "fighter";
        else
            ret = type;
    }*/
    if (ob->is_lrweapon())
        type = "["+type+"]";
    return type;
}

// should use the functions in /std/money rather than this.... *Styx* 1/26/03
int convert_money(string cointype,int cost) {
    int cp,sp,ep,gp,pp;
    int ocp,osp,oep,ogp,opp;
    int fail_flag;

    cp = (int)this_player()->query_money("copper");
    sp = (int)this_player()->query_money("silver");
    ep = (int)this_player()->query_money("electrum");
    gp = (int)this_player()->query_money("gold");
    pp = (int)this_player()->query_money("platinum");
    ocp=cp;osp=sp;oep=ep;ogp=gp;opp=pp;
    fail_flag = 0;

    this_player()->add_money("copper",-cp);
    this_player()->add_money("silver",-sp);
    this_player()->add_money("electrum",-ep);
    this_player()->add_money("gold",-gp);
    this_player()->add_money("platinum",-pp);

    if (cointype == "copper") {
        do {
            if (sp > 0) {
                cp += 10;sp -= 1;
            } else if (ep > 0) {
                cp += 10;sp += 4;ep -= 1;
            } else if (gp > 0) {
                cp += 10;sp += 4;ep += 1;gp -= 1;
            } else if (pp > 0) {
                cp += 10;sp += 4;ep += 1;gp += 4;pp -= 1;
            } else if (cp < cost) {
                fail_flag = 1;break;
            }
        }while ( cp < cost);
    } else if (cointype == "silver") {
        do {
            if (cp > 10) {
                sp += cp/10;cp = cp%10;
            } else if (ep > 0) {
                sp += 5;ep -= 1;
            } else if (gp > 0) {
                sp += 5;ep += 1;gp -= 1;
            } else if (pp > 0) {
                sp += 5;ep += 1;gp += 4;pp -= 1;
            } else if (sp < cost) {
                fail_flag = 1;break;
            }
        }while ( sp < cost);
    } else if (cointype == "electrum") {
        do {
            if (cp > 10) {
                sp += cp/10;cp = cp%10;
            } else if (sp > 5) {
                ep += sp/5;sp = sp%5;
            } else if (gp > 0) {
                ep += 2;gp -= 1;
            } else if (pp > 0) {
                ep += 2;gp += 4;pp -= 1;
            } else if (ep < cost) {
                fail_flag = 1;break;
            }
        }while ( ep < cost);
    } else if (cointype == "gold") {
        do {
            if (cp > 10) {
                sp += cp/10;cp = cp%10;
            } else if (sp > 5) {
                ep += sp/5;sp = sp%5;
            } else if (ep > 2) {
                gp += ep/2;ep = ep%2;
            } else if (pp > 0) {
                gp += 5;pp -= 1;
            } else if (gp < cost) {
                fail_flag = 1;break;
            }
        }while ( gp < cost);
    }

    else if (cointype == "platinum") {
        do {
            if (cp > 10) {
                sp += cp/10;cp = cp%10;
            } else if (sp > 5) {
                ep += sp/5;sp = sp%5;
            } else if (ep > 2) {
                gp += ep/2;ep = ep%2;
            } else if (gp > 5) {
                pp += gp/5;gp = gp%5;
            } else if (pp < cost) {
                fail_flag = 1;break;
            }
        }while ( pp < cost);
    }

    if (fail_flag) {
        this_player()->add_money("copper",ocp);
        this_player()->add_money("silver",osp);
        this_player()->add_money("electrum",oep);
        this_player()->add_money("gold",ogp);
        this_player()->add_money("platinum",opp);
        return 1;
    } else {
        this_player()->add_money("copper",cp);
        this_player()->add_money("silver",sp);
        this_player()->add_money("electrum",ep);
        this_player()->add_money("gold",gp);
        this_player()->add_money("platinum",pp);
        return 1;
    }
}


// Repair Stuff

int __Repair(string str)
{
    object ob;
    string tmp;
    int cost, x,lvl,enchant;
    string cointype, *not_allowed, response,type;

    if (!str)
    {
        write("Try 'repair <item> [#]'!");
        return 1;
    }

    not_allowed = ({ "bound", "disabled", "unconscious" });

    if(disabled(TP, not_allowed)) {	return 1; }

    if(disabled(TO, not_allowed))
    {
        write("Do you really expect someone who cannot move to repair something?");
	    return 1;
    }

    response = "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^";

    if (!should_interact(TP))
    {
        force_me("glare "+TPQN);
        force_me("say Leave my shop, scum, I will not serve you.");
        return 1;
    }

    if (!TP->is_player() && member_array(TP->query_race(),RACE_D->query_races())== -1)
    {
        force_me("say We don't serve your kind around here.");
        return 1;
    }

    if (!(ob = present(str, TP)))
    {
        tell_room(ETO, TPQCN+" asks the shopkeeper about an item.", TP);
        tell_room(ETO, response+"You don't have any "+str+"s in need of repair!");
        return 1;
    }

    if (check_allowed(ob) == 0)
    {
        tell_room(ETO, response+"Sorry, I don't deal in "+str+"s!");
        return 1;
    }

    if(ob->query_property("enchantment"))
    {
        enchant = absolute_value((int)ob->query_property("enchantment"));
        enchant += 1;
    }

    if(ob->query_property("no repair"))
    {
        tell_room(ETO,response+" That "+str+" can't be fixed.");
        return 1;
    }

//    cost = enchant * ((8 + roll_dice(1,8))*1000);
// not really feasible except for characters that farm at top level. Don't want to cater to them. N, 8/12.
    cost = enchant * ((3 + roll_dice(1,3))*1000);
    cost = adjust_cost(cost);

    if(ob->is_weapon()) { type = "weapon"; }
    else { type = "armor"; }

    if(type == "weapon")
    {
        if(ob->query_wielded())
        {
            tell_room(ETO,response+"You need to unwield your "+str+" first.");
            return 1;
        }
    }
    if(type == "armor")
    {
        if(ob->query_worn())
        {
            tell_room(ETO,response+"You need to remove your "+str+" first.");
            return 1;
        }
    }

    cointype = (string)ob->query_cointype();
    if ((int)this_player()->query_money(cointype) < cost)
    {
        convert_money(cointype,cost);
        if ((int)this_player()->query_money(cointype) < cost)
        {
            tell_room(ETO, response+TPQCN+", you don't have enough money for that!", TP);
	        tell_object(TP, response+"You don't have enough money.");
            tell_room(ETO, response+"You need "+cost+" "+ob->query_cointype()+".");
            return 1;
        }
    }


    tell_room(ETO,response+"That'll be "+cost+" gold.");
    tell_room(ETO,TP->QCN+" gives "+TO->QCN+" a stack of gold coins.",TP);
    tell_object(TP,"You give "+TO->QCN+" "+cost+" gold coins.");

    tell_room(ETO,TO->QCN+" takes "+TP->QCN+"'s "+str+" and begins repairing it.",TP);
    tell_object(TP,TO->QCN+" takes your "+str+" and begins repairing it.");

    tell_room(ETO,TO->QCN+" finishes repairing the "+str+" and hands it back to "+TP->QCN+".",TP);
    tell_object(TP,TO->QCN+" finishes repairing your "+str+" and hands it back to you.");

    tell_room(ETO,response+ "There you go, good as new!");

    ob->repairMe(200);

    TP->add_money(ob->query_cointype(), -cost);

    return 1;
}

int __Resize(string str) {
    object ob;
    int cost, x,lvl,enchant, mysize, failflag;
    string tmp, cointype, *not_allowed, response,type;

    if (!str) {
	write("Try 'buy <item> [#]'!");
	return 1;
    }
    not_allowed = ({ "bound", "disabled", "unconscious" });
    if(disabled(TP, not_allowed)) {	return 1; }
    if(disabled(TO, not_allowed)) {
	write("Do you really expect someone who cannot move to repair something?");
	return 1;
    }

    response = "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^";
    if (!should_interact(TP)) {
        force_me("glare "+TPQN);
        force_me("say Leave my shop, scum, I will not serve you.");
        return 1;
    }
    if (!TP->is_player() && member_array(TP->query_race(),RACE_D->query_races())== -1) {
        force_me("say We don't serve your kind around here.");
        return 1;
    }
    if (!(ob = present(str, TP))) {
        tell_room(ETO, TPQCN+" asks the shopkeeper about an item.", TP);
        tell_room(ETO, response+"You don't have any "+str+"s to resize!");
        return 1;
    }

    if (!high_mortalp(TP) && !avatarp(TP) && !OB_ACCOUNT->is_high_mortal(TP->query_true_name())) { // currently HM only command. May change in future? N, 8/12.
        tell_room(ETO, TPQCN+" asks the shopkeeper about an item.", TP);
        tell_room(ETO, response+"Hah. Why would I go to that much effort for someone as unimpressive as you?");
        return 1;
    }
    if (check_allowed(ob) == 0) {
        tell_room(ETO, response+"Sorry, I don't deal in "+str+"s!");
        return 1;
    }
    if(ob->query_property("no resize")) {
        tell_room(ETO,response+" That "+str+" can't be adjusted to fit you.");
        return 1;
    }
    if(ob->is_weapon()) {
        tell_room(ETO,response+" Sorry, it is far too complex for me to resize a weapon.");
        return 1;
    }

    if(ob->query_property("enchantment")) {
        enchant = absolute_value((int)ob->query_property("enchantment"));
        enchant += 1;
    }
    cost = enchant * ((20 + roll_dice(1,5))*1000); // going off prior use prices, 20-25k per plus.
    cost = adjust_cost(cost);

    if(ob->query_worn()) {
        tell_room(ETO,response+"You need to remove your "+str+" first.");
        return 1;
    }
    mysize = (int)TP->query_size();
    if((int)ob->query_size() == -1 || (int)ob->query_size() == mysize) {
        tell_room(ETO,response+"That "+str+" is already in your size!");
        return 1;
    }

    cointype = (string)ob->query_cointype();
    if ((int)this_player()->query_money(cointype) < cost) {
        convert_money(cointype,cost);
        if ((int)this_player()->query_money(cointype) < cost) {
            tell_room(ETO, response+TPQCN+", you don't have enough money for that!", TP);
	        tell_object(TP, response+"You don't have enough money.");
            tell_room(ETO, response+"You'll need around "+cost+" "+ob->query_cointype()+".");
            return 1;
        }
    }

    tell_room(ETO,response+"That'll be "+cost+" gold.");
    tell_room(ETO,TP->QCN+" gives "+TO->QCN+" a stack of gold coins.",TP);
    tell_object(TP,"You give "+TO->QCN+" "+cost+" gold coins.");

    tell_room(ETO,TO->QCN+" takes "+TP->QCN+"'s "+str+" and begins resizing it to fit you.",TP);
    tell_object(TP,TO->QCN+" takes your "+str+" and begins resizing it.");

    tell_room(ETO,TO->QCN+" finishes resizing the "+str+" and hands it back to "+TP->QCN+".",TP);
    tell_object(TP,TO->QCN+" finishes resizing your "+str+" and hands it back to you.");

    tell_room(ETO,response+ "There you go, all done! Remember, it has been sized to fit you specifically now - most other people will not fit it!");

// going to just add a d20 roll here as there were mixed opinions on DCs. d20 roll of 1 loses an enchant. Can change as needed. N, 8/12.
    failflag = random(20);
    enchant = (int)ob->query_property("enchantment");
    if(!failflag && enchant > 0) {
        tell_room(ETO,response+ "I had a little difficulty in the process though, the item may not be as potent as it was before.");
        ob->remove_property("enchantment");
        enchant--;
        if(ob->query("no curse")) ob->set_property("enchantment",enchant);
        else {
            ob->set("no curse",1);
            ob->set_property("enchantment",enchant);
            ob->delete("no curse");
        }
    }

    ob->set_size(mysize);
    ob->set_property("hm resized",1);
    TP->add_money(ob->query_cointype(), -cost);

    return 1;
}
