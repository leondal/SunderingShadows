// /bin/skills/_limbs.c
// From the Nightmare Mudlib
// A cleric, monk, kataan spell to determine the body damage of others.
// By Gregon@Nightmare
 
 
#include <std.h>
 
inherit DAEMON;
 
 
int cmd_limbs(string str){
   string name, *limbs;
   object ob, tp;
   int x, i, *dam, maxdam;
 
   if(!str){
     notify_fail("Correct syntax: limbs [whom]\n");
     return 0;
   }
   
   tp=this_player();
 
   if((string)tp->query_class()!="kataan" && (string)tp->query_class()!="monk"
      && (string)tp->query_class()!="cleric"){
        notify_fail("Only people of high faith may perform this action.\n");
        return 0;
   }
 
   x=(int)this_player()->query_skill("faith");
   if(x<20){
     notify_fail("You are not yet faithful enough to do that.\n");
     return 0;}
   
   if((int)tp->query_mp()<20){
     notify_fail("You do not have the magic strength to do that right now.\n");
     return 0;
   }
 
   ob=find_living(str);
   if(!ob || !present(ob,environment(this_player()))){
     notify_fail(capitalize(str)+" is not here.\n");
     return 0;
   }
   
   if(ob->query_ghost()){
     notify_fail("That player has no limbs at all!\n");
     return 0;
   }
 
   tp->add_mp(-20);
   if((string)tp->query_class()=="kataan")
     say(tp->query_cap_name()+" begins to pray to the demons of the "
         "underworld for guidance.");
   else say(tp->query_cap_name()+" utters a request for divine guidance.");
 
   if(x-random(51)<0){
     write("Your prayers for guidance are not heard.");
     return 1;
   }
   tp->add_skill_points("faith",10);
   dam=allocate(i=sizeof(limbs=(string *)ob->query_limbs()));
   while(i--){
     dam[i]=to_int(percent((int)ob->query_dam(limbs[i]),
               (int)ob->query_max_dam(limbs[i])));
     if(dam[i]>dam[maxdam])
        maxdam=i;
     }
   name=(string)ob->query_cap_name();
   if(!dam[maxdam]){
      write(name+" has minimal body damage.");
      return 1;
   }
 
   if(x<40){
     if(x-random(51)<0)
     maxdam=random(i);
     write("You get the sense that "+name+"'s "+limbs[maxdam]+" is damaged.");
      return 1;
   }
 
   if(x<65){
      write("You get the sense that "+name+"'s "+limbs[maxdam]+" is damaged.");
      return 1;
   }
 
   if(x<80){
     if(dam[maxdam]<20){
       write("You get the sense that "+name+"'s "+limbs[maxdam]+" is slightly "
             "damaged.");
       return 1;
     }
     if(dam[maxdam]<40){
       write("You get the sense that "+name+"'s "+limbs[maxdam]+" is "
             "somewhat damaged.");
       return 1;
     }  
     if(dam[maxdam]<60){
       write("You get the sense that "+name+"'s "+limbs[maxdam]+" is heavily "
             "damaged.");
       return 1;
     }
     if(dam[maxdam]<80){
       write("You get the sense that "+name+"'s "+limbs[maxdam]+" is severely "
             "damaged.");
        return 1;
     }
     write("You get the sense that "+name+"'s "+limbs[maxdam]+" is about to "
           "fall off!");
     return 1;
   }
 
   write("You get the sense that "+name+"'s "+limbs[maxdam]+" is at "+
         dam[maxdam]+" percent of its potential.");
}
 
 
 
void help(){
    write("syntax: limbs [whom]\nThis allows the faithful to offer a prayer "
          "for guidance in determining the location of injuries on another.");
}
