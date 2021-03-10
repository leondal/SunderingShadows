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
         "%^RESET%^Just ahead lie the pathways of "+
         "%^MAGENTA%^Kildare Glen%^RESET%^, a town beset by "+
         "dread beasts known as %^GREEN%^perytons%^RESET%^.  The "+
         "town remains in much "+
         "peril, and only the bravest of young adventurers should "+
         "journey there!\n\n"+
         "It is said that the %^GREEN%^perytons%^RESET%^ look like great eagles "+
         "with the heads of stags and that they eat the hearts "+
         "of humanoids.  Are you brave enough to help the poor "+
         "citizens of %^MAGENTA%^Kildare Glen%^RESET%^?\n\n";
      switch((int)TP->query_lowest_level()){
         case 0..10: tmp = "%^BOLD%^%^RED%^Beware the pathways ahead, young "+
            "one!  This challenge is well above the goblins "+
            "and ogres you should be fighting.\n";
            break;
         case 11..16: tmp = "%^ORANGE%^The pathways ahead are meant for those of "+
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