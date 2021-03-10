#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("A small wooden sign");
   set_short("A small wooden sign");
   set_long("This small wooden sign is placed on a short post and "+
      "seems to provide information on what lies just beyond.  "+
      "You should probably read it.");
   set_id(({"sign","wooden sign","area sign"}));
   set_weight(10000);
   set("read",(:"sign_read":));
}

int sign_read(string str){
string main, tmp;
   if(id(str)){
      main = "%^CYAN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"+
         	"%^RESET%^Just ahead is a camp of "+
                "%^MAGENTA%^Orcs%^RESET%^, ready to rampage through"+
		" the %^GREEN%^Meadowlands%^RESET%^ and lands beyond.  The "+
                "orc are poised for combat, ready to unleash a bloody fury"+
		" upon anyone who trespasses.  There are rumors that the elven"+
		" village of %^BOLD%^%^GREEN%^Synoria%^RESET%^ lays somewhere within these forests, "+
                "watching the orcs and adventurers carefully.\n\n"+
         	"Can you, brave adventurer, stop the"+
	" %^MAGENTA%^Orcs%^RESET%^ before they invade the lands?\n\n";
      switch((int)TP->query_lowest_level()){
         case 0..9: tmp = "%^BOLD%^%^RED%^Beware the forest ahead, young "+
            "one!  This challenge is well above those of the Meadowlands and goblins.\n";
            break;
         case 10..15: tmp = "%^ORANGE%^The forest ahead are meant for those of "+
            "your stature.  Use caution and proceed if you will - "+
            "though a few friends might be most helpful!\n";
            break;
         default: tmp = "%^YELLOW%^The pathways ahead are likely to offer little "+
            "challenge for one of your skill.\n";
            break;
	}
      tell_object(TP,""+main+""+tmp+"%^RESET%^%^CYAN%^~*~*~*~*~*~*~*~"+
         "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^");
      if(!TP->query_invis()){
         tell_room(ETP,""+TPQCN+" seems to be studying the sign.",TP);
      }
      return 1;   
   }
   return 0;
}
