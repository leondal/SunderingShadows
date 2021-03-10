//  This is to be a room inheritable for underwater rooms.
//    People will be able to 'hold their breath' for a length of time
//    determined by their constitution.  There will be spells potions and
//    other items to follow to allow for breathing water.
//  Grendel  1/99
//
//  USAGE:
//   A person in a room with this inheritable will slowly drown.  Also, unless
//    they have a special item, they will sink if they are overloaded with eq.
//   Air pockets can be supplied.  Room can be set as a surface room.
//   Sinking is down.  Floating is staying put.

//    set_surface(1)  sets the room as a 'surface' room.  Plenty of air, but
//      will still sink
//    set_surface(0)  Default.  Sets room as underwater.  No air, still sinks.
//    set_air_pocket(int x)  Sets the room as having stored air.  Can breathe
//      here for a limited period of time.  

//  Any questions read on, or talk to Grendel
// changed to inherit CROOM so we can control wandering mob populations 6/17/03
// yes, it makes all of them use a little more memory but Grendel agreed it's the lesser of evils than to duplicate the CROOM coding  *Styx*

#include <std.h>
#define SUFFOCATEOB "/d/dagger/suff_ob.c"

inherit CVAULT;
int floats(object ob);
void set_air_pocket(int x);
int query_air_pocket();
void set_surface(int x);

void create() {
    ::create();
    set_property("continue heartbeat", 1);
    set_property("underwater", 1);
    set_property("used sticks", 1);
    set_property("indoors", 1);
    set_name("Drowning");
    set_heart_beat(2);
}

void init() {
    ::init();
    add_action("light", "light_lantern");
}

void heart_beat() {
    int i;
    object *inv, ob;
    string roomstr;
    ::heart_beat();

    inv = all_inventory(TO);
    for (i=0;i<sizeof(inv);i++) {
// added check to exclude true invis immortals *Styx* 1/4/04, last change 6/17/03
        if (!floats(inv[i]) && !query_property("no sinking") && !inv[i]->query_true_invis()) {
            if (roomstr = TO->query_exit("down")) {
                if (file_exists(roomstr)) {
                    if (ob = find_object_or_load(roomstr)) {
                        tell_room(TO, "%^BOLD%^"+inv[i]->query_short()+" sinks!");
                        tell_room(ob, "%^BOLD%^"+inv[i]->query_short()+" slowly sinks into the room");
                        inv[i]->move(ob);
                    }
                }
            }
        }

        if (!living(inv[i])) continue;
		//fixed a typo here - was undrwtr_breath_ob - instead of the 
		//correct spelling - Saide - July 1, 2008
        if (present("underwtr_breath_ob", inv[i]) || inv[i]->query_property("water breather") || query_property("surface"))
            continue;
// added check to exclude true invis immortals *Styx* 1/4/04, last change 6/17/03
	if(inv[i]->query_true_invis())
	   continue;
        if (query_property("air pocket")) {
            set_property("air pocket", -1);
            if (!(query_property("air pocket")%6))
                tell_object(inv[i], "The air in here is getting stale.");
            if (!query_property("air pocket"))
                tell_object(inv[i], "There is no more air here to breathe!!!");
            continue;
        }
        if (!present("suff_ob", inv[i])) {
            tell_object(inv[i], "%^BOLD%^%^CYAN%^Just before your mouth goes below the water, you fill your lungs with air.");
            ob = new(SUFFOCATEOB);
            ob->move(inv[i]);
            ob->start_suffocation();
        }
    }
    return;
}

int floats(object ob) {
    int x, y;
    float z;

    if (wizardp(ob)) return 1;
    if (!living(ob)) return 0;
    if (ob->query("no swim")) return 0;
    if (ob->query_property("floats") || ob->query_property("swims")) return 1;
    x = ob->query_internal_encumbrance();
    y = ob->query_max_internal_encumbrance();
    z = to_float(x)/to_float(y);
    z *= 100;
    x = z;
    if (x > 65) return 0;
    return 1;
}

int light(string str) {
    object ob;

    if (!str) return 0;
    if (present(str, TP)) ob = present(str, TP);
    if (present(str, ETP)) ob = present(str, ETP);
    if (!ob) return 0;
    if (ob->query_fuel() && !ob->query_property("underwater light")) {
        tell_object(TP, "You can't light that underwater!");
        return 1;
    }
}

void set_air_pocket(int x) {
    set_property("air pocket", x);
}
int query_air_pocket() {
    return query_property("air pocket");
}

void set_surface(int x) {
    if (x) {
        remove_property("underwater");
        set_property("surface", 1);
    } else {
        remove_property("surface");
        set_property("underwater", 1);
    }
}
