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
         "%^RESET%^Once a dwarven mine and (some say) grand city, "+
         "the pathways through %^YELLOW%^Echoes Mountains %^RESET%^"+
         "have now been taken over by vicious %^RED%^ogres%^RESET%^!\n\n"+
         "The dwarves of %^YELLOW%^Echoes Mountains %^RESET%^have "+
         "lost much of their home to the plundering of the %^RED%^"+
         "ogres%^RESET%^.  Do you think you're strong enough to do "+
         "what the dwarves couldn't?  Treasure lies in wait for "+
         "those brave enough to try.\n\n";
      switch((int)TP->query_lowest_level()){
         case 0..8: tmp = "%^BOLD%^%^RED%^The caverns ahead are filled "+
            "with many hidden dangers!  You might wish to test your "+
            "skills against the goblins in the stronghold before you "+
            "venture down here.\n";
            break;
         case 9..14: tmp = "%^ORANGE%^The caverns below are just right "+
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