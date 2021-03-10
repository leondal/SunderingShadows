inherit "std/room";

void create() {
    set_property("light", 0);
    set("short", "A hole in the ground");
    set("long",
	"You are in a deep hole in the ground. The light is very poor "
	"down here.");
    set_no_clean(1);
    set_exits( ([ ]) );
}

void fixing_a_hole() {
    remove_item_description("hole");
    remove_exit("up");
}

void digging() {
   add_item_description("hole", "A hole up to the surface.");
   add_exit("/d/standard/west_road2", "up");
}

void reset() {
    object money;
    ::reset();
    if(!present("money")) {
        money = new("/std/obj/coins");
	money->set_money("platinum", random(5));
	money->set_money("silver", random(100));
	money->set_money("copper", random(1000));
	money->move(this_object());
    }
}

