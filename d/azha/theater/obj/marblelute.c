#include <std.h>
inherit OBJECT;

void create(){
      ::create();
      set_name("marble lute");
      set_id(({ "lute", "marble lute"}));
      set_short("%^BOLD%^%^WHITE%^Marble Lute%^RESET%^");
      set_long("%^BOLD%^%^WHITE%^Carved from white marble,"+
		" this large lute is purely for decoration.  The lute's"+
		" frame curves with elegant graceful lines.  The neck"+
		" is shaped from pure %^YELLOW%^gold%^WHITE%^."+
		"  Strung with six %^YELLOW%^gold%^WHITE%^ string, the"+
		" lute looks lavish.  Too bad that it is only a decoration"+
		" and not a true instrument. \n");
      set_weight(5);
      set_value(0);
}
void save_me(string file){return 1;}
