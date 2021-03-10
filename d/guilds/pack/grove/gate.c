#include <std.h>
#include "/d/guilds/pack/short.h"
#define GUILDSD "/daemon/guild_d.c"

inherit ROOM;

void create() {
    ::create();
   set_terrain(HEAVY_FOREST);
   set_travel(FOOT_PATH);
    set_property("light", 0);
    set_property("indoors", 0);
    set_property("no teleport", 1);
   set_short("%^RED%^Before the gates of Destiny Keep%^RESET%^");
    set_long(
@SEETH
 You stand before the %^RED%^Gates %^RESET%^of Destiny Keep%^RESET%^
 %^RED%^The fortress is shrouded by darkness and despair. There are many corpses and skeletons of those who tried to enter the Keep. There seems to be no other way in besides the iron gates. The gates themselves appear to weigh more than a ton. It is hopeless to even dare try to enter Destiny Keep.
SEETH
    );
    set_items( ([

      ]) );
    set_exits( ([
	"south" : GROVE "g13.c",
      ]) );


}
void init() {
    ::init();
    add_action("touch_gate","touch");
}

int touch_gate(string str){
    //string pguild, guild;

    //pguild = (string)TP->query_guild();
    //guild = GUILDSD->query_control_guild("/d/guilds/pack/hall/main");
    if(!str){
	write("what?");
	return 1;
    }
    if(str == "gate" || str == "gates"){
        /*if(guild != pguild){
	    tell_room(TO,TP->query_cap_name()+" touches the Iron Gates.",TP);
	    write("You touch the gates, but nothing happens.");
	    return 1;
        }*/
	write("%^BOLD%^%^RED%^You touch the Iron Gates and feel yourself being pulled through the gates.");
	TP->move_player(HALL "main.c");
	return 1;
    }
}
