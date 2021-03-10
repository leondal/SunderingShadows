#include <std.h>
inherit OBJECT;
int bucket;
void create() {
    ::create();
    	set_id( ({"well"}) );
    	set_name("well");
    	set("short", "A small, broken-down wooden well");
    	set_weight(1000000);
    	set_long(
@MELNMARN
You are looking at a small wooden well. It is isn't in the 
greatest shape, yet it looks quite old. 
There is a small hand crank on the side of the
well. You also notice there is a rope hanging
down from the top of the well, with a bucket 
attached to it. You might be able to raise and
lower the bucket.
MELNMARN
);
    	set_value(0);
	bucket = 0;
}

void init(){
    ::init();
	add_action("lower_it","lower");
	add_action("raise_it","raise");
	add_action("drink_it","drink");
}

int lower_it(string str){
	if(!str) return notify_fail("Lower what?\n");
	if(str != "bucket") return notify_fail("You can't lower that!\n");
	if(bucket) 
		if(bucket == 1) return notify_fail("The bucket is already lowered!\n");
	tell_object(TP,
@LOWER
You reach out, and take the crank handle in your hand. 
Slowly you turn the handle, and begin to lower the bucket 
into the well. The rope seems to last forever, as the 
bucket goes down further and further. Finally, you see
the end of the rope getting near and hear a distant 
splash.
LOWER
	);
	tell_room(environment(TP), TPQCN+" lowers the bucket into the well.",TP);
	bucket = 1;
	return 1;
}
int raise_it(string str){
	if(!str) return notify_fail("Raise what?\n");
	if(str != "bucket") return notify_fail("You can't raise that!\n");
	if((bucket == 2) || (bucket == 0)) return notify_fail("The bucket is already up here!\n");
	tell_object(TP,
@RAISE
You reach out, and take the crank handle in your hand. 
Slowly you turn the handle, and begin to raise the bucket 
out of the well. The rope seems to last forever, as the 
bucket slowly rises. Finally, you see the bucket coming 
up out of the darkness below.
RAISE
	);
	tell_room(environment(TP), TPQCN+" raises the bucket out of the well.",TP);
	bucket = 2;
	return 1;
}
int drink_it(string str){
	if(!str) return notify_fail("Drink what?\n");
	if(str != "water") return notify_fail("You can't drink that!\n");
	if(bucket == 1) return notify_fail("Raise it first!\n");
	if(!bucket) return notify_fail("It is empty!\n");
	
    if(!TP->add_quenched(20))
        return notify_fail("Your stomach is sloshing already!\n");
	tell_object(TP,
@RAISE
You reach out and take the bucket in hand. So 
happy to see water, you spill most of the bucket 
with one swig. Your clothing is now soaking wet.
RAISE
	);
	tell_room(environment(TP), TPQCN+" drinks some water and spills nost of it all over "+TP->query_objective()+"self.",TP);
	bucket = 0;
//	TP->add_quenched(1);
//fixed this in response to bug reports that drinking didn't help your thirst.
//Circe 12/23/04
	return 1;
}

