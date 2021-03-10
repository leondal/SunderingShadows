#include <std.h>
inherit ROOM;

void init(){
	::init();
	add_action("read_func", "read");
}
void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^The pathway continues to form an ever decreasing circle.  However, the forest appears to be getting darker and the pathway somewhat harder to see.  There is a small sign hanging lopsided upon a branch, perhaps you should <read> it before you continue.%^RESET%^");
set ("night long", "%^CYAN%^The pathway continues to form an ever decreasing circle.  However, the forest appears to be getting darker and the pathway somewhat harder to see.  The globes appear as dim glows ahead of you.  There is a sign handing lopsided upon a branch, perhaps you should <read> it before you decide to travel onward.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell of the forest returns, damp earth and pine scents.");

set_listen ("default", "You hear the cry of a desperate child come from ahead");
set_exits (([
"east" : "/d/dagger/Elvanta/forest/room70",
"northwest" : "/d/dagger/Elvanta/forest/room68"
]));
set_items
(([
"globes" : "These globes are welcome in this forest and light your way.  They are approximately two feet in diameter and give off a warm blue light.  They are hung from intricately braided silver chains.",
"forest" : "This forest feels comfortable, you are not afraid as you walk through the circle of trees.  However, it might not be a bad idea to still be on your guard.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"pathway" : "The pathway continues in a southeast direction, but is not as clear as it once was, as mist starts to rise from out of nowhere."
]));
}
int read_func(string str){
	write("%^RED%^You are entering the dark area of Elvanta; a leftover from the war between the darkness and the light.  No one individual has ever been able to truly banish evil, and herein lies in wait, some of its denizens.");
	return 1;
}
