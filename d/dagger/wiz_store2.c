//Re-equipping store for wizzes & avatars - by Styx 6/01

#include <std.h>
#include "sp_armor.h"
#include "sp_weapons.h"
#include "sp_other.h"
#include "sp_mundane.h"

#define FLAGS ([ "death keep":"Death Keep","plot_item":"Plot Item (No offer / No Vendor / No Donate)", "no offer":"No Offer", "death remove":"Death Remove" ])

#define KEYS_F(x) keys(FLAGS)[x]
inherit ROOM;
object ob;

void create(){
	::create();
	set_properties((["light":2,"indoors":1,"no attack":1]));
	set_property("no teleport",1);
	set("short","Equipment generator for avatars and wizzes");
	set("long",
"This room is for the convenience of wizzes and avatars when needing common "
"gear for their use or to replace from bugs and crashes.  You are trusted to "
"use it responsibly so we don't have to restrict the abilities.\nYou can "
"%^BOLD%^<list [armor|weapons|other|mundane] > %^RESET%^and then %^BOLD%^"
"<request listedname> %^RESET%^anything you see there.\n"
"You can also %^BOLD%^<identify> %^RESET%^the items on the floor, or "
"%^BOLD%^<identify me> %^RESET%^or %^BOLD%^<identify myself> %^RESET%^to "
"identify all your equipment.\n"
"As well, you can mark things as %^BOLD%^<stolen>%^RESET%^.  Again, by "
"itself, the command operates on all the items in the room whereas %^BOLD%^"
"<stolen myself> %^RESET%^or %^BOLD%^<stolen me> %^RESET%^does them on your "
"personal inventory (And does mark the items 'inside' like stealing a sack "
"does as well).\n"
"(Identify and Stolen are brought to you by the diminutive letter 'g'. :))\n"
"----------~~~~~~~~~~----------~~~~~~~~~~----------\n"
"%^BOLD%^death_remove <id> %^RESET%^will set/unset an object to be recycled upon the "
"death of the holder.\n"
"%^BOLD%^death_keep <id> %^RESET%^will set/unset an object to be kept through "
"death of the holder.\n"
"%^BOLD%^plot_item <id> %^RESET%^will set/unset an object with the properties "
"of a plot item (no offer, no sell/donate/vendor/fence).\n"
"%^BOLD%^no_offer <id> %^RESET%^will set/unset an object to be unofferable"
", but can still be donated,fenced, or sold.\n"
"%^BOLD%^flags <id>%^RESET%^ will list the properties above.\n"
"----------~~~~~~~~~~----------~~~~~~~~~~----------\n"
"Added ability to %^BOLD%^<size itemname to [1|2|3]>%^RESET%^ and %^BOLD%^"
"<enchant itemname>%^RESET%^ (adds one plus at a time, up to +5).  *Styx*"
"\nYou can now %^BOLD%^<unenchant itemname>%^RESET%^ (removes one plus at a time)."
        );
	set_items(([
	({"list", "lists", "armor list", "weapons list"}) : "Use 'list armor', 'list weapons', or 'list other' to see what you can request.",
	]));
	set_exits(([
		"out":"/d/dagger/avalounge"
	]));
	set_smell("default","You smell soothing vanilla candles to relieve your stress.");
	set_listen("default","Soothing music attempts to drown out the sounds of the distressed players.");
	set_items( ([
	]) );
}

void reset(){
	::reset();
}

void init() {
    ::init();
    if (avatarp(TP)) {
        add_action("list_stuff","list");
        add_action("death_remove","death_remove");
        add_action("death_keep","death_keep");
        add_action("plot_item","plot_item");
        add_action("no_offer","no_offer");
        add_action("show_flags","flags");
        add_action("request","request");
	    add_action("id_inventory","identify");
	    add_action("stole_it","stolen");
	    add_action("enchant_it","enchant");
        add_action("unenchant_it","unenchant");
	    add_action("size_it", "size");
    }
    if (!avatarp(TP)) add_action("nono","",1);
}

