#include <std.h>
inherit OBJECT;

void create(){
      ::create();
      set_name("hand crank");
      set_id(({ "crank", "hand crank","handcrank"}));
      set_short("%^BOLD%^%^BLACK%^Hand Crank%^RESET%^");
      set_long("%^BOLD%^%^BLACK%^Covered with dust, "+
		"this hand crank appears to not have been used for"+
		" quite some time.  The wooden handle of the hand "+
		"crank is worn smooth from repetitive use.  The "+
		"handle runs perpendicular to the thick metal bar,"+
		" the two pieces fused together.  The rounded end "+
		"of the hand crank has been rounded off.  Cut "+
		"inside of this circle is a hollow square shape,"+
		" as if it once fit onto something.\n");
      set_weight(15);
      set_value(0);
}
void save_me(string file){return 1;}
