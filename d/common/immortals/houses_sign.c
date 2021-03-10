#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_long("This sign has been placed here to allow us to keep a running "+
      "total on the number of HM houses that have been requested as well as "+
      "who is working on what.  If you know of a request an HM has made, please "+
      "pass it on to Circe, and she'll add it here.  This list will be kept "+
      "up-to-date so we may all know what's going on.  To see the list, simply "+
      "<view list>."
	);
   set_short("%^BOLD%^%^GREEN%^A sign%^MAGENTA%^");
   set_id(({"sign", "houses_sign"}));
   set_name("houses_sign");
   set_weight(10000);
   set_value(0);
}

void init(){
   	::init();
   	add_action("view_func","view");
}

int view_func(string str) {
   if(!str && str != "list") return 0;
   TP->force_me("more /realms/circe/working/hm_houses");
   return 1;
}