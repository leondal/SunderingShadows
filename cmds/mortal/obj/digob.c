// digger object by Garrett and Obsidian
#include <std.h>

inherit OBJECT;

void create()
{
    ::create();
    set_name("Digging Object");
    set_short("digger object");
    set_long("This is something you dig with. Offer it");
    set_id(({ "dig", "digger object", "digger" }));
}

void init()
{
    ::init();
    if (ETO == find_player("garrett")) {
        tell_object(ETO, "Hi dad!");
    }
}

int drop()
{
    return 1;
}

int save_me(string file)
{
    return 1;
}

int get()
{
    return 0;
}

int restore_me(string file)
{
    TO->remove();
}

int begin_dig(string str, object tp)
{
    if ((!objectp(tp)) && (!objectp(environment(tp)))) {
        return 0;
    }

    tell_object(tp, "You begin digging at the rocks.");
    tell_object(tp, "Hit <RETURN> to stop digging at the rubble.");
    tell_room(environment(tp), tp->query_cap_name() + " digs at the rubble blocking the exit.", tp);
    call_out("move_rubble", 1, str, tp);
    input_to("check_activity", 1);
    tp->set_paralyzed(400);
    return 1;
}

int check_activity(string str)
{
    if (remove_call_out("move_rubble") != -1) {
        tell_object(TP, "You stop digging to do something else.");
        TP->remove_paralyzed();
        TO->remove();
        return 1;
    }
    TO->remove();
    return 1;
}

void move_rubble(string ext, object tp)
{
    string* buried_exits;
    mapping buried_exit_map;
    object etp, otp;
    int i;

    buried_exit_map = (mapping)environment(tp)->query_buried_exits();
    buried_exits = keys(buried_exit_map);
    if (tp->query_unconscious()) {
        tell_object(tp, "You have passed out from exhaustion.");
        tp->remove_paralyzed();
        TO->remove();
        return;
    }
    if (member_array(ext, buried_exits) == -1) {
        tell_object(tp, "There is no more rubble to dig.");
        tell_object(tp, "press <RETURN> to continue.");
        tp->remove_paralyzed();
        TO->remove();
        return;
    }

    if (tp->query_stats("constitution") < random(25)) {
        tell_object(tp, "You hurt your back moving the stone.");
        tp->cause_typed_damage(tp, "torso", roll_dice(1, 5), "untyped");
    }

    tell_object(tp, "You slowly move the rubble out of the way.");
    tell_room(environment(tp), tp->query_cap_name() + " moves the rubble away from the exit.", tp);
    i = environment(tp)->dig_exit(ext, (int)tp->query_stats("strength"));
    if (i <= 0) {
        etp = environment(tp);
        tell_object(tp, "You break through the rubble.");
        tell_room(environment(tp), tp->query_cap_name() + " breaks through the rubble to the other side.", tp);
        tell_object(tp, "press <RETURN> to continue.");
        tp->remove_paralyzed();
        if (objectp(etp)) {
            etp->remove_property("wall of stone");
        }
        if (objectp(otp = to_object(etp->query_exit(ext)))) {
            otp->remove_property("wall of stone");
        }
        TO->remove();

        return;
    }

    {
        int tim;

        tim = (tp->query_stats("dexterity") - 10) / 2;
        tim = tim < 1 ? 1 : tim;
        tim = tim > 10 ? 10 : tim;
        tim = 10 / tim;
        call_out("move_rubble", tim, ext, tp);
    }
}