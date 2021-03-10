#include <std.h>
#include "../tharis.h"
inherit WATER;

int water_level, clog;
string* swimming;

void create()
{
    ::create();
    set_travel(SLICK_FLOOR);
    set_property("no sticks", 1);
    set_name("Sewer pit");
    set_property("light", 0);
    set_property("surface", 1);
    set_property("no teleport", 1);
    set_short("%^BLUE%^The bottom of the slide%^RESET%^");
    set_long("%^BLUE%^You are surrounded on four sides by tall, slick walls. You immediately "
             "see that escape up will not come by climbing. Old pipes staggered above you gush out "
             "%^CYAN%^water, %^BLUE%^tumbling to pummel your head. You stand in about two feet of water, "
             "but you know it isn't getting any higher. At the base of each wall is a large %^RESET%^drain "
             "%^BLUE%^that drops the water into what must be another channel. Every now and then the water "
             "comes in a great gush. You worry that these might eventually hurt you seriously.\n%^RESET%^");
    set_listen("default", "You hear little but the crashing water");
    set_smell("default", "The fetid waters send irritating fumes.");

    set_exits(([]));
    set_items(([
                   "water" : "The water falls in and flows out through the drains on the floor.",
                   "pipes" : "These rusty old pipes bring water from about the city to this drainage area.",
                   ({ "walls", "wall" }) : "These walls are slick with the slime of water slamming into them on its downward path.",
                   ({ "drains", "drain" }) : "These drains are allowing water to flow quickly from the room. Without these the pit would fill and possibly overflow. That gives you an idea..."
               ]));
    water_level = 2;
    swimming = ({});
}

void init()
{
    ::init();

    tell_room(TO, "%^BOLD%^%^BLUE%^SPOOOOOOOOOOSH!!!!!");
    write("%^BOLD%^%^YELLOW%^You land heavily in " + water_level + " feet of water.");
    tell_room(TO, "%^BOLD%^" + TPQCN + " lands heavily next to you!", TP);
    TP->add_attacker(TO);
    TP->do_damage("torso", random(20));
    TP->continue_attack();
    TP->remove_attack(TO);
    add_action("swim", "swim");
    add_action("plugem", "plug");
    add_action("get_stop", "get");
}

int get_stop(string str)
{
    if (!str) {
        return 0;
    }
    if (member_array(TPQN, swimming) == -1) {
        return 0;
    }
    tell_object(TP, "You can't manage to get that item while you are swimming!");
    return 1;
}

int swim(string str)
{
    int temp1, temp2;
    if ((!clog) || (water_level < 4)) {
        return notify_fail("You can't swim in this little water!\n");
    }
// that's a little newbie unfriendly for me...
/*  temp1 = TP->query_internal_encumbrance();
   temp2 = TP->query_max_internal_encumbrance();
   if (temp1> temp2/2) {
    tell_object(TP,"%^BOLD%^%^GREEN%^You flounder around, but you are too encumbered to swim!");
    tell_room(TO,"%^BOLD%^%^BLUE%^"+TPQCN+" is pulled under by "+TP->QP+" equipment!",TP);
    TP->set_paralyzed(10,"Your floundering has dragged you under slightly!");
    return 1;
   } */
    if (member_array(TPQN, swimming) == -1) {
        tell_room(TO, "%^BOLD%^%^BLUE%^" + TPQCN + " starts swimming!!", TP);
        tell_object(TP, "%^BOLD%^%^BLUE%^You start swimming in these fetid waters!");
        swimming += ({ TPQN });
    }else {
        tell_object(TP, "You are already swimming");
    }
    return 1;
}

int plugem(string str)
{
    if (!str) {
        return notify_fail(query_verb() + " what?\n");
    }
    if (str != "drain" && str != "drains") {
        return notify_fail(query_verb() + " what?\n");
    }

    tell_object(TP, "%^BOLD%^%^BLUE%^You gather cloth and dirt and such and start trying to block the drains.");
    tell_room(TO, "%^BOLD%^%^BLUE%^" + TPQCN + " starts trying to block the drains!", TP);
    clog = 1;
    TP->set_paralyzed(10, "You are clogging the drains!");
    call_out("fill", 7);
    return 1;
}

