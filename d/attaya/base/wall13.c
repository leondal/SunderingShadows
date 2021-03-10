
#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("%^MAGENTA%^I%^CYAN%^n%^CYAN%^s%^MAGENTA%^i%^CYAN%^d%^MAGENTA%^e%^CYAN%^ the walls of the %^MAGENTA%^T%^CYAN%^o%^CYAN%^w%^MAGENTA%^er %^MAGENTA%^of %^MAGENTA%^t%^CYAN%^h%^MAGENTA%^e %^MAGENTA%^Bl%^CYAN%^a%^MAGENTA%^c%^CYAN%^k %^CYAN%^D%^MAGENTA%^awn%^CYAN%^.");
    set_long("%^MAGENTA%^I%^CYAN%^n%^CYAN%^s%^MAGENTA%^i%^CYAN%^d%^MAGENTA%^e%^CYAN%^ the walls of the %^MAGENTA%^T%^CYAN%^o%^CYAN%^w%^MAGENTA%^er %^MAGENTA%^of %^MAGENTA%^t%^CYAN%^h%^MAGENTA%^e %^MAGENTA%^Bl%^CYAN%^a%^MAGENTA%^c%^CYAN%^k %^CYAN%^D%^MAGENTA%^awn%^CYAN%^.
%^CYAN%^You are inside the %^MAGENTA%^walls%^CYAN%^ that surround the crystalline tower. The tower itself is visible through huge windows that line the inside of the walls!
%^CYAN%^A huge gateway occupies the south wall here. It is comprised of brightly polished metals and shines brilliantly. Looking down the hall, you can see many similar such structures, holding up the ceiling like braces. The hall is majestic and decorated with large red tapestries and paintings. The tower walls continue west and east.");
    set_smell("default","There is a strange odor in the air, almost like some sort of spice.");
    set_listen("default","Your footsteps echo loudly through the halls.");

    set_exits( ([
    "west" : "/d/attaya/base/wall14",
    "east" : "/d/attaya/base/wall12",
    "south" : "/d/attaya/base/wall29",
        ]) );
    set_items(([
      "windows" : "The entire inner wall is made of glass to display the beautiful crystalline tower outside.",
    "pool" : "The reflecting pool is crystal clear and reflects the crystalline tower."
    ]));

}
void reset(){
   object mon;
   ::reset();

    if(!present("archer")) {
         mon = new("/d/attaya/mon/archer");
	mon->move(this_object());
         mon = new("/d/attaya/mon/archer2");
       mon->move(this_object());
         mon = new("/d/attaya/mon/archer2");
       mon->move(this_object());
         mon = new("/d/attaya/mon/archer2");
      mon->move(this_object());
   }

}
