// Pator@ShadowGate
// Sept 11 1996
// The realms of Svaha & Pator
//
#include <std.h>
#include <druids.h>

inherit ROOM;

init() {
object *items ;
int x;
string obj1;
  ::init();

   items = all_inventory(TO);
   for(x=0; x < sizeof(items); x++) {
   		if(obj1 = items[x]->query_true_name()) {
    	 if (obj1 == "pator" || obj1 == "svaha" || archp(TP)) {
        	return 1; }
   		}
       	else
   		{	obj1->move("/d/shadowgate/adv_main.c"); 
     		tell_object(obj1,	"You aren't allowed to enter this domain"); 
     		return 1;
     	}
    }
}
/*
reset() {
   ::reset();
//	init(); }
}
*/
create() {
    ::create();
    set_id( ({ "The Svaha & Pator domain" }) );
    set_property("light",2);
    set_indoors(1);
    set_short(
       "%^CYAN%^%^BOLD%^You are in the domains for Svaha and Pator%^RESET%^");
    set_long(
@PATOR
%^CYAN%^%^BOLD%^You are standing inside the realms especially created for
Svaha and Pator. When you look around you see a grand and vast cave with
clean but crude rock walls. The light seems to come from everywhere and
there is plenty of it. You see two doorways to the workrooms and you can
smell the potions brewed by these fabulous druids.

The cave is furnished with nicely styled chairs, tables, desks and
a huge waterbed. The books are stored in a sidecave where lots of
workers have carved shelves in the rock.

When you walk here, you know you are at home !!
%^RESET%^
PATOR
);
    set_property("no attack", 1);
    set_property("no steal", 1);
    set_smell("default",
       "You smell the potions brewed by these fabulous druids");
    set_listen("default",
       "You hear only tranquility");
    set_items( ([ "bed" : "A large waterbed carved out of one huge rock.There is place for two in it!",
                 "tables" : "Large wooden tables covered with nice covers set with gold",
		 "chairs" : "Wooden chairs made with artistic craftmanship",
		 "sidecave" : "A small cave on the western side of the cave where the library is located",
		 "shelves" : "These are carved out of the cavewalls",
		 "light" : "It comes from everywhere and it shines in all colors of the rainbow",
		 "desks" : "The are covered with books, but because they are made out of wood and rock they will withstand the load",
		 "walls" : "The are made out of crude rock",
		 "books" : "All you ever wanted to know is in them !"
		 ]) );
     set_exits( ([
	 "PATOR" : "/realms/pator/workroom.c",
	 "SVAHA" : "/realms/svaha/rooms/entrance.c" ]));
}


