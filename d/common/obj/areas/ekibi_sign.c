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
         "%^RESET%^The %^MAGENTA%^Ekibi Caverns %^RESET%^were so "+
         "named by the Halfling band that discovered them.  The "+
         "name means simply 'bad' in the language of the Halflings, "+
         "and it does seem to describe the caverns well.  Here, "+
         "insects grow to monstrous sizes, and they are the ones "+
         "who hunt humanoids!\n\n"+
         "Can you face the fierce man-eating insects of the "+
         "%^MAGENTA%^Ekibi Caverns%^RESET%^?\n\n";
      switch((int)TP->query_lowest_level()){
         case 0..4: tmp = "%^BOLD%^%^RED%^The insects which lie in "+
            "wait in the caverns ahead are vicious!  Most are well-"+
            "protected and might prove too great a challenge for you.  "+
            "You might consider returning to Offestry to hone your "+
            "skills.\n";
            break;
         case 5..8: tmp = "%^ORANGE%^The caverns below are just right "+
            "for someone of your experience and adventurous spirit.  "+
            "Proceed with caution - and remember, it never hurts "+
            "to have a few friends with you!\n";
            break;
         default: tmp = "%^YELLOW%^The caverns ahead are likely to offer little "+
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