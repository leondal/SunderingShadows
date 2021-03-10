//Coded by Bane//
#include <std.h>
inherit CROOM;

void create(){
    set_monsters(({"/d/laerad/mon/bugbear2"}),({2}));
    ::create();
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_name("Main street");      
    set_short("Main street");     
    set_long(     
	"%^BOLD%^Main street%^RESET%^
You are standing on one of the central roads of Systyquah.  The "+      
        "street leads off to the southeast and southwest "+       
        "here.  You can see a number of wood huts to either side of "+     
        "the road.  A few bonfires are lit in the gutters of the "+      
        "street, smoke pouring into the sky. To the north is a "+       
	"massive castle towering into the sky."       
    );                        
    set_property("indoors",0);         
    set_property("light",2);                                           
    set_smell("default","The breeze carries a rank, nauseating smell.");           
    set_listen("default","You hear the shouts of bugbears and troll war parties.");             
    set_exits( ([                                            
        "southeast":"/d/laerad/parnelli/systyquah/sys017",        
        "southwest":"/d/laerad/parnelli/systyquah/sys016",         
	//"north":"/d/laerad/parnelli/systyquah/cas001"         
    ]) );                                                      
    set_pre_exit_functions( ({"north"}),({"go_north"}) );       
}              
int go_north(){            
    if(present("bugbear")){                   
	write("%^MAGENTA%^Bugbear says%^RESET%^: Sorry the castle is off limits.");
	return 0;
    }         
}       
void reset(){       
    ::reset();                
/* changed to use CROOM  *Styx* 7/2002
    if(!present("bugbear")){             
	new("/d/laerad/mon/bugbear2")->move(TO);        
	new("/d/laerad/mon/bugbear2")->move(TO);
    }      
*/
}
