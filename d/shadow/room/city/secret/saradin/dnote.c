#include <std.h>
#include <daemons.h>
inherit  "/std/Object";
void create() {
  ::create();
  	set_name("scribbled note");
  	set_id(({"note","scribbled note"}));
  	set_short("%^RESET%^%^ORANGE%^scribbled note%^RESET%^");
  	set_long("This is a piece of torn paper with a hurriedly "+
		"scribbled note on it.  The penmanship is horrible.\n"
     );
 	set_weight(1);
   set("value",0);
}
void init() {
  	::init();
  	add_action("read_em","read");
}
int read_em(string str) {
  	if(!str) {
   	tell_object(TP,"Read what?");
      return 1;
   }
  	if(str == "note" || str == "scribbled note"){
   	if(TP->query_lang("dwarvish") < 1) {
      	tell_object(ETO,"The inscription is written in a language "+
         	"you do not know.");
         return 1;
     	}
      if(TP->query_lang("dwarvish") < 75) {
      	tell_object(ETO,"The inscription is written in dwarven, but you "+
         	"do not know the language well enough to read what it says.");
         return 1;
     	}
     	write("%^RESET%^%^ORANGE%^"+
			"Seek da 13, not'sa tuff.\n"+
			"Look and find da shapes.\n"+
			"If ye press dem right 'nuff.\n"+
			"Den da open door gapes.\n"+
			"Round, triangle, square, round, triangle it be.\n"+
			"Opens tha door...ye'll see.\n"+
			"When done, or go ye in,\n"+
			"Close it up and it hides agin."+
			"%^RESET%^");
     	return 1;
 	}
}