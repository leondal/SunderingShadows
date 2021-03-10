#include <std.h>
inherit OBJECT;
void create(){
  ::create();
  set_name("lava sack");
 set_id(({"lava sack","lava","sack"}));
  set_short("%^BOLD%^%^RED%^Lava Sack%^RESET%^");
  set_long("%^BOLD%^%^RED%^The lava sack is actually a"+
	" gland within the Lava Rex that allows him to "+
	"draw in searing hot lava and store it within.  "+
	"The lava is then spewed or spit forth when he is"+
	" threatened.  The sack is dull gray in color with"+
	" a thick mucus membrane around it that gives it a"+
	" slick wet feeling.  You can feel the heat of the"+
	" lava that still resides inside the sack.");
   set_weight(6);
  set_value(random(2500)+5000);
}
