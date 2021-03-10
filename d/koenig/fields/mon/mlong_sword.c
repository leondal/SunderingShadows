inherit "/std/weapon";

create() {
    	::create();
   	set_id(({ "sword", "long sword", "a long sword", "long" }));
   	set_name("long sword");
   	set_short("A long sword");
   	set_long(
@KAYLA
This is a beautiful shining long sword, glowing a dull blue hue.  You
feel the power in the blade just being near it.
KAYLA
	);
   	set_weight(7);
   	set_size(2);
   	set("value", 250);
   	set_wc(1,8);
   	set_large_wc(1,12);
   	set_type("slashing");
   	set_property("enchantment",1);
}
