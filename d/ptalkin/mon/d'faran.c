inherit "/std/comp_vend.c";

create() {
   ::create();
set_name("D'faran");
set_id(({"D'faran", "d'faran", "clerk", "shop keeper", "shopkeeper"}));
set_short("D'faran, The Alchemist");
   set("aggressive", 0);
   set_level(19);
set_long("%^RED%^D'faran, the alchemist stands approximately five feet four inches tall and weights about 150.  He has fine features with high etched cheekbones.  His skin is pale, his hair blonde and his eyes a bold brilliant blue.  He leans over his counter with one slight hand resting upon his brow.  Soot and smudges upon his face, hands and heavy leather apron complete his makeup.");
   set_gender("male");
   set_alignment(5);
set("race", "elf");
set_size(2);
   set_hd(19,1);
    set_body_type("human");
    set_property("no bump", 1);
      set_components(100);
	add_money("silver", 500);
set_emotes(2, ({
"D'faran mumbles : Too much sulfur, too much sulfur",
"D'faran looks up wearily and asks : Can I help you?"
}), 0);
}

