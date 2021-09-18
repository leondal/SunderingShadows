//NOT ACTIVELY USED

#include <objects.h>
#include <daemons.h>

string* night_races()
{
    return ({ "drow", "half-drow", "bugbear", "kobold", "hobgoblin", "gnoll", "orc", "lich", "ogre", "ogre-mage", "goblin", "minotaur", "ratkin", "troll", "nightwing" });
}

string* list_classes()
{
    string* possible_classes, * classlist = ({}), myname;
    int i;
    object class_ob;
    myname = TP->query_name();
    possible_classes = get_dir("/std/class/*.c");
    possible_classes = explode(implode(possible_classes, ""), ".c");
    possible_classes -= ({ "cavalier", "antipaladin" });
    if (sizeof(possible_classes)) {
        for (i = 0; i < sizeof(possible_classes); i++) {
            class_ob = find_object_or_load("/std/class/" + possible_classes[i] + ".c");
            classlist += ({ possible_classes[i] });
        }
    }
    return classlist;
}

int immunity_check(object obj, string type)
{
    string myrace, mysubrace;
    int num;
    if (!objectp(obj)) {
        return 0;
    }
    myrace = obj->query_race();
    mysubrace = obj->query("subrace");

    switch (type) {
    case "sleep":
    {
        if (obj->is_undead()) {
            return 1;
        }

        if (member_array(myrace, ({ "elf", "drow", "half-elf", "half-drow", "golem", "soulforged" })) != -1) {
            return 1;
        }

        return 0;
    }

    case "charm":
    {
        if (myrace == "barrus") {
            return 1;
        }

        if (check_aura(obj, "resolve") == 1) {
            return 1;
        }
    }

    case "fear":
    {
        if (FEATS_D->usable_feat(obj, "no fear of the flame")) {
            return 1;
        }

        if (FEATS_D->usable_feat(obj, "bravery")) {
            return 1;
        }

        if (check_aura(obj, "courage") == 1) {
            return 1;
        }

        if (obj->query_property("fear_immunity")) {
            return 1;
        }

        if (member_array(myrace, ({ "halfling", "troll", "firbolg" })) != -1) {
            return 1;
        }

        if (myrace == "human" && mysubrace == "attayan") {
            return 1;
        }

        if(obj->query_class_level("cleric"))
        {
            if(member_array("martyr", obj->query_divine_domain()) >= 0)
                return 1;
        }

        return 0;
    }

    case "fatigue":
    {
        if (obj->is_undead()) {
            return 1;
        }
        if (member_array(obj->query_race(),
                         ({ "golem", "construct", "soulforged" }))) {
            return 1;
        }

        return 0;
    }


    default:
        return 0;
    }

    return 0;
}

int check_aura(object target, string type)
{
    object* allies;
    string aura;
    int prot;

    if (!target || !type) {
        return 0;
    }

    allies = PARTY_D->query_party_members(target->query_party());

    if (!sizeof(allies)) {
        allies = ({ target });
    }

    //Immunity
    if (FEATS_D->usable_feat(target, "aura of " + type)) {
        return 1;
    }

    allies -= ({ target });

    //+4
    foreach(object ally in allies)
    {
        if (FEATS_D->usable_feat(ally, "aura of " + type)) {
            return 2;
        }
    }

    return 0;
}

int opposed_alignment(object me, object you)
{
    string* opposed;
    int my_align, your_align;

    if (!me || !you) {
        return 0;
    }

    my_align = me->query_true_align();
    your_align = you->query_true_align();

    if (my_align == 5 || your_align == 5) {
        return 0;
    }

    //If you're the polar opposite
    if (my_align - (10 - your_align) == 0) {
        return 2;
    }

    opposed = ({ "000", "78936", "789", "78914", "369", "000", "147", "12369", "123", "12347" });

    if (strsrch(opposed[my_align], your_align + "") >= 0) {
        return 1;
    }

    return 0;
}
