#include <std.h>
#include <daemons.h>
#define MAPPING_D "/daemon/mapping_d.c"

inherit ROOM;

string *owners = ({"margath", "bryanna", "obsidian"});

void create()
{
  ::create();
  set_terrain(WOOD_BUILDING);
  set_travel(PAVED_ROAD);
  set_property("indoors",1);
  set_property("light",2);
  set_property("no sticks",1);
  set_short("Backstage of the theatre");
  set_long(
	   "This is the backstage of the Rhapsody Inn. Red velvet curtains lead to"+
	   " the stage. This is where the actors and other performers prepare to go"+
	   " on stage. There is a door that leads to the green room on the north."+
	   " The green room is basically fancy actor terminology for the main"+
	   " dressing room, though it is also a gathering place for actors before"+
	   " the show. There are several shelves to the left of the green room that"+
	   " are filled with props for shows. All sorts of weird things can be"+
	   " found on the prop shelves, everything from stuffed snakes and fake"+
	   " antiques to feather boas and collapsible swords. There doesn't seem"+
	   " to be much organization to the props at all. There are rope pulleys"+
	   " on the south for closing and opening the curtains. A few chairs are"+
	   " next to the pulleys for waiting actors and performers to sit on."
	   );
  set_smell("default","The fresh aroma of food and drink drift in from"+
	    " the inn.");
  set_listen("default","You can hear the chatter of customers in the inn.");
  set_items(([
	      "west wall" : "The west wall is surprisingly bare and uncluttered"+
	      " compared to the rest of the room.",
	      "floor" : "%^BOLD%^%^BLACK%^The floor is painted black, as are most of"+
	      " the other things back stage. That way there's less of a chance of"+
	      " spotting something back here, especially during a scene change.",
	      "ceiling" : "%^BOLD%^%^BLACK%^The ceiling is very high up, and you can't"+
	      " make out very many details, there does seem to be some sort of cat walk"+
	      " up there, but everything is painted black.",
	      ({"curtains","red curtains","red velvet curtains","velvet curtains"}) :
	      "%^BOLD%^%^RED%^Thick red velvet curtains lead to the stage.",
	      ({"shelf","shelves","props","prop shelves"}) : "On the north wall are"+
	      " several shelves filled with props. They appear very disorganized and"+
	      " contain all sorts of odd items.",
	      ({"feather boas","feather boa"}) : "%^BOLD%^Several white feather boas"+
	      " are tumbled together at the back of a shelf.",
	      ({"stuffed snake","stuffed snakes"}) : "There are a few types of stuffed"+
	      " snakes, ranging from rattlers to cobras. Some of them are obviously"+
	      " fake, while others seem quite real.",
	      ({"collapsible sword","collapsible swords"}) : "There are a couple"+
	      " different collapisble blades here, some daggers and a few swords."+
	      " There are compartments in a few for %^BOLD%^%^RED%^blood%^RESET%^ to"+
	      " spurt out of.",
	      ({"fake antiques","fake antique"}) : "The fake antiques range from"+
	      " expensive jewelry to ancient pottery, most of them look very real.",
	      ({"dressing room","door","green room"}) : "%^GREEN%^The door to the"+
	      " green room is, predictably, painted a dark green shade. No one is"+
	      " allowed back there except the actors. A paper is pinned on the door.",
	      "paper" : "You can record things on this paper.",
	      ({"rope pulleys","pulleys","pulley"}) : "Rope pulleys control the stage"+
	      " curtains. During a performance they can be opened or closed to varying"+
	      " degrees at the appropriate times.",
	      ({"chair","chairs"}) : "%^BOLD%^%^BLACK%^Three chairs are placed near the"+
	      " end of the curtain. They are very simple, probably not overly"+
	      " comfortable, and like everything else they're painted black.",

	      ]));
  set_exits(([
	      "inn" : "/d/darkwood/room/rhapsody",
	      "wall" : "/d/guilds/regents/rooms/hall1.c",
	      ]));
  set_invis_exits(({"wall"}));
  set_pre_exit_functions(({"wall"}),({"GoThroughDoor"}));
}

