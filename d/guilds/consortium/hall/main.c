#include <std.h>

inherit ROOM;

void create() {
   object ob;
   ::create();
   set_light(2);
   set_property("indoors", 1);
   set_short("Main Hall");
   set_long(
           "You have entered the breath-taking tower of the Thaumaturgical Consortium.  Here is where those deemed the best minds in the realms study and research to better their personal knowledge.  Tapestries and Paintings line the walls depicting the growth of the lands as time has passed.  An oversized hourglass sits in one corner of the room and in the opposite corner a globe of Shadowgate.  Double doors to the east lead to the Hall of the Council where the Leaders meet to discuss events and changes."
           );
   set_listen("default", "You hear the murmer of chanting mages.");
   set_smell("default", "Burning incense is strong in the air.");
   set_items( ([
               "tapestries" : "These beautiful tapestries taken together give you a beautiful depiction of the history of ShadowGate",
               "hourglass" : "This hourglass silently counts away time.",
               ]) );
   set_exits( ([
               "south":"/d/guilds/consortium/hall/storeroom",
               "east":"/d/guilds/consortium/hall/meeting",
      "up" : "/d/guilds/consortium/hall/lab",
               "west":"/d/guilds/consortium/hall/lounge",

               ]) );

//   ob = new("std/bboard");
//   ob->set_name("board");
//   ob->set_id( ({ "board", "bulletin board", "reality board"}) );
//   ob->set_board_id("consortium_board");
//   ob->set("short", "The Board of the Consortium");
//   ob->set("long", "This is the thought board for the Consortium members.");
//   ob->set_max_posts(30);
//   ob->set_location("/d/guilds/consortium/hall/main");

}
