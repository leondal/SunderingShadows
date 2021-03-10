#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create(){
	::create();
	set_travel(PAVED_ROAD);
	set_terrain(CITY);
	set_light(2);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
	set_indoors(1);
	set_name("Crystal Emporium");
	set_short("Crystal Emporium");
	set_long(
"%^BOLD%^Crystal Emporium, Tabor%^RESET%^\n"+
"%^CYAN%^Despite the %^BOLD%^crystalline walls%^RESET%^"+
"%^CYAN%^, this shop has an almost country-home feel to it.  "+
"A simple overstuffed %^ORANGE%^arm chair %^CYAN%^sits in "+
"one corner, a large %^RESET%^doily %^CYAN%^upon its back.  "+
"A %^ORANGE%^table %^CYAN%^standing alongside it supports a "+
"unique %^YELLOW%^lamp %^RESET%^%^CYAN%^with a %^RED%^m%^ORANGE%^u"+
"%^YELLOW%^l%^GREEN%^t%^CYAN%^i%^WHITE%^-%^BLUE%^h%^RESET%^%^MAGENTA%^u"+
"%^BOLD%^e%^RED%^d %^RESET%^%^CYAN%^shade encrusted with %^BOLD%^"+
"%^WHITE%^gems%^RESET%^%^CYAN%^.  Clearly, the owner of this shop "+
"has chosen to make good use of the %^BOLD%^crystals %^RESET%^"+
"%^CYAN%^at hand, using them as shop decorations.  In addition to "+
"%^ORANGE%^wooden boxes %^CYAN%^filled "+
"with finished %^BOLD%^crystals%^RESET%^%^CYAN%^, various other "+
"gems unfit for use with powers have instead been turned into "+
"decorations.  %^BOLD%^%^WHITE%^Crystal vases %^RESET%^%^CYAN%^"+
"full of likewise %^BOLD%^crystalline %^RED%^f%^MAGENTA%^l"+
"%^YELLOW%^o%^MAGENTA%^w%^RED%^e%^MAGENTA%^r%^YELLOW%^s %^RESET%^"+
"%^CYAN%^are placed alongside the %^ORANGE%^boxes%^CYAN%^, "+
"adding to the homey feel of the shop.\n\n"+
"%^RESET%^<help shop> will give you help on how to use the shop.\n"
	);
	set_smell("default","The pleasant scent of wildflowers is in the air.");
	set_listen("default","A faint wisp of soft music plays at the back of your mind.");
	set_items(([
         ({"chair","armchair","arm chair"}) : "The arm chair in the "+
            "corner is made of soft plaid material, well-worn and "+
            "comfortable looking.  The material covering the arms is "+
            "thin, likely from its owner helping herself up and "+
            "down to help customers.  The lace doily upon the back "+
            "bears a few distinct cat hairs.",
         ({"lamp","table","table lamp"}) : "The lamp upon the "+
            "table casts a multi-colored light over the room, "+
            "its shade made in a stained glass array of "+
            "gems.  It seems to have been hand-made and slightly "+
            "eye-jarring, except of course to those who like "+
            "bright colors.",
         ({"boxes","crystals","tables"}) : "Small round tables "+
            "spread about the room hold the boxes of crystals for "+
            "sale.  There seems to be little organization - the "+
            "gems seemed to have been jumbled together for aesthetic "+
            "value rather than convenience.",
         ({"vases","vase","flowers","crystalline flowers","flower"}) : "Flowers "+
            "made of tiny gems joined together upon crystalline stalks "+
            "are arranged in vases upon the tables, and they seem "+
            "to emanate a fragrance just like real flowers!  Much "+
            "care has been taken in their creation and arrangement, "+
            "almost more than in the shop itself."
    ]));
    set_exits(([
        "north" : ROOMDIR+"psihall"
    ]) );
}

void reset(){
   ::reset();
   if(!present("aemilia")) {
      find_object_or_load(MONDIR+"aemilia")->move(TO);
   }
}
