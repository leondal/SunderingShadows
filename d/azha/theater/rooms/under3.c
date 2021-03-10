#include <std.h>
#include "../theater.h"
inherit UNDER;
int BFLAG;
int LFLAG;
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
	"not been in use for decades.  %^BOLD%^%^CYAN%^Sky blue"+
	"%^RESET%^ %^ORANGE%^"+
	"curtains and %^MAGENTA%^Lavender%^ORANGE%^ "+
	"curtains block the northern and southern entrances from"+
	" view.\n");
	add_item(({"sky blue curtain","sky blue curtains","blue curtain""+
	","blue curtains"}),"%^BOLD%^%^CYAN%^These tightly woven sky blue "+
	"silk curtains cover the northern entrance.  Woven into the "+
	"silk fibers is a large %^WHITE%^silver%^CYAN%^ starburst design"+
	".  The colors of the curtain are faded in some section, from"+
	" time.  The two curtains meet in the middle, allowing for one to part"+
	" them as they enter and leave.",);
	add_item(({"lavender curtain","lavender curtains"}),"%^MAGENTA%^These"+
	" tightly woven lavender silk"+
	" curtains covers the southern entrance.  Woven into the silk fibers is "+
	"a large %^BOLD%^%^WHITE%^silver%^RESET%^%^MAGENTA%^ starburst design.  "+
	"The colors of the"+
	" curtain are faded in some sections, from time.  The two curtains meet"+
	" in the middle, allowing for one to push them aside as they enter "+
	"and leave.",);
	add_item(({"curtains","curtain"}), "%^ORANGE%^There are two sets of "+
	"curtains. Did you want to look at the %^BOLD%^%^CYAN%^sky blue%^RESET%^"+
	"%^ORANGE%^ ones"+
	" or the %^MAGENTA%^lavender%^ORANGE%^ ones?",);
	set_exits(([ "west" : ROOMDIR"under2", ]));
}
void init(){
::init();
    add_action("part","part");
	add_action("push","push");
    add_action("push","move");
}
int part(string str){
        if(str != "blue curtains" && str != "sky blue curtains")
      return notify_fail("Part which curtains?\n");

      tell_object(TP,"%^BOLD%^%^CYAN%^You part the sky blue curtains, "+
	"opening up a lavish dressing room.");
	tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" parts the sky blue"+
	" curtains, opening up a lavish dressing room.",TP);
	add_exit(ROOMDIR"droom3","north");
                BFLAG = 1;
                return 1;
}
int push(string str){
        if(str != "lavender curtains" &&
           str != "lavender curtain" &&
           str != "purple curtains")
      return notify_fail("Part which curtains?\n");

      tell_object(TP,"%^MAGENTA%^You push open the lavender curtains"+
	", opening up a lavish dressing room.");
      tell_room(ETP,"%^MAGENTA%^"+TPQCN+" pushes open the lavender"+
	" curtains, opening up a lavish dressing room.",TP);
  	add_exit(ROOMDIR"droom4","south");
                LFLAG = 1;
                return 1;

}
void reset() {
	::reset();
		BFLAG=0;
		LFLAG=0;
	return;
}
