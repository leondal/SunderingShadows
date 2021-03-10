//monsters by the House of Svaha
inherit "/std/vendor";

create() {
   ::create();
set_name("F'bollin");
set_id(({"shop keeper", "shopkeeper", "clerk", "F'bollin", "f'bollin", "elf"}));
set_short("%^MAGENTA%^F'bollin, shopkeeper");
   set("aggressive", 0);
   set_level(19);
set_long(
@DESC
%^MAGENTA%^F'bollin, waits behind the counter.  He is a sylvan elf by
appearance, but for the most part is much more jolly than his country
men.  Dark russet hair is set off by a pair of emerald green eyes, 
which appear to be watching you very closely.  F'bollin brooks no 
thieves in HIS store.  There are no real outstanding features on 
F'bollin, except the size of his biceps, years of carrying merchandise
to and fro in the store, have made him one of the best arm wrestlers in
the area.  He smiles and greets you warmly.
DESC
);
   set_gender("male");
   set_alignment(4);
set("race", "elf");
   add_money("gold", random(500));
   set_body_type("human");
set_size(2);
set_storage_room("d/ptalkin/room/g_storage");
   set_property("no attack", 1);
   set_hd(19,3);
   set_items_allowed("misc");
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
set_emotes(2, ({
"F'bollin bellows : How can I help you traveller",
"F'bollin says : Feel free to have a look around and let me know if
you need any help"
}), 0);
}
