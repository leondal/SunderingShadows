#include <std.h>

inherit "/std/guilds/members.c";

void create(){
    ::create();
    set_property("indoors", 1);
    set_light(2);
    set_short("Meeting Room");
    set_long(
      "Here in this room many decisions are made to better the Consortium.  A long, oval table centers itself in the room lined with candlesticks to light the room.  Twelve chairs encircle the table for the Council to sit and converse over different topics."
    );
    set_smell("default", "Pipe smoke lingers in the air.");
    set_listen("default", "You can almost hear the arguments that happen in this room as you listen to the silence.");
    set_items( ([
      "table" : "This long oval table has seen many arguments, and many more colloborations to the better of the Consortium.",
      "candlesticks" : "These magic candlesticks will burn until the end of time.",
    ]) );
    set_exits( ([

         "west":"/d/guilds/consortium/hall/main",
         
    ]) );
    set_guild_name("The Consortium");
    set_guild_object("/d/guilds/consortium/obj/cowl_knowledge.c");

}
