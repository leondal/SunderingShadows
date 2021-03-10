// by Styx 9/2002
#include <std.h>
#define BRM "/d/common/boards/"
inherit ROOM;

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no teleport",1);
    set_short("Portal to OOC boards");
    set_long("A room with no view....  It does, however, house the "
       "portals to the ooc board objects for your convenience in "
       "reading and posting.");
    set_smell("default", "You smell the fresh scent of fresh ink.");
    set_listen("default", "You hear various exclamations from adjoining rooms.");
    set_exits( ([
         "clerics" : BRM+"clericboard",
         "druids" : BRM+"druidboard",
        "paladins" : BRM+"paladinboard",
        "cavaliers": BRM+"cavalierboard",
        "antis" : BRM+"antipaladinboard",
        "mages" : BRM+"mageboard",
        "hms"  :  BRM+"hmboard",
        "bards" : BRM+"bardboard",
        "rangers" : BRM+"rangerboard",
        "fighters" : BRM+"fighterboard",
        "announcements" : BRM+"announcementboard",
        "assassins" : BRM+"assassinboard",
        "comments" : BRM+"commentboard",
        "rids" : BRM+"ridboard",
        "main" : BRM+"mainboard",
        "thieves" : BRM+"thiefboard",
    ]) );
}

void reset() {
  ::reset();
}

void init(){
    ::init();
}

