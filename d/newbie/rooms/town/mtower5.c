//Scroll shop added by Circe for newbies only 6/7/07
//Added after discussion with other Imms
#include <std.h>
#include "../../newbie.h"
inherit ROOM;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("An imposing stone tower");
    set_short("%^MAGENTA%^An imposing stone tower");
    set_long("%^MAGENTA%^An imposing stone tower%^RESET%^\n"+
"This cluttered room is dominated by a rather large, low %^ORANGE%^table%^RESET%^ that sits just about a foot off the "
"floor.  Two wooden %^ORANGE%^stools %^RESET%^sit near the table, providing easy access to the %^BOLD%^quills%^RESET%^, "
"reams of parchment, and bottles of %^BOLD%^%^BLACK%^ink%^RESET%^ strewn across its surface.  All around the walls, "
"%^BOLD%^%^CYAN%^bookcases %^RESET%^painted in brilliant shades of aquamarine, pink, and gold have been placed, but "
"strangely, they are only about half as tall as the room would allow.  Delicate %^CYAN%^globes %^RESET%^of light hang at "
"different heights around the room, providing plenty of light to work by.\n\n"
"%^YELLOW%^<help shop> %^RESET%^will give you help on how to use this shop.\n");
    set_smell("default","The tower smells of dry parchment, mingled with faint hints of sulfur.");
    set_listen("default","Little disturbs the quiet here.");
    set_items(([
        ({"globes","globe"}) : "%^CYAN%^The globes appear to be very delicate, etched from fine glass.  They have been "
"filled with phosphorescent moss that sheds a soft magical glow around the tower.%^RESET%^",
        ({"bookcases","bookcase"}) : "%^BOLD%^%^CYAN%^The bookcases provide a rainbow of color to an otherwise dull room"
".  They are arranged almost haphazardly along the walls, and they reach much shorter heights than one would normally "
"find.  They are filled with rolled scrolls as well as blank parchments and supplies.%^RESET%^",
        ({"table","stool","stools"}) : "%^ORANGE%^The low table is large and covered with countless supplies needed for "
"magical writings.  It seems to be sized for someone quite small, as are the stools standing nearby.%^RESET%^",
        ({"scrolls","bottles","ink","quills","parchment"}) : "%^BOLD%^Scattered all over the room are the supplies needed "
"to complete scrolls.%^RESET%^"
    ]));
    set_exits(([
      "east" : MAINTOWN"mtower1"
    ]));
}

void reset(){
   ::reset();
   if(!present("taribella")) find_object_or_load(MON"taribella")->move(TO);
}