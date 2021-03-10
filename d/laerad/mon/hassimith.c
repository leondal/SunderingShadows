//Coded by Bane//
#include <std.h>
inherit "/std/comp_vend";
void create() {
    ::create();
    set_id(({"hassimith","shopkeeper","hassimith the apprentice"}));
    set_name("hassimith");
    set_short("Hassimith the apprentice");
    set_long(
	"Hassimith is the tiniest troll you have ever seen.  He stands only about "+
	"4 feet tall and is clothed in a stinky brown robe.  He is amazingly "+
	"ugly even for a troll.  You can <list comp> to see what is for sale."
    );
   set_gender("male");
    set_body_type("human");
    set_race("troll");
    set_size(2);
    set_alignment(5);
    set_components(100);
    set_hd(19,3);
    set_hp(155);
    set("aggressive",0);
}

