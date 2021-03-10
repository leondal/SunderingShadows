#include <std.h>

#define POFF "/d/player_stores/poffices/"

#define PSTORE "/std/pstore"
// #define PSTORE "/realms/styx/pstore"

inherit PSTORE;
// inherit VAULT;  // need to be able to use owner functions here too

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
// *********
// Note:  Need to keep the settings in shadow.c (owners, etc.) in sync with these
  set_owners( ({"stefano", "styx" }));
  set_drop_storage(POFF+"shadowstorage");
  set_drop_deposit(100);   // owner can specify, but setting static here
  set_items_allowed( ({ "letters" }) );
  set_name("Back room");
  set_short("A back room");
  set_long("%^BOLD%^%^WHITE%^A simple room with white plaster walls and is sparsely furnished with just a single desk and chair.  %^RESET%^%^GREEN%^Green carpet%^BOLD%^%^WHITE%^ covers the floor and the back wall has numerous racks of locked metal cubby holes.  Each rack has sections marked with a letters of the alphabet.");
  set_smell("default", "You can smell the clean smell of the new carpet.");
  set_listen("default", "The sounds of the street are quite faint in here.");
  set_exits(([
	"out": POFF+"shadow",
  ]));
  set_door("iron bound door",POFF+"shadow","out");  //no key here so people don't get locked in
  set_open("iron bound door", 0);  // will default to this actually
//  set_locked("iron bound door", 1);  this should be done by the other side ??
  set_door_description("iron bound door", "%^ORANGE%^This sturdy looking oak door is bound with %^BOLD%^%^BLACK%^iron%^RESET%^%^ORANGE%^");

  set_items( ([
	({"rack", "racks", "cubby hole", "cubby holes" }) : "The cubby holes are clearly designed to store folded pieces of paper.  Each rack is subdivided into sections for a letter of the alphabet.",
	({"section", "sections" }) : "Each section is further sub-divided to allow for quick storage and retrieval of the documents, apparently by title or topic or name.",
	"desk": "A quite basic looking light pine desk with four legs and one center drawer.",
	({"letter", "letters" }) : "You're probably tempted to pull some out and peek at them aren't you?  Or is your conscience going to lead you to respect the obviously private nature of these documents?",
	"chair":  "A small plain, wooden chair with no padding.  Probably not very comfortable.",
    ]) );
}

void init() {
   ::init();
   add_action("get_letter", "pull");
   add_action("return_letter", "return");
}

int get_letter(string str) {
   string what;
   int x, num;
   object storage, *inv, which;
   if(TP->query_unconscious()) {
	tell_object(TP, "Not in your current state!");
	return 1;
   }
   if(TP->query_paralyzed()) {
 	TP->send_paralyzed_message("info",TP);
	return 1;
   }
   if(TP->query_bound()) {
	tell_room(ETP, TPQCN+" seems to be struggling to do something.", TP);
        tell_object(TP, "You can't do that while bound.");
	return 1;
   }
   if(!str || sscanf(str, "%s from racks",what) != 1 ) {
	tell_object(TP, "What were you trying to pull from where?");
	return 1;
   }

   what = replace_string(what,"letter", "paper");
   what = replace_string(what,"document", "paper");
   if(what == "paper")   num = 1;
   sscanf(what, "paper %d",num);
   storage = find_object_or_load("/d/player_stores/poffices/shadow"->query_drop_storage());
   inv = all_inventory(storage);
   if(!num || (num > sizeof(inv)) ) {
	tell_object(TP, "You don't seem to find a "+what+".");
	return 1;
   }
   if(which = inv[num -1]) {
      write("You pull a letter from the racks.\nSo now, will you decide to "
	  "return it when you're finished with it?");
      tell_room(ETO, TPQCN+" pulls a "+(string)which->query_short()+" from the racks.", TP);
      if (which->move(TP)) {
        tell_object(TP, "You drop it as fast as you get it!");
        tell_room(TO, TPQCN+" drops "+(string)which->query_short()+".", TP);
        which->move(TO);
      }
      return 1;
   }
   return 0;
}

int return_letter(string str) {
   string what;
   object storage, obj;
   if(TP->query_unconscious()) {
	tell_object(TP, "Not in your current state!");
	return 1;
   }
   if(TP->query_paralyzed()) {
 	TP->send_paralyzed_message("info",TP);
	return 1;
   }
   if(TP->query_bound()) {
	tell_room(ETP, TPQCN+" seems to be struggling to do something.", TP);
        tell_object(TP, "You can't do that while bound.");
	return 1;
   }
   if(!str || sscanf(str, "%s to racks",what) != 1 ) {
	tell_object(TP, "What were you trying to return to where?");
	return 1;
   }

   what = replace_string(what,"letter", "paper");
   what = replace_string(what,"document", "paper");
   if(!obj = present(what, TP)) {
	tell_object(TP,"You don't seem to have a "+what+".");
	tell_room(ETP, TPQCN+" seems to be fumbling through "+TP->query_possessive()+
	   " inventory.", TP);
	return 1;
   }
   if(!obj->id("paper")) {
	tell_object(TP,"You look a little silly trying to stuff a "+what+" into the letter racks.");
	tell_room(ETP, TPQCN+" looks a little silly trying to stuff a "+what+" into the letter racks.", TP);
	return 1;
   }
   if(!obj->query_property("pstore_mailto")) {
	tell_object(TP,"That paper isn't addressed properly and the racks reject it.");
	tell_room(ETP, TPQCN+" looks confused while trying to put a paper in the racks.", TP);
	return 1;
   }
   storage = find_object_or_load("/d/player_stores/poffices/shadow"->query_drop_storage());
   obj->move(storage);
   tell_object(TP,"You return the letter to the letter racks.");
   tell_room(ETP, TPQCN+" returns a letter to the racks.", TP);
   return 1;
}

void reset() {
   string guard;
   ::reset();
   guard = "/d/player_stores/mons/poguard_shad2";
   if(!present("shop guard"))
     if(!objectp(environment(find_object_or_load(guard)))) 	
	find_object_or_load(guard)->move(TO);
}