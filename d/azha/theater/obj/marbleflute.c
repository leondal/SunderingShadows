#include <std.h>
inherit OBJECT;

void create(){
      ::create();
      set_name("marble flute");
      set_id(({ "flute", "marble flute"}));
      set_short("%^BOLD%^%^WHITE%^Marble Flute%^RESET%^");
      set_long("%^BOLD%^%^WHITE%^Carved from white marble,"+
		" this large flute is purely for decoration.  The flute's"+
		" frame curves with elegant graceful lines.  The mouthpiece"+
		" is shaped from pure %^YELLOW%^gold%^WHITE%^."+
		"  Trimmed with %^YELLOW%^gold%^WHITE%^, each hole of the"+
		" flute shines.  Too bad that it is only a decoration"+
		" and not a true instrument. \n");
      set_weight(5);
      set_value(0);
}
void save_me(string file){return 1;}
