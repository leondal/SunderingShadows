//guild2.c

#include <std.h>

inherit VAULT;

int flag;

void create(){
  ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_property("no teleport",1);
    set_property("indoors",1);
    set_property("light",2);
    set("short","The receptionist's office in the merchant's guild");
    set("long",

@OLI
	%^BOLD%^%^YELLOW%^Merchant's receptionist office%^RESET%^
This office is meant for basic greetings. The person behind the desk,
a small wooden desk, is obviously meant to be pretty and greet the merchants
in an appropriate manner. To the north is a door and to the west is another 
door. The hard wood floors and the paneled wall are gratuitously ornate
and expensive. Murmur's of chatter come from the other room.
OLI
	
	);
  set_exits(([
		"north":"/d/tharis/Tharis/market9",
               "east":"/d/tharis/Tharis/street7",
		"west":"/d/tharis/Tharis/guild1"
		]));
  
  set_door("west door","/d/tharis/Tharis/guild1","west","guild key");
  set_search("default",(:this_object(),"find_key":));
  set_smell("default","A wiff of perfume and a touch of colone greets you.");
  set_listen("default","A small chitter chatter comes from the west.");

  set_open("west door",0);
  set_locked("west door",1);
  "/d/tharis/Tharis/guild1"->set_open("reception door",0);
  "/d/tharis/Tharis/guild1"->set_locked("reception door",1);
}

void reset(){
  object ob1;
  ::reset();
  if(!present("secretary")){
     ob1 = new(MONSTER);
     ob1->set("short","Melinda, the merchant's secretary");
     ob1->set("long","This is Melinda, the secretary who works for the merchant's guild");
     ob1->set_hd(1,1);
     ob1->set_gender("female");
     ob1->set_size(2);
     ob1->set_body_type("human");
     ob1->set_race("human");
     ob1->set_id(({"secretary","woman","melinda","Melinda"}));
     ob1->set_name("Melinda, the secretary");
     ob1->set_emotes(5,({"Melinda winks at you",
			     "Melinda fluffs her hair",
			     "Melinda files her nails",
			     "Melinda touches your hand softly",
			     "Melinda crosses her legs.",
			     "Melinda licks her lips."}),0);
     ob1->move(TO);
   }

  set_open("west door",0);
  set_locked("west door",1);
  "/d/tharis/Tharis/guild1"->set_open("reception door",0);
  "/d/tharis/Tharis/guild1"->set_locked("reception door",1);
  flag = 0;
}

string find_key() {
  object ob;
  if(!flag){
    tell_room(environment(TP),"%^MAGENTA%^"+TPQCN+" searches the room and finds something",TP);
    write("%^MAGENTA%^You search the room and find a key.");
    ob = new(OBJECT);
    ob->set_name("Guild key");
    ob->set_id(({"guild key","key","Guild key"}));
    ob->set_weight(1);
    ob->set("short","A Guild key");
    ob->set("long","The key to the door of the merchant's guild");
    ob->move(TP);
    ob->set_value(2);
    flag = 1;
  }
  else {
    tell_room(environment(TP),"%^MAGENTA%^"+TPQCN+" searches the room and finds nothing",TP);
    write("%^MAGENTA%^You search the room and find nothing.");
  }   
  return " ";
}
