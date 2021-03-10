inherit "/std/armour";
void create(){
	::create();
set_name("helm");
set_id(({"helmet","helm","armour","armor"}));
set_short("Rusted helm");
set_long(
@MILT
This is a rusted helmet from an age long past.
MILT
);
set_type("clothing");
set_value(20);
set_weight(8);
set_ac(1);
set_limbs(({"head"}));
}
