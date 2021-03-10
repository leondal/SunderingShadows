//monsters by the House of Svaha
inherit "/std/vendor";


void create() {
   ::create();
set_name("F'relck");
set_id(({"F'relck", "f'relck", "banker", "elf"}));
set_short("%^ORANGE%^F'relck, moneyman");
set_long(
@DESC
%^ORANGE%^F'relck, the moneyman, is about 5'6" tall.  He has dark brown
hair tied back with a piece of leather.  His eyes are dark brown and
very cold.  A ragged scar crosses his left eye, runs across his nose
and reaches to the right side of his chin.  His right ear is rounded,
not by birth.  His right hand has three fingers missing, and his left
has two fingers missing.  One leg is slightly crooked, from an injury
not healed correctly.  An ally to be proud of, a foe to be feared.
DESC
);
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
"F'relck growls : What do you want?"
}), 0);
}
