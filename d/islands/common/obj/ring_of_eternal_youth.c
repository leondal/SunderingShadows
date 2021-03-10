#include <std.h>

inherit "/d/common/obj/jewelry/ring.c";

string OWNER;

// ages for the various different races to be on the cusp of adulthood, could adjust this somewhat,
// I just looked at the high end of average start age and used that number -Ares
mapping AGES = ([
        "beastman"  : 23,
        "dwarf"     : 70,
        "elf"       : 130,
        "firbolg"   : 70,
        "gnome"     : 96,
        "half-elf"  : 21,
        "half-orc"  : 16,
        "halfling"  : 32,
        "human"     : 19,
        "bugbear"   : 16,
        "centaur"   : 16,
        "drow"      : 130,
        "gnoll"     : 11,
        "goblin"    : 19,
        "half-drow" : 19,
        "half-ogre" : 20,
        "hobgoblin" : 20,
        "kobold"    : 16,
        "minotaur"  : 18,
        "orc"       : 14,
        "ogre"      : 19,
        "ogre-mage" : 24,
        "voadkyn"   : 105,
        "wemic"     : 16,
        "yuan-ti"   : 19,
]);


void create()
{
    ::create();

    set_name("ring of eternal youth");

    set_obvious_short("%^RESET%^%^BOLD%^an %^CYAN%^exquisitely crafted band %^RESET%^of %^YELLOW%^pure gold%^RESET%^");

    set_short("%^RESET%^%^BOLD%^ring %^RESET%^of %^BLUE%^eternal %^BOLD%^%^CYAN%^youth%^RESET%^");

    set_id(({ "ring", "band","golden band","polished golden band","ring of eternal youth" }));

    set_long("%^RESET%^%^BOLD%^At first glance this ring seems to be an %^GREEN%^ordinary%^RESET%^%^BOLD%^, if %^CYAN%^exquisitely crafted, "
        "band %^RESET%^of %^YELLOW%^pure gold%^RESET%^%^BOLD%^.  On closer inspection however, %^MAGENTA%^images%^RESET%^%^BOLD%^ can be seen moving just "
        "below the %^CYAN%^metallic %^RESET%^surface %^BOLD%^of the ring.  When one stares into the ring they can see %^MAGENTA%^visions%^RESET%^%^BOLD%^ of "
        "people.  If one peers %^RED%^intently%^RESET%^%^BOLD%^ enough at the ring they can even begin to %^BLUE%^recognize%^RESET%^%^BOLD%^ some of the "
        "%^RESET%^faces%^BOLD%^ from their own past!  Unfortunately, as quickly as the %^MAGENTA%^visions%^RESET%^%^BOLD%^ appear, they are just as "
        "quickly lost and then the %^YELLOW%^ring%^RESET%^%^BOLD%^ again looks to be just an %^CYAN%^exquisitely crafted band %^RESET%^of %^YELLOW%^pure gold.%^RESET%^");

    set_lore("Since the very first mortals were gifted life by the gods they have wanted more time.  Various methods of gaining additional "
        "years have been tried over the centuries, from undeath to reincarnation to pacts with fiends and otherworldly forces and countless "
        "additional methods, some more successful than others.  In the year 487 SG there was a rumor that a consortium of powerful clerics "
        "and mages from a multitude of different faiths were commissioned by a wealthy trade group from the Tsarvani Empire.  They were given "
        "an almost unlimited budget to explore different methods of granting and sustaining youth in an individual.  The trade group wanted "
        "this ability so that their leaders could live out eternity in the opulence that their vast wealth could afford.  After more than fifty "
        "years working on the problem, and after spending tens of millions of the trade groups platinum coins for materials and research, the "
        "consortium finally had to admit that it had failed in the task.  The group was executed to a person for their failure.  Unbeknownst to "
        "either the consortium or to the trade group, a young assistant named Shelia Massit had succeeded where the others had failed.  By tieing "
        "the individual's own life force at a fixed place in time to their current physical form, she was able to create a ring that would grant "
        "the wearer everlasting youth.  These rings have recently begun to surface, along with the name of their creator.  It stands to reason that "
        "if Shelia had discovered the secret to eternal youth that she would still be around to craft more of the rings to this very day.");

    set_property("lore difficulty",10);
    set_weight(0);
    set_value(10000);
    set_property("magic", 7);
    set_property("no animate",1);
    set_property("death keep",1);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int query_overallStatus() { return 100; }

// check to make sure they are older than the age it would set them to before letting them use it
int age_check()
{
    string race;
    int age;

    if (!objectp(ETO)) { return 0; }
    race = lower_case((string)ETO->query_race());
    age = AGES[race];

    if (!age) { return 0; }
    if (age > (int)ETO->query_real_age()) { return 0; }
    return 1;
}


void do_first_wear(int step)
{
    int age;
    string race;

    if (!objectp(TO)) { return; }
    if (!objectp(ETO)) { return; }
    if (!objectp(EETO)) { return; }

    switch (step)
    {
    case 0:

        tell_object(ETO, "%^RESET%^%^YELLOW%^As the ring gets near your %^MAGENTA%^finger%^RESET%^%^YELLOW%^, you can feel a sudden surge of "
            "%^RESET%^%^BOLD%^%^CYAN%^life%^RESET%^%^YELLOW%^ and %^RESET%^%^BOLD%^%^CYAN%^vitality%^RESET%^%^YELLOW%^.%^RESET%^\n");
        tell_room(EETO, "%^RESET%^%^YELLOW%^As " + ETO->QCN + " brings the ring near " + ETO->QP + " %^MAGENTA%^finger%^RESET%^%^YELLOW%^"
            ", " + ETO->QS + " seems to %^RED%^pulsate%^RESET%^%^YELLOW%^ with %^RESET%^%^BOLD%^energy%^RESET%^%^YELLOW%^!%^RESET%^\n", ETO);
        call_out("do_first_wear", 5, 1);
        return;

    case 1:

        tell_object(ETO, "%^RESET%^%^BOLD%^%^GREEN%^When the ring slips onto your %^RESET%^%^MAGENTA%^finger%^RESET%^%^BOLD%^%^GREEN%^ you can instantly "
            "feel your %^RESET%^%^RED%^body%^RESET%^%^BOLD%^%^GREEN%^ begin to change.  The %^RESET%^%^YELLOW%^complexion %^RESET%^%^BOLD%^%^GREEN%^of your "
            "%^RESET%^%^BOLD%^skin%^GREEN%^ becomes more %^MAGENTA%^smooth%^RESET%^%^BOLD%^%^GREEN%^, your %^RESET%^%^BOLD%^bones%^RESET%^%^BOLD%^%^GREEN%^ become "
            "%^RESET%^%^BOLD%^%^RED%^stronger%^RESET%^%^BOLD%^%^GREEN%^, your %^RESET%^%^BOLD%^e%^CYAN%^y%^BLUE%^e%^RESET%^s%^BOLD%^%^GREEN%^ can suddenly %^RESET%^see "
            "%^BOLD%^%^GREEN%^more %^RESET%^%^BOLD%^clearly%^GREEN%^ and you are %^YELLOW%^alive%^RESET%^%^BOLD%^%^GREEN%^ with so much %^RED%^energy%^RESET%^%^BOLD%^%^GREEN%^!%^RESET%^\n");
        tell_room(EETO, "%^RESET%^%^BOLD%^%^GREEN%^When " + ETO->QCN + " slips the %^YELLOW%^ring%^RESET%^%^BOLD%^%^GREEN%^ onto " + ETO->QP + " "
            "finger, " + ETO->QP + " %^RED%^body%^RESET%^%^BOLD%^%^GREEN%^ begins to %^RESET%^%^MAGENTA%^change%^RESET%^%^BOLD%^%^GREEN%^!  You can practically %^RESET%^%^BOLD%^see "
            "%^GREEN%^the %^CYAN%^youth %^RESET%^%^BOLD%^%^GREEN%^and %^CYAN%^vigor %^RESET%^%^BOLD%^%^GREEN%^seeping into " + ETO->QO + "!%^RESET%^\n", ETO);
        call_out("do_first_wear", 5, 2);
        return;

    case 2:

        race = (string)ETO->query_race();
        age = AGES[race];
        if (!age)
        {
            tell_object(ETO, "ERROR: Race: " + race + " is not set in the ring of eternal youth, please notify a wiz.");
            return;
        }

        tell_object(ETO, "%^RESET%^%^BOLD%^With the %^YELLOW%^ring%^RESET%^%^BOLD%^ finally in place, you know without doubt that something profound "
            "has happened to you.  You feel %^CYAN%^young%^RESET%^%^BOLD%^, you must be no more than %^RED%^" + age + "%^RESET%^%^BOLD%^ years old!%^RESET%^\n");
        ETO->force_me("wear ring of eternal youth");
        return;
    }

    return;
}

int set_owner(string ownr)
{
    OWNER=ownr;
}

int wearme()
{
    string race;
    int age;

    if (!objectp(ETO)) { return 0; }
    if (!interactive(ETO)) { return 1; }

    if (!OWNER || !stringp(OWNER) || !strlen(OWNER))
    {
        if (!age_check())
        {
            tell_object(ETO, "%^RESET%^%^BOLD%^%^RED%^The ring burns painfully as it nears your finger.  No matter how hard you try, it refuses to go on!%^RESET%^");
            return 0;
        }

        OWNER = (string)ETO->query_true_name();
        do_first_wear(0);
        return 0;
    }

    if (OWNER != (string)ETO->query_true_name())
    {
        tell_object(ETO, "%^RESET%^%^MAGENTA%^No matter how hard you try, you just can't seem to get the ring to go onto your finger!%^RESET%^");
        return 0;
    }

    race = (string)ETO->query_race();
    age = AGES[race];

    if (!age)
    {
        tell_object(ETO, "ERROR: Race: " + race + " is not set in the ring of eternal youth, please notify a wiz.");
        return 0;
    }

    ETO->set("fixed_age", age);

    tell_object(ETO, "%^CYAN%^You slip the cool band over your finger and feel the vitality of youth running through your veins!%^RESET%^");
    tell_room(EETO, "%^CYAN%^" + ETO->QCN + " slips a cool band over " + ETO->QP + " finger.%^RESET%^", ETO);
    return 1;
}


int removeme()
{
    tell_object(ETO, "%^RESET%^%^RED%^No matter how hard you try, you can't seem to get the ring off of your finger!%^RESET%^");
    return 0;
}


int drop()
{
    if (!interactive(ETO)) { return ::drop(); }
    if (!OWNER || !stringp(OWNER) || !strlen(OWNER)) { return ::drop(); }
    if (!TO->query_worn()) { return ::drop(); }

    tell_object((ETO), "%^RESET%^%^RED%^No matter how hard you try, you can't seem to get the ring off of your finger!%^RESET%^");
    return 1;
}
