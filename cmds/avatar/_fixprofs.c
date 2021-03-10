#include <std.h>
#include <daemons.h>
#include "/daemon/nwps_d.h"

inherit DAEMON;
int help(){
    write(
@CYTHERA
Usage:  fixprofs <player> <blades axe hammer club spear>
This will reset the profs a player has spent on outdated profs.
In case of small blades, it will take aways skills spent on small blades
and apply them to short blades, and in the case of specialized fighters
will set them to specialize in short blades.
In the case of the others, it will clear any skills spent on small, medium,
and large types, and set their prof to the current one, including specialization
if the case maybe.  It will also change the parent weapon.
NOTE:  You need to get the prof clearer from the avatar lounge <press
button 3>
first and use it before using this command.
CYTHERA
    );
    return 1;
} 

int cmd_fixprofs(string str){
  int i;
  string whom, what, myparent;
  object player;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or
apprentice.");
       return 1;
   }
    
  if (!str) {
   help();
   return 1;
  }
  if(sscanf(str, "%s %s",whom,what) == 2) {
        player = find_player(whom); 
        myparent = player->query("youth weapon");
    if (!objectp(player)) {
        return notify_fail("Player not found.\n");
    }
                switch(what){
case "blades":
        if(player->is_class("fighter")  && (string)player->query("specialized") ==
("small blades")){
                player->set_profs("small blades",0);
                player->set("specialized",0);
                player->set_skill("small blades",50);
                player->set_skill("short blades",50);
                player->set("specialized","short blades");
                        write(player->QCN+"'s profs should be reset, please check to make
sure.");
    }else{
                player->set_profs("small blades",0);
                player->set_skill("small blades",50);
		    player->set_skill("short blades",50);
                player->set("max short blades",100);
        }
        write(""+player->QCN+"'s profs should be reset.  Please check to make
sure.");
        break;
case "spear":
        if(player->is_class("fighter")  && (string)player->query("specialized") ==
("medium spear") || ("small spear") || ("large spear")){
                player->delete_skill("medium spear");
                player->delete_skill("large spear");
                player->delete_skill("small spear");
                player->set("specialized",0);
                player->set_skill("spear",100);
                player->set_profs("spear",2);
                player->set("specialized","spear");
                if((myparent == "small spear") || (myparent == "medium spear") ||
(myparent == "large spear")){
                        player->set("youth weapon","spear");
                        player->set_skill("spear",120);
                        player->set("max spear",120);
                }
        }else{
                player->delete_skill("medium spear");
                player->delete_skill("large spear");
                player->delete_skill("small spear");
                player->set_skill("spear",50);
                player->set("max spear",100);
                if((myparent == "small spear") || (myparent == "medium spear") ||
(myparent == "large spear")){   
                        player->set("youth weapon","spear");
                        player->set("max spear",120);
                }
        }
case "axe":
        if(player->is_class("fighter")  && (string)player->query("specialized") ==
("medium axe") || ("small axe") || ("large axe")){
                player->delete_skill("medium axe");
                player->delete_skill("large axe");
                player->delete_skill("small axe");
                player->set("specialized",0);
                player->set_skill("axe",100);
                player->set_profs("axe",2);
                player->set("specialized","axe");
                if((myparent == "small axe") || (myparent == "medium axe") ||
(myparent == "large axe")){
                        player->set("youth weapon","axe");
                        player->set_skill("axe",120);
                        player->set("max axe",120);
                }
        }else{
                player->delete_skill("medium axe");
                player->delete_skill("large axe");
                player->delete_skill("small axe");
                player->set_skill("axe",50);
                player->set("max axe",100);
                if((myparent == "small axe") || (myparent == "medium axe") ||
(myparent == "large axe")){   
                        player->set("youth weapon","axe");
                        player->set("max axe",120);
                }
        }
case "hammer":
        if(player->is_class("fighter")  && (string)player->query("specialized") ==
("medium hammer") || ("small hammer") || ("large hammer")){
                player->delete_skill("medium hammer");
                player->delete_skill("large hammer");
                player->delete_skill("small hammer");
                player->set("specialized",0);
                player->set_skill("hammer",100);
                player->set_profs("hammer",2);
                player->set("specialized","hammer");
                if((myparent == "small hammer") || (myparent == "medium hammer") ||
(myparent == "large hammer")){
                        player->set("youth weapon","hammer");
                        player->set_skill("hammer",120);
                        player->set("max hammer",120);
                }
        }else{
                player->delete_skill("medium hammer");
                player->delete_skill("large hammer");
                player->delete_skill("small hammer");
                player->set_skill("hammer",50);
                player->set("max hammer",100);
                if((myparent == "small hammer") || (myparent == "medium hammer") ||
(myparent == "large hammer")){   
                        player->set("youth weapon","hammer");
                        player->set("max hammer",120);
                }
        }
case "club":
        if(player->is_class("fighter")  && (string)player->query("specialized") ==
("medium clublike") || ("small clublike") || ("large clublike")){
                player->delete_skill("medium clublike");
                player->delete_skill("large clublike");
                player->delete_skill("small clublike");
                player->set("specialized",0);
                player->set_skill("club",100);
                player->set_profs("club",2);
                player->set("specialized","club");
                if((myparent == "small clublike") || (myparent == "medium clublike") ||
(myparent == "large clublike")){
                        player->set("youth weapon","club");
                        player->set_skill("club",120);
                        player->set("max club",120);
                }
        }else{
                player->delete_skill("medium clublike");
                player->delete_skill("large clublike");
                player->delete_skill("small clublike");
                player->set_skill("club",50);
                player->set("max club",100);
                if((myparent == "small clublike") || (myparent == "medium clublike") ||
(myparent == "large clublike")){   
                        player->set("youth weapon","club");
                        player->set("max club",120);
                }
        }

                write(""+player->QCN+"'s profs should be reset.  Please check to make
sure.");
        break;
                                return 1;
default:
        help();
        return 1;
        break;
                }
        }
}
