#include "../../newbie.h"
inherit ROOM;

void create(){
	::create();
	set_travel(PAVED_ROAD);
	set_terrain(CITY);
	set_light(2);
	set_indoors(1);
	set_name("A Song and a Smile");
	set_short("%^BOLD%^A Song and a Smile%^RESET%^");
	set_long("%^BOLD%^A Song and a Smile%^RESET%^\n"+
"The cheery nature of this store is apparent even before one walks inside.  The %^YELLOW%^walls %^RESET%^are painted a "
"sunny shade of yellow, with iris-blue lining the %^BOLD%^%^CYAN%^windowpanes%^RESET%^ and %^BOLD%^%^CYAN%^shelves"
"%^RESET%^.  Upon them are set a variety of %^BOLD%^%^WHITE%^musical instruments%^RESET%^, ranging from simple wooden "
"clappers through to pipes and finely-strung lutes.  Colorful %^GREEN%^ribbons %^RESET%^are hung from the open doorway "
"itself, the bells attached to the ends chiming gently as anyone walks in.\n\n"
"%^YELLOW%^<help shop> %^RESET%^will give you help on how to use this shop.\n");
	set_smell("default","The smell of polished wood greets your senses.");
	set_listen("default","An occasional draft of wind sets the doorbells to chiming.");
	set_items( ([
        ({"walls","panes","windowpanes","shelves"}) : "%^CYAN%^The room seems brighter just from the sunny yellow walls, "
"and the shelves and panels that have been painted iris-blue.%^RESET%^",
        ({"instruments","musical instruments"}) : "%^BOLD%^%^WHITE%^All kinds of instruments are set upon the shelves, "
"ranging from simple wooden clapping blocks through to carefully strung lutes and harps.%^RESET%^",
        ({"ribbons","bells"}) : "%^GREEN%^Colorful ribbons have been hung from the doorway, each tied to a small golden "
"bell.  The entry of any customer sets them to a gentle chiming.%^RESET%^"
    ]) );
    set_exits(([
        "east" : MAINTOWN"nstreet3",
        "south" : MAINTOWN"bardcomps",
    ]) );
}

void reset(){
   ::reset();
   if(!present("jake")) find_object_or_load(MON"jake")->move(TO);
}