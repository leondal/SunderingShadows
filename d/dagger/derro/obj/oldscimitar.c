// fixing the problem that it vapes if they are overloaded, updated to inherit from /d/common too *Styx*  8/20/06
//Streamlined the code to use one function, made the syntax easier for players, and added lore. ~Circe~ 2/17/13

#include <std.h>
#include "../derrodefs.h"

inherit "/d/common/obj/weapon/scimitar";

void create(){
   ::create();
   set_id(({"old scimitar","scimitar","sword"}));
   set_name("scimitar");
   set_short("old scimitar");
   set_long("This scimitar has seen better days.  It is old "
      "and beaten, lacking even a pommel.  The blade is nicked "
      "and scratched, and one side of the aged hilt has a "
      "prongred hole that looks as though something has been "
      "recently pried from it.  If you had the right gem, you "
      "could probably <insert> it again.");
   set_lore("Little is known about who - or what - once wielded "
      "this scimitar.  Similar blades have been found, and they "
      "are rumored to transform into quite impressive weapons "
      "indeed when the right sapphire is inserted into the hilt.  "
      "Should you find such a stone, you could <insert sapphire "
      "into scimitar>.");
   set_property("lore difficulty",15);
}

void init(){
  ::init();
   add_action("insert","insert");
}

int insert(string str){
   object gem,ob;
   string what,sword;
   if(!str) 
	return notify_fail("Insert what into what?");
   if(sscanf(str, "%s into %s",what,sword) != 2)
      return notify_fail("Try <insert sapphire into scimitar>.");
   gem = present(what,TP);
   if(objectp(gem)){
      if(gem->is_scimitar_gem()){
         if(!TO->id(sword)){
            tell_object(TP,"That is not a valid id for the scimitar. Try <insert sapphire into scimitar>.");
            return 1;
         }
         if((string)gem->query_name() == "star gem"){
            TO->move("/d/shadowgate/void");
            tell_object(TP,"You look at the hilt and the gem for a"
               " second, wondering how you're going to do it."
               "\n%^CYAN%^Suddenly, the star gem is pulled out of your hand, "
               "latches to the hilt, and the whole scimitar glows silver!%^RESET%^");
            tell_room(ETP,"%^CYAN%^"+TPQCN+"%^RESET%^'s blue gem lodges "
               "itself in the hilt of the scimitar, which begins to glow silver!%^RESET%^",TP);
            ob=new(OBJ"scimitar.c");
            ob->move(TP);
            gem->remove();
            remove();
            return 1;
         }else if((string)gem->query_name() == "black sapphire"){
            TO->move("/d/shadowgate/void");
            tell_object(TP,"%^BOLD%^%^BLACK%^Your black sapphire firmly secures "
               "itself into the pronged hole in the hilt of the scmitar, which "
               "darkens the surroundings!"
               "\n%^BOLD%^%^BLACK%^Suddenly, the black scimitar takes on a new "
               "and smoother look.%^RESET%^");
            tell_room(ETP,"%^BOLD%^%^BLACK%^"+TPQCN+"'s black sapphire firmly "
               "secures itself into the newer hole in the hilt of the scmitar, "
               "which darkens the surroundings!%^RESET%^",TP);
            ob=new(OBJ"blackscimitar.c");
            ob->move(TP);
            gem->remove();
            remove();
            return 1;
         }else{
            tell_object(TP,"You don't seem to have the right gem!");
            return 1;
         }
      tell_object(TP,"You don't seem to have the right gem!");
      return 1;
      }
   tell_object(TP,"You don't seem to have the right gem!");
   return 1;
   }
   tell_object(TP,"Try to <insert sapphire into scimitar>.");
   return 1;
}
