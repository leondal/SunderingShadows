//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(RUINS);
    set_travel(RUBBLE);
/*    set_property("no teleport",1);
    set_property("no steal",1);
*/
    set_name("An old abandoned throne room");
    set_short("An old abandoned throne room");
    set_long(
	"You are standing in a torn up throne room.  Broken chairs and "+
	"pieces of wood are scattered across the room.  Rusted weapons and "+
	"armors are hung from the walls.  An ancient throne sits on the "+
	"northern wall, all dull and covered in dust.  A skeleton sits "+
	"upon it, unmoving."
    );
    set_items(([
      (({"throne","ancient throne"})) : "The ancient throne is made of aged, "+
         "cracking wood.  Moss and fungi have begun to grow along the legs, "+
         "spoiling the once-grand splendor.  A large skeleton sits atop the "+
         "throne, lifeless and still.",
      (({"chairs","chair","broken chairs","wood","debris"})) : "The throne "+
         "room is littered with various bits of broken chairs and other debris.  "+
         "The wood is all splintered and decaying, and everything is completely "+
         "covered in thick dust.",
      (({"weapons","armors","rusted weapons","rusted armors"})) : "Hanging from "+
         "pegs on the wall are once-grand weapons and armors, most of which are "+
         "rusted completely through in places.  Rust stains are smeared down the "+
         "walls beneath many of them.  Suits of fullplate, breastplates, shields, and "+
         "gauntlets fill space between various battle-axes, swords, and daggers.",
      "skeleton" : "The large skeletal figure seated upon the throne must have "+
         "been a great warrior at one time.  He is rumored to have been the guardian of "+
         "this chamber when whoever lived here was a vital part of the world, but "+
         "his time has past as the memories of this place have faded."
    ]));
    set_smell("default","The smell of old armors and weapons fill the air.");
    set_listen("default","Silence hangs in the air.");
    set_exits( ([
	"south":"/d/shadow/guilds/angels/tmp/hall1"
    ]) );
}
/*
void init(){
    ::init();
    if((string)TP->query_guild() == "Fallen Angel"){
    set_name("Fallen Angels throne room");
    set_short("Fallen Angels throne room");
    set_long(
        "You are standing in a fabulous throne room. Candeliers decorate "+
        "the ceiling shedding a wonderful glow across the room.  Ancient "+
        "weapons and armors adorn the walls, obviously important artifacts "+
        "relating to the victories of the guild.  A huge golden throne "+
        "sits on the northern wall.  A gaunt figure sits upon it keeping "+
        "watch over the room and its treasures."
    );
    } else {
    set_name("An old abandoned throne room");
    set_short("An old abandoned throne room");
    set_long(
	"You are standing in a torn up throne room.  Broken chairs and "+
	"pieces of wood are scattered across the room.  Rusted weapons and "+
	"armors are hung from the walls.  An ancient throne sits on the "+
	"northern wall, all dull and covered in dust.  A skeleton sits "+
	"upon it keeping watch over the room."
    );
    }
}
*/
void reset(){
    ::reset();
//    if(!present("nihilus")){  ****Commenting out since the guild is inactive and this is a lowbie area - Circe 8/24/03
//	new("/d/shadow/guilds/angels/tmp/mon/nihilus")->move(this_object());
//    }
/* not appropriate with guild gone
    if(!present("chest")){
	new("/d/shadow/guilds/angels/tmp/gchest")->move(this_object());
    }
*/
}
/*
void clean_up(){return 1;}
*/
