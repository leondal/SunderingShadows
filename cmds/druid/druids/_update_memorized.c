int cmd_update_memorized(string str);
int help(string str);

int cmd_update_memorized(string str) {
object mis, who;
string *spells;
int i,inc;
if (!str) {
  spells = ({ });
  write("You have to give a spell name !!\n");
  return 1; 
        }
  who= this_player();
  spells += (string*)who->query("updated_memorized");
 if ( member_array(str, spells)) {
     write("You can't updated your memory for this spell !!");
     return 1; }
        who->set_memorized(str,9999);
	who->set("updated_memorized",str);
	tell_object(who, "Updated spell : "+str);
   return 1;
	}


int help(string str) {
if (!str)
    { return 0; }
else   {
    write(
@PATOR
       -=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-   

                         DRUID  HELP  

         Syntax : update_memorized [spell_name]

         You can use it to make it possible to cast the spell
         spell_name.
           
         This is a temporary command for Druids. The mistletoe
	 will be altered so this won't be necesarry anymore !

       -=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-=0=-  
PATOR
);
   return 1;
}
return 1;
}