int list_stuff(string str) {
	int i;
	string *tmp = ({});
	if(!str) notify_fail("List what?\n");
	if(str == "armor" || str == "armors" || str == "armour") {
		tmp = keys(ARMOR);
		tmp = sort_array(tmp, "sort_alpha", TO);
		for(i=0;i<sizeof(tmp);i++) {
			write(tmp[i]);
		}
		return 1;
	}

	if(str == "weapons" || str == "weapon")	{
		tmp = keys(WEAPONS);
		tmp = sort_array(tmp, "sort_alpha", TO);
		for(i=0;i<sizeof(tmp);i++) {
			write(tmp[i]);
		}
		return 1;
	}
	if(str == "other" )	{
		tmp = keys(OTHER);
		tmp = sort_array(tmp, "sort_alpha", TO);
		for(i=0;i<sizeof(tmp);i++) {
			write(tmp[i]);
		}
		return 1;
	}
	if(str == "mundane" )	{
		tmp = keys(MUNDANE);
		tmp = sort_array(tmp, "sort_alpha", TO);
		for(i=0;i<sizeof(tmp);i++) {
			write(tmp[i]);
		}
		return 1;
	}
   say("Try 'list armor', 'list weapons', 'list other', or 'list mundane' to see the lists.");
}

void request(string str) {
	object thing;
   if(str == "rop +2") {
	  thing = new("/d/deku/armours/ring_p.c");
	  thing->set_property("enchantment",1);
	  thing->move(TO);
	  tell_room(ETP,thing->query_short()+" appears before you.");
	  return 1;
   }
	if(str == "rop +3") {
	  thing = new("/d/deku/armours/ring_p.c");
	  thing->set_property("enchantment",2);
     thing->move(TO);
     tell_room(ETP,thing->query_short()+" appears before you.");
     return 1;
   }
	if(str == "rop +4") {
	  thing = new("/d/deku/armours/ring_p.c");
	  thing->set_property("enchantment",3);
     thing->move(TO);
     tell_room(ETP,thing->query_short()+" appears before you.");
     return 1;
   }
   if(str == "wool cloak small") {
     thing = "/d/islands/pirates/armor/woolcloak.c",
     thing->set_size(1);
     thing->move(TO);
     tell_room(ETP,thing->query_short()+" appears before you.");
     return 1;
   }
	if( member_array(str, keys(ARMOR)) != -1) {
		new(thing = ARMOR[str])->move(TO);
		tell_room(ETP,thing->query_short()+" appears before you.");
		return 1;
	}
	if(member_array(str, keys(WEAPONS)) != -1) {
		new(thing = WEAPONS[str])->move(TO);
		tell_room(ETP,thing->query_short()+" appears before you.");
		return 1;
	}
	if(member_array(str, keys(OTHER)) != -1) {
		new(thing = OTHER[str])->move(TO);
		tell_room(ETP,thing->query_short()+" appears before you.");
		return 1;
	}
	if(member_array(str, keys(MUNDANE)) != -1) {
		new(thing = MUNDANE[str])->move(TO);
		tell_room(ETP,thing->query_short()+" appears before you.");
		return 1;
	}
	write("That item isn't on the list.");
	return 1;
}


string sort_alpha (string one, string two) {
	return strcmp(one, two);
}

int id_inventory(string str) {
   object ob, *inventory;
    int iter,max;

   if (stringp(str) && (member_array(str,({"myself","me","mine"})) != -1))
     inventory = all_inventory(TP);
   else inventory = all_inventory(TO);
  max = sizeof(inventory);
  for (iter=0;iter<max;iter++) {
    if (!objectp(inventory[iter])) continue;
    if (userp(inventory[iter])) continue;
    if (inventory[iter]->is_living()) continue;
    inventory[iter]->add_identified(TP->query_name());
    }
    tell_room(ETP,"%^BOLD%^The identification requested is complete.");
  return 1;
}

int nono(string str) {
  if (member_array(query_verb(),({"identify","request","list","stolen"})) == -1) return 0;
  write("I'm sorry, Dave, I can't let you do that.");
  return 1;
}

int stole_it(string str) {
  object ob, *inventory;
  int iter, max;
   if (stringp(str) && (member_array(str,({"myself","me","mine"})) != -1))
    max=sizeof(inventory=all_inventory(TP));
    else max=sizeof(inventory=all_inventory(TO));
  for (iter=0;iter<max;iter++) {
    if (!objectp(inventory[iter])) continue;
   if (userp(inventory[iter])) continue;
    if (inventory[iter]->is_living()) continue;
    "/cmds/mortal/_steal"->flag_stolen(inventory[iter],-1);
  }
  tell_room(ETP,"%^BOLD%^The stolen flag(s) requested have been set.");
return 1;
}

int show_flags(string str) {
  object this;
  int i;
  if(!stringp(str) || str == "" || str == " ") { return 0; }

  if (!objectp(this = present(str,TP))) {
    return notify_fail("I don't see what you want to inspect the flags on!\n");
    }
    write(this->query_short()+":");
  for(i=0;i<sizeof(FLAGS);i++) {
    if ((!this->query_property((string)KEYS_F(i))) || (undefinedp(this->query_property((string)KEYS_F(i)))) ) {
      write("%^RED%^Does NOT%^RESET%^ have: "+values(FLAGS)[i]+"."); 
    }else {
      write("    %^GREEN%^DOES%^RESET%^ have: "+values(FLAGS)[i]+"."); 
    }
  }
  write("---");
}


