#include <std.h>
#define MAGIC_DIR "/d/shadow/obj/magic/"
inherit OBJECT;
string default_long,sword,no_sword,closed;
int sword_present, open, wait;

void open_case();
void close_case();

void create() {
    ::create();
    set_id( ({"glass case","glass","case"}) );
    set_name("glass case");
    set_short("A glass display case");
    set_weight(100000);
    default_long = 
	"This is a glass display case.\n"+
"It's on an oak stand and is about six feet long, and a foot wide and deep.";
    sword = 
	" Inside the case you can see a 'black sword'. The 'black sword' seems"+
	" to be hanging in mid-air, inside the case, not touching the"+
	" glass or the bottom.\n";
    no_sword = "  It is empty.\n";
    closed = "It is closed!\n";
    set_long(default_long+sword+closed);
    set_value(0);
    sword_present = 1;
    open = 0;
    wait = 0;
}
void reset(){
    ::reset();
	if(!sword_present) {
		wait++;
		if(wait > 10) {
			wait = 0;
			set_long(default_long+sword+closed);
			sword_present = 1;
		}
	}
}
void init(){
    ::init();
	add_action("get_sword","get");
	add_action("open_it","open");
	add_action("attack_it","attack");

}

int open_it(string str){
	if(str == "case"){
		write("You search for a way to open the case, but fail to find one.");
		return 1;
	}
	return 0;
}
int attack_it(string str){
	write("Your weapon is deflected from the glass. It does no damage.");
	return 1;
}
void open_case(){
	if(open) {
		return;
	}
	open = 1;
	closed = "It is open.";
	set_long(default_long+sword+closed);
	if(sword_present) write("The sword calls out to you.");
	return;
	
}
void close_case(){
	if(!open) {
		return 1;
	}
	open = 0;
	closed = "It is closed.\n";
	set_long(default_long+sword+closed);
	if(sword_present) write("The sword calls out to you.");
	return 1;
	
}
int get_sword(string str){
	if(!str) return 0;
	if(str != "black sword") return 0;
	if(!open) {
		write("The glass cover is in the way.");
		return 1;
	}
	write("You reach out and take the sword by it's handle."+
	"As your hand grasps the handle, you feel a strange power surge into your body."+
	"You get a gloomy feeling. Was it wise to take this sword.");
	new(MAGIC_DIR+"chaosblade")->move(TP);
	set_long(default_long + no_sword);
	sword_present = 0;
	return 1;


}
