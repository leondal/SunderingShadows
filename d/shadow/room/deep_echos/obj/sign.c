#include <std.h>
inherit OBJECT;

void create(){
      ::create();
      set_name("sign");
      set_id(({ "sign", "rock sign"," sign"}));
      set_short("A sign made from stone");
      set_long("%^BOLD%^%^BLACK%^This sign is made from a large rock."+
	           "  It is somewhat grey and black.  "
			   "Water from the area causes it to be wet "+
			   "and slippery.  Writing is carved into it.  "
	            "Perhaps you "+
                "could read it?\n");
        set_read("\n\n%^GREEN%^The tunnels have been overrun\n"+
                "Head back before it is too late\n "+
                "Death or worse awaits the foolish here.\n"+
                "%^YELLOW%^Make the right choice.\n"+
                "\n\n%^CYAN%^OOC This area is meant for"+
                " parties 15ish.");
        set_language("wizish");

      set_weight(10000);
      set_value(0);
}
