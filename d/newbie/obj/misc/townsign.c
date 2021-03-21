#include <std.h>
//inherit OBJECT;
inherit "/d/newbie/obj/misc/map";

void create() {
    ::create();
    set_id( ({"sign","large sign", "map"}) );
    set_name("large sign");
    set_short("%^RESET%^%^ORANGE%^a large sign%^RESET%^");
    set_weight(1000000);
    set_property("no animate", 1);
    set_long("%^RESET%^%^ORANGE%^Lines of text have been scrawled upon the sign to read.  Beneath them, there is a "
"%^YELLOW%^map%^RESET%^%^ORANGE%^ that you could %^RESET%^read%^ORANGE%^.\n\n"
"%^RESET%^The town of Offestry is the center of this small valley, and serves as the entry point to the wider world of "
"Sundering Shadows.  Here, life is easier and simpler, so that you may learn your way before you progress onwards.  Newbie "
"status will end when you find your trainer or pass through the last gate far to the south.  Help is readily available "
"via the 'newbie' and 'inform' lines, and even the shopkeepers will try to answer some of your questions.\n\n"
"%^BOLD%^It is required that the rules be observed and that you roleplay from the beginning.  Reading  <help rules>, "
"<help newbie>, and <faq> will give you the basis you need to get started.  You can also wander into the <ooc> area from "
"here and look at the posters, when you are ready for more information about the game.\n");
    set_value(0);
}

void init(){
	::init();
}

int __Read(string str)
{
//   object mapObj;
//   if(str == "sign")
//   {
//        TP->force_me("look sign");
//        return 1;
//   }
//   if(str == "map")
//   {
//     mapObj = new("/d/newbie/obj/misc/map");
//     return (: "/d/newbie/obj/misc/map"->"read_func", str :);
//     mapObj->remove();
//     return 1;
//
//   }
     return ::read_func(str);
}
