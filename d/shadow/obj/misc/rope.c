#include <std.h>

inherit OBJECT;
int query_attached();
int attached;

void create() {
    ::create();
    set_id( ({"rope"}) );
    set_name("rope");
    set("short", "Some rope");
    set_long( 
	"A 50 foot length of rope, made from the finest hemp.\n"
	"You can attach it to things, and climb up or down it."
    );
    set_weight(20);
    set_value(1);
    attached = 0;
}

void init() {
    ::init();
	add_action("attach_rope","attach");
//	add_action("get_rope","get");
}

int attach_rope(string str){
    string rope,spike;
    object obj;
	if(!str) return notify_fail("Attach what to what?\n");
	if(sscanf(str,"%s to %s",rope,spike) != 2)
	    return notify_fail("Attach what to what?\n");
	if(rope != "rope") return notify_fail("Attach what?\n");
	if(!(obj = present(spike,environment(TP)))) 
	    return notify_fail("There is no "+spike+" here!\n");
	if((int)obj->query_attachable() != 1) 
	    return notify_fail("You can't attach the "+rope+" to that "+spike+"!\n");
	if(!(int)obj->query_driven()) return notify_fail("The "+spike+" is not secured in the ground!\n");
	move(environment(TP));
	attached = 1;
	environment(TO)->set_rope(1);
	tell_room(environment(TO),TPQCN+" attaches a length of rope to the "+spike+".",TP);
	write("You reach down and attach the rope to the "+spike+".");
    	return 1;
	
}
int query_attached() { return attached; }

int get(){
	attached = 0;
	environment(TO)->set_rope(0);
	return 1;
}
