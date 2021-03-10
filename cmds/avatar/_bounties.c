#include <std.h>
#include <daemons.h>


inherit DAEMON;




private void swap(int i, int j, string *bounties){
  string tmp;

  tmp = bounties[i];
  bounties[i]=bounties[j];
  bounties[j]=tmp;
}




void sort(string *bounties){
  int i,j;

  for(j=0;j<sizeof(bounties);j++) {
    for(i=sizeof(bounties)-1;i>j;i--){
      if(bounties[i] < bounties[i-1]){

        swap(i-1,i,bounties);
      }
    }
  }
}



int cmd_bounties(){
     int i,j;
     string * pbounties;
     
     mapping mbounties;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

   pbounties = KILLING_D->query_personals();
   mbounties = KILLING_D->query_personal_bounties(); 
   write("\n");
   write("%^BOLD%^%^CYAN%^\tThe following rewards are offered by private citizens:\n");
   j = sizeof(pbounties);
   if(pbounties && j)
   sort(pbounties);
   for(i=0;i<j;i++)
   write("%^BOLD%^%^YELLOW%^\t   A reward of "+mbounties[pbounties[i]]["money"]+" is offered for "+capitalize(pbounties[i])+"!");             
     return 1;
}
