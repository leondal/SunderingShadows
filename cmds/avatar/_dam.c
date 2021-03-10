#include <std.h>

inherit DAEMON;

int help();

int cmd_dam(string str){
   object obj;
   int amount;
   string who;

   string posxxx;
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

   if(!str) return notify_fail("Who do you want to do damage on?\n");
   if(sscanf(str,"%s %d",who,amount) != 2)
      return help();
   obj = find_living(who);
   if(!obj) return notify_fail(capitalize(str)+": not found.\n");
   if(!interactive(obj))
      return notify_fail("You can only use it on players who is online right now.\n");
   set_property("magic",1);
   obj->do_damage("torso",amount);
   write("%^YELLOW%^You damaged "+obj->query_cap_name()+" for "+amount+" HP.\n");
   return 1;
}

int help(){
   write(
@OBS
Syntax: dam <user> <amount of hp>
Warning: Always have a good reason when you use the command.
         Any abuse will lead to punishment.
Note: Put negative values in amount, you can make it a healing command.
OBS
   );
   return 1;
}
