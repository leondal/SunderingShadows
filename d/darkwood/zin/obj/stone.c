inherit "/std/Object";

void create() {
    ::create();
    set_name("stone");
    set("id", ({"stone", "stone of shattering"}) );
    set("short", "Stone of Shattering");
    set("long", "This appears to be an ordinary stone washed up from "+
        "the depths of Darklake.  The many years washing under the "+
        "the dark cold waters has worn it smooth.  You feel a slight "+
        "tinge of magic pulse from the stone causing you to think that "+
        "the waters of Darklake have done more than just smoothed its "+
        "surface.");
    set_weight(1);
    set_value(200);
    set_property("magic item", ({"rub"}) );
}

void init() {
    ::init();
    add_action("shatter", "shatter");
}

int shatter(string str) {
    //  The actual shatter function is called in the correct room. 
    if(!str) {
        notify_fail("Shatter what?\n");
        return 0;
    }
    notify_fail("You fail to shatter "+str+".\n");
    return 0;
}
