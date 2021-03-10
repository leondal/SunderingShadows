#include <std.h>
inherit OBJECT;

void create(){
      ::create();
      set_name("sign");
      set_id(({ "sign", "warning sign"}));
      set_short("A warning sign");
      set_long("This is a metal pole with a wooden sign on it."+
      "  The way it is presented with many warning and danger "+
      "marks begs someone to <read sign>.");
      set_read("\n\n%^CYAN%^Warning!  The waters are extemely dangerous!\n \n"+
                "%^MAGENTA%^Moving the heart of water unsealed something best left sealed.\n"+
                "Diving to explore the ruins below will only bring death.\n"+
                "Be weary the %^CYAN%^water%^MAGENTA%^ lest it claim your life too..\n\n"+
                "%^GREEN%^OOC:  Underwater area recomended level 40+.\n");
      set_language("elven");
      set_weight(10000);
      set_value(0);
}
