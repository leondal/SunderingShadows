#include <std.h>
#include "../tecqumin.h"

#define ENERGIES "%^BOLD%^%^CYAN%^different %^BOLD%^%^MAGENTA%^coloured %^BOLD%^%^GREEN%^energies"

inherit MONSTER;

string* exits, * destinations, location;

void create()
{
    ::create();
    set_long("This octagonal stone seal is about the size of a human"
             + " hand, and is carved with eight symbols. Each symbol aligns with"
             + " one of the edges of the octagon, and their inner edges meet to"
             + " form a smaller octagon in the centre of the seal. A ninth symbol"
             + " sits in this nexus, seemingly absorbing and redirecting the power"
             + " of the other eight. \n %^ORANGE%^All of the symbols are alive"
             + " and %^BOLD%^%^YELLOW%^glowing%^RESET%^%^ORANGE%^"
             + " with power, and sheets of " + ENERGIES
             + " %^RESET%^%^ORANGE%^stream off from them, blocking access"
             + " to every exit from the room. A final,"
             + " %^BOLD%^%^CYAN%^sh%^RESET%^i%^CYAN%^m%^BLUE%^m"
             + "%^CYAN%^e%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^i"
             + "%^BLUE%^n%^BOLD%^%^CYAN%^g %^RESET%^%^CYAN%^d"
             + "%^BLUE%^o%^CYAN%^m%^BLUE%^e %^RESET%^%^ORANGE%^"
             + "of energy fountains from the central symbol, blocking the room"
             + " from teleportation!");
    set_gender("neuter");
    set_race("seal");
    set_property("not random monster", 1);
    set_short("octagonal stone seal");
    set_weight(5);
    set_id(({ "seal", "stone seal", "octagonal seal", "octagonal stone seal" }));
    set_max_hp(3000);
    set_hp(3000);
    set_body_type("humanoid");
    remove_limb("left hand");
    remove_limb("right hand");
    remove_limb("left arm");
    remove_limb("right arm");
    remove_limb("left foot");
    remove_limb("right foot");
    remove_limb("left leg");
    remove_limb("right leg");
    remove_limb("neck");
    remove_limb("waist");
}

void init()
{
    ::init();
    add_action("get_me", "get");
    add_action("break_me", "break");
}

int get_me(string str)
{
    return notify_fail("The seal is clamped to the floor, and you can't lift it!"
                       + " Maybe you could try to break it, though?");
}

int break_me(string str)
{
    int i;
    for (i = 1; i < 10; i++) {
        if (present("seal " + i, ETO) == TO) {
            TP->force_me("attack seal " + i);
            return 1;
        }
    }
    return 0;
}

int activate()
{
    int i, count, colour;
    if (!objectp(ETO)) {
        return 0;
    }
    if (!ETO->is_room()) {
        return 0;
    }
    location = file_name(ETO);
    exits = ETO->query_exits();
    count = sizeof(exits);
    destinations = ({});
    for (i = 0; i < count; i++) {
        destinations += ({ ETO->query_exit(exits[i]) });
        ETO->remove_exit(exits[i]);
    }
    ETO->set_property("teleport proof", 63); //upped to 67, equivalent of no tp ball
    //ETO->set_property("sealed", 15);
    tell_room(ETO, "Sheets of " + ENERGIES + " %^RESET%^shoot off from the octagonal stone seal, blocking all the exits.");
    tell_room(ETO, "%^ORANGE%^A final, %^BOLD%^%^CYAN%^sh%^RESET%^"
              + "i%^CYAN%^m%^BLUE%^m%^CYAN%^e%^BOLD%^%^CYAN%^"
              + "r%^RESET%^%^CYAN%^i%^BLUE%^n%^BOLD%^%^CYAN%^g"
              + " %^RESET%^%^CYAN%^d%^BLUE%^o%^CYAN%^m%^BLUE%^e"
              + "%^RESET%^%^ORANGE%^ of energy forms above the whole area,"
              + " blocking any form of teleportation");
    call_out("expire", 40 + random(30));
}

void restore_exits()
{
    int i, count;
    object room;
    room = find_object_or_load(location);
    if (!objectp(room)) {
        return;
    }
    count = sizeof(exits);
    if (count > sizeof(destinations)) {
        count = sizeof(destinations);
    }
    if (count > 0) {
        for (i = 0; i < count; i++) {
            room->add_exit(destinations[i], exits[i]);
            tell_room(room, "%^BOLD%^%^RED%^The " + exits[i] + " exit is revealed!");
        }
    }
    room->set_property("teleport proof", -63);
}

void expire()
{
    object room;
    room = find_object_or_load(location);
    if (objectp(room)) {
        tell_room(room, "The " + ENERGIES + " %^RESET%^emanating from the octagonal stone seal start to %^YELLOW%^waver%^RESET%^.");
        call_out("expire2", 10 + random(10));
    }
}

void expire2()
{
    object room;
    room = find_object_or_load(location);
    if (objectp(room)) {
        tell_room(room, "The " + ENERGIES + " %^RESET%^finally sputter out, rushing back into the octagonal stone seal, which implodes and disappears.");
        restore_exits();
        TO->move("/d/shadowgate/void");
        TO->remove();
    }
}

void die(object ob)
{
    object room, corpse;
    room = find_object_or_load(location);
    if (objectp(room)) {
        tell_room(room, "%^BOLD%^%^RED%^With a mighty%^YELLOW%^"
                  + " flash of light%^RED%^, the %^RESET%^octagonal stone seal"
                  + " %^BOLD%^%^RED%^shatters, and the%^BOLD%^%^CYAN%^"
                  + " different %^BOLD%^%^MAGENTA%^coloured"
                  + " %^BOLD%^%^GREEN%^energies%^BOLD%^%^RED%^"
                  + " dissipate!");
        restore_exits();
    }
    room = ETO;
    ::die(ob);
    if (objectp(room)) {
        corpse = present("corpse", room);
        if (objectp(corpse)) {
            corpse->move("d/shadowgate/void");
            corpse->remove();
        }
    }
}
