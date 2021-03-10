#include <std.h>
#include "/d/islands/tonerra/areadefs.h"


inherit DAEMON;


object *make_party(string path);

void clean_up() { return 0;}







object *make_party(string path){
        object *party, temp,leader;
        int i,j;

        party = ({});
        
              
		leader = new(MON+"native");
        party += ({leader});
        if(random(2)){
        	temp = new(MON+"native");
        	party += ({temp});
        }
        if(!random(5)){
        	temp = new(MON+"nativeT");
        	party += ({temp});
        }
        if(!random(6)){
        	temp = new(MON+"nativeS");
        	party += ({temp});
        	leader = temp;
        }

		if(!random(4)){
        	temp = new(MON+"nativeW");
        	party += ({temp});
        }
        for(i=0;i<sizeof(party);i++){
                if(objectp(party[i]))
                   	if(party[i] != leader){
                       	leader->add_follower(party[i])
;
                  	}
      	}


        leader->set_speed(30);

        for(i=0;i<sizeof(party);i++){
                party[i]->move(path);
        }
        
        return party;
}

