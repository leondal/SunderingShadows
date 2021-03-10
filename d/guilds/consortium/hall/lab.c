#include <std.h>
inherit "/std/lab";

void create()
{
   object ob;
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(STAIRWAY);
   set_property("light",2);
   set_short("Laboratory of the Consortium");
   set_long("You have entered the laboratory of the Consortium.  The guilds' mages"+
   " come here in order to practice their magical crafts and create new spells."+
   "  There are many cubbies filled with vials and potions, exotic ingredients and"+
   " unusual spell components.  The furniture in the room is sparse with only a"+
   " rectangular table and a few stools about it.");
   set_smell("default","The scent from a variety of exotic components and unusual potions fills the room.");
    set_listen("default","It is generally quiet in here, with an occasional loud explosion from a botched mixture.");
   set_property("indoors",1);
   //setOwner("consortium");
   setLabId("consortium");
   set_exits(([
   "down" : "/d/guilds/consortium/hall/main",
   ]));
}
