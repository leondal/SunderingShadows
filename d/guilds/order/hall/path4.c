#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(FOOT_PATH);

   set_short("Torn path toward the ruins of a once grand stronghold");
   set_long(
@OLI
   %^BOLD%^%^RED%^Before the broken gate of a once grand stronghold%^RESET%^
The rushing stream that once was here is now a shallow murky mess.
Obviously whatever attacked and took over this stronghold filled in the
stream. The drawbridge that was once on the opposite side is now no more
than a few blunted boards. The once white stone of the walls is now gray
with ashes. Streaks of black where siege towers burned dot the tops of the
now broken walls. The attackers must have had grand sappers, for at least two gaping holes exist in the walls.
OLI
   );
    set_property("light",2);
   set_smell("default","You can smell the blackened walls and the now slow and fetid stream.");
   set_listen("default","There is only the creak of wind from deep within the ruins.");

   set_exits(([

      "northeast":"/d/guilds/order/hall/path3",
      "south":"/d/guilds/order/hall/main"
      ]));

}

void init(){
   ::init();

   //add_action("call","lower");
}

int call(string str){
    if(member_array("Order of the Metallic Dragon",TP->query_guild()) < 0) return 0;
   if(!str || (str != "bridge" && str != "draw bridge"))
      return notify_fail("lower bridge\n");
   tell_object(TP,"The draw bridge lowers and allows you to enter.");
   tell_room(TO,"The draw bridge lowers and allows "+TPQCN+" to enter",TP);
   TP->move_player("/d/guilds/order/hall/main");
   return 1;
}
