#include <std.h>
inherit OBJECT;

void create(){
      ::create();
      set_name("marble lyre");
      set_id(({ "lyre", "marble lyre"}));
      set_short("%^BOLD%^%^WHITE%^Marble Lyre%^RESET%^");
      set_long("%^BOLD%^%^WHITE%^Carved from white marble,"+
		" this large lyre is purely for decoration.  The lyre's"+
		" frame curves with elegant graceful lines.  The central"+
		" crossbar is shaped from pure %^YELLOW%^gold%^WHITE%^."+
		"  Strung with six %^YELLOW%^gold%^WHITE%^ string, the"+
		" lyre looks lavish.  Too bad that it is only a decoration"+
		" and not a true instrument. \n");
      set_weight(5);
      set_value(0);
}
void save_me(string file){return 1;}
