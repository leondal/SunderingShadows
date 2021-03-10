#include <std.h>
inherit ROOM;

void create() {
        ::create();
        set_property("indoors",1); 
        set_property("light",1);
        set_terrain(BUILT_TUNNEL);
        set_travel(PAVED_ROAD);
        set_name("A dank tunnel"); 
        set_short("%^BLUE%^A dank tunnel%^RESET%^");
        set_long("%^BOLD%^%^BLACK%^Spira%^RESET%^%^BLUE%^l%^BOLD%^"+
           "%^BLACK%^ling gradually through the mountainside, "+
           "this narrow tunnel feels oppre%^RESET%^s%^BOLD%^"+
           "%^BLACK%^sive, as though the very darkness itself "+
           "is closing in on you.  Various %^RESET%^%^GREEN%^"+
           "mosses %^BOLD%^%^BLACK%^and low %^RESET%^%^GREEN%^"+
           "leafy plants %^BOLD%^%^BLACK%^grow along the walls, "+
           "a testament to the %^RESET%^%^CYAN%^moisture "+
           "%^BOLD%^%^BLACK%^coming from deeper within the "+
           "%^RESET%^%^RED%^tunnel%^BOLD%^%^BLACK%^.  The "+
           "gl%^RESET%^i%^BOLD%^%^BLACK%^tt%^WHITE%^e%^BLACK%^"+
           "ring gran%^RESET%^i%^BOLD%^%^BLACK%^te walls leak "+
           "a thick, viscous %^RESET%^liquid %^BOLD%^%^BLACK%^"+
           "that looks like nothing so much as a starless "+
           "night sky solidified.  It is unclear where this "+
           "tunnel leads, though it was clearly cut for a purpose.\n");
        set_smell("default","The dank odor of mosses and plants "+
           "fills the tunnel.");
        set_listen("default","From somewhere deep within the tunnel, "+
           "you hear the sound of rushing water.");
        set_items(([
           ({"tunnel","here","walls","floor","wall"}) : "This "+
              "tunnel is carved from the granite mountainside, "+
              "making the walls and floor glitter.  Little light "+
              "penetrates here, and the floor is always somewhat "+
              "slick, making footing uncertain.  A thick liquid "+
              "rolls slowly from the walls.",
           ({"moss","mosses","plants","plant"}) : "The mosses and "+
              "plants growing here are somewhat unusual for a "+
              "tunnel...they must be gathering liquid from somewhere.",
           ({"liquid","thick liquid"}) : "%^BOLD%^%^BLACK%^The "+
              "thick liquid is an inky black that seems to be "+
              "made of pure darkness itself."
        ]));
        set_exits(([
           "west" : "/d/magic/temples/shar_tunnel",
           "southeast" : "/d/magic/temples/shar_tunnel3"           
        ]));
}