inherit "/std/weapon";

create() {
    	::create();
   	set_id(({ "sword", "short sword", "a short sword", "short" }));
   	set_name("short sword");
   	set_short("A short sword");
   	set_long(
@KAYLA
This sword once belonged to a dirty kobold, and it shows it.  The blade
is quite misused and dull.
KAYLA
	);
   	set_weight(3);
   	set_size(1);
   	set("value", 10);
   	set_wc(1,5);
   	set_large_wc(1,7);
   	set_type("blade");
}
