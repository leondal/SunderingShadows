
#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("%^MAGENTA%^I%^CYAN%^n%^CYAN%^s%^MAGENTA%^i%^CYAN%^d%^MAGENTA%^e%^CYAN%^ the walls of the %^MAGENTA%^T%^CYAN%^o%^CYAN%^w%^MAGENTA%^er %^MAGENTA%^of %^MAGENTA%^t%^CYAN%^h%^MAGENTA%^e %^MAGENTA%^Bl%^CYAN%^a%^MAGENTA%^c%^CYAN%^k %^CYAN%^D%^MAGENTA%^awn%^CYAN%^.");
    set_long(query_short()+"
%^CYAN%^The Tower is unlike anything you could ever have imagined.  It is built at a phenominal scale and sparkles in the light.  You can see hundreds of floating quartz layers inside!  Surrounding the tower is a crystal clear reflecting %^BLUE%^pool%^CYAN%^.
The scene is breathtaking.
%^BOLD%^A large mirror stands here.
");

    set_smell("default","There is a strange odor in the air, almost like some sort of spice.");
    set_listen("default","Your footsteps echo loudly through the halls.");

    set_exits( ([
    "west" : "/d/attaya/base/wall24",
    "east" : "/d/attaya/base/wall2",
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
	mon->set_id( ({"archer", "guard"}) );
	mon->move(this_object());
   }

}
void init() {
  ::init();
  add_action("enter_mirror", "enter");

}
  int enter_mirror(string str) {
  if(str=="mirror") {
  write("You step through the mirror and find yourself outside.");
  say(TPQCN+" floats like a wraith through the mirror.");
  TP->move_player("/d/attaya/base/enter");
return 1;
  }
return 0;
}
