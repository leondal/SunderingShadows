inherit "/std/weapon";
create(){
	::create();

set_name("longsword");
set_id(({"sword","weapon"}));
set_short("A rusted longsword");
set_long(
@MILT
This is a normal iron longsword.  A little rust is on the blade
because of its years of lack of use.
MILT
);
set_weight(4);
set_size(2);
set_value(12);
set_wc(1,8);
set_large_wc(1,12);
set_type("slash");
}
