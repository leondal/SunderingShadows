inherit "/std/Object";
void create(){
  ::create();
  set_name("rubble");
  set_id(({"rubble","pile of rubble","pile"}));
  set_short("pile of rubble");
  set_long(
    " It's a pile of scrap metal with what look like joints and gears and all sorts of other mechanical nonsense with grease and oil leaking onto the floor from it."
  );
  set_weight(100000);
  set_value(0);
  set_property("no animate",1);
}
