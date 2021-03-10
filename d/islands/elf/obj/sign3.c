#include <std.h>
inherit OBJECT;

void create(){
      ::create();
      set_name("carving");
      set_id(({ "carving", "stone carving"}));
      set_short("A stone carving");
      set_long("This is a stone carving built into the wall."+
	  "   It looks to have some elven writing on it. ");
      set_read("\n\n%^CYAN%^Ashta'Rathai's mythal built by Tel'Quessir of centuries past.\n \n"+
                "%^MAGENTA%^It once turned away all scrying eyes.\n"+
                "It once turned away all non elven teleporation.\n"+
                "Sadly, the high magic of mythal craft is lost to us.\n\n"+
                "%^GREEN%^We remember our ancestors and their great wonders.\n");
      set_language("elven");
      set_weight(10000);
      set_value(0);
}
