#include <std.h>
      
inherit CROOM;
      
void create() {
    set_monsters(({"/d/tharis/monsters/patrol"}),({ random(5) }));
           ::create();
       set_light(2);
       set_indoors(1);
      set_short("Patrol Head quarters");
   set_long(
@OLI
	This is a Patrol headquarters. There are most often 
patrols here. However they are sometimes away. You know 
that patrols are well equiped. This could be where they keep 
  the stuff. The patrols at this station deal mainly with petty theft.
	There is an office to the west.
OLI
     );
  set_smell("default","");
 set_listen("default"," ");
     set_exits((["east":"/d/tharis/Tharis/market3",
"south":"/d/tharis/Tharis/wstreet1",
"west":"/d/tharis/Tharis/office2" ]));
set_pre_exit_functions(({"west"}),({"patrol_thing"}));
      set_items(([
"desk":"This desk is cluttered with papers. ",
        ] ));
}
	
int patrol_thing(){
 	if(present("patrol")) {
write("You can't go in there");
return 0;
}
else return 1;
}
