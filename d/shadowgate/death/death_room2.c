#include <std.h>
#include <dieties.h>

inherit ROOM;

void create(){
    ::create();
    set_short("The gate to the etherial plane");
    set_property("light", 2);
    set_property("no teleport", 1);
    set_property("indoors", 1);
    set_long(
      "You are floating in a strange room.  Before you there are many gateways to the mortal plane, each leading into a different church.  To move on, choose the exit that leads to the church that you wish to go, and you shall move there. Beware though, this gateway is one way."
    );
    set_smell("default", "You smell nothing in the void.");
    set_listen("default", "You hear nothing in the void.");
    set_exits( ([
	"shadow" : "/d/shadow/room/city/church",
	"tharis" : "/d/tharis/Tharis/church",
	"kinaro" : "/d/dagger/kinaro/church",
	"daggerdale" : "/d/dagger/Daggerdale/shops/chapel",
	"seneca" : "/d/attaya/seneca/church",
	"graez" : "/d/undead/town/rooms/church",
	"asgard" : "/d/laerad/parnelli/asgard/as72",
	"antioch" : "/d/antioch/wild/forest/chapel_out",
	"deku" : "/d/deku/town/church",
	"tonovi" : "/d/dagger/tonovi/town/temple2.c",
	"dallyh" : "/d/islands/dallyh/forest/rooms/church.c",
   "temple" : "/d/shadow/room/city/church.c",
      ]) );
}

void init(){
    ::init();
    add_action("temple", "temple");
}

int temple(string str){
    if(!TP->query_diety() || (string)TP->query_diety() == "pan"){
      tell_object(TP, "You need to follow a diety before you can go to their temple.");
      return 1;
    }

    if(member_array(TP->query_diety(), keys(DIETIES)) == -1){
      tell_object(TP, "That god doesn't exist.");
      return 1;
    }

    TP->move_player("/d/magic/temples/"+TP->query_diety());

    return 1;
}