void init()
{
  ::init();
  add_action("sit","sit");
  add_action("peer","peer");
  add_action("record","record");
  add_action("bless","bless");
}

int record(string str){
  string *badass,arg,name;
  int i;
  if ((member_array(TPQN,owners) == -1) && (!wizardp(TP)) )return 0;
  if(!str) return notify_fail("Syntax: record -l(ist)|a(dd)|r(emove) [name]\n");
  badass = MAPPING_D->query_values("rhapsody_unwanted");
  if(str == "-l"){
    write("The list reads:");
    for(i = 0;i<sizeof(badass);i++) write(badass[i]);
    return 1;
  }
  else if(sscanf(str,"-%s %s",arg,name) != 2){
    return notify_fail("Syntax: record -l(ist)|a(dd)|r(emove) [name]\n");
  }
  else if(arg == "a"){
    if ((string)TP->realName(name) == "") {
      write("You do not know who they are.");
      return 1;
    }
    MAPPING_D->set_value("rhapsody_unwanted",(string)TP->realName(name),name);
    write("You added "+name+" to the unwanted list.");
    return 1;
  }
  else if(arg == "r"){
    if(member_array(name,badass) == -1){
      write("That name is not on the list.");
      return 1;
    }
    else{
      MAPPING_D->remove_value_from_array("rhapsody_unwanted",name);
      write("You removed "+name+" from the unwanted list.");
      return 1;
    }
  }
}

int GoThroughDoor()
{
  if(avatarp(TP)) {
    tell_object(TP,"You walk through the western wall.");
    TP->move("/d/guilds/regents/rooms/hall1.c");
    return 1;
  }
  /*if(member_array("Regents of the Silver Lore",TP->query_guild()) != -1){
    tell_object(TP,"You walk through the western wall.");
    TP->move("/d/guilds/regents/rooms/hall1.c");
    return 1;
  }
  else {
    tell_object(TP,"What?\n");
    return 0;
  }*/
}

void sit(string str)
{
  if(str == "chair" || str == "black chair") {
    tell_object(TP,"%^BOLD%^%^BLACK%^You take a seat on one of the"+
                " chairs and await your cue.");
    tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->query_cap_name()+" takes"+
	      " a seat on one of the chairs and awaits "+TP->query_possessive()+""+
	      " cue.",TP);
    return 1;
  }
}

void peer(string str)
{
  if(!str) return 0;
  if ((str != "inn") && (str != "inn 1")) {
    tell_object(TP,"You can see nothing in that direction.");
    return 1;
  }
}

int bless(string str){
  string *enforcers,arg,name;
  int i;
  if ((member_array(TPQN,owners) == -1) && (!wizardp(TP)) )return 0;
  if(!str) return notify_fail("Syntax: bless -l(ist)|a(dd)|r(emove)
[name]\n");
  enforcers = MAPPING_D->query_values("rhapsody_enforcers");
  if(str == "-l"){
    write("The list reads:");
    for(i = 0;i<sizeof(enforcers);i++) write(enforcers[i]);
    return 1;
  }
  else if(sscanf(str,"-%s %s",arg,name) != 2){
    return notify_fail("Syntax: record -l(ist)|a(dd)|r(emove) [name]\n");
  }
  else if(arg == "a"){
    if ((string)TP->realName(name) == "") {
      write("You do not know who they are.");
    }
    MAPPING_D->set_value("rhapsody_enforcers",(string)TP->realName(name),name);
    write("You added "+name+" to the enforcers list.");
    return 1;
  }
  else if(arg == "r"){
    if(member_array(name,enforcers) == -1){
      write("That name is not on the list.");
      return 1;
    }
    else{
      MAPPING_D->remove_value_from_array("rhapsody_enforcers",name);
      write("You removed "+name+" from the enforcers list.");
      return 1;
    }
  }
}
