#include <std.h>
#include "../theater.h"
inherit UNDER;
int RFLAG;
int YFLAG;
	void create(){ 
	::create();
	set_long("%^ORANGE%^Smooth sandstone blocks form the "+
	"walls of the understage area of the theater.  Carved"+
	" from the foundation of the theater, the understage "+
	"area is where the real work of the theater is done. "+
	" The wide spacious corridors allow for plenty of room"+
	" to move large objects to the stage.  Wooden support "+
	"beams transverse the ceiling of this area, granting "+
	"support to the theater above.  Large amounts of "+
	"%^RESET%^dust%^ORANGE%^ covers the walls and beams, "+
	"giving the illusion that this part of the theater has "+
	"not been in use for decades.  %^RED%^Dark red %^ORANGE%^"+
	"curtains and %^BOLD%^sunny yellow%^RESET%^%^ORANGE%^ "+
	"curtains block the northern and southern entrances from"+
	" view.\n");
	add_item(({"red curtain","red curtains","dark red curtain""+
	","dark red curtains"}),"%^RED%^These tightly woven dark red "+
	"wool curtains covers the northern entrance.  Woven into the "+
	"wool fibers is a large %^YELLOW%^golden sunburst%^RESET%^%^RED%^"+
	" design.  The colors of the curtain are faded in some section, from"+
	" time.  The two curtains meet in the middle, allowing for one to part"+
	" them as they enter and leave.",);
	add_item(({"yellow curtain","yellow curtains","sunny yellow curtains""+
	","sunny yellow curtains"}),"%^YELLOW%^These tightly woven sunny yellow"+
	" curtains covers the southern entrance.  Woven into the wool fibers is "+
	"a large %^RED%^fiery red%^YELLOW%^ sunburst design.  The colors of the"+
	" curtain are faded in some sections, from time.  The two curtains meet"+
	" in the middle, allowing for one to push them aside as they enter "+
	"and leave.",);
	add_item(({"curtains","curtain"}), "%^ORANGE%^There are two sets of "+
	"curtains. Did you want to look at the %^RED%^dark red%^ORANGE%^ ones"+
	" or the %^YELLOW%^sunny yellow%^RESET%^%^ORANGE%^ ones?",);
	set_exits(([ "west" : ROOMDIR"under1",
			 "east" : ROOMDIR"under3",
			]));
     	}
void init(){
::init();
    	add_action("part","part");
	add_action("push","push");
}
int part(string str){
        if(str != "red curtains" && str != "dark red curtains") 
      return notify_fail("Part which curtains?\n");

      tell_object(TP,"%^RED%^You part the dark red curtains, "+
	"opening up a dressing room.");
	tell_room(ETP,"%^RED%^"+TPQCN+" parts the dark red "+
	"curtains, opening up a dressing room.",TP);
		add_exit(ROOMDIR"droom1","north");
                RFLAG = 1;
                return 1;
}
int push(string str){
        if(str != "yellow curtains" && str != "sunny yellow curtains") 
      return notify_fail("Part which curtains?\n");

      tell_object(TP,"%^YELLOW%^You push open the sunny yellow curtains"+
	", opening up a dressing room.");
	tell_room(ETP,"%^YELLOW%^"+TPQCN+" pushes open the sunny "+
	"yellow curtains, opening up a dressing room.",TP);
		add_exit(ROOMDIR"droom2","south");
                YFLAG = 1;
                return 1;
}
void reset() { 
	::reset(); 
		RFLAG=0;
		YFLAG=0; 
	return; 
}
