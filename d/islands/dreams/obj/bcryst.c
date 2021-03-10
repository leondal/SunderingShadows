#include <std.h>
inherit OBJECT;

void create(){
      ::create();
      set_name("blue crystal");
      set_id(({ "crystal", "bcryst","blue crystal"}));
      set_short("%^BOLD%^%^BLUE%^B%^CYAN%^l%^BLUE%^u%^CYAN%^e "+
		"%^BLUE%^Crystal%^RESET%^");
      set_long("%^BOLD%^%^BLUE%^This large kite shaped crystal "+
		"has been cut with numerous planes.  The planes help "+
		"the crystal catch the light and sparkle. The blue "+
		"crystal is about as big as a male human's hand, "+
		"tapering off to a point at the bottom. How the "+
		"crystal is cut it almost seems as if it is meant"+
		" to fit into something.  \n");
      set_weight(1);
      set_value(0);
}
void save_me(string file){return 1;}