int death_remove(string str) {
  object this;
  if (!objectp(this = present(str,TP))) {
    return notify_fail("I don't see what you want to mark with death remove!\n");
    }
  if ((!this->query_property("death remove")) || (undefinedp(this->query_property("death remove"))) ) {
    this->set_property("death remove",1);
    write(this->query_short() + " death remove property %^GREEN%^ADDED%^RESET%^.");
    return 1;
    } else { 
    this->remove_property("death remove");
    write(this->query_short() + " death remove property %^RED%^REMOVED%^RESET%^.");
    return 1;
    }
}

int plot_item(string str) {
  object this;
  if (!objectp(this = present(str,TP))) {
    return notify_fail("I don't see what you want to mark as being a plot item?\n");
    }
  if ((!this->query_property("plot_item")) || (undefinedp(this->query_property("death remove"))) ) {
    this->set_property("plot_item",1);
    write(this->query_short() + " plot_item property %^GREEN%^ADDED%^RESET%^.");
    return 1;
    } else { 
    this->remove_property("plot_item");
    write(this->query_short() + " plot_item property %^RED%^REMOVED%^RESET%^.");
    return 1;
    }
}

int death_keep(string str) {
  object this;
  if (!objectp(this = present(str,TP))) {
    return notify_fail("I don't see what you want to mark with death keep!\n");
    }
  if ((!this->query_property("death keep")) || (undefinedp(this->query_property("death keep"))) ) {
    this->set_property("death keep",1);
    write(this->query_short() + " death keep property %^GREEN%^ADDED%^RESET%^.");
    return 1;
    } else { 
    this->remove_property("death keep");
    write(this->query_short() + " death keep property %^RED%^REMOVED%^RESET%^.");
    return 1;
    }
}

int no_offer(string str) {
  object this;
  if (!objectp(this = present(str,TP))) {
    return notify_fail("I don't see what you want to mark with no offer!\n");
    }
  if ((!this->query_property("no offer")) || (undefinedp(this->query_property("no offer"))) ) {
    this->set_property("no offer",1);
    write(this->query_short() + " no offer property %^GREEN%^ADDED%^RESET%^.");
    return 1;
    } else { 
    this->remove_property("no offer");
    write(this->query_short() + " no offer property %^RED%^REMOVED%^RESET%^.");
    return 1;
    }
}

int enchant_it(string str) {
    object ob;
    int enchant;
    if(!str) {
        write("You need to specify what to enchant.");
        return 1;
    }
    if(!ob = present(str)) {
        write("That isn't here.");
        return 1;
    }
    enchant = ob->query_property("enchantment");
    if(enchant > 7)  {
        write("+8 is quite enough, so I don't think so, sorry.");
        return 1;
    }
    while((int)ob->query_property("enchantment") != (enchant+1)) {
        ob->remove_property("enchantment");
        ob->set_property("enchantment",enchant+1);
    }
    tell_room(ETP,"%^BOLD%^One enchantment has been added to "+
    str+".");
    return 1;
}

int unenchant_it(string str) {
    object ob;
    int enchant;
    if(!str) {
        write("You need to specify what to unenchant.");
        return 1;
    }
    if(!ob = present(str)) { 
        write("That isn't here.\n");
        return 1;
    }
    enchant = ob->query_property("enchantment");
    while((int)ob->query_property("enchantment") != (enchant-1)) {
        ob->remove_property("enchantment");
        ob->set_property("enchantment",enchant-1);
    }
    tell_room(ETP,"%^BOLD%^One enchantment has been remove from "+
    str+".");
    return 1;
}

int size_it(string str, int size) {
  object ob;
  int sizewas;
  if(!str)   return notify_fail("You need to specify what you want sized.\n");
  if(!sscanf(str, "%s to %d", str, size) ) 
    return notify_fail("Try size itemname (single word id) to 1 (or 2 or 3).\n");
  if(!present(str))  return notify_fail("That isn't here.\n");
  ob = present(str);
  if(size < 1 || size > 3) 
     return notify_fail("You need to specify size 1 (small), 2 (normal), or "
        "3 (large).\n");
  sizewas = ob->query_size();
  ob->set_size(size);
  tell_room(ETP,"%^BOLD%^You have changed "+str+" from a size "+sizewas+" to "
     "size "+size+".");
  return 1;
}
