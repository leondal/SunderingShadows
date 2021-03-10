
#include <std.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_property(  "light" , 2);
    set_property( "indoors" , 1 );
    set_short(" Alchemist Shop ");
    set_long(
"%^BOLD%^You are standing in the shop of an alchemist.%^RESET%^\n"+
"You can see vials and test tubes everywhere here, with all of it neatly organized."+
" In the back of the shop are many experimental potions that are either simmering or"+
" cooling. The shop holds all sorts of different ingredients for things.\n"+
"Type <help shop> for information on how to use the shop."
);

   set_smell("default","You smell the odor of harsh chemicals.");
    set_listen("default","You hear the sounds of bubbling liquids.");

    set_items( ([ "tube": "A tube of colorless bubbling liquid",
      "vial": "A glass vial containing some unknown liquid",
      "tubes": "A row of glass tubes containing colorless bubbling liquids",
      "vials": "A row of glass vials containing some unknown liquid" ]) );
    set_exits( ([
"north" : "/d/dagger/Daggerdale/streets/street24",
"east" : "/d/dagger/Daggerdale/streets/street17",
                ]) );
}

void reset()
{
    ::reset();
    if(!present("shanna"))
      find_object_or_load("/d/dagger/Daggerdale/shops/npcs/shanna")->move(TO);
}
