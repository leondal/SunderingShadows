inherit "/std/vendor";


void create() {
   ::create();
set_name("D'repal");
set_id(({"D'repal", "d'repal", "banker", "elf"}));
set_short("D'repal, the banker");
set_long("The banker D'repal paces around the room, checking over shoulders, bending to look at papers and smiling genially at customers.  While he is a full high elf, he is about five feet tall, unlike most high elves, rather sort of chubby and dumpy looking. However his bright blue eyes miss nothing and intelligence is marked by the quickness of his movements.");
   set("aggressive", 0);
   set_level(19);
   set_gender("male");
   set_alignment(4);
	set("race", "elf");
   set_body_type("human");
set_size(2);
   set_property("no attack", 1);
   set_hd(19,3);
set_emotes(2, ({
"D'repal sighs : Money, money, money.....",
"D'repal laughs softly to himself : Oooooo, so many coins"
}), 0);
}
