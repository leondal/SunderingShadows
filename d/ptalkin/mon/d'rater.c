inherit "/std/comp_vend.c";

create() {
   ::create();
set_name("D'rater");
set_id(({"D'rater", "d'rater"}));
set_short("%^GREEN%^D'rater, stablekeeper");
   set("aggressive", 0);
   set_level(19);
set_long("%^ORANGE%^D'ratr is an average size elf, wearing a brown tunic and pants.  His light brown hair is tousled and has the occasional piece of straw attached.  His face is wrinkled due to the amount of weather he gets by looking after his horses.  His long legs are slightly bowed after years of riding.");
   set_gender("male");
   set_alignment(5);
set("race", "elf");
   set_hd(19,1);
    set_body_type("human");
set_size(2);
    set_property("no bump", 1);
      set_components(100);
	add_money("silver", 500);
set_emotes(2, ({
"D'rater asks : What can I help you with?",
"D'rater says : My mounts are the finest in the country"
}), 0);
}
