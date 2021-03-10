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
      "%^RESET%^Just ahead is  "+
      "%^MAGENTA%^Piaf Huffelmuffin's Farm%^RESET%^, a strange farm"+
	" owned by a gnomish inventor.  Piaf's cottage lays just off "+
	"the main path to the farm, stop in and pay him a visit if you "+
	"wish.  Piaf's not exactly known for his skills as a farmer, so"+
	" be careful when exploring the lands.  You never know what you "+
	"might find.\n\n";
      switch((int)TP->query_lowest_level()){
         case 0..9: tmp = "%^BOLD%^%^RED%^Beware the pathways ahead, young "+
            "one!  This challenge is well above those you have found on the stream.\n";
            break;
         case 10..14: tmp = "%^ORANGE%^The farmland ahead are meant for those of "+
            "your stature.  Use caution and proceed if you will - "+
            "though a few friends might be most helpful!\n";
            break;
         default: tmp = "%^YELLOW%^The farm ahead are likely to offer little "+
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