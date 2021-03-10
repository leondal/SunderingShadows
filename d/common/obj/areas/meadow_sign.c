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
         	"%^RESET%^Just ahead is the pastorial "+
         	"%^MAGENTA%^Bendith Y Mamau%^RESET%^, more commonly known as"+
		" the %^GREEN%^Meadowlands%^RESET%^.  The name comes from the "+
		"halfling term meaning 'Mother's Blessing', which they believe "+
		"the verdant bounty of the meadowlands to be a gift to their "+
		"people from Mielikki.  Some halflings have set up shops for "+
		"the adventures across the Meadowlands, offering clothing in "+
		"all sizes, trinkets, and even healing.  The temples of "+
		"%^BOLD%^%^MAGENTA%^Lathander%^RESET%^ and %^BOLD%^%^BLUE%^"+
		"Tymora%^RESET%^ also can be found within the verdant green "+
		"meadows. The Meadowlands have "+
		"become infested with werebeasts and ill tempered creatures that"+
		" threaten the halflings who live here.\n\n"+
         	"Can you, young adventurer, quell the large number of "+
	" %^MAGENTA%^beasts%^RESET%^?\n\n";	
      switch((int)TP->query_lowest_level()){
         case 0..5: tmp = "%^BOLD%^%^RED%^Beware the meadows ahead, young "+
            "one!  This challenge is well above those of Offestry.\n";
            break;
         case 6..12: tmp = "%^ORANGE%^The meadows ahead are meant for those of "+
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