void fill()
{
    int i, j;
    object ob, * inven, * livings, * temp;
    string* temp2;
    temp = ({});
    temp2 = ({});
    livings = ({});
    inven = all_inventory(TO);
    i = sizeof(inven);
    for (j = 0; j < i; j++) {
        if (living(inven[j])) {
            livings += ({ inven[j] });
        }
    }

    if (water_level > 29) {
        i = sizeof(swimming);
        for (j = 0; j < i; j++) {
            if (ob = present(swimming[j])) {
                tell_object(ob, "%^BOLD%^%^BLUE%^The water has reached sufficient " +
                            "height that you manage to slowly crawl out of the pit!\n");
                tell_room(TO, "%^BOLD%^%^BLUE%^" + ob->QCN + " manages to climb from the pit!", TP);
                ob->move_player(SEWERS "sewer11");
                tell_object(ob, "%^BOLD%^%^BLUE%^The fatigue of the struggle takes " +
                            "control of your body! You collapse, unable to move!\n");
                ob->set_paralyzed(50, "You are too tired to move!");
                temp2 += ({ ob->query_name() });
                temp += ({ ob });
            }
        }
        swimming -= ({ temp2 });
        livings -= ({ temp });
        if (water_level > 31) {
            tell_room(TO, "%^BOLD%^%^BLUE%^Suddenly the drains clear themselves!");
            tell_room(TO, "%^BOLD%^%^BLUE%^The water gushes downward, sucking you with it.");
            clog = 0;
            swimming = ({});
            water_level = 2;
            set_property("surface", 1);
            return;
        }
    }
    if (water_level > 7) {
        i = sizeof(livings);
        for (j = 0; j < i; j++) {
            if (member_array(livings[j]->query_name(), swimming) == -1) {
                tell_object(livings[j], "%^BOLD%^%^BLUE%^The deep water presses against you! You realise you should start swimming if you want to reach the top!\n");
                ob = present("suff_ob", livings[j]);
                if (objectp(ob)) {
                    ob->set_held_time((int)ob->query_held_time() + 10);
                }
            }
        }
    } else if (water_level > 5) {
        i = sizeof(livings);
        for (j = 0; j < i; j++) {
            if (member_array(livings[j]->query_name(), swimming) == -1) {
                if ((int)livings[j]->query_size() == 2 || (int)livings[j]->query_size() == 1) {
                    tell_object(livings[j], "%^BOLD%^%^BLUE%^The deep water presses against you! You realise you should start swimming if you want to reach the top!\n");
                    ob = present("suff_ob", livings[j]);
                    if (objectp(ob)) {
                        ob->set_held_time((int)ob->query_held_time() + 10);
                    }
                }
            }
        }
    } else if (water_level > 3) {
        i = sizeof(livings);
        for (j = 0; j < i; j++) {
            if (member_array(livings[j]->query_name(), swimming) == -1) {
                if ((int)livings[j]->query_size() == 1) {
                    tell_object(livings[j], "%^BOLD%^%^BLUE%^The deep water presses against you! You realise you should start swimming if you want to reach the top!\n");
                    ob = present("suff_ob", livings[j]);
                    if (objectp(ob)) {
                        ob->set_held_time((int)ob->query_held_time() + 10);
                    }
                }
            }
        }
    }
    tell_room(TO, "%^BOLD%^BLUE%^SPOOSHSPOOSHSPOOSHSPOOSHSPOOSHSPOOSHSPOOSHSPOOSHSPOOSH");
    tell_room(TO, "%^BOLD%^BLUE%^The water rises rapidly!!");
    water_level += 2;
    remove_property("surface");
    call_out("fill", 4);
}
