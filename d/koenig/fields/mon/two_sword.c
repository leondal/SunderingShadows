inherit "/std/weapon";

create() {
    	::create();
   	set_id(
   		({ "sword", "two-handed sword", "a two-handed sword", "two-handed" })
   	);
   	set_name("two-handed sword");
   	set_short("a two-handed sword");
   	set_long(
@KAYLA
This is a huge 40 inch steel blade mounted on an elaborately decorated
handle, big enough for two large hands.
KAYLA
	);
   	set_weight(15);
   	set_size(3);
   	set("value", 50);
   	set_wc(1,10);
   	set_large_wc(3,6);
   	set_type("blade");
}
