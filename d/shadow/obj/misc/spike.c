#include <std.h>

inherit OBJECT;

int query_attachable();
void set_driven(int drive);
int query_driven();

int driven;


void create() {
    ::create();
    set_id( ({"spike"}) );
    set_name("spike");
    set("short", "a spike");
    set_long( 
	"A steel spike. You can attach ropes to it, if it is driven into\n" 
	"the ground."
    );
    set_weight(20);
    set_value(1);
}

int query_attachable() { return 1;}
void set_driven(int drive){
	if(!drive) return 1;
	if(drive != 0){
		driven = 1;
		set_long("A steel spike, driven deep into the ground.\n"
			 "You could attach some rope to it."
		);
		set_weight(100000);
	} else {
		driven = 0;
		set_weight(20);
    		set_long( 
		"A steel spike. You can attach ropes to it, if it is driven into\n" 
		"the ground."
    		);

	}
}
int query_driven(){ return driven;}
