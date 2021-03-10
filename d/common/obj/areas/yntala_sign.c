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
         "%^RESET%^Just ahead lie the woods of "+
         "%^MAGENTA%^Yntala%^RESET%^, a forest beset by "+
         "dread beasts known as %^GREEN%^Yuan-Ti%^RESET%^.  Dire "+
	"wolves and Girallions stalk the western parts of the forest."+
	" While the snake-like Yuan-ti tend to keep to the eastern portions."+
	"  It is rumored that a camp of %^ORANGE%^centaurs%^RESET%^ is "+
	"somewhere within the forest, keeping watch over a sacred %^CYAN%^pool%^RESET%^."+
	" Beware of the %^GREEN%^leprachauns %^RESET%^, for they might think you"+
	" are after their fabled pots of gold.\n\n"+
         "Mystery and danger are to be found in the"+
	" %^MAGENTA%^Yntala Forest%^RESET%^.\n\n";
      switch((int)TP->query_lowest_level()){
         case 0..10: tmp = "%^BOLD%^%^RED%^Beware the forest ahead, young "+
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