#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_long(
	"You have walked upon a fantastic Oasis. Palm trees litter the "+
	"area around a glorious pond of fresh clean water. A straw bar "+
	"is set up between a few of the palm trees. A menu is tacked "+
	"up onto one of the trees. You can <read> it to see what is "+
	"being sold."
    );
    set_exits( ([
	"west":"/d/laerad/wasteland/waste57",
	"east":"/d/laerad/wasteland/waste81",
	"north":"/d/laerad/wasteland/waste68",
	"south":"/d/laerad/wasteland/waste70"
    ]) );
}
void reset(){
    ::reset();
    if(!present("jabbar"))new("/d/laerad/mon/jabbar")->move(this_object());
}
void init(){
    ::init();
    add_action("read", "read");
}
int read(){
    object ob;
    int i;
    ob = present("jabbar");
    if(!ob){
	write("Someone has torn down the menu.");
	return 1;
    }
    write("The following drinks are served at this Oasis");
    write("-------------------------------------------------------------------------");
    write("Water\t\t\t\t\t"+ (int)ob->get_price("water")+" gold");
    write("Desert Twister\t\t\t\t"+ (int)ob->get_price("twister")+" gold");
    write("Sandstorm\t\t\t\t"+ (int)ob->get_price("sandstorm")+" gold");
    write("Ale\t\t\t\t\t"+ (int)ob->get_price("ale")+" gold");
    write("---------------------------------------------------------------------");
    write("<buy drink_name> gets you the drink.");
    return 1;
}
