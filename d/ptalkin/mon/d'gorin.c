inherit "/std/vendor";

create() {
   ::create();
set_name("D'gorin");
set_id(({"D'gorin", "d'gorin", "clerk", "shop keeper", "shopkeeper"}));
set_short("D'gorin, Armourer");
   set("aggressive", 0);
   set_level(19);
set_long("%^ORANGE%^D'gorin stands in front of a large round spinning whetstone.  He is honing a large battleaze and the sparks are flying.  His apron, made of thick leather shows cuts, slashes and the burn marks of his trade.");
   set_gender("male");
   set_alignment(5);
set("race", "elf");
   set_hd(19,1);
    set_body_type("human");
set_size(2);
    set_property("no bump", 1);
set_storage_room("/d/ptalkin/room/ar_storage");
	add_money("silver", 500);
set_emotes(2, ({
"D'gorin asks : Can I help you in anyway?",
"D'gorin smiles : Feel free to look around."
}), 0);
}

