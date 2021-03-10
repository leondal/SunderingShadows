#include <std.h>
inherit OBJECT;

void create(){
      ::create();
      set_name("sign");
      set_id(({ "sign", "bronze sign"}));
      set_short("A frost covered sign");
      set_long("This is a bronze sign that looks to be"+
	  " hung from the wall.  There is a green painted"+
	  " message etched into the flat.  The whole sign"+
	  " is covered with snow and ice.  One has to brush"+
	  " it off to get a good look at the lettering.");
      set_read("\n\n%^CYAN%^Ashta'Rathai is a haven for Tel'Quessir\n \n"+
                "Outsiders turn back now.\n"+
                "Do not be foolish.\n\n"+
                "%^GREEN%^No mercy will be shown to those that disrespect these boundaries.\n");
        set_language("common");

      set_weight(10000);
      set_value(0);
}
