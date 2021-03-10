
#include <std.h>
inherit ROOM;


void create(){
object ob;
:: create();

set_short("Arena healing room.");
set_long(
@ZERINA
This is the room where all vanquished warriors go. There is a healing pool here that will heal your wounds and make you whole again.
%^BOLD%^%^RED%^You hear a voice ring in your ears saying%^RESET%^: Be well noble Shades Warrior. Heal so you might fight yet another battle!

ZERINA
);

set_items(([
"pool" : "The pool before you is calm and the water glistens.",

]));

set_exits(([
"out" : "/d/shadow/guilds/pack/hall/pack2.c",

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
hp_gain = 1000;
    TP->add_hp(hp_gain);
write("You feel healed by the wonderful waters.");
return 1;

}



