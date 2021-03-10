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
         "%^RESET%^Just ahead is the dreaded "+
         "%^MAGENTA%^Goblin Fortress%^RESET%^, a camp of %^GREEN%^Goblins"+
        "%^RESET%^.  The goblins are poised for war, threatening to plunder the lands.\n\n"+
         "Can you, young adventurer, stop the"+
	" %^MAGENTA%^Goblins%^RESET%^ from invading the lands?\n\n";
      switch((int)TP->query_lowest_level()){
         case 0..10: tmp = "%^ORANGE%^The fortress ahead are meant for those of "+
            "your stature.  Use caution and proceed if you will - "+
            "though a few friends might be most helpful!\n";
            break;
         default: tmp = "%^YELLOW%^The fortress ahead are likely to offer little "+
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
