inherit "/std/vendor";


void create() {
   ::create();
set_name("S'sverak");
set_id(({"S'sverak", "s'sverak", "drow", "monk", "drow monk"}));
set_short("%^RED%^S'sverak, the monk");
set_long("%^RED%^S'sverak is a drow elf.  Unlike those of his race, his red eyes see the light instead of wallowing in darkness.  All who seek his aid for a good and true cause have a strong ally in S'sverak.  However, those will evil intent, will find S'sverak retains all his drow capabilites and characteristics");
   set("aggressive", 0);
   set_level(19);
   set_gender("male");
   set_alignment(4);
	set("race", "elf");
   set_body_type("human");
set_size(2);
   set_property("no attack", 1);
   set_hd(19,3);
}
