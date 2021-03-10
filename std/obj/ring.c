inherit "std/artifact";
inherit "std/armour";

void create()   {
  artifact::create();
  armour::create();
  set_name("ring of gandalf");
  set_short("Gandalf's Ring");
  set_id(({"ring","ring of gandalf"}));
  set_long("This is Gandalf's lost ring.");
  set_weight(10);
  set_value(2000);
  set_point_value(3);
}

void init()   {  armour::init();   }

