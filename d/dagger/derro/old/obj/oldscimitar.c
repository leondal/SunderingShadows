// fixing the problem that it vapes if they are overloaded, updated to inherit from /d/common too *Styx*  8/20/06

#include <std.h>
#include "../derrodefs.h"

inherit "/d/common/obj/weapon/scimitar";

void create(){
  ::create();
  set_id(({"old scimitar","scimitar","sword"}));
  set_name("scimitar");
  set_short("old scimitar");
   set_long("It's an old beaten up scimitar without a pommel. It looks like it needs to have something replaced on one side and there is, compared to the rest of the sword, a newer hole on the opposite side of the hilt. Something could possible be inserted there.");
/* covered by the inherit now
*  set_weight(5);
*  set_size(2);
*  set_wc(1,8);
*  set_large_wc(1,8);
*  set_type("slashing");
*  set_prof_type("medium blades");
****/
}

void init(){
  ::init();
   add_action("insert","insert");
  add_action("replace","replace");
}

int replace(string str){
   object ob;
   if(!str) 
	return notify_fail("Replace what on what?");
   if((str=="star sapphire on old scimitar")) {
     if(!present("star gem",TP))
	return notify_fail("You don't have the right gem.");
    ob=(present("star gem",TP));
    ob->remove();
// moving the old scimitar before giving them the new one to avoid encumbrance issues, it still needs to not dest until after the rest of this is complete.
    TO->move("/d/shadowgate/void");
    ob=new(OBJ"scimitar.c");
    ob->move(TP);
    write("You look at the pommel and the gem for a second wondering how you're going to do it."
  "\n%^CYAN%^Suddenly the star gem is pulled out of your hand, latches to the pommel, and the whole scimitar glows silver!");
    say("%^CYAN%^"+TPQCN+"%^RESET%^'s blue gem lodges itself in the hilt of the scimitar which begins to glow silver!");
    remove();
    return 1;
  }
  write("Use the full names of both objects to get it right <replace what on what>.");
  return 1;
}

int insert(string str){
   object ob;
   if(!str)
	return notify_fail("Insert what into what?");
   if((str="black sapphire into old scimitar")) {
     if(!present("black sapphire",TP))
	return notify_fail("The sword does not respond to this gem.");
     ob=(present("black sapphire",TP));
     ob->remove();
// moving the old scimitar before giving them the new one to avoid encumbrance issues, it still needs to not dest until after the rest of this is complete.
     TO->move("/d/shadowgate/void");
     ob=new(OBJ"blackscimitar.c");
     ob->move(TP);
     say("%^BOLD%^%^BLACK%^"+TPQCN+"'s black sapphire firmly secures itself into the newer hole in the hilt of the scmitar, which darkens the surroundings!");
     write("%^BOLD%^%^BLACK%^Your black sapphire firmly secures itself into the newer hole in the hilt of the scmitar, which darkens the surroundings!"
   "\n%^BOLD%^%^BLACK%^Suddenly the black scimitar takes on a new and smoother look.");
     remove();
     return 1;
   }
   write("Use the full names of both objects, <insert what into what>.");
   return 1;
}
