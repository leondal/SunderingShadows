#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("A large oak sign");
   set_short("A large oak sign");
   set_long("This large oak sign is placed on a tall post and "+
      "seems to provide information on those banned for Tabor.  "+
      "You should probably read it.");
   set_id(({"sign","wooden sign","banned sign"}));
   set_weight(10000);
   set("read",(:"sign_read":));
}

int sign_read(string str){
string main;
   if(id(str)){
      main = "%^YELLOW%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"+
		"%^BOLD%^%^BLUE%^The Following List of People are Banned from Tabor\n\n%^RESET%^"+
		"Etarena aka Aera - A human woman with sapphire eyes and long, ebony hair\n"+
		"Nalthic - A dirt encrusted male dwarf with a dark scar\n"+	
		"Eiryasha - An aging female human of slim athletic build with hands of"+
			"glistening ice\n\n"
		
		"%^BOLD%^%^WHITE%^Failure to honor the banishment that Tabor has given"+
		" these people for their lack of cooperation in following the simple laws"+
		" will result in a bounty placed on their heads.\n\n";
	               
tell_object(TP,""+main+"%^YELLOW%^~*~*~*~*~*~*~*~"+
         "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^");
      if(!TP->query_invis()){
         tell_room(ETP,""+TPQCN+" seems to be studying the sign.",TP);
      }
      return 1;   
   }
   return 0;
}
