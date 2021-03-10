inherit "/std/armour";
void create(){
	::create();
set_name("plate");
set_id(({"platemail","mail","Platemail","armor","armour"}));
set_short("Rusted platemail");
set_long(
@MILT
This is a rusted suit of platemail.  On the tarnished chestplate
you can vaguely make out Kravor's crest.
MILT
);
set_weight(50);
set_value(450);
set_type("armour");
set_limbs(({"torso"}));
set_ac(6);
}
