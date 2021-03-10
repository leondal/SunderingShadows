#include <std.h>

inherit DAEMON;

int cmd_parties(string str){

   string posxxx;
   mapping temp;
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }
   temp = "/adm/daemon/party_d.c"->query_parties_full();
   temp = map_delete(temp,"token_monster_party");
   if(!sizeof(keys(temp))) 
   {
       tell_object(TP,"No parties currently formed");
   }
    write(identify(temp));
    return 1;
}

int help(){
write(
@OLI
    parties
       will return a list of all the parties and thier members.
OLI
  );
   return 1;
}
