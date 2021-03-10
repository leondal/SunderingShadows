#include <std.h>
inherit OBJECT;

void create(){
      ::create();
      set_name("sign");
      set_id(({ "sign", "frozen sign","rock sign"}));
      set_short("A frozen sign");
      set_long("This sign looks to be made from rocks placed"+
	  " into the ice and frozen there.  One has to brush "+
	  "off the thin bit of snow to read it.  It obviously "+
	  "is a warning of some kind that someone decided to "+
	  "make before leaving to a safer place. \n"+
	  "    Perhaps you could read it?\n");
      set_read("\n\n%^CYAN%^This island is stuck in"+
	  " a perpetual winter.  There is nothing"+
	  " here but the chill touch of Lord Shadow.  "+
	  "Turn back lest you end up a frozen corpse.\n\n"+
	  "%^MAGENTA%^This area is designed for "+
	  "parties around level 30. Parts of it will be difficult"+
	  " for characters in their 40s."+
	  "\n%^BOLD%^%^RED%^Characters lower than that will"+
	  " likely get to meet Lysara.");
      set_language("wizish");
      set_weight(10000);
      set_value(0);
}
