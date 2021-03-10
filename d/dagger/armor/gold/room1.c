// fixed the .c on exits for peer, probably needs updated to use VAULT but the special messages would probably need preserved, so not today *Styx*  2/2/05

#include <std.h>

inherit ROOM;
int Glock, Gclosed;
object ob;

void set_locked(int num);
void set_closed(int num);
int query_locked();
int query_closed();

void create(){
    ::create();
    set_property("no teleport", 1);
    set_property("light", 3);
    set_property("indoors", 1);
    set_short("%^BOLD%^%^RED%^A dark cavern");
    set_long(
      "You have entered a dark cavern.  You can barely make out the dirt walls to your side, but a great metal door blocks the passage to the south.  You get a very eerie feeling...  perhaps that door is more meant to keep something in than keep you out."
    );
    set_pre_exit_functions( ({"door"}), ({"go_thru_door"}) );
    set_smell("default", "You can smell nothing here.");
    set_listen("default", "You hear a slow scratching at the back of the door.");
    set_items( ([
	"door" : "This great door is made of a thick and hard steel.  It has a golden keyhole under the handle to pull it open.",
	"walls" : "they are made of clay and are not very well supported.",
      ]) );
    set_exits( ([
	"out" : "/d/attaya/base/oubliette20",
	"door" : "/d/dagger/armor/gold/room2",
      ]) );
    set_locked(1);
    set_closed(1);
}

void init(){
    ::init();
    add_action("lock", "lock");
    add_action("unlock", "unlock");
    add_action("open", "open");
    add_action("close", "close");
    add_action("sneak", "sneak");
}

void set_locked(int num) { Glock = num; }
void set_closed(int num) { Gclosed = num; }
int query_locked() { return Glock; }
int query_closed() { return Gclosed; }

int lock(string str){
    if(!str) return notify_fail("Lock what?\n");
    if(str != "door") return notify_fail("Lock what?\n");
    if(query_locked()) return notify_fail("The door is already locked!\n");
    if(!query_closed()) return notify_fail("You can't lock an open door!\n");
    if(!(ob=present("csarmorkey", TP))) return notify_fail("You have to have a key to lock the door with!\n");

    set_locked(1);
    set_closed(1);
    ob->remove();
    tell_object(TP, "You securely lock the door.\n");
    tell_object(TP, "The key disapears from your hand as you lock the door!\n");
    tell_room(ETP, TPQCN+" locks the door.\n", TP);
    return 1;
}

int unlock(string str){
    if(!str) return notify_fail("Unlock what?\n");
    if(str != "door") return notify_fail("Unlock what?\n");
    if(!query_locked()) return notify_fail("The door is already unlocked!\n");
    if(!(ob=present("csarmorkey", TP))) return notify_fail("You have to have the correct key to unlock this door!\n");

    set_locked(0);
    ob->remove();
    tell_object(TP, "You unlock the great door.\n");
    tell_object(TP, "The key disapears from your hand as you unlock the door!\n");
    tell_room(ETP, TPQCN+" unlocks the door.\n", TP);
    return 1;
}

int open(string str){
    if(!str) return notify_fail("Open what?\n");
    if(str != "door") return notify_fail("Open what?\n");
    if(query_locked()) return notify_fail("The door is locked.\n");
    if(!query_closed()) return notify_fail("The door is already open!\n");

    set_closed(0);
    tell_player(TP, "You slowly open the door on well oiled hinges.\n");
    tell_room(ETP, TPQCN+" slowly opens the door.\n", TP);
    return 1;
}

int close(string str){
    if(!str) return notify_fail("Close what?\n");
    if(str != "door") return notify_fail("Close what?\n");
    if(query_closed()) return notify_fail("The door is already closed.\n");

    set_closed(1);
    tell_object(TP, "You slowly close the door.\n");
    tell_room(ETP, TPQCN+" slowly closes the door.\n", TP);
    return 1;
}

int go_thru_door(){
    if(query_closed()) {
	tell_object(TP, "You bump into the closed door.\n");
	tell_room(ETP, TPQCN+" bumps into the closed door.\n", TP);
	return 0;
    } else {
	tell_object(TP, "You move through the door and into the next room.\n");
	tell_room(ETP, TPQCN+" moves through the door into the next room.\n", TP);
	return 1;
    }
}

void reset(){
    ::reset();
    set_closed(1);
    set_locked(1);
}

int sneak(string str){
    tell_object(TP, "You try to sneak through the door, but you haven't learned that osmosis trick yet.\n");
    tell_room(ETP, TPQCN+" tries to sneak through the door, and succeedes in getting a bloody nose after running into it.", TP);
    return 1;
}
