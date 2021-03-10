#include <std.h>
inherit OBJECT;

void create(){
      ::create();
      set_name("yellow crystal");
      set_id(({ "crystal", "ycryst","yellow crystal"}));
      set_short("%^YELLOW%^Y%^RESET%^%^ORANGE%^e%^BOLD%^l"+
		"%^RESET%^%^ORANGE%^l%^BOLD%^o%^RESET%^%^ORANGE%^"+
		"w%^BOLD%^ Crystal%^RESET%^");
      set_long("%^YELLOW%^This large kite shaped crystal "+
		"has been cut with numerous planes.  The planes help "+
		"the crystal catch the light and sparkle. The yellow "+
		"crystal is about as big as a male human's hand, "+
		"tapering off to a point at the bottom. How the "+
		"crystal is cut it almost seems as if it is meant"+
		" to fit into something.  \n");
      set_weight(1);
      set_value(0);
}
void save_me(string file){return 1;}
