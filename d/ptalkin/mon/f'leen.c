//monsters by the House of Svaha
inherit "/std/comp_vend.c";

create() {
   ::create();
set_name("F'leen");
set_id(({"F'leen", "f'leen", "clerk", "alchemist", "shopkeeper"}));

set_short("%^RED%^F'leen, the alchemist");
set_long(
@DESC
%^RED%^F'leen, the alchemist reaches a height of 5' 6".  His dark
brown hair stands straight up at about one inch as the singed edges speak
of an experiment gone wrong.  He is, at the moment mixing flasks of blue
and a noxious green.  He seems to be peering intently at the smoke. 'By the
Gods', the smoke is brilliant RED.
DESC
);

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
"F'leen mumbles : Too much sulfur, too much sulfur",
"F'leen looks up through the smoke and gasps : Can I help you?"
}), 0);
}






