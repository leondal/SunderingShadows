inherit "/std/weapon";

create() {
    ::create();
     set_id( ({ "dagger", "fogdagger", "fog dagger", "fog" }) );
     set_name("fogdagger");
     set_short("A fog dagger");
   set_long(
	"This is a shiney, well kept dagger. "
   );
   set_weight(1);
   set_size(1);
   set_wc(1,4);
   set_value(15);
   set_large_wc(1,3);
}
