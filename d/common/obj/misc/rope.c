#include <std.h>

inherit OBJECT;
int query_attached();
int query_bind_strength();
int is_binder();
int set_bind_strength(mixed var);
int attached;

void create() {
    ::create();
    set_id( ({"rope", "silk rope"}) );
    set_name("rope");
    set_short("silk rope");
/*
    set_long("A 50 foot length of rope, made from the finest hemp.\n"
	"You can attach it to things, and climb up or down it."   );
   set_weight(10);
*/
    set_long("This is a length of very strong and durable silk rope, about the thickness of an arrow shaft.  It looks like it would <bind> a person quite well.");
    set_weight(1);
    set_bind_strength(3);
    set_value(5);
    attached = 0;
}

/* haven't seen spikes or any other code to support this so making this rope lighter and less bulky and more appropriate for binding people since that's how it's being used now.
*Styx*  2/12/04

void init() {
    ::init();
	add_action("attach_rope","attach");
	add_action("get_rope","get");
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
*/

int query_bind_strength() {
   return (query("bind_strength"));
}

mixed set_bind_strength(mixed var) { 
  if (intp(var))
    return set("bind_strength",var);
  else
    return delete("bind_strength");
}

int is_binder() {
  if (query_bind_strength())
    return 1;
  else
    return 0;
}
