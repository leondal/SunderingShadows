#include <std.h>

inherit DAEMON;

int help();

int cmd_damall(string str){
   object * objs;
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

   //   if(!str) return notify_fail("Who do you want to do damage on?\n");
   // if(sscanf(str,"%s %d",who,amount) != 2)
   //   return help();
   objs = all_inventory(ETP);;
   //  if(!obj) return notify_fail(capitalize(str)+": not found.\n");
   //  if(!interactive(obj))
   //   return notify_fail("You can only use it on players who is online right now.\n");
   amount=atoi(str);
   if (!intp(amount))
     return help();
   set_property("magic",1);
   objs->do_damage("torso",amount);
   write("%^RED%^WARNING: Improper use of this command will be punished!");
   write("%^YELLOW%^You damaged "+identify(objs->query_cap_name())+" for "+amount+" HP.\n");
   return 1;
}

int help(){
   write(
@OBS
Syntax: damall <amount of hp>
Warning: Always have a good reason when you use the command.
         Any abuse will lead to punishment.
Note: Put negative values in amount, you can make it a healing command
Damages everything in your environment.
OBS
   );
   return 1;
}
