#include <std.h>
inherit OBJECT;

void create(){
      string str;
      ::create();
	  str = read_file("log/elftown.log");
      set_name("sign");
      set_id(({ "sign", "wooden sign"}));
      set_short("%^RESET%^%^ORANGE%^A wooden sign%^RESET%^");
      set_long("This is a large wooden sign "+
	  "that has many reports of crimes attached"+
	  " to it.  The watch submits reports and "+
	  "they are compiled here for investigation. "+
	  " One could _read sign_ if they wished to.");
      set_read("\n"+str);
      set_language("elven");

      set_weight(10000);
      set_value(0);
}
