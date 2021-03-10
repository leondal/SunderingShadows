// reaver trap by Bane
#include <std.h>
#include "/d/tharis/barrow/short1.h"
inherit ROOM;
void create(){
    ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(RUTTED_TRACK);
   set_name("Reaver nest");
    set_short("Reaver nest");
    set_long(
	"The room is a massive hell hole.  Fire leaps "+
	"at you from a large pit in the center of the room.  Half "+
	"severed bodies hang in shackles from the walls draped in "+
	"barbed wire and spikes.  The floor appears to be moving but "+
	"at a closer look you notice the entire floor is covered in "+
	"running blood."
   "\nThe walls have what appear to be footholes in them."
    );
    set_property("light",2);
    set_property("indoors",1);
    set_smell("default","The room smells of urine and blood.");
    set_listen("default","The screams of unseen prisoners haunts your mind.");
    set_exits( ([
    ]) );
}
void init(){
    ::init();
    add_action("climb_func","climb");
}
void climb_func(string str){
    if(!str) return notify_fail("Climb what?\n");
    if(str != "wall") return 0;
    write("You climb out of the Reavers nest.");
    tell_room(TO,TPQCN+" climbs up the wall.");
TP->move_player(RPATH "pit");
    return 1;
}

void reset(){
    object ob, ob2;
    ::reset();
    if(!present("reaver")){
      ob = new("/d/dagger/marsh/swamp/mon/reaver");
      ob->move(TO);
      ob2 = present("scythe", ob);
      if(objectp(ob2)) ob2->set_property("monsterweapon", 1);
      //ob2 = present("scythe 2", ob);  // The reaver has been modified to have only one weapon, and so this was generating an error 7/19/05 -Ares
      //ob2->set_property("monsterweapon", 1);
      ob2 = present("robe", ob);
      if(objectp(ob2)) ob2->set_property("monsterweapon", 1);
      new("/d/tharis/barrow/obj/tyrelk")->move(ob);
    }
}
