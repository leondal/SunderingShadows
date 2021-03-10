
#include <std.h>
inherit ROOM;


void create(){
    object ob;
    :: create();

    set_short("Arena healing room.");
    set_property("no teleport", 1);
    set_long(
      "Here is where the warriors that have been defeated in honorable battle are sent to heal.  A mystic pool of healing is here.  Drink from its waters and you will feel your strength return."
    );

    set_items(([
	"pool" : "The pool before you is calm and the water glistens.",

      ]));

    set_exits(([
	"out" : "/d/shadow/guilds/riders/guild2.c"

      ]));

    set_smell("default", "It smells of blood here.");

    set_listen("default","You can hear the soothing sounds made by the water in the pool.");
    set_property("arena",1);
}
void init(){
    ::init();
    add_action("drink","drink");
}

int drink(string str){
    int hp_gain;
    if(!str) return notify_fail("Drink what?\n");
    if(str != "water") {
	notify_fail("You can't drink that!");
	return 0;
    }
    write("You drink from the healing pool....and feel a bit of healing throughout your body.");
    hp_gain = 4000;
    TP->add_hp(hp_gain);
    write("You feel healed by the wonderful waters.");
    return 1;

}



