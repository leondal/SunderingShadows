//ACTIVELY USED
//This function be performed with existing efuns
//find_object(), find_player()

#include <std.h>
#include <daemons.h>
inherit DAEMON;


object find_player_target(object to){
       	object *inven,*living_items, *players;
       	int i,j,who;
       	string file;

       	inven = ({});
       	living_items = ({});
	players = ({});

     if(objectp(environment(to)))
        inven = all_inventory(environment(to));
        if(!inven) return to;
        i = sizeof(inven);

        while(i--)
          if(living(inven[i]) == 1)
             living_items+= ({ inven[i]});

        if(living_items == ({})) return to;
        j = sizeof(living_items);
        while(j--) {
	   if(FILTERS_D->is_non_immortal_player(living_items[j]))
		players += ({living_items[j]});
        }
/* changing to above to check for a valid object and ignore invis. and invis. immortals 
   it also does an objectp check which was apparently needed
   *Styx* 2/20/05   last change was 7/98
            file = file_name(living_items[j]);
            	if(file[0..8] == "/std/user") {
			players += ({living_items[j]});
		}
        }
*/
         if(players == ({})) return to;

        who = random(sizeof(players));
        return players[who];
}